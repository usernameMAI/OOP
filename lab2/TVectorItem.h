//
// Created by Dmitriy on 10/11/2021.
//

#ifndef LAB1_TVECTORITEM_H
#define LAB1_TVECTORITEM_H

#include <iostream>
#include "pentagon.h"

class TVectorItem {
public:
    TVectorItem(const Pentagon& pentagon);

    TVectorItem(const TVectorItem& other);

    Pentagon& GetPentagon();

    TVectorItem(){}

    friend std::ostream &operator<<(std::ostream &os, TVectorItem &p);


private:
    Pentagon p;
};

#endif //LAB1_TVECTORITEM_H
