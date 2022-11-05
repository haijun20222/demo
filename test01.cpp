#include<iostream>
using namespace std;
void test01(void);
void test03();
void test04();
void sum(void);
int main()
{
   test04();
}

void sum(void)
{
  int i=100,sum =0;
   for(int i =0;i!=10;++i)
  {
   sum =sum+i;
   cout<<i<<""<<sum<<endl;
  }
}

void test01(void)
{
   int i =10;
   while(i--)
   {
      cout<<"i="<<i<<endl;
   }
}


void test03()
{
  int val1 = 0;
  int val2 = 0;
  int min =0;
  int max =0;
  cin >> val1;
  cin >> val2;
  min = val1;
  max = val2;
  if(val2<val1)
  {
      min = val2;
      max = val1;
  }
  for(int i = min; i< max;i++)
  {
      cout<< "i="<<i<<endl;
  }
}

void test04()
{
  int val = 0;
  int sum = 0;
  while (cin>>val)
  {
      sum = sum+val;
  }
  cout << "sum ="<< sum << endl;
}