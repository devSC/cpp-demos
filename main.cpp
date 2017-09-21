#include <iostream>
#include "Box.h"

//声明使用std命名控件，下面凡是用到标准库的方法属性都不需要使用std::去使用
//std 是所有标准库的命名空间的名字，
using namespace std;

//重命名
typedef double Volume;
using Spark = double;

//声明函数必须放在使用之前
void testPrintf();
void testInput();
int add(int x, int y);

int main() {

//    testPrintf();
//    testInput();

//    Box box;
///    box.test();


    const auto sum = add(2,4);
    cout << "sum: " << sum << endl;
    return 0;
}


void testPrintf() {
    // << 流插入运算符， 将后面的数据插入到输出流中去  endl 行结束， 如果没有则不会换行。
    cout << "Hello World" << endl;
    cout << "Welcome to c++!" << endl;
    cout << "The size of int is: \t\t" << sizeof(int) << "bytes. \n";
}

void testInput() {
    //声明常量
    const double pi(3.1415926);
    //定义变量
    int radius;
    cout << "Please enter the radius!\n";
    //从标准输入设备读入一个整数存入radius中
    cin >> radius;
    //输出变量radius值
    cout << "The radius is:" << radius << '\n';
    cout << "PI is: " << 3.14 << '\n';
    cout << "Please enter a different radius! \n";
    cin >> radius;
    cout << "Now the radius is changed to:" << radius << '\n';
}

int add(int x, int y) {
    return x + y;
}

void testArray() {
    //定义包含 8 个整数元素的数组
    int a[8];
    //数组只能逐一赋值
    //数组：将相同的数据元素组织成整体，构成单一纬度上的数据序列。

    //数组的地址
    //a == &a == &a[0]
}