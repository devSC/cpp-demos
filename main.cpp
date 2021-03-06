#include <iostream>
#include "student.h"
#include "book.h"
#include "derived.h"
#include "complex.h"
#include "MyArray.h"
#include "mypair.h"
#include "Store.h"
#include "array.h"

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <fstream>
#include <pthread.h>

//声明使用std命名空间，下面凡是用到标准库的方法属性都不需要使用std::去使用
//std 是所有标准库的命名空间的名字，
using namespace std;

//重命名
typedef double Volume;
using Spark = double;



//声明函数必须放在使用之前
void testPrintf();
void testInput();
int add(int x, int y);



//命名控件
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



//动态控件分配
void testNewDelete();

//类
void testClass();

//纯虚函数 和 纯虚类(类似于Oc中的接口)
void testVirtualClassAndMethod();


//运算符重载
void testcomplex();


//模板模式 匿名函数
void testTemplateClass();

//基本序列式容器
void testSequence();

//基本关联式容器
void testRelationSet();

//STL 算法
void testAlgorithm();


//二进制文件读写
void testFileOutput();


//指针
void testPointer();


//多线程
void testpthread();

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

//    testClass();

//    testVirtualClassAndMethod();

//    testcomplex();

//    testTemplateClass();

//    testSequence();

//    testRelationSet();

//    testAlgorithm();

//    testFileOutput();

//    testPointer();

    testpthread();

    return 0;
}


enum indexError { underflow, overflow };

int array_index( int *A, int n, int index );

void testLog();

void testios_baseMethod();

void testPrintf() {
    // << 流插入运算符， 将后面的数据插入到输出流中去  endl 行结束， 如果没有则不会换行。
    cout << "Hello World" << endl;
    cout << "Welcome to c++!" << endl;
    cout << "The size of int is: \t\t" << sizeof(int) << "bytes. \n";

    /*
     * 标准输出流对象cout、cerr和clog中
     * cerr和clog对象都是标准错误流，不同的是cerr是直接将错误信息输出到显示器，
     * 而clog则不同，clog是将错误信息先写入到缓冲区，待清扫缓冲区时，
     * 再将错误内容输出到显示器中。与cerr和clog对象不同，cout对象则非错误流，
     * 而只是普通的输出流，该对象在进行输出时，也会经过先缓冲区，然后再输出到显示器。
     * */
//    testLog();
    testios_baseMethod();

}

void testLog() {
    int *A = new int [ 10 ];
    for ( int i = 0; i < 10; i ++ )
        A[i] = i;
    try
    {
        cout << array_index( A,10,5 ) << endl;
    }
    catch( indexError e )
    {
        if( e == underflow )
        {
            cerr << "index underflow!" << endl;
        }
        if( e == overflow )
        {
            cerr << "index overflow!" << endl;
        }
    }
    //index underflow test!
    try
    {
        cout << array_index( A,10,-1 ) << endl;
    }
    catch( indexError e )
    {
        if( e == underflow )
        {
            cerr << "cerr - index underflow!" << endl;
        }
        if( e == overflow )
        {
            cerr << "cerr - index overflow!" << endl;
        }
    }
    // index overflow test!
    try
    {
        cout << array_index( A,10,15 ) << endl;
    }
    catch( indexError e )
    {
        if( e == underflow )
        {
            clog << "clog - index underflow!" << endl;
        }
        if( e == overflow )
        {
            clog << "clog - index overflow!" << endl;
        }
    }
}

int array_index( int *A, int n, int index ) {
    if ( index < 0 ) throw underflow;
    if ( index > n-1 ) throw overflow;
    return A[index];
}

void testios_baseMethod() {
    ios_base::fmtflags old_val = cout.flags( ios_base::left | ios_base::hex |ios_base::uppercase | ios_base::showbase );
    for( int i = 100; i < 150; i ++ )
        cout << i << endl;
    cout<<endl<<endl;
    cout.unsetf ( ios_base::left | ios_base::hex |ios_base::uppercase );
    cout.setf ( old_val );
    for( int i = 100; i < 150; i ++ )
        cout << i << endl;
    cout<<endl<<endl;
    cout.unsetf( old_val );
    cout.setf ( ios_base::hex | ios_base::uppercase );
    cout << " hex " << 170 << endl;
    cout.unsetf( ios_base::hex | ios_base::uppercase );
    cout.setf ( ios_base::oct );
    cout << " oct " << 170 << endl;
    cout.unsetf( ios_base::oct );
    cout.setf ( ios_base::dec );
    cout << " dec " << 170 << endl;
}


void testInputGet();
void testNormalInput();

void testInput() {
//    testNormalInput();
    testInputGet();
}

void testNormalInput() {
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

void testInputGet() {
    char a;
    while ( (a = cin.get()) != EOF )
    {
        cout.put(a);
    }
    cout << endl;

    //文件结束符 ctrl + d
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


//    book Alice;
//    Alice.settitle("Alice is Wonderland");
//    Alice.setprice(20.0);
//    Alice.display();
//
//    book Harry("Harry Potter", 49.9);
//    display(Harry);
}


void testArray() {
    //定义包含 8 个整数元素的数组
    int a[8];
    //数组只能逐一赋值
    //数组：将相同的数据元素组织成整体，构成单一纬度上的数据序列。

    //数组的地址
    //a == &a == &a[0]
}



/*
 * 形成多态必须具备以下三个条件：
 * 必须存在继承关系；
 * 继承关系中必须有同名的虚函数；
 * 存在基类类型的指针或引用，通过该指针或引用调用虚函数。
 *
 * */
void testVirtualClassAndMethod2();
void testVirtualClassAndMethod() {
//    base *p;
//    derived test;
//    p = &test;
//    p->display();

    testVirtualClassAndMethod2();
}

void testVirtualClassAndMethod2() {
    base *p = new base;
    p->display();
    delete p;

    p = new derived;
    p->display();
    delete p;
}


void testTypeId() {
    int a;
    double b;
    char *c;
    long d;

    if (typeid(a) == typeid(int)) {
        cout<< "true" << endl;
    }
    /*
    typeid(a) == typeid(int)	true
    typeid(a) == typeid(float)	false
    typeid(a) == typeid(int *)	false
    typeid(b) == typeid(double)	true
    typeid(b) == typeid(float)	false
    typeid(b) == typeid(long double)	false
    typeid(c) == typeid(char *)	true
    typeid(c) == typeid(char)	false
    typeid(c) == typeid(string)	false
    typeid(d) == typeid(long)	true
    typeid(d) == typeid(int)	false
     * */
}


void testcomplex() {
    complex c1(4.3, -5.8);
    complex c2(8.4, 6.7);
    complex c3;

    //复数的加法
    c3 = c1 + c2;
    //规范调用方法
    c3 = c1.operator+(c2);

    cout<<"c1 + c2 = ";
    c3.display();
    cout<<endl;

    //复数的减法
    c3 = c1 - c2;
    cout<<"c1 - c2 = ";
    c3.display();
    cout<<endl;

    //复数的乘法
    c3 = c1 * c2;
    cout<<"c1 * c2 = ";
    c3.display();
    cout<<endl;

    //复数的除法
    c3 = c1 / c2;
    cout<<"c1 / c2 = ";
    c3.display();
    cout<<endl;
}

// 函数模板


template <class T>
T getmax(T a, T b) {
    T result;
    result = ( a > b) ? a : b;
    return result;
}


void testTemplateClass() {

//    cout<< getmax<int>(1,5) << endl;
//    mypair<int> myobject(114, 46);

    MyArray<int> a(10);
    for (int i = 0; i < 10; ++i) {
        a[i] = 2 * i;
    }
    cout << a << endl;

    //模板中的函数式参数
    HI::array<int, 10> b;
    for (int i = 0; i < 10; ++i) {
        b[i] = 2 * i;
    }
    cout << b << endl;

    Store<int> s1, s2;
    s1.putElem(3);
    s2.putElem(-7);
    cout << s1.getElem() << " " << s2.getElem() << endl;
}


void testDeque();
void testVector();
void testList();

void testSequence() {
    /*
    vector	序列式容器	按照需要改变长度的数组
    list	序列式容器	双向链表
    deque	序列式容器	可以操作两端的数组
    set	关联式容器	集合
    multiset	关联式容器	允许重复的集合
    map	关联式容器	图表
    multimap	关联式容器	允许重复的图表


     关于操作效率:

     基本操作	vector	deque	list
     在容器头部插入或删除元素	线性	恒定	恒定
     在容器尾部插入或删除元素	恒定	恒定	恒定
     在容器中部插入或删除元素	线性	线性	恒定
     访问容器头部的元素	恒定	恒定	恒定
     访问容器尾部的元素	恒定	恒定	恒定
     访问容器中部的元素	恒定	恒定	线性
    */

    testVector();

    //两个程序的运行结果完全相同。是不是vector和deque相同呢？其实不是的，vector说到底是个数组，在非尾部插入元素都需要移动其它元素，deque则不同，它是一个可以操作数组头部和尾部的数组，因此在头部或尾部插入或删除数据，其处理效率都是一样的。当我们需要频繁在头部和尾部插入或删除数据，则deque优于vector。
    testDeque();

    testList();
}

void testVector() {
    vector<int> num;
    num.push_back(50);
    num.insert(num.begin(), 10);
    num.insert(num.end(), 20);
    num.push_back(60);
    num.push_back(40);
    cout << num.size() << endl;
    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
    num.erase(num.begin());
    cout << num.size() << endl;
    for(int i = 0; i < num.size(); i++)
        cout<< num[i] <<" ";
    cout << endl;
}


void testDeque() {
    deque<int> num;
    num.push_back(50);
    num.insert(num.begin(), 10);
    num.insert(num.end(), 20);
    num.push_back(60);
    num.push_back(40);
    cout << num.size() << endl;
    for(int i = 0; i < num.size(); i++)
        cout << num[i] << " ";
    cout << endl;
    num.erase(num.begin());
    cout << num.size() << endl;
    for(int i = 0; i < num.size(); i++)
        cout<< num[i] <<" ";
    cout << endl;
}

void testList() {
    list<string> str;
    str.insert( str.begin(), "A" );
    str.insert( str.begin(), "B" );
    str.insert( str.end(), "C" );
    str.insert( str.end(), "D" );
    str.insert( str.begin(), "E" );
    str.insert( str.begin(), "F" );

    //定义容器
    //定义了一个迭代器iter。通常每定义一个容器，就会有一个与容器数据类型相关的迭代器
    list< string >::iterator iter;

    //list< string >::const_iterator

    //将迭代器指向str,begin()
    for(iter = str.begin(); iter != str.end(); iter++)
        cout<< * iter << " ";

    cout << endl;
    str.reverse();
    for(iter = str.begin(); iter != str.end(); iter++)
        cout<< * iter <<" ";
    cout << endl;
}


void testSet();
void testMap();

//基本关联式容器
void testRelationSet() {
    /*
     关联式容器主要有：set、multiset、map和multimap，这四种容器可以分为两组：map和set。

     set可以理解为我们数学中的集合，它可以包含0个或多个不重复、不排序的数据，这些数据被称为键值。map也是一种集合，它同样可以包含0个或多个不排序的元素对，每一个元素对有一个键值和一个与键值相关联的值，在map中键值是不允许重复的。而multiset则是允许重复的集合，multimap则是允许有重复键值的map，因为multiset和multimap可以看做是set和map的扩展，因此我们将主要介绍set和map。
     */
    testSet();
    testMap();
}

void testSet() {

    set< int > s;
    //insert函数能保证插入元素后set容器中不会出现重复的元素。 但不保证顺序.
    s.insert(s.begin(), 9);
    s.insert(1);
    s.insert(s.end(),4);
    s.insert(5);
    s.insert(6);
    s.insert(7);
    s.insert(9);
    s.insert(0);
    set< int >::const_iterator itor;
    for(itor = s.begin (); itor != s.end(); itor++)
        cout<< *itor<<" ";
    cout<< endl;
    itor = s.find( 2 );
    if( itor == s.end() )
        cout<< "NOT Found 2!" << endl;
    else
        cout<< "Found 2 in set!" << endl;
    itor = s.find( 5 );
    if( itor == s.end() )
        cout<< "NOT Found 5!" << endl;
    else
        cout<< "Found 5 in set!" << endl;
}

void testMap() {
    map<char, int> m;
    m[ 'a' ] = 1;
    m[ 'b' ] = 2;
    m[ 'c' ] = 3;
    m[ 'd' ] = 4;
    m[ 'e' ] = 1;
    m[ 'f' ] = 2;
    m[ 'g' ] = 3;
    m[ 'h' ] = 4;
    m[ 'a' ] = 0;
    map< char, int >::iterator itor;
    for(itor = m.begin(); itor != m.end(); itor++)
        cout << itor->first << " -- " << itor->second <<endl;

}







bool compare( const int & a, const int & b)
{
    return a > b;
}
void display( int i )
{
    cout<< i << " ";
}
bool odd( int i )
{
    return i % 2 != 0;
}

void testAlgorithm() {
    vector<int> num(10);

    //生成随机数字，填充num
    generate( num.begin(), num.end(), rand );
    //将其中的奇数全部替换我0
    replace_if( num.begin(), num.end(), odd, 0 );
    //从大到小排序
    sort( num.begin(), num.end(), compare );

    for_each(num.begin(), num.end(), display);
}


void testFileOutput() {
    int A[ 3 ][ 10 ] = { { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 },
                         { 1, 2, 3, 4, 7, 7, 7, 7, 7, 7 },
                         { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 } };
    int B[ 3 ][ 10 ];
    int i, j;
    for( i = 0; i < 3; i++ )
    {
        for( j = 0 ; j < 10; j++ )
        {
            cout << A[ i ][ j ] <<" ";
        }
        cout << endl;
    }
    cout << endl;
    //*******************************************
    ofstream output( "test.txt", ios::out | ios::binary );
    if( ! output )
    {
        cerr << "Open output file error!" << endl;
        exit( -1 );
    }
    output.write ((char *) A, sizeof( A ) );
    for( i = 0; i < 3; i++ )
    {
        for( j = 0 ; j < 10; j++ )
        {
            //output.write ( ( char * ) & A [ i ][ j ], sizeof( A [ i ][ j ] ) );
        }
    }
    output.close();
    //*******************************************
    ifstream input( "test.txt", ios::in | ios::binary );
    if( ! input )
    {
        cerr << "Open input file error!" << endl;
        exit( -1 );
    }
    input.read( ( char * ) & B , sizeof( B ) );
    for( i = 0; i < 3; i++ )
    {
        for( j = 0 ; j < 10; j++ )
        {
            //input.read ( ( char * ) & B[ i ][ j ], sizeof( B[ i ][ j ] ));
        }
    }
    for( i = 0; i < 3; i++ )
    {
        for( j = 0 ; j < 10; j++ )
        {
            cout << B[ i ][ j ] <<" ";
        }
        cout << endl;
    }
    //*******************************************
    int temp;
    input.seekg( 20 * sizeof( int ), ios::beg );
    input.read( ( char * ) & temp, sizeof( int ));
    cout << temp << endl;
    input.close();
}




/*
 * 指针
 *
 * 指针是一个变量, 其值为另一个变量的地址. 即, 内存地址的直接地址.
 */
void testSimplePointer();

void testArrayWithPointer();

//从函数返回指针
void testReturnPointerFromFunction();

void testPointer() {

    // * 号用来指定一个变量是指针.

    //定义一个整形指针
    int *ip;

    //一个double 型指针
    double *dp;

    //一个浮点型指针
    float *fp;

    //一个字符型指针.
    char *cp;

//    testSimplePointer();

    testArrayWithPointer();

//    testReturnPointerFromFunction();
}


void testSimplePointer() {
    /*
    * 所有指针的值的实际数据类型, 不管是整型, 浮点型, 字符型, 还是其他的数据类型
    * 都是一样的, 都是一个代表内存地址的十六进制数.
    *
    * 不同数据类型的指针之间唯一的不同是, 指针所指向的变量或常量的数据类型不同.
    *
    *
    * 使用指针时会频繁进行以下几个操作：定义一个指针变量、把变量地址赋值给指针、访问指针变量中可用地址的值
    */

    //声明实际变量
    int var = 20;
    //声明指针变量
    int *ip;

    //在指针变量中存储变量var的地址
    ip = &var;

    cout << "Value of var variable: ";
    cout << var << endl;

    //输出变量 ip 中存储的变量var的地址
    cout << "Value of ip variable: " << ip << endl;
    //输出在指针变量中存储的地址
    cout << "Value of *ip variable: " << *ip << endl;

}


//指针 vs 数组

//指针数组
void testArrayWithPointer2();

//字符指针
void testCharPointerArray();

//指向指针的指针（多级间接寻址）
void testPointerToPointer();

//传递指针给函数
void testPointerForFunction();

void testArrayWithPointer() {
    /*
     * 指针和数组是密切相关的。事实上，指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。请看下面的程序：
     */

    const int MAX = 3;

    //这里数组的值其实就是数组的首元素的地址
    int var[MAX] = {10, 100, 200};

    //定义一个指针 "*ip"，其中 "ip" 需要赋于一个地址(可以用 & 符号获取其他变量的地址再赋值给 ip)，而 "*ip" 是一个具体的值，即读取地址后获得的值；
    int *ptr;

    //由于一个数组名对应一个指针常量，只要不改变数组的值，仍然可以用指针形式的表达式。例如，下面是一个有效的语句，把 var[2] 赋值为 500：
    *(var + 2) = 500;


    //指针中的数组地址
    ptr = var;
    for (int i = 0; i < MAX; ++i) {
        cout << "var[" << i << "]的内存地址为 " << ptr << " ";
        cout << "var[" << i << "]的值为 " << *ptr << endl;

        //移动到下一个位置
        ptr ++;
    }


//    testArrayWithPointer2();
    testCharPointerArray();
//    testPointerToPointer();
//    testPointerForFunction();
}


//指针数组
void testArrayWithPointer2() {

    cout << "[testArrayWithPointer2]" << endl;

    /*
     * 指针和数组是密切相关的。事实上，指针和数组在很多情况下是可以互换的。例如，一个指向数组开头的指针，可以通过使用指针的算术运算或数组索引来访问数组。请看下面的程序：
     */

    const int MAX = 3;

    //这里数组的值其实就是数组的首元素的地址
    int var[MAX] = {10, 100, 200};

    //让数组 存储 指向 int 或 char 或其他数据类型 的指针
    int *ptr[MAX];
    //把 ptr 声明为一个数组，由 MAX 个整数指针组成。因此，ptr 中的每个元素，都是一个指向 int 值的指针。

    *(var + 2) = 500;


    //指针中的数组地址
    for (int i = 0; i < MAX; ++i) {
        ptr[i] = &var[i];
    }

    for (int j = 0; j < MAX; ++j) {
        cout << "var[" << j << "]的值为 " << *ptr[j] << endl;
    }


}


//用一个指向字符的指针数组来存储一个字符串列表，如下：
void testCharPointerArray() {
    const int MAX = 4;


    //char *names[MAX] 是指针数组, 它的本质是存储指针的数组, 既存储 char 类型的指针的数组, 数组内的每个元素都是一个指针指向一个存储 char 类型的地址:
    //http://www.runoob.com/cplusplus/cpp-array-of-pointers.html
    const char *names[MAX] = {
            "Zara Ali",
            "Hina Ali",
            "Nuha Ali",
            "Sara Ali",
    };

    for (int i = 0; i < MAX; ++i) {
        cout << "Value of names[" << i << "] = ";
        cout << names[i] << endl;

        cout << " --- names[i]              = " << names[i] << endl;
        cout << " --- *names[i]             = " << *names[i] << endl;
        cout << endl;
        cout << " --- (*names[i] + 1)       = " << (*names[i] + 1) << endl;
        cout << " --- (char)(*names[i] + 1) = " << (char)(*names[i] + 1) << endl;
        cout << " ------------------------------------ " << endl << endl << endl << endl;

    }
}


/*
 * 指向指针的指针（多级间接寻址）
 *
 * 指向指针的指针是一种多级间接寻址的形式，或者说是一个指针链。通常，一个指针包含一个变量的地址。当我们定义一个指向指针的指针时，第一个指针包含了第二个指针的地址，第二个指针指向包含实际值的位置。
 */
void testPointerToPointer() {

    //声明了一个指向 int 类型指针的指针：
    //int **var;

    int var;
    int *ptr;
    int **pptr;

    var = 3000;

    //获取var的地址
    ptr = &var;

    //使用运算符 & 获取 ptr的地址.
    pptr = &ptr;

    //使用pptr获取值
    cout << "Value of var :" << var << endl;
    cout << "Value available at *ptr :" << *ptr << endl;
    cout << "Value available at **pptr :" << **pptr << endl;
}





//传递一个无符号的 long 型指针给函数，并在函数内改变这个值：
void getSeconds(unsigned long *par);

// 函数声明
double getAverage(int *arr, int size);

void testPointerForFunction() {

    unsigned long sec;
    getSeconds(&sec);
    // 输出实际值
    cout << "Number of seconds :" << sec << endl;


    // 带有 5 个元素的整型数组
    int balance[5] = {1000, 2, 3, 17, 50};
    double avg;
    // 传递一个指向数组的指针作为参数
    avg = getAverage( balance, 5 ) ;
    // 输出返回值
    cout << "Average value is: " << avg << endl;
}

void getSeconds(unsigned long *par) {
    // 获取当前的秒数
    *par = time( NULL );
}


double getAverage(int *arr, int size) {
    int i, sum = 0;
    double avg;

    for (i = 0; i < size; ++i) {
        sum += arr[i];
    }

    avg = double(sum) / size;
    return avg;
}



//您必须声明一个返回指针的函数，如下:
//int * function() {
//
//}

//C++ 不支持在函数外返回局部变量的地址，除非定义局部变量为 static 变量。
int * getRandom() {
    static int r[10];

    //设置种子
    srand((unsigned)time(NULL));
    for (int i = 0; i < 10; ++i) {
        r[i] = rand();
        cout << r[i] << endl;
    }
    return r;
}



void testReturnPointerFromFunction() {
// 一个指向整数的指针
    int *p;

    p = getRandom();
    for ( int i = 0; i < 10; i++ ) {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
}


/*
 * 多线程 http://www.runoob.com/cplusplus/cpp-multithreading.html
 *
 * 多线程是多任务处理的一种特殊形式，多任务处理允许让电脑同时运行两个或两个以上的程序。一般情况下，两种类型的多任务处理：基于进程和基于线程。
    基于进程的多任务处理是程序的并发执行。
    基于线程的多任务处理是同一程序的片段的并发执行。

    多线程程序包含可以同时运行的两个或多个部分。这样的程序中的每个部分称为一个线程，每个线程定义了一个单独的执行路径。
 */



void testpthread1();

void testpthread() {
    /*
    pthread_create (thread, attr, start_routine, arg)

    在这里，pthread_create 创建一个新的线程，并让它可执行。下面是关于参数的说明：
    参数      	描述
    thread	指向线程标识符指针。
    attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
    start_routine	线程运行函数起始地址，一旦线程被创建就会执行。
    arg	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。

    创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
     */
    testpthread1();
}

#define NUM_THREADS 5
//线程的运行函数
void* say_hello(void *args);

void testpthread1() {
    /*
  pthread_create (thread, attr, start_routine, arg)

  在这里，pthread_create 创建一个新的线程，并让它可执行。下面是关于参数的说明：
  参数      	描述
  thread	指向线程标识符指针。
  attr	一个不透明的属性对象，可以被用来设置线程属性。您可以指定线程属性对象，也可以使用默认值 NULL。
  start_routine	线程运行函数起始地址，一旦线程被创建就会执行。
  arg	运行函数的参数。它必须通过把引用作为指针强制转换为 void 类型进行传递。如果没有传递参数，则使用 NULL。

  创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
   */

    // 定义线程的 id 变量，多个变量使用数组
    pthread_t tids[NUM_THREADS];
    int indexes[NUM_THREADS];// 用数组来保存i的值
    int rc;
    int i;
    for (int i = 0; i < NUM_THREADS; ++i) {
        cout << "main() : 创建线程, " << i << endl;
        indexes[i] = i; //先保存i的值
        //参数依次是: 创建的线程id, 线程参数, 调用的函数, 传入的函数参数.
        // 传入的时候必须强制转换为void* 类型，即无类型指针
        int result = pthread_create(&tids[i], NULL, say_hello, (void *)&(indexes[i]));
        //创建线程成功时，函数返回 0，若返回值不为 0 则说明创建线程失败。
        if (result != 0) {
            cout << "pthread_create error: error_code=" << result << endl;
            exit(-1);
        }
    }

    //等各个线程退出后，进程才结束，否则进程强制结束了，线程可能还没反应过来；
    pthread_exit(NULL);
}

void *say_hello(void *threadid) {

    // 对传入的参数进行强制类型转换，由无类型指针变为整形数指针，然后再读取
    int tid = *((int *)threadid);
    cout << "Hello. 线程 ID, " << tid << endl;
    pthread_exit(NULL);
}


