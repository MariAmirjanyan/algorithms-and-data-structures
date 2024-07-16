#include "dynamic-array.h"

template <typename T>
DynamicArray<T>::DynamicArray() 
    :m_arr(nullptr),
    m_capacity(0),
    m_size(0) 
{}

template <typename T>
DynamicArray<T>::DynamicArray(size_t capacity) 
    :m_arr(new T[capacity]),
    m_capacity(capacity),
    m_size(0) 
{}

template <typename T>
DynamicArray<T>::DynamicArray(std::initializer_list<T> init_list) 
    : m_arr(new T[init_list.size()]), 
    m_capacity(init_list.size()),
     m_size(init_list.size())
{
    size_t index = 0;
    for (const auto& elem : init_list) {
        m_arr[index++] = elem;
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) 
    : m_arr(new T[other.m_capacity]),
    m_capacity(other.m_capacity),
    m_size(other.m_size) 
{
    for (size_t i = 0; i < other.m_size; ++i) {
        m_arr[i] = other.m_arr[i];
    }
}

template <typename T>
DynamicArray<T>::DynamicArray(DynamicArray&& other) noexcept
    : m_arr(other.m_arr),
    m_capacity(other.m_capacity), 
    m_size(other.m_size)
{
    other.m_arr = nullptr;
    other.m_capacity = 0;
    other.m_size = 0;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other){
    if (this != &other) {
        delete[] m_arr;
        m_arr = new T[other.m_capacity];
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        for (size_t i = 0; i < other.m_size; ++i) {
            m_arr[i] = other.m_arr[i];
        }
    }
    return *this;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(DynamicArray&& other) noexcept{
    if (this != &other) {
        delete[] m_arr;
        m_arr = other.m_arr;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        other.m_arr = nullptr;
        other.m_capacity = 0;
        other.m_size = 0;
    }
    return *this;
}


template <typename T>
T& DynamicArray<T>::operator[](size_t ind){
    if (ind >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[ind];
}

template <typename T>
const T& DynamicArray<T>::operator[](size_t ind) const{
    if (ind >= m_size) {
        throw std::out_of_range("Index out of range");
    }
    return m_arr[ind];
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    clear();
}

template <typename T>
size_t DynamicArray<T>::getSize() const{
    return m_size;
}

template <typename T>
size_t DynamicArray<T>::getCapacity() const{
    return m_capacity;
}

template <typename T>
bool DynamicArray<T>::isEmpty() const{
    return !m_size;
}

template <typename T>
bool DynamicArray<T>::include(const T& value) const{
    for(int i = 0; i < m_size; i++){
        if(m_arr[i] == value){
            return true;
        }
    }
    return false;
}

template <typename T>
void DynamicArray<T>::resize(size_t new_capacity){
    T* new_arr = new T[new_capacity];
    for (size_t i = 0; i < m_size; ++i) {
        new_arr[i] = std::move(m_arr[i]);
    }
    delete[] m_arr;
    m_arr = new_arr;
    m_capacity = new_capacity;
}

template <typename T>
void DynamicArray<T>::reserve(size_t new_capacity){
    if (new_capacity > m_capacity) {
        resize(new_capacity);
    }
}

template <typename T>
void DynamicArray<T>::emplace(size_t position, const T& value){
    if(position < 0 || position > m_size){
        throw std::out_of_range("Index out of range");
    }
    if(m_size == m_capacity){
        resize(2 * m_capacity); 
    }
    for(size_t i = m_size; i > position; --i){
        m_arr[i] = m_arr[i - 1];
    }
    m_arr[position] = value;
    ++m_size;
}

template <typename T>
void DynamicArray<T>::insert(size_t position, const T& value){
    emplace(position, value);
}

template <typename T>
void DynamicArray<T>::pushBack(const T& value){
    if(m_size == m_capacity){
        resize(2 * m_capacity);
    }
    m_arr[m_size++] = value;
}

template <typename T>
void DynamicArray<T>::popBack(){
    if(m_size > 0){
        --m_size;
    }
}

template <typename T>
void DynamicArray<T>::remove(size_t position){
    if(position < 0 || position >= m_size){
        throw std::out_of_range("Index out of range");
    }
    if(m_size == m_capacity){
        resize(2 * m_size); 
    }
    for(int i = position; i < m_size - 1; ++i){
        m_arr[i] = m_arr[i + 1];
    }
    --m_size;
}

template <typename T>
void DynamicArray<T>::clear(){
    delete[] m_arr;
    m_arr = nullptr;
    m_capacity = 0;
    m_size = 0; 
}

template <typename T>
void DynamicArray<T>::shrinkToFit(){
    if(m_size * 2 < m_capacity){
        resize(m_size * 2);
    }
}