//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_ARRAY_H
#define CPP_DEMOS_ARRAY_H

#include <string>
#include <iostream>

namespace HI {
    using namespace std;

/*
 * C++模板中的函数式参数
 * http://www.weixueyuan.net/view/6400.html
 *
 *
 *模板类至少有一个类参数，但是可以有多个参数，这些参数中可以存在非类类型的参数，例如系统内建的普通数据类型参数或程序自定义的数据类型参数，我们将这种非类类型的参数称之为函数式参数。
 */

    template <class T, int S> class array {
    public:
        array() {
            num = new T[S];
            length = S;
        };

        T &operator [] (int i) {
            if (i < 0 || i >= length) {
                throw string("out of bounds");
            }
            return num[i];
        }

        const T &operator [] (int i) const {
            if (i < 0 || i >= length) {
                throw string("out of bounds");
            }
            return num[i];
        }

        int getlen() const {
            return length;
        }

        ~array() {
            delete[] num;
        }


    private:
        int length;
        T* num;
    };

//重载 << 标识符
    template <class T, int S>
    ostream &operator << (ostream &out, const array<T, S> &a) {
        for (int i = 0; i < a.getlen(); ++i) {
            out<< a[i] << " ";
        }
        return out;
    }
}
#endif //CPP_DEMOS_ARRAY_H
