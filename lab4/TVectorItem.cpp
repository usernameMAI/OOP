//
// Created by Dmitriy on 10/11/2021.
//

#include <iostream>
#include "TVectorItem.h"

template<class T>
TVectorItem<T>::TVectorItem(const std::shared_ptr<T>& other){
    p = other;
}

template<class T>
TVectorItem<T>::TVectorItem(const std::shared_ptr<TVectorItem<T>>& other){
    p = other->p;
}

template<class T>
std::shared_ptr<T>& TVectorItem<T>::GetPentagon(){
    return p;
}

template<class A>
std::ostream &operator<<(std::ostream &os, TVectorItem<A> &p){
    os << *p.GetPentagon();
    return os;
}

template class TVectorItem<Pentagon>;
template std::ostream& operator<<(std::ostream& os, TVectorItem<Pentagon>& p);
