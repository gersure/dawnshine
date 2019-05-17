//
// Created by emp on 2019-05-14.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>
#include <error.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <limits.h>
#include <poll.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/epoll.h>
#include <time.h>
#include <list>
#include <arpa/inet.h>

#define BUF_SIZE 1024                 //默认缓冲区
#define SERVER_PORT 8888             //监听端口
#define SERVER_HOST "127.0.0.1"   //服务器IP地址
#define EPOLL_RUN_TIMEOUT -1          //epoll的超时时间
#define EPOLL_SIZE 1000              //epoll监听的客户端的最大数目

#define STR_WELCOME "Welcome to seChat! You ID is: Client #%d"
#define STR_MESSAGE "Client #%d>> %s"
#define STR_NOONE_CONNECTED "Noone connected to server except you!"
#define CMD_EXIT "EXIT"

//两个有用的宏定义：检查和赋值并且检测
#define CHK(eval) if(eval < 0){perror("eval"); exit(-1);}
#define CHK2(res, eval) if((res = eval) < 0){perror("eval"); exit(-1);}

int setnonblocking(int sockfd);
int handle_message(int new_fd);


using namespace std;

// 存放客户端socket描述符的list
list<int> clients_list;

int setnonblocking(int sockfd)
{
    CHK(fcntl(sockfd, F_SETFL, fcntl(sockfd, F_GETFD, 0)|O_NONBLOCK));
    return 0;
}

int handle_message(int client)
{
    char buf[BUF_SIZE], message[BUF_SIZE];
    bzero(buf, BUF_SIZE);
    bzero(message, BUF_SIZE);

    int len;

    CHK2(len,recv(client, buf, BUF_SIZE, 0));  //接受客户端信息

    if(len == 0)   //客户端关闭或出错，关闭socket，并从list移除socket
    {
        CHK(close(client));
        clients_list.remove(client);
    }
    else          //向客户端发送信息
    {
        if(clients_list.size() == 1)
        {
            CHK(send(client, STR_NOONE_CONNECTED, strlen(STR_NOONE_CONNECTED), 0));
            return len;
        }

        sprintf(message, STR_MESSAGE, client, buf);
        list<int>::iterator it;
        for(it = clients_list.begin(); it != clients_list.end(); it++)
        {
            if(*it != client)
            {
                CHK(send(*it, message, BUF_SIZE, 0));
            }
        }
    }

    return len;
}

using namespace std;

char message[BUF_SIZE];     //接受服务器信息
list<int> list_of_clients;  //存放所有客户端
int res;
clock_t tStart;

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in addr;
    addr.sin_family = PF_INET;
    addr.sin_port = htons(SERVER_PORT);
    addr.sin_addr.s_addr = inet_addr(SERVER_HOST);

    tStart = clock();

    for(int i=0 ; i<EPOLL_SIZE; i++)  //生成EPOLL_SIZE个客户端，这里是10000个，模拟高并发
    {
        CHK2(sock,socket(PF_INET, SOCK_STREAM, 0));
        CHK(connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0);
        list_of_clients.push_back(sock);

        bzero(&message, BUF_SIZE);
        CHK2(res,recv(sock, message, BUF_SIZE, 0));
        printf("%s\n", message);
    }

    list<int>::iterator it;          //移除所有客户端
    for(it = list_of_clients.begin(); it != list_of_clients.end() ; it++)
        close(*it);

    printf("Test passed at: %.2f second(s)\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    printf("Total server connections was: %d\n", EPOLL_SIZE);

    return 0;
}