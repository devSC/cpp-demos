//
// Created by Wilson-Yuan on 2017/9/21.
//

#include "Box.h"
#include <iostream>

using namespace std;

int main() {


}

void test() {
    //声明 Box1, 类型为Box
    Box Box1;
    Box Box2;

    //用于储存体积
    double volume = 0.0;

    Box1.height = 5.0;
    Box1.length = 6.0;
    Box1.breadth = 7.0;

    Box2.height = 15.0;
    Box2.length = 16.0;
    Box2.breadth = 17.0;

    //box1的体积
    volume = Box1.height * Box1.length * Box1.breadth;
    cout << "Box1 的体积:" << volume <<endl;

    volume = Box2.height * Box2.length * Box2.breadth;
    cout << "Box2 的体积:" << volume <<endl;
}
