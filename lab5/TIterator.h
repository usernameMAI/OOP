#pragma once

#include <memory>

template <typename T>
class TIterator {
public:
    TIterator(std::shared_ptr<T> *iter) : iter_(iter) {}

    T operator*() const {
        return *(*iter_);
    }

    T operator->() const {
        return *(*iter_);
    }

    void operator++() {
        iter_ += 1;
    }

    TIterator operator++(int) {
        TIterator iter(*this);
        ++(*this);
        return iter;
    }

    bool operator==(TIterator const &iterator) const {
        return iter_ == iterator.iter_;
    }

    bool operator!=(TIterator const &iterator) const {
        return iter_ != iterator.iter_;
    }

private:
    std::shared_ptr<T> *iter_;
};
