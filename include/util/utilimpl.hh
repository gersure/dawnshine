//
// Created by zhengcf on 2019-05-17.
//

#pragma once

#include <memory>
#include <type_traits>

#if defined(__cplusplus) && (__cplusplus <= 201103L)

namespace std {

    template<typename T, typename... Args>
    unique_ptr<T> make_unique(Args &&... args) {
        return unique_ptr<T>(new T(forward<Args>(args)...));
    }

    template<bool B, class T = void>
    using enable_if_t = typename enable_if<B, T>::type;

}

#endif