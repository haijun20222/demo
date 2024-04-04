#include<iostream>
#include<cstring>
using namespace std;

class Person 
{
    public:
    Person (int age, string name) {

    }
    string name;
};

template <class T>
void mySwap(T&a, T&b) {
    T temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T> 
void sort(T arr, int len) {
    int i,j,max;
    for(i=0;i<len;i++) 
    {
        max = i;
        for(j=i+1; j<len; j++) 
        {
            if (arr[max] < arr[j]) 
            {
                max = j;
            }
        }
        if (max != i )
        {
            swap(arr[max], arr[i]);
        }
    }
}

template <class T>
void sort_insert(T arr, int len)
{
    int i,j,temp;
    for (i=1;i< len; i++)
    {
        if (arr[i-1] > arr[i]) {
            temp = arr[i];
            for(j=i;j > 0 && temp < arr[j-1]; j--) 
            {
                arr[j] = arr[j-1];
            }
            arr[j] = temp;
        }
    }
}

template <class T>
void print_arr(T arr, int len) 
{
    int i;
    cout << "data:" ;
    for(i=0;i<len;i++) {
        cout << " " << arr[i];
    }
    cout << endl;
}

void test() {
    int a = 10;
    int b = 20;
    mySwap<int>(a, b);
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    double c = 1.1;
    double d = 2.2;
    mySwap<double>(c, d);
    cout << "c = " << c << endl;
    cout << "d = " << d << endl;
}

void test_01()
{
 int arr[] = {1,10,3,4,3,7};
 int len = sizeof(arr)/sizeof(int);
 sort<int*>(arr, len);
 sort_insert<int*>(arr, len);
 print_arr<int*>(arr, len);


}

struct student {
    int age;
    int id;
};

struct student fun ()
{
    struct student stu;
    stu.age = 5;
    stu.id =5;
    return stu;
}




int main() {
    //test_01();
    struct student stu;
    stu = fun ();
    cout << "stu.age:  " << stu.age <<endl;
    cout << "stu.id: " << stu.id <<endl;
}
