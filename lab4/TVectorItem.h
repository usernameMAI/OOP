//
// Created by Dmitriy on 10/11/2021.
//

#ifndef LAB1_TVECTORITEM_H
#define LAB1_TVECTORITEM_H

#include <iostream>
#include <memory>
#include "pentagon.h"

template<class T>
class TVectorItem {
public:
    TVectorItem(const std::shared_ptr<T>& other);

    TVectorItem(const std::shared_ptr<TVectorItem<T>>& other);

    std::shared_ptr<T>& GetPentagon();

    TVectorItem(){}

    template<class A> friend std::ostream &operator<<(std::ostream &os, TVectorItem<A> &p);


private:
    std::shared_ptr<T> p;
};

#endif //LAB1_TVECTORITEM_H
