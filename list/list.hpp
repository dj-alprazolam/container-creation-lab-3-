#pragma once
#include<iostream>
#include<memory>
#include<algorithm>

template<typename T>

class list
{
private:
    struct Node
    {
        T data;
        Node *prev;
        Node *next;

        Node(const T& val) : data(val), prev(nullptr), next(nullptr){}
    };

    Node* first;
    Node* last;
    size_t count;

public:
    list();
    ~list();
    size_t size() const;
    void push_back(const T& value);
    void push_front(const T& value);
    T& operator[](size_t index);
    const T& operator[](size_t index) const;
    void insert(size_t index, const T& value);
    void erase(size_t index); 
};

template<typename T>
list<T>::list() : first(nullptr), last(nullptr), count(0){}

template <typename T>
list<T>::~list()
{
    Node *current = first;
    while (current != nullptr)
    {
        Node *next = current->next; 
        delete current;
        current = next;
    }
    first = last = nullptr;
    count = 0;
}

template<typename T>
size_t list<T>::size() const{
    return count;
}

template<typename T>
void list<T>::push_back(const T& value){
    Node* newnode = new Node(value);
    if (first == nullptr)
    {
        first = last = newnode;
    }else{
        newnode->prev = last;
        last->next = newnode;
        last = newnode;
    }

    ++count;
}

template<typename T>
void list<T>::push_front(const T& value){
    Node* newnode = new Node(value);
    if (first == nullptr)
    {
        first = last = newnode;
    }else{
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }

    ++count;
}

template<typename T> 
T &list<T>::operator[](size_t index){
    Node* curr = first;
    for (size_t i = 0; i < index; ++i)
    {
        curr = curr->next;
    }

    return curr->data;
}

template<typename T> 
const T &list<T>::operator[](size_t index) const{
    Node* curr = first;
    for (size_t i = 0; i < index; ++i)
    {
        curr = curr->next;
    }

    return curr->data;
}

template<typename T>
void list<T>::insert(size_t index, const T& value){
     if (index > count)
     {
        throw std::out_of_range("Of range");
     }
     
     Node* curr = first;
     for (size_t i = 0; i < index; ++i)
     {
        curr = curr->next;
     }

     Node* newNode = new Node(value);
     newNode -> next = curr;
     newNode -> prev = curr->prev;
     curr->prev->next = newNode;
     curr->prev = newNode;
     
     
     ++count;
     
}

template<typename T>
void list<T>::erase(size_t index){
    if (count < index)
    {
        throw std::out_of_range("Out in size");
    }

    Node* curr = first;
    for (size_t i = 0; i < index; ++i)
    {
        curr = curr->next;
    }

    Node *prevNode = curr->prev;
    Node *nextNode = curr->next;

    if (prevNode != nullptr)
    {
        prevNode->next = nextNode;
    }else{
        first = nextNode;
    }

    if (nextNode != nullptr)
    {
        nextNode->prev = prevNode;

    }else{
        last = prevNode;
    }
    
    delete curr;
    --count;
    
}
