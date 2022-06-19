//
// Created by Dmitriy on 10/11/2021.
//

#include <iostream>
#include "TVectorItem.h"

TVectorItem::TVectorItem(const Pentagon& pentagon){
    p = pentagon;
}

TVectorItem::TVectorItem(const TVectorItem& other){
    p = other.p;
}

Pentagon& TVectorItem::GetPentagon(){
    return p;
}

std::ostream &operator<<(std::ostream &os, TVectorItem &p){
    os << p;
    return os;
}
