//
// Created by Wilson-Yuan on 2017/9/22.
//

#ifndef CPP_DEMOS_MYPAIR_H
#define CPP_DEMOS_MYPAIR_H

template <class T>
class mypair {
    T values[2];
public:
    mypair(T first, T second) {
        values[0] = first;
        values[1] = second;
    }
};


#endif //CPP_DEMOS_MYPAIR_H
