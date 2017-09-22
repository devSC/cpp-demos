//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_DERIVED_H
#define CPP_DEMOS_DERIVED_H

#include <iostream>

/*
 * 形成多态必须具备以下三个条件：
 * 必须存在继承关系；
 * 继承关系中必须有同名的虚函数；
 * 存在基类类型的指针或引用，通过该指针或引用调用虚函数。
 */
using namespace std;
class base {
public:
    base();

    virtual void display(){cout<<"I'm base class!"<<endl;}
    //虚析构函数, http://www.weixueyuan.net/view/6373.html
    //如果存在多态的情况,则必须将析构函数申明为虚析构函数.
    //将基类的析构函数声明为虚函数之后，派生类的析构函数也自动成为虚析构函数，在主函数中基类指针p指向的是派生类对象，当delete释放p指针所指向的存储空间时，会执行派生类的析构函数，派生类的析构函数执行完之后会紧接着执行基类的析构函数，以释放从基类继承过来的成员变量所消耗的资源。如此一来就不会存在内存泄漏问题了。
    virtual ~base();


    /* http://www.weixueyuan.net/view/6375.html
     * 1) 重载
     * 函数重载是指两个函数具有相同的函数名，但是函数参数个数或参数类型不同。函数重载多发生在顶层函数之间或者同一个类中，函数重载不需要构成继承关系。
     */
    int fun(int a);
    int fun(double a);
    int fun(int a, int b);

private:
    int * a;
};

class derived: public base {
public:
    derived();

    //通常情况下, 可以把派生类中的virtual省略掉 http://www.weixueyuan.net/view/6371.html
    //常情况下，如果一个类需要作为基类，并且期望在派生类中修改某成员函数的功能，并且在使用类对象的时候会采用指针或引用的形式访问该函数，则将该函数声明为虚函数。
    void display() {cout<<"I'm derived class!"<<endl;}
    ~derived();

private:
    int *b;
};


//在类外部顶层函数也同样能够成函数重载关系，如本例中的g函数，这三个函数都是顶层函数，由于函数名相同，但是函数参数不同，构成函数重载关系。
//函数重载是编译期绑定，它并不是多态。
int g(int a);
int g(double a);
int g(int a, int b);

#endif //CPP_DEMOS_DERIVED_H
