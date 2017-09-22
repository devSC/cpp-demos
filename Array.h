//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_ARRAY_H
#define CPP_DEMOS_ARRAY_H

#include <iostream>
/*
 * 在前面已经提到下标操作符是必须要以类的成员函数的形式进行重载的。其在类中的声明格式如下：
        返回类型 & operator[] (参数)
    或
        const 返回类型 & operator[] (参数)

    第一种不仅可以访问对象, 还可以修改对象, 第二种为只读.

 * */
class Array {
public:
    Array() { lenght = 0, num = NULL; };
    Array(int n);

    //重载下表操作符.
    int &operator [] (int);
    const int &operator [] (int) const;
    int getlength() const { return lenght; };

private:
    int length;
    int *num;
};


#endif //CPP_DEMOS_ARRAY_H
