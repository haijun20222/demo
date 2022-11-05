#include<iostream>
using namespace std;

int main()
{
  int val=0;
  int sum = 0;
  while(val<=100)
  {
    sum = sum + val;
    val++;
  }
  cout<<"sum="<< sum <<endl;
}