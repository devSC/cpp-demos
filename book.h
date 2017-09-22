//
// Created by Wilson-Yuan on 2017/9/21.
//

#ifndef CPP_DEMOS_BOOK_H
#define CPP_DEMOS_BOOK_H


class book {
public:
    /*
        构造函数是类中一种特殊的成员函数，其特殊之处有三点：
        构造函数的函数名必须与类名相同；
        构造函数无返回值；
        当我们创建类对象的时候构造函数会被自动调用，而无需我们主动调用。

        一个类中可以有多个构造函数，构造函数之间构成函数重载的关系。


        构造函数与普通成员函数类似，可以在类内部定义，也可以在类外部定义。第一个没有参数的构造函数book()，其定义就在类内部；第二个构造函数book(char * a, double p)在类内部声明，类外部定义。

        这里:如果不声明默认构造函数book()，而只声明带参构造函数book(char *a, double p)的时候，语句book Alice;是无法创建对象的
     * */

    book() :page(0) {} //如果不添加此方法,则初始化只能通过下面方法进行,相当于Oc中的designer initial method
    book(char* a, double p = 5.0); //可以带默认参数

    //拷贝构造函数 http://www.weixueyuan.net/view/6344.html
    //拷贝构造函数除了能有对象引用这样的参数之外，同样也能有其它参数。但是其它参数必须给出默认值。例如下面这种拷贝构造函数声明方式。
    book(book &b, double price = 5.0);
    //或者:
    //book(const book &b);

    void copy(book &b);

    book setprice(double a);

    /*
     * http://www.weixueyuan.net/view/6348.html
     const成员函数
     const成员函数可以使用类中的所有成员变量，但是不能修改变量的值，这种措施主要还是为了保护数据而设置的。
     */
    double getprice() const;

    void settitle(char *a);
    char* gettitle();

    /* 友元函数和友元类
     * http://www.weixueyuan.net/view/6350.html
     * 通过friend关键字，我们可以将不属于当前类的一个函数在当前类中加以声明，该函数便可以成为当前类的友元函数。
     */
    friend void display();

    //析构函数。析构函数就是用于回收创建对象时所消耗的各种资源。与构造函数类似，析构函数也是一个成员函数。
    ~book();

private:
    double price;
    char *title;

    //可以通过参数初始化表 来为const属性进行初始化
    /*
     const成员变量
     const成员变量其用法和普通的const变量用法相似，在定义时只需在前面加上const关键字即可。const成员变量的初始化只有唯一的一条途径：参数初始化表。这个在前面已经提到过，不记得的话可以再去翻看参数初始化表那一小节。
     */
    const int page;

    /*
     * 静态成员变量
     * http://www.weixueyuan.net/view/6349.html
     */
    static int count;
};


#endif //CPP_DEMOS_BOOK_H
