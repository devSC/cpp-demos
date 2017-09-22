//
// Created by Wilson-Yuan on 2017/9/22.


#include "derived.h"

base::base() {
    cout<<"base constructor!"<<endl;
    a = new int[10];
}

base::~base() {
    cout<<"base destructor!"<<endl;
    delete[] a;
}

derived::derived() {
    cout<<"derived constructor!"<<endl;
    b = new int[1000];
}

derived::~derived() {
    cout<<"derived destructor!"<<endl;
    delete[] b;
}