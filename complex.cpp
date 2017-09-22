//
// Created by Wilson-Yuan on 2017/9/22.
//

#include "complex.h"


complex::complex() {
    real = 0.0;
    imag = 0.0;
}
complex::complex(double a) {
    real = a;
    imag = 0.0;
}
complex::complex(double a, double b) {
    real = a;
    imag = b;
}
//打印复数
void complex::display()const {
    std::cout<<real<<" + "<<imag<<" i " << std::endl;
}

//重载加法操作符
complex complex::operator+(const complex &A) const {
    complex B;
    B.real = real + A.real;
    B.imag = imag + A.imag;
    return B;
}

//重载减法操作符
complex complex::operator-(const complex & A)const {
    complex B;
    B.real = real - A.real;
    B.imag = imag - A.imag;
    return B;
}
//重载乘法操作符
complex complex::operator*(const complex & A)const {
    complex B;
    B.real = real * A.real - imag * A.imag;
    B.imag = imag * A.real + real * A.imag;
    return B;
}

//重载除法操作符
complex complex::operator/(const complex & A)const {
    complex B;
    double square = A.real * A.real + A.imag * A.imag;
    B.real = (real * A.real + imag * A.imag)/square;
    B.imag = (imag * A.real - real * A.imag)/square;
    return B;
}

//重载输入操作符
std::istream & operator >> (std::istream &in, complex &a) {
    in >> a.real  >> a.imag;
    return in;
}
