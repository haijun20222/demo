#include<iostream>
using namespace std;
class Myarray
{
public:
    Myarray();
    //1、在某个位置插入数据
    void Setdata(int pos,int data);
    //2、获取指定位置的数据
    int  Getdata(int pos);
    //3、获取数组的长度
    int  Getlen();
    //4、尾插法
    void Pushback(int data);
    //5、析构函数，释放数组空间
private:
   int Arraysize;
   int Arraycapacity;
   int *Arrayadress;
};