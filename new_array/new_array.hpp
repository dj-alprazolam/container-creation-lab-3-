#pragma once 
#include<iostream>
#include<memory>

template <typename T>

class newdynamicarry{
private:
    std::unique_ptr<T[]> data;
    size_t sizearry;
    size_t capacityarry;
    void allocate();
public:
    newdynamicarry();
    ~newdynamicarry();
    size_t size() const;
    void push_back(const T& value);
    void erace(size_t index);
    void push_front(const T& value);
    void insert(size_t index, const T &value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    

};

template<typename T>
newdynamicarry<T>::newdynamicarry() : data(nullptr),sizearry(0),capacityarry(0){}

template<typename T>
newdynamicarry<T>::~newdynamicarry() {
}

template<typename T>// size
size_t newdynamicarry<T>::size() const{
    return sizearry;
}

template <typename T>// push_back
void newdynamicarry<T>::push_back(const T &value)
{
    if (sizearry == capacityarry)
    {
        allocate();
    }

    data[sizearry] = value;
    ++sizearry;
}

template<typename T> // erase
void newdynamicarry<T>::erace(size_t index){
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
void newdynamicarry<T>::push_front(const T &value)
{
    if (sizearry == capacityarry)
    {
        allocate();
    }

    for (size_t i = sizearry; i > 0; --i)
    {
        data[i] = std::move(data[i - 1]);   
    }  

    data[0] = value;
    ++sizearry;
}

template <typename T>
void newdynamicarry<T>::insert(size_t index, const T &value)
{
    if (index > sizearry)
    {
        throw std::out_of_range("Out in size");
    }
    if (sizearry == capacityarry)
    {
        allocate();
    }
    for (size_t i = sizearry; i > index; --i)
    {
        data[i] = std::move(data[i - 1]);
    }

    data[index] = value;
    ++sizearry;
}

template <typename T>
T &newdynamicarry<T>::operator[](size_t index)
{
    return data[index];
}

template <typename T>
const T &newdynamicarry<T>::operator[](size_t index) const
{
    return data[index];
}

template<typename T>
void newdynamicarry<T>::allocate(){
    size_t newcapacityarry = (capacityarry == 0) ? 1 : capacityarry + capacityarry / 2;
    std::unique_ptr<T[]> new_data = std::make_unique<T[]>(newcapacityarry);
    for (size_t i = 0; i < sizearry; ++i)
    {
        new_data[i] = std::move(data[i]);
    }

    data = std::move(new_data);
    capacityarry = newcapacityarry;
    
}