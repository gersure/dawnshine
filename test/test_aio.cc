#include<iostream>
#include <libaio.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<errno.h>
#include<unistd.h>


#define PAGE_SIZE 1<<12
#define CHECK_ERROR(r, w, fs, f) (check_error(r,w,fs,f,__FILE__, __LINE__))
#define MAX_NR 10000
#define MIN_NR 1


/*
* ret:fun ret
* what:what value
* sf_flag:succuess or failure
*        1 succuess
*        0 failure
*
*/
int check_error(int ret, int what, int sf_flag, const char *fun, const char *szFile, const int iLine) {
    if (sf_flag == 1) {
        if (ret != what) {
            printf("error file:%s line:%d", szFile, iLine);
            perror(fun);
            exit(-1);
        }
    } else if (sf_flag == 0) {
        if (ret == what) {
            printf("error file:%s line:%d", szFile, iLine);
            perror(fun);
            exit(-1);
        }
    }
    return 0;
}

class AIOre {
public:
    int *buffer;

    virtual void Complete(int ret) = 0;

    AIOre() {
        int ret = posix_memalign((void **) (&buffer), PAGE_SIZE, PAGE_SIZE);/* 分配一个4096(bytes)大小的4096对其内存空间 */
        CHECK_ERROR(ret, 1, 0, "posix_memalign");
    }

    virtual ~AIOre() {
        printf("Virtual AIOre destory function to free this buffer!");
        free(buffer);
    }
};

class Adder {
public:
    virtual void Add(int amount) = 0;

    virtual ~Adder() {};
};

class AIOread : public AIOre {
private:
    Adder *adder;//父类指针
public:
    AIOread(Adder *adder) : AIOre()//父类指针指向子类对象
    {
        this->adder = adder;
    }

    virtual void Complete(int res) {
        //return check
        int value = buffer[0];
        printf("Read of %d Completed %d res ", value, res);
        //多态
        adder->Add(value);
    }

};

class AIOWrite : public AIOre {
private:
    int value;
public:
    AIOWrite(int value) : AIOre() {
        buffer[0] = value;
        this->value = value;
    }

    virtual void Complete(int res) {
        //error check
        printf("Write of %d Completed %d \n", value, res);
    }
};

class AIOAdder : public Adder {
public:
    int fd;
    io_context_t ioctx;
    int counter; /* 偏移量 */
    int reap_counter; /* event个数 */
    int sum; /* */
    int length; /* 文件大小/PAGE_SIZE */

    AIOAdder(int length) {
        ioctx = 0;//必须初始化为0
        counter = 0;
        reap_counter = 0;
        sum = 0;
        this->length = length;
    }

    void init() /* 初始化打开文件并且预分配文件大小 */
    {
        printf("Open file\n");
        fd = open("test", O_RDWR | O_DIRECT | O_CREAT, 0644); //必须包含O_DIRECT
        CHECK_ERROR(fd, 0, -1, "open");
        printf("Allocating enough space for the sum\n");
        {
            int ret = fallocate(fd, 0, 0, PAGE_SIZE * length);/* 预先分配length*4096大小的文件 */
            CHECK_ERROR(fd, 1, 0, "fallocate");
        }
        printf("Setting the io Context\n");
        {
            int ret = io_setup(100, &ioctx); /* 初始化ioctx*/
            CHECK_ERROR(ret, 1, 0, "io_setup");
        }
    }

    virtual void Add(int amount) {
        sum += amount;
        printf("Adding %d for toal of %d \n", amount, sum);
    }

    void submitwr() {
        printf("submitting a wirte to  %d \n", counter);
        struct iocb iocb;//建立一个异步I/O需求
        struct iocb *iocbs = &iocb;
        AIOre *req = new AIOWrite(counter); /* 这里使用counter去初始化buffer buffer 4K大小 但是counter只有4 BYTES */
        /* void io_prep_pwrite(struct iocb *iocb, int fd, void *buf, size_t count, long long offset); */
        /* 初始化这个异步I/O需求 counter为偏移量 */
        io_prep_pwrite(&iocb, fd, req->buffer, PAGE_SIZE, counter * PAGE_SIZE);
        iocb.data = req; /* 用户指针实际上就是本次提交Write操作的类对象指针用于释放buffer */
        int res = io_submit(ioctx, 1, &iocbs);/* 提交这个I/O不会堵塞 */
        CHECK_ERROR(res, 1, 1, "io_submit");
    }

    void writefile() {
        reap_counter = 0;
        for (counter = 0; counter < length; counter++) /* 偏移量不断增加不断写入 */
        {
            submitwr(); /* 异步提交操作 实际在多线程下本线程提交后则可以干其他事情了不会堵塞等待而耗费CPU */
            reap(); /* 获得i/o状态 */
        }
        reapremain();
    }

    void submitrd() {
        printf("submitting a read from  %d \n", counter);
        struct iocb iocb;//建立一个异步I/O需求
        struct iocb *iocbs = &iocb;
        AIOre *req = new AIOread(this);
        /* void io_prep_pread(struct iocb *iocb, int fd, void *buf, size_t count, long long offset); */
        io_prep_pread(&iocb, fd, req->buffer, PAGE_SIZE, counter * PAGE_SIZE);
        iocb.data = req;
        int res = io_submit(ioctx, 1, &iocbs);
        CHECK_ERROR(res, 1, 0, "io_submit");
        printf("test:%p %p\n", &iocb, iocbs);
    }

    void readfile() {
        reap_counter = 0;
        for (counter = 0; counter < length; counter++) {
            submitrd();
            reap();//here paramter used
        }
        reapremain();
    }

    int doreap(int min_nr) {
        printf("Reap between %ld and %ld io_events\n", min_nr, MAX_NR);//what mean
        struct io_event *events = new io_event[MAX_NR]; /* pending I/O max support */
        struct timespec timeout;
        timeout.tv_sec = 0;
        timeout.tv_nsec = 100000000;
        int num_events;
        printf("Calling io_getevents");
        num_events = io_getevents(ioctx, min_nr, MAX_NR, events, &timeout); /* 获得异步I/O event个数 */
        CHECK_ERROR(num_events, -1, 0, "io_getevents");
        printf("Calling completion function on results");
        for (int i = 0; i < num_events; i++) /* 开始获取每一个event并且做相应处理 */
        {
            struct io_event event = events[i];
            AIOre *req = (AIOre * )(event.data); /* 多态AIOre可以是度或者写及 AIOWrite/AIOread */
            req->Complete(event.res);
            delete req; /* 到这里一次I/O就完成了,删除内存对象包含buffer */
        }
        delete events;
        printf("Reaped %ld io_getevents", num_events);
        reap_counter = num_events + reap_counter; /* 将event个数汇总 */
        return num_events; /* 返回本次获取的event个数 */
    }

    void reap() {
        if (counter >= MIN_NR) /* 如果大于了min_nr才开始reap */
        {
            doreap(MIN_NR);
        }
    }

    void reapremain() /* 做最后的reap */
    {
        while (reap_counter < length) {
            doreap(1);
        }
    }

    ~AIOAdder() {
        printf("Closing AIO context and file");
        io_destroy(ioctx);
        close(fd);
    }

    int Sum() {
        printf("Writing consecutive integers to file");
        writefile();
        printf("Rriting consecutive integers to file");
        readfile();
        return sum;
    }

};

int main() {
    AIOAdder adder(10000);
    adder.init();/* 文件预先分配大小 */
    adder.writefile();
    adder.readfile();

}