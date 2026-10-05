#pragma once 
#include<memory>
#include<algorithm>

template <typename T>
class forward_list
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr){}
        Node(T&& val) : data(std::move(val)), next(nullptr){}

    };

    Node* first;
    size_t count;

public: 
    class iterator
    {
    private:
        Node *curr_node;
    public:
        iterator() : curr_node(nullptr) {}
        explicit iterator(Node *node) : curr_node(node) {}
        T &operator*() const
        {
            return curr_node->data;
        }

        T *operator->() const
        {
            return &curr_node->data;
        }

        iterator &operator++()
        {
            curr_node = curr_node->next;
            return *this;
        }


        bool operator ==(const iterator& other) const{
            return curr_node == other.curr_node;

        }
        
        bool operator !=(const iterator& other) const{
            return curr_node != other.curr_node;

        }

        T& get(){
            return curr_node->data;
        }

    };

    forward_list();
    ~forward_list();
    void clear();
    forward_list(forward_list &&other) noexcept;
    forward_list &operator=(forward_list &&other) noexcept;
    iterator begin();
    iterator end();
    void push_front(T &&val);
    void push_front(const T &val);
    void push_back(T &&val);
    void push_back(const T &val);
};

template<typename T> 
forward_list<T>::forward_list() : first(nullptr), count(0){}

template<typename T> 
forward_list<T>::~forward_list()
{
    while (first)
    {
        Node *temp = first;
        first = first->next;
        delete temp;
    }
    
}

template<typename T> 
forward_list<T>::forward_list(forward_list&& other) noexcept : first(other.first), count(other.count){
    other.first = nullptr;
    other.count = 0;
}

template <typename T>
forward_list<T> &forward_list<T>::operator=(forward_list &&other) noexcept
{
    if (this != &other)
    {
        clear();
        first = other.first;
        count = other.count;
        other.first = nullptr;
        other.count = 0;
    }
    return *this;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin()
{
    return iterator(first);
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end()
{
    return iterator(nullptr);
}

template <typename T>
void forward_list<T>::push_front(T&& val)
{
    Node* node = new Node(std::move(val));
    node->next = first;
    first = node;
    ++count;
}

template <typename T>
void forward_list<T>::push_front(const T& val)
{
    Node* node = new Node(val);
    node->next = first;
    first = node;
    ++count;
}

template <typename T>
void forward_list<T>::push_back(T&& val)
{
    Node* node = new Node(std::move(val));

    if (!first)
    {
        first = node;
    }
    else
    {
        Node* cur = first;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
    ++count;
}

template <typename T>
void forward_list<T>::push_back(const T& val)
{
    Node* node = new Node(val);

    if (!first)
    {
        first = node;
    }
    else
    {
        Node* cur = first;
        while (cur->next)
            cur = cur->next;
        cur->next = node;
    }
    ++count;
}

template <typename T>
void forward_list<T>::clear()
{
    while (first)
    {
        Node* tmp = first;
        first = first->next;
        delete tmp;
    }
    count = 0;
}