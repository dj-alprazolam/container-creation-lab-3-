#include <iostream>
#include "array/dynamic_arry.hpp"
#include"list/list.hpp"
int main(int, char**){
std::cout << "______Dynamic_array________" << std::endl;
dynamicarry<int> a;
a.push_back(0);
a.push_back(1);
a.push_back(2);
a.push_back(3);
a.push_back(4);
a.push_back(5);
a.push_back(6);
a.push_back(7);
a.push_back(8);
a.push_back(9);

for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " << std::endl;
}

std::cout << "------ERACE-------"<< std::endl;
a.erace(3);
a.erace(5);
a.erace(7);

for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " << std::endl;
}

std::cout<<"---------Push_front------------"<<std::endl;
a.push_front(10);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " << std::endl;
}

std::cout <<"---------Insert---------------"<< std::endl;

a.insert(4,20);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " << std::endl;
}

std::cout <<"---------Push_back---------------"<< std::endl;
a.push_back(30);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " << std::endl;
}

}
