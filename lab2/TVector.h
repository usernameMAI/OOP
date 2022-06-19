//
// Created by Dmitriy on 10/11/2021.
//

#ifndef LAB1_TVECTOR_H
#define LAB1_TVECTOR_H

#include <iostream>
#include "TVectorItem.h"
#include "pentagon.h"

class TVector {
public:

    TVector();

    TVector(const TVector& other);

    ~TVector();

    void InsertLast(const Pentagon& pentagon);

    void RemoveLast();

    Pentagon& Last();

    Pentagon& operator[] (const size_t idx);

    bool Empty();

    size_t Length();

    friend std::ostream& operator<<(std::ostream& os, const TVector& arr);

    void Clear();


private:
    size_t size;
    size_t capacity;
    TVectorItem *data;
};

#endif //LAB1_TVECTOR_H
