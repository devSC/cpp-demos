//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_STORE_H
#define CPP_DEMOS_STORE_H

#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
class Store {
private:
    T item;
    bool haveValue;
public:

    Store(): haveValue(false) {};

    T getElem() {
        if (!haveValue) {
            cout << "No item present!" << endl;
            exit(1);//使程序完全退出，返回到操作系统。
        }
        return item;
    }

    void putElem(const T &x) {
        haveValue = true;
        item = x;
    }

};

//template <class T>
//Store<T>::Store(): haveValue(false) {}

//template <class T>
//T Store<T>::getElem() {
//    if (!haveValue) {
//        cout << "No item present!" << endl;
//        exit(1);//使程序完全退出，返回到操作系统。
//    }
//    return item;
//}

//template <class T>
//void Store<T>::putElem(const T &x) {
//    haveValue = true;
//    item = x;
//}


#endif //CPP_DEMOS_STORE_H
