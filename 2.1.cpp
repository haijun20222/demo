#include<iostream>
using namespace std;


void modify_val(int &val, int new_val)
{
    val = new_val;
}

int main()
{
    unsigned u=10,u2 = 42;
    int b =10;
    const int a =10;
    modify_val(const_cast<int &>a, 12);
    // const int &a =b;
    int*p =&b;
    *p =20;
    cout<<"a="<<a<<endl;
    cout<< "u - u2=" <<hex <<u-u2 << endl;
    cout << hex << 120<<endl;
}
