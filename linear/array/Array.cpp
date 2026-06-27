#include "Array.h"
#include <iostream>

template <typename T>
Array<T>::Array() : data_(new T[1]), size_(0), capacity_(1) {}

template <typename T>
Array<T>::Array(int capacity) : data_(new T[capacity]), size_(0), capacity_(capacity) {}

template <typename T>
Array<T>::~Array() {
    delete[] data_;
}

// 맨 뒤에 원소 추가
template <typename T>
void Array<T>::pushBack(const T& value) {
    if (size_ == capacity_)
        resize();
    data_[size_++] = value;
}

// 맨 뒤 원소 제거
template <typename T>
void Array<T>::popBack() {
    if (empty())
        throw std::underflow_error("Array is empty");
    --size_;
}

// index 위치에 삽입 — 그 뒤 원소들을 한 칸씩 밀기
template <typename T>
void Array<T>::insert(int index, const T& value) {
    checkIndex(index);
    if (size_ == capacity_)
        resize();
    for (int i = size_; i > index; --i)
        data_[i] = data_[i - 1];
    data_[index] = value;
    ++size_;
}

// index 위치 제거 — 그 뒤 원소들을 한 칸씩 당기기
template <typename T>
void Array<T>::remove(int index) {
    checkIndex(index);
    for (int i = index; i < size_ - 1; ++i)
        data_[i] = data_[i + 1];
    --size_;
}

template <typename T>
T& Array<T>::operator[](int index) {
    checkIndex(index);
    return data_[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    checkIndex(index);
    return data_[index];
}

template <typename T>
int Array<T>::size() const { return size_; }

template <typename T>
int Array<T>::capacity() const { return capacity_; }

template <typename T>
bool Array<T>::empty() const { return size_ == 0; }

template <typename T>
void Array<T>::print() const {
    std::cout << "[ ";
    for (int i = 0; i < size_; ++i)
        std::cout << data_[i] << " ";
    std::cout << "]  size=" << size_ << "  capacity=" << capacity_ << "\n";
}

// 꽉 차면 capacity를 2배로 늘리고 데이터 복사
template <typename T>
void Array<T>::resize() {
    capacity_ *= 2;
    T* newData = new T[capacity_];
    for (int i = 0; i < size_; ++i)
        newData[i] = data_[i];
    delete[] data_;
    data_ = newData;
}

template <typename T>
void Array<T>::checkIndex(int index) const {
    if (index < 0 || index >= size_)
        throw std::out_of_range("Index out of range");
}
