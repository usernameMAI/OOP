//
// Created by Dmitriy on 10/11/2021.
//

#ifndef LAB1_TVECTORITEM_H
#define LAB1_TVECTORITEM_H

#include <iostream>
#include <memory>
#include "pentagon.h"


class TVectorItem {
public:
    TVectorItem(const std::shared_ptr<Pentagon>& other);

    TVectorItem(const std::shared_ptr<TVectorItem>& other);

    std::shared_ptr<Pentagon>& GetPentagon();

    TVectorItem(){}

    friend std::ostream &operator<<(std::ostream &os, TVectorItem &p);


private:
    std::shared_ptr<Pentagon> p;
};

#endif //LAB1_TVECTORITEM_H
