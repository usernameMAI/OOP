#pragma once

#include <ostream>
#include <memory>
#include <cstdlib>

template <typename T>
class TStack {
public:
    TStack();

    TStack(const TStack &);

    virtual ~TStack();

    size_t Length() const {
        return length_;
    }

    bool Empty() const {
        return !length_;
    }

    std::shared_ptr<T> &Top() const {
        return data_[length_ - 1];
    }

    void Emplace(const T &&);

    void Push(const std::shared_ptr<T> &);

    inline T Pop() {
        return *data_[--length_];
    }

    void Clear();

    template<typename TF>
    friend std::ostream &operator<<(
            std::ostream &, const TStack<TF> &);

private:
    void _Resize(const size_t new_capacity);

    std::shared_ptr<T> *data_;
    size_t length_, capacity_;
};

template <typename T>
TStack<T>::TStack()
        : data_(new std::shared_ptr<T>[32]),
          length_(0), capacity_(32) {}

template <typename T>
TStack<T>::TStack(const TStack &vector)
        : data_(new std::shared_ptr<T>[vector.capacity_]),
          length_(vector.length_), capacity_(vector.capacity_) {
    std::copy(vector.data_, vector.data_ + vector.length_, data_);
}

template <typename T>
TStack<T>::~TStack() {
    delete[] data_;
}

template <typename T>
void TStack<T>::_Resize(const size_t new_capacity) {
    std::shared_ptr<T> *newdata = new std::shared_ptr<T>[new_capacity];
    std::copy(data_, data_ + capacity_, newdata);
    delete[] data_;
    data_ = newdata;
    capacity_ = new_capacity;
}

template <typename T>
void TStack<T>::Emplace(const T &&item)
{
    if (length_ >= capacity_)
        _Resize(capacity_ << 1);
            data_[length_++] = std::make_shared<T>(item);
}


template <typename T>
void TStack<T>::Push(const std::shared_ptr<T> &item) {
    if (length_ >= capacity_)
      _Resize(capacity_ << 1);
    data_[length_++] = item;
}

template <typename T>
void TStack<T>::Clear() {
    delete[] data_;
    data_ = new std::shared_ptr<T>[32];
    length_ = 0;
    capacity_ = 32;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const TStack<T> &stack) {
    for (size_t i = stack.length_ - 1; i >= 0; --i)
        os << (*stack.data_[i]);
    return os;
}