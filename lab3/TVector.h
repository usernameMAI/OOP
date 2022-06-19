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

    TVector(const std::shared_ptr<TVector>& other);

    ~TVector();

    void InsertLast(const std::shared_ptr<Pentagon>& pentagon);

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
    std::shared_ptr<TVectorItem[]> data;
};

#endif //LAB1_TVECTOR_H
