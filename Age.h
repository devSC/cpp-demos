//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_AGE_H
#define CPP_DEMOS_AGE_H


//转型构造函数 http://www.weixueyuan.net/view/6343.html

//用于类型间的转换，将其它数据类型转变为类的对象类型。转型构造函数只有一个参数，如果该参数是int型，则我们是将int型对象转换为类对象，如果该参数类型为char *类型，我们则是将字符串常量转换为类对象。
class Age {
public:

    //调用构造函数时,会存在隐式转换, 可以使用explicit来关闭
    explicit Age(int a);

private:
    int age;
};


#endif //CPP_DEMOS_AGE_H
