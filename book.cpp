//
// Created by Wilson-Yuan on 2017/9/21.
//
#include <iostream>
#include "book.h"

using namespace std;


//析构函数: http://www.weixueyuan.net/view/6345.html
book::~book() {
    //清空数据 dealloc
}

/*
book::book(char *a, double p) {
    title = a;
    price = p;
}
 */

//参数初始化表 http://www.weixueyuan.net/view/6340.html
//参数初始化表还有一个很重要的作用，那就是为const成员变量初始化。
book::book(char *a, double p) :title(a), price(p), page(0) {}

book::book(book &b, double price):page(0) {
    price = b.price;

    //在每一个成员函数中都包含一个常量指针，我们称其为this指针，该指针指向调用本函数的对象，其值为该对象的首地址。通过该指针，我们可以在成员函数的函数体内访问对象。其中this是C++的一个关键字。
    this->title = b.title;
//    title = b.title;
}

void book::copy(book &b) {

    //this指针是常量指针，它的值是不能被修改的，一切企图修改该指针的操作如赋值、递增、递减等都是不允许的。此外this指针只非static成员函数中才是有效的，这一点在我们介绍完static成员函数后大家就会明白为何会如此了，在此处暂时只要知道这一点就可以了。

    //this指针先判断被拷贝的对象的引用是否是调用该函数的对象自身，如果是的话则推出函数。
    if (this == &b) {
        cout << "same object!" << endl;
        return;
    }
    else {
        title = b.title;
        this->price = b.price;
    }
}

book book::setprice(double a) {
    price = a;
}

double book::getprice() {
    return price;
}

void book::settitle(char *a) {
    title = a;
}

char * book::gettitle() {
    return title;
}

void book::display() {
    cout<<"The price of "<<title<<" is $"<< price <<endl;
}


void display(book &b) {
    cout<<"The price of "<<b.title<<" is $"<<b.price<<endl;
}
//
int book::count = 0;