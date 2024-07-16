#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H
#include <iostream>
#include <stdexcept> 
#include <initializer_list> 

template <typename T>
class DynamicArray {
private:
    T* m_arr;
    size_t m_capacity;
    size_t m_size;

    void resize(size_t new_capacity);

public:
    DynamicArray();
    DynamicArray(size_t capacity);
    DynamicArray(std::initializer_list<T> init_list);
    DynamicArray(const DynamicArray& other); 
    DynamicArray(DynamicArray&& other) noexcept;

    DynamicArray& operator=(const DynamicArray& other); 
    DynamicArray& operator=(DynamicArray&& other) noexcept; 

    T& operator[](size_t ind);
    const T& operator[](size_t ind) const;
    
    ~DynamicArray();

    size_t getSize() const;
    size_t getCapacity() const;
    bool isEmpty() const;
    bool include(const T& value) const;
    void reserve(size_t new_capacity);
    void emplace(size_t position, const T& value);
    void insert(size_t position, const T& value);
    void pushBack(const T& value);
    void popBack();
    void remove(size_t position);
    void clear();
    void shrinkToFit();

    friend std::ostream& operator<<(std::ostream& os, const DynamicArray& array) {
        for (size_t i = 0; i < array.m_size; ++i) {
            os << array.m_arr[i] << " ";
        }
        return os;
    }
};

#include "dynamic-array.cpp" 

#endif //DYNAMIC_ARRAY_H