#pragma once

#include <iostream>
#include <memory>
#include <cstdlib>

#include "TIterator.h"

template <typename T>
class TVector {
public:
    TVector();

    TVector(const TVector &);

    virtual ~TVector();

    size_t Length() const {
        return length_;
    }

    bool Empty() const {
        return !length_;
    }

    const std::shared_ptr<T> &operator[](const size_t index) const {
        return data_[index];
    }

    std::shared_ptr<T> &Last() const {
        return data_[length_ - 1];
    }

    void InsertLast(const std::shared_ptr<T> &);

    void EmplaceLast(const T &&);

    void Remove(const size_t index);

    T RemoveLast() {
        return *data_[--length_];
    }

    void Clear();

    TIterator<T> begin() {
        return TIterator<T>(data_);
    }

    TIterator<T> end() {
        return TIterator<T>(data_ + length_);
    }

    template<typename TF>
    friend std::ostream &operator<<(
            std::ostream &, const TVector<TF> &);

private:
    void _Resize(const size_t new_capacity);

    std::shared_ptr<T> *data_;
    size_t length_, capacity_;
};

template <typename T>
TVector<T>::TVector()
        : data_(new std::shared_ptr<T>[32]),
          length_(0), capacity_(32) {}

template <typename T>
TVector<T>::TVector(const TVector &vector)
        : data_(new std::shared_ptr<T>[vector.capacity_]),
          length_(vector.length_), capacity_(vector.capacity_) {
    std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

template <typename T>
TVector<T>::~TVector() {
    delete[] data_;
}

template <typename T>
void TVector<T>::_Resize(const size_t new_capacity) {
    std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
    std::copy(data_, data_ + capacity_, newdata);
    delete[] data_;
    data_ = newdata;
    capacity_ = new_capacity;
}

template <typename T>
void TVector<T>::InsertLast(const std::shared_ptr<T> &item) {
    if (length_ >= capacity_)
      _Resize(capacity_ << 1);
    data_[length_++] = item;
}

template <typename T>
void TVector<T>::EmplaceLast(const T &&item) {
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
    data_[length_++] = std::make_shared<T>(item);
}

template <typename T>
void TVector<T>::Remove(const size_t index) {
    std::copy(data_ + index + 1, data_ + length_, data_ + index);
    --length_;
}

template <typename T>
void TVector<T>::Clear() {
    delete[] data_;
    data_ = new std::shared_ptr<T>[32];
    length_ = 0;
    capacity_ = 32;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TVector<T> &vector) {
    const size_t last = vector.length_ - 1;

    for (size_t i = 0; i < vector.length_; ++i)
        os << (*vector.data_[i]);
    os << std::endl;
    return os;
}