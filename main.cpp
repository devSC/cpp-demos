#include <iostream>
#include "student.h"
#include "book.h"

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




void testNameSpace();

/*-------BEGIN--------*/
void testReference();
int valplus(int &a);
//int & valplus(int &a);

/*-------END--------*/



//强制类型转换
void testTypeForceTransform();


//内联函数
void testInlineFunction();
//inline 关键字应该与函数体放在一起：
void swap(int &a, int &b);




void testNewDelete();


void testClass();


int main() {

//    testPrintf();

//    testInput();

    //const auto sum = add(2,4);
    //cout << "sum: " << sum << endl;

    //命名控件
//    testNameSpace();

    //引用 http://www.weixueyuan.net/view/6328.html
//    testReference();

    //http://www.weixueyuan.net/view/6329.html
    //testTypeForceTransform();

//    testInlineFunction();

//    testNewDelete();

    testClass();

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



//定义自己的命名空间
namespace JK {
    bool spark = false;
}

namespace LI {
    bool spark = true;
}

void testNameSpace() {
    //http://www.weixueyuan.net/view/6326.html
    //:: 域解析操作符 指明此时用的spark变量是谁定义出来的flag变量
    cout << "JK中Spark的值是:" << JK::spark <<endl;
    cout << "LI中Spark的值是:" << LI::spark <<endl;

    //除了直接使用域解析操作符，还可以采用using声明（using declaration），例如：
    using LI::spark;
    cout << "LI中Spark的值是:" << spark <<endl;
    //在代码的开头用using声明了Li::flag，其含义是using声明以后的程序中如果出现未指明的flag时，则使用Li::flag，但是若要使用小韩定义的flag，则仍需要Han::flag。

    //using声明不仅仅可以针对命名空间中的一个变量，也可以用于声明整个命名空间，例如：
    using namespace LI;
    cout << "LI中Spark的值是:" << spark <<endl;
    //如果命名空间Li中还定义了其他的变量，则同样具有flag变量的效果，在using声明后，若出现未具体指定命名空间的命名冲突变量，则默认采用Li命名空间中的变量。

}




void testReference() {
    /**
     * 引用(Reference)是C++语言相对于C语言的又一个扩充，类似于指针，只是在声明的时候用&取代了*。引用可以看做是被引用对象的一个别名，在声明引用时，必须同时对其进行初始化。引用的声明方法如下：
     *  类型标识符 &引用名 = 被引用对象
     */

    int a = 10;
    int &b = a;
    cout << a << " " << b << endl;
    cout << &a << " " << &b << endl;

    int num1 = 10;
    int num2;
    num2 = valplus(num1);
    cout<<num1<<" "<<num2<<endl;
}

int valplus(int &a) {
    a = a + 5;
    return a;
}

//虽然下面运行结果和上面运行结果是相同的，但下面中的valplus函数在将a变量加上5之后，其运算结果是直接拷贝给num2的，中间没有经过拷贝给临时空间，再从临时存储空间中拷贝出来的这么一个过程。这就是普通的传值返回和引用返回的区别。
//int & valplus(int &a) {
//    a = a + 5;
//    return a;
//}



//C++语言中新增了四个关键字static_cast、const_cast、reinterpret_cast和dynamic_cast。这四个关键字都是用于强制类型转换的。我们逐一来介绍这四个关键字。
void testTypeForceTransform() {
   // C语言所采用的类型转换方式：

    int a = 10;
    int b = 3;
    /*
    double result = (double)a / (double)b;
    */
    double result = static_cast<double>(a) / static_cast<double>(b);

}



//采用内联函数可以有效避免函数调用的开销，程序执行效率更高。使用内联函数的缺点就是，如果被声明为内联函数的函数体非常大，则编译器编译后程序的可执行码将会变得很大。另外，如果函数体内出现循环或者其它复杂的控制结构的时候，这个时候处理这些复杂控制结构所花费的时间远大于函数调用所花的时间，因此如果将这类函数声明为内联函数，意义不大，反而会使得编译后可执行代码边长。

//通常在程序设计过程中，我们会将一些频繁被调用的短小函数声明为内联函数。
inline void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void testInlineFunction() {
    int a = 1;
    int b = 2;
    swap(a, b);
    cout << a << b << endl;
}



//C语言中，动态分配和释放内存的函数是malloc、calloc和free，而在C++语言中，new、new[]、delete和delete[]操作符通常会被用来动态地分配内存和释放内存。
void testNewDelete() {
    /*
    “new 数据类型”即为new关键字的基本语法，可以动态的分配一个数据类型大小的空间。例如：
     */
    int *p = new int;
    /*
    为p指针分配了一个int型的空间。new操作符根据请求分配的数据类型来推断所需的空间大小。

    new[] 则是为了分配一个数组的空间。具体语法如：
     */
    int *A = new int[10];
    /*
     该语句为A指针分配了一个数组的空间，该数组有10个int数组成员，如果分配成功，则p指针指向首地址，并且数组10个成员的地址是连续的，其地址分别为A、A+1、A+2、……、A+9。

    delete操作符则专门用于释放由new分配的动态存储空间，在前面我们为p分配了一个int型的空间，我们可以按照如下的方式释放它：
     * */
    delete p;
    /*
    delete[] 则用于释放掉由new[]分配的数组空间，在前面我们为A指针分配了十个int单元，构成了一个数组，可以按照如下方式释放掉该空间：
     */
    delete[] A;
    /*
    为了避免内存泄露，通常new和delete、new[]和delete[]操作符应该成对出现，并且不要将这些操作符与C语言中动态分配内存和释放内存的几个函数一起混用。建议在编写C++程序时尽量使用new、new[]、delete和delete[]操作符进行动态内存分配和释放，而不要使用C语言中内存分配和释放的函数，这是因为new、new[]、delete和delete[]操作符可以使用C++的一些特性，如类的构造函数和析构函数，能够更好地管理C++程序的内存。
     */

}





void testClass() {
    student student1;
    student1.set_age(12);
    cout << student1.get_age() << endl;

    //通常来讲，除非是迫不得已，否则最好不要采用 *传值的方式* 传递和返回对象，这是因为采用传值的方式传递和返回对象的过程中需要经历对象间的*拷贝操作*，这样会在一定程度上降低程序运行的效率，从而使得待处理数据量增大，增加内存的使用。而采用引用或指针的方式则不会有这样的问题，而实际上，因为引用表达更加简练直观，因此也较少使用指针来传递对象或作为函数返回值。

    //对象的引用和普通的变量引用基本语法是一样的
    student &student2 = student1;


    book Alice;
    Alice.settitle("Alice is Wonderland");
    Alice.setprice(20.0);
    Alice.display();

    book Harry("Harry Potter", 49.9);
    Harry.display();
}


void testArray() {
    //定义包含 8 个整数元素的数组
    int a[8];
    //数组只能逐一赋值
    //数组：将相同的数据元素组织成整体，构成单一纬度上的数据序列。

    //数组的地址
    //a == &a == &a[0]
}