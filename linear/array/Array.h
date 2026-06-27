#pragma once
#include <stdexcept>

template <typename T>
class Array {
public:
    Array();
    explicit Array(int capacity);
    ~Array();

    void pushBack(const T& value);
    void popBack();
    void insert(int index, const T& value);
    void remove(int index);

    T& operator[](int index);
    const T& operator[](int index) const;

    int size() const;
    int capacity() const;
    bool empty() const;
    void print() const;

private:
    T* data_;
    int size_;
    int capacity_;

    void resize();
    void checkIndex(int index) const;
};

#include "Array.cpp"
