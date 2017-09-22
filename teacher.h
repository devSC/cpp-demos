//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_TEACHER_H
#define CPP_DEMOS_TEACHER_H


class teacher {
public:
    void settitle(char *a) { title = a; }
    char * gettitle() { return title; }

private:
    char * title;
};

class cadre {
public:
    void setpost(char *a){post = a;}
    char * getpost(){return post;}
private:
    char *post; //职务
};

//这里允许多继承, 其他属性和单继承相同.
class teacher_cadre: public cadre, public teacher
{
public:
    void setwages(int a){wages = a;}
    int getwages(){return wages;}
private:
    int wages; //工资
};


#endif //CPP_DEMOS_TEACHER_H
