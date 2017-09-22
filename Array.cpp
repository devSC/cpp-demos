//
// Created by Wilson-Yuan on 2017/9/22.
//

#include "Array.h"
#include <string>

using namespace std;

Array::Array(int n) {
    try {
        num = new int[n];
    }
    catch(bad_alloc) {
        cerr<<"allocate storage failure!" <<endl;
        throw;
    }

    length = n;
}

//这样处理, 可以通过下标直接赋值 a[10] = "ss";
int & Array::operator[](int i) {
    //处理数组越界
    if (i < 0 || i > length) {
        throw string("out of bounds");
    }
    return num[i];
}

const int& Array::operator[](int i) const {
    if (i < 0 || i > length) {
        throw string("out of bounds");
    }
    return num[i];
}
