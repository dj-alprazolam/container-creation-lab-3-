#include"dynamic_arry.h"
#include <memory>
#include<algorithm>
#include<iostream>


template<typename T>
dynamicarry<T>::dynamicarry() : data(nullptr),sizearry(0),capacityarry(0){}

template<typename T>
dynamicarry<T>::~dynamicarry() {
     delete[] data;
}

template<typename T>// size
size_t dynamicarry<T>::size() const{
    return sizearry;
}

template<typename T>// push_back
void dynamicarry<T>::push_back(const T& value){
    if
}
