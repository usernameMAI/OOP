//
// Created by Dmitriy on 10/11/2021.
//

#include <iostream>
#include "TVectorItem.h"

TVectorItem::TVectorItem(const std::shared_ptr<Pentagon>& other){
    p = other;
}

TVectorItem::TVectorItem(const std::shared_ptr<TVectorItem>& other){
    p = other->p;
}

std::shared_ptr<Pentagon>& TVectorItem::GetPentagon(){
    return p;
}

std::ostream &operator<<(std::ostream &os, TVectorItem &p){
    os << *p.GetPentagon();
    return os;
}
