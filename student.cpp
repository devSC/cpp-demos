//
// Created by Wilson-Yuan on 2017/9/21.
//

#include "student.h"

void student::set_age(int a) {
    age = a;
}

int student::get_age() const {
    return age;
}

//student类中声明函数set_age和get_age时都使用了inline关键字，这就使得这两个函数也成为了内联函数，尽管它们是在类外进行定义函数体的。
void student::set_id_num(int a) {
    id_num = id_num;
}

int student::get_id_num() {
    return id_num;
}