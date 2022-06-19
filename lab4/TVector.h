//
// Created by Dmitriy on 10/11/2021.
//

#ifndef LAB1_TVECTOR_H
#define LAB1_TVECTOR_H

#include <iostream>
#include "TVectorItem.h"
#include "pentagon.h"

template<class T>
class TVector {
public:

    TVector();

    TVector(const std::shared_ptr<TVector>& other);

    ~TVector();

    void InsertLast(const std::shared_ptr<T>& pentagon);

    void RemoveLast();

    T& Last();

    T& operator[] (const size_t idx);

    bool Empty();

    size_t Length();

    template<class A> friend std::ostream& operator<<(std::ostream& os, const TVector<A>& arr);

    void Clear();


private:
    size_t size;
    size_t capacity;
    std::shared_ptr<TVectorItem<T>[]> data;
};

#endif //LAB1_TVECTOR_H
