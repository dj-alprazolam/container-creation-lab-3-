#pragma once 
#include<iostream>
#include<memory>

template <typename T>

class dynamicarry{
private:
    std::unique_ptr<T[]> data;
    size_t sizearry;
    size_t capacityarry;
public:
    dynamicarry();
    ~dynamicarry();
    size_t size() const;
    void push_back(const T& value);
    void erace(size_t index);
    void push_front(const T& value);
    void insert(size_t index, const T &value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    

};

template<typename T>
dynamicarry<T>::dynamicarry() : data(nullptr),sizearry(0),capacityarry(0){}

template<typename T>
dynamicarry<T>::~dynamicarry() {
}

template<typename T>// size
size_t dynamicarry<T>::size() const{
    return sizearry;
}

template <typename T>// push_back
void dynamicarry<T>::push_back(const T &value)
{
    if (sizearry == capacityarry)
    {
        size_t new_capacity = (capacityarry == 0) ? 1 : capacityarry * 2;
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);

        for (size_t i = 0; i < sizearry; ++i)
        {
            new_data[i] = std::move(data[i]);
        }

        data = std::move(new_data);
        capacityarry = new_capacity;
    }

    data[sizearry] = value;
    ++sizearry;
}

template<typename T> // erase
void dynamicarry<T>::erace(size_t index){
    if(sizearry < index){
        throw std::out_of_range("Out in size");
    }

    for (size_t i = index; i < sizearry - 1; ++i)
    {
        data[i] = std::move(data[i+1]);
    }

    --sizearry;
    
}

template <typename T>// push_front
void dynamicarry<T>::push_front(const T &value)
{
    if (sizearry == capacityarry)
    {
        size_t new_capacity = (capacityarry == 0) ? 1 : capacityarry * 2;
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);

        for (size_t i = 0; i < sizearry; ++i)
        {
            new_data[i] = std::move(data[i]);
        }

        data = std::move(new_data);
        capacityarry = new_capacity;
    }

    for (size_t i = sizearry; i > 0; --i)
    {
        data[i] = std::move(data[i - 1]);   
    }  

    data[0] = value;
    ++sizearry;
}

template<typename T>// insert 
void dynamicarry<T>::insert(size_t index, const T &value){
    if (sizearry < index)
    {
        throw std::out_of_range("Out in size");
    }

    if (sizearry == capacityarry)
    {
        size_t new_capacity = (capacityarry == 0) ? 1 : capacityarry * 2;
        std::unique_ptr<T[]> new_data = std::make_unique<T[]>(new_capacity);

        for (size_t i = 0; i < sizearry; ++i)
        {
            new_data[i] = std::move(data[i]);
        }

        data = std::move(new_data);
        capacityarry = new_capacity;
    }

    for (size_t i = index; i < sizearry - 1; ++i)
    {
        data[i] = std::move(data[i+1]);
    }

    data[index] = value;
    ++sizearry;
}

template <typename T>
T &dynamicarry<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
const T &dynamicarry<T>::operator[](size_t index) const
{
    return data[index];
}
