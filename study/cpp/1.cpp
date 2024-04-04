#include<iostream>
#include<cstring>
using namespace std;

class Person 
{
public:
    Person(int age)
    {
        this->age = 18;
        strcpy(this->name,"chj");
        cout << "my name:" << this->name << endl;
        cout << "my age:" << this->age << endl;
    }

    Person (const Person& person)
    {
        cout << "i am copy" <<endl;
    }
    int age;
    char name[];
};

int main() {
     int age = 5;
     Person person(age);
     Person person1 = person;

}
