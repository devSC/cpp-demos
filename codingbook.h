//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_CODINGBOOK_H
#define CPP_DEMOS_CODINGBOOK_H

#include "book.h"

enum language { none, cpp, java, python, javascript, php, ruby };

//继承

//public指明继承方式属于公有继承，book为被继承的类名

/*
 基类派生出派生类，派生类继承基类的继承方式有三种：public、protected和private。在未指定的情况下编译器会默认继承方式为protected或private方式。
 1) public继承方式

 基类中所有public成员在派生类中为public属性；
 基类中所有protected成员在派生类中为protected属性；
 基类中所有private成员在派生类中不可访问。
 2) protected继承方式

 基类中的所有public成员在派生类中为protected属性；
 基类中的所有protected成员在派生类中为protected属性；
 基类中的所有private成员在派生类中仍然不可访问。

 3) private继承方式

 基类中的所有public成员在派生类中均为private属性；
 基类中的所有protected成员在派生类中均为private属性；
 基类中的所有private成员在派生类中均不可访问。
 * */

class codingbook: public book {
public:
    codingbook():book(){lang = none;};
    codingbook(language lang, char *t, double p);

    void setlang(language lang);
    language getlang(language lang);

    //如果需要覆盖父类方法,则需要重新声明.
    void display();

private:
    language lang;

    //using声明可以改变基类成员在派生类中的访问属性。我们知道基类的公有成员经过公有继承，在派生类中其属性为public的，但是通过using 声明，我们可以将其改为private或protected属性。
    using book::setprice;
};


#endif //CPP_DEMOS_CODINGBOOK_H
