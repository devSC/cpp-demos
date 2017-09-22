//
// Created by Wilson-Yuan on 2017/9/22.
//

#include <mach/mach_types.h>
#include "codingbook.h"
#include <iostream>

codingbook::codingbook(language lang, char *t, double p):book(t,p) {
    this->lang = lang;
}

void codingbook::setlang(language lang) {
    lang = lang;
}

language codingbook::getlang(language lang) {
    return lang;
}

void codingbook::display() {
    book::display();
    std::cout << "The language is " << lang << std::endl;
}

