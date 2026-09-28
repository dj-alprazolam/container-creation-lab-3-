#include <iostream>
#include "array/dynamic_arry.hpp"
#include"list/list.hpp"
#include "new_array/new_array.hpp"
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
    std::cout<< a[i] << " ";
}
std::cout << '\n';
std::cout << "-------ERACE-------"<< std::endl;
a.erace(3);
a.erace(5);
a.erace(7);

for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " ;
}
std::cout << '\n';
std::cout<<"---------Push_front------------"<<std::endl;
a.push_front(10);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " ";
}
std::cout << '\n';
std::cout <<"---------Insert---------------"<< std::endl;
a.insert(4,20);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " ;
}
std::cout << '\n';
std::cout <<"---------Push_back---------------"<< std::endl;
a.push_back(30);
for (size_t i = 0; i < a.size(); i++)
{
    std::cout<< a[i] << " " ;
}
std::cout << '\n';


std::cout << "_____________List________________" << std::endl;

list<int> b;
b.push_back(0);
b.push_back(1);
b.push_back(2);
b.push_back(3);
b.push_back(4);
b.push_back(5);
b.push_back(6);
b.push_back(7);
b.push_back(8);
b.push_back(9);
for (size_t i = 0; i < b.size() ; i++)
{
    std::cout << b[i] << " ";
}
std::cout << '\n';
std::cout << "-------ERACE-------"<< std::endl;
b.erase(3);
b.erase(5);
b.erase(7);

for (size_t i = 0; i < b.size(); i++)
{
    std::cout<< b[i] << " " ;
}
std::cout << '\n';
std::cout<<"---------Push_front------------"<<std::endl;
b.push_front(10);
for (size_t i = 0; i < b.size(); i++)
{
    std::cout<< b[i] << " ";
}
std::cout << '\n';
std::cout <<"---------Insert---------------"<< std::endl;
b.insert(4,20);
for (size_t i = 0; i < b.size(); i++)
{
         std::cout<< b[i] << " " ;
}
std::cout << '\n';
std::cout <<"---------Push_back---------------"<< std::endl;
b.push_back(30);
for (size_t i = 0; i < b.size(); i++)
{
    std::cout<< b[i] << " " ;
}
std::cout << '\n';


std::cout << "______NEWDynamic_array________" << std::endl;
newdynamicarry<int> c;
c.push_back(0);
c.push_back(1);
c.push_back(2);
c.push_back(3);
c.push_back(4);
c.push_back(5);
c.push_back(6);
c.push_back(7);
c.push_back(8);
c.push_back(9);

for (size_t i = 0; i < c.size(); i++)
{
    std::cout<< c[i] << " ";
}
std::cout << '\n';
std::cout << "-------ERACE-------"<< std::endl;
c.erace(3);
c.erace(5);
c.erace(7);

for (size_t i = 0; i < c.size(); i++)
{
    std::cout<< c[i] << " " ;
}
std::cout << '\n';
std::cout<<"---------Push_front------------"<<std::endl;
c.push_front(10);
for (size_t i = 0; i < c.size(); i++)
{
    std::cout<< c[i] << " ";
}
std::cout << '\n';
std::cout <<"---------Insert---------------"<< std::endl;
c.insert(4,20);
for (size_t i = 0; i < c.size(); i++)
{
    std::cout<< c[i] << " " ;
}
std::cout << '\n';
std::cout <<"---------Push_back---------------"<< std::endl;
c.push_back(30);
for (size_t i = 0; i < c.size(); i++)
{
    std::cout<< c[i] << " " ;
}
std::cout << '\n';

}

