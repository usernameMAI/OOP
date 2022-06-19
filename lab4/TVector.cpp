//
// Created by Dmitriy on 10/11/2021.
//

#include "TVector.h"
#include <cassert>

template<class T>
TVector<T>::TVector():size(0), data(nullptr), capacity(0) {
}

template<class T>
TVector<T>::TVector(const std::shared_ptr<TVector<T>>& other){
    size = other->size;
    capacity = other->capacity;
    TVectorItem<T>* data_new = new TVectorItem<T>[capacity];
    for(int i = 0; i < size; ++i)
        data_new[i] = other->data[i];
    data.reset(data_new);
}

template<class T>
TVector<T>::~TVector() {
}

template<class T>
void TVector<T>::InsertLast(const std::shared_ptr<T>& pentagon){
    if(capacity != 0 && capacity > size){
        data[size++] = pentagon;
    }
    else{
        if(capacity == 0)
            capacity = 1;
        capacity *= 2;
        TVectorItem<T>* data_new = new TVectorItem<T>[capacity];
        for(int i = 0; i < size; ++i){
            data_new[i] = data[i];
        }
        data_new[size++] = pentagon;

        data.reset(data_new);
    }
}

template<class T>
void TVector<T>::RemoveLast(){
    if(size > 0)
        --size;
}

template<class T>
T& TVector<T>::Last(){
    assert(size > 0);
    return *data[size - 1].GetPentagon();
}

template<class T>
size_t TVector<T>::Length() {
    return size;
}

template<class T>
T& TVector<T>::operator[] (const size_t idx){
    assert(idx >= 0 && idx < size);
    return *data[idx].GetPentagon();
}

template<class T>
bool TVector<T>::Empty(){
    return size == 0;
}

template<class T>
void TVector<T>::Clear() {
    data = nullptr;
    capacity = size = 0;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const TVector<T>& arr){
    for(int i = 0; i < arr.size; ++i){
        os << *arr.data[i].GetPentagon();
    }
    return os;
}

template class TVector<Pentagon>;
template std::ostream& operator<<(std::ostream& os, const TVector<Pentagon>& arr);
