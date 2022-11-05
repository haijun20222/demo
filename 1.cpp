#include<iostream>
using namespace std;

class Person
{
    public:
    Person(int a = 3)
    {
       cout<<"有参构造"<<endl;
    };
};


int main()
{
    Person p{};
}
