//
// Created by Dmitriy on 10/11/2021.
//

#include "TVector.h"
#include <cassert>

TVector::TVector():size(0), data(nullptr), capacity(0) {
}

TVector::TVector(const std::shared_ptr<TVector>& other){
    size = other->size;
    capacity = other->capacity;
    TVectorItem* data_new = new TVectorItem[capacity];
    for(int i = 0; i < size; ++i)
        data_new[i] = other->data[i];
    data.reset(data_new);
}

TVector::~TVector() {
}

void TVector::InsertLast(const std::shared_ptr<Pentagon>& pentagon){
    if(capacity != 0 && capacity > size){
        data[size++] = pentagon;
    }
    else{
        if(capacity == 0)
            capacity = 1;
        capacity *= 2;
        TVectorItem* data_new = new TVectorItem[capacity];
        for(int i = 0; i < size; ++i){
            data_new[i] = data[i];
        }
        data_new[size++] = pentagon;

        data.reset(data_new);
    }
}

void TVector::RemoveLast(){
    if(size > 0)
        --size;
}

Pentagon& TVector::Last(){
    assert(size > 0);
    return *data[size - 1].GetPentagon();
}

size_t TVector::Length() {
    return size;
}

Pentagon& TVector::operator[] (const size_t idx){
    assert(idx >= 0 && idx < size);
    return *data[idx].GetPentagon();
}

bool TVector::Empty(){
    return size == 0;
}

void TVector::Clear() {
    data = nullptr;
    capacity = size = 0;
}

std::ostream& operator<<(std::ostream& os, const TVector& arr){
    for(int i = 0; i < arr.size; ++i){
        os << *arr.data[i].GetPentagon();
    }
    return os;
}
