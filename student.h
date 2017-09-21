//
// Created by Wilson-Yuan on 2017/9/21.
//

#ifndef CPP_DEMOS_STUDENT_H
#define CPP_DEMOS_STUDENT_H

//C++中，struct与class基本是通用的，唯一不同的是如果使用class关键字，类中定义的成员变量或成员函数默认都是private属性的，而采用struct关键字，结构体中定义的成员变量或成员函数默认都是public属性的。

//http://www.weixueyuan.net/view/6337.html

class student {
    char name[20];
    int id_num;
    int age;
    char sex;


    //类内声明函数，如果在函数声明时使用inline关键字，如例4所示，则可以将类内声明类外定义的函数强制转换为内联函数。
    inline void set_id_num(int a);
    inline int get_id_num();

public:
    //set_age函数和get_age函数在类声明内部仅有声明部分，而无定义部分，其函数体在类声明之外定义。本例中定义函数采用了域解析符 ::。
    void set_age(int a);
    int get_age() const;
};


#endif //CPP_DEMOS_STUDENT_H
