#pragma once 
#include<iostream>
#include<memory>

template <typename T>

class dynamicarry{
private:
    std::unique_ptr<T> data;
    size_t sizearry;
    size_t capacityarry;
public:
    dynamicarry();
    ~dynamicarry();
    size_t size() const;
    void push_back(const T& value);

};