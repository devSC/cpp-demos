//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_VIRTUALCLASS_H
#define CPP_DEMOS_VIRTUALCLASS_H

class A {
public:
    void setx(int a){x = a;}
    int getx(){return x;}
private:
    int x;
};

//虚基类 解决菱形继承问题.
class B: virtual public A {
public:
    void sety(int a){y = a;}
    int gety(){return y;}
private:
    int y;
};

class C: virtual public A {
public:
    void setz(int a){z = a;}
    int getz(){return z;}
private:
    int z;
};

//类B和类C都是继承类A都是虚继承，如此操作之后，类D只会得到一份来自类A的数据。在本例的主函数中，定义了类D的对象test，然后通过该对象调用从类A间接继承来的setx和getx成员函数，因为B和C继承自类A采用的是虚继承，故通过D调用setx和getx不会有命名冲突问题，因为D类只得到了一份A的数据。
class virtualclass: public B, public C {

};


#endif //CPP_DEMOS_VIRTUALCLASS_H
