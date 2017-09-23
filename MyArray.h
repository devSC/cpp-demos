//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_MYARRAY_H
#define CPP_DEMOS_MYARRAY_H

#include <iostream>
using namespace std;

/*
 * 在前面已经提到下标操作符是必须要以类的成员函数的形式进行重载的。其在类中的声明格式如下：
        返回类型 & operator[] (参数)
    或
        const 返回类型 & operator[] (参数)

    第一种不仅可以访问对象, 还可以修改对象, 第二种为只读.

 * */

/*
 * 模版类  泛型编程
 *
 * 模版类的定义和实现必须在一个文件下.
 * */

template < class T >
class MyArray {
public:
//    MyArray() {
//        cout << "Array constructor" << endl;
//        length = 0, num = NULL;
//    };
    MyArray(int n);

    //重载下表操作符.
    T & operator [] (int);
    const T & operator [] (int) const;
    int getlength() const { return length; };

    ~MyArray();

private:
    int length;
    T* num;
};


template < class T >
ostream & operator << (ostream &out, const MyArray<T> &a);


template < class T >
MyArray<T>::~MyArray() {
    delete[] num;
}


template < class T >
MyArray<T>::MyArray(int n) {
    cout<<"my array n constructor" <<endl;
    try {
        num = new T[n];
    }
    catch(bad_alloc) {
        cout<<"allocate storage failure!" <<endl;
        throw;
    }

    length = n;
}

//这样处理, 可以通过下标直接赋值 a[10] = "ss";
template < class T >
T & MyArray<T>::operator[](int i) {
    //处理数组越界
    if (i < 0 || i > length) {
        throw string("out of bounds");
    }
    return num[i];
}

template < class T >
const T & MyArray<T>::operator[](int i) const {
    if (i < 0 || i > length) {
        throw string("out of bounds");
    }
    return num[i];
}

//

//重载输入操作符
template < class T >
ostream & operator << (ostream &out, const MyArray<T> &a) {
    cout<<  "reload << operator" <<"\n";
    for (int i = 0; i < a.getlength(); i++) {
        out << a[i] << " ";
    }
    return out;
}


//模板类至少有一个类参数，但是可以有多个类参数，每一个类参数前都必须有关键字class或者类型名。

template < class T, class S, class R >
class test {
public:
    S testfunc(R r) { S s; return s; };

private:
    T x;
};

#endif //CPP_DEMOS_MYARRAY_H
