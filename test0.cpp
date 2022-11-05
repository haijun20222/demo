#include<iostream>
using namespace std;
int& Add(int a, int b)
{
    static int c;
    c = a + b;
    cout<<"&c  :"<<&c<<endl;
    cout<<"c  :"<<c<<endl;

    return c;
}



int    main(void)
{
    int& ans = Add(2, 2);
    cout << ans << endl;
    cout << &ans << endl;

    int &b = Add(4, 2);
    cout<< "Add(4, 2)"<<Add(4, 2)<<endl;
    cout <<"&b    :"<<&b << endl;
    cout << "b     :"<<b << endl;
    cout << ans << endl;
    return 0;
}