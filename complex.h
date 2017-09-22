//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_COMPLEX_H
#define CPP_DEMOS_COMPLEX_H

#include <iostream>

class complex {
public:
    complex();
    complex(double a);
    complex(double a, double b);

    //两个复数相加，函数返回值为complex类对象，仍然为一个复数。
    //复数相加需要两个复数进行运行，调用函数的类对象本身就是一个复数，因此还需要另外一个复数作为参数，在该函数声明中函数的参数为复数类对象的引用，并且加上了const关键字以确保在函数中不会修改该对象的引用
    complex operator + (const complex &A) const; //后面const标示此函数只允许读取属性
    complex operator - (const complex &A) const;
    complex operator * (const complex &A) const;
    complex operator / (const complex &A) const;

    //重载的操作符是一元操作符，并将其作为类的成员函数，则不需要参数。
    //bool operator ! ();

    //重载输入与输出操作符 http://www.weixueyuan.net/view/6382.html
    friend std::istream & operator >> (std::istream &in, complex &a);

    void display() const;

private:
    double real;   //复数的实部
    double imag;   //复数的虚部
};


#endif //CPP_DEMOS_COMPLEX_H
