//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_PUREVIRTUALCLASS_H
#define CPP_DEMOS_PUREVIRTUALCLASS_H

#include <iostream>

/*
  公共接口是指一系列成员函数的集合，支持该接口的类必须以合适的方式重新定义这些成员函数，否则就无法创建对象。在C++中，可以通过抽象基类来实现公共接口。为了介绍抽象基类，我们需要先来了解一下纯虚成员函数。

  纯虚成员函数的声明语法如下：
    virtual 函数返回类型 函数名 (函数参数) = 0;

  纯虚成员函数没有函数体，只有函数声明，在纯虚函数声明结尾加上“=0”表明此函数为纯虚成员函数。

  包含纯虚成员函数的类即为抽象基类，之所以说它抽象，那是因为它无法实例化，也即无法用于创建对象。
 *
 */
class pure {
public:
    virtual void display() = 0;
};

class purevirtualclass: public pure {
public:
    //纯虚成员函数可以被派生类继承，如果派生类不重新定义抽象基类中的所有（有多个则要重新定义多个）纯虚成员函数，则派生类同样会成为抽象基类，因而也不能用于创建对象。
    void display() {
        std::cout<<"pure virtual class" << std::endl;
    }
    //抽象基类可以用于实现公共接口，在抽象基类中声明的纯虚成员函数，派生类如果想要能够创建对象，则必须全部重新定义这些纯虚成员函数。
};


#endif //CPP_DEMOS_PUREVIRTUALCLASS_H
