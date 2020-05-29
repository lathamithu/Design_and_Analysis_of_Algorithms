#include<iostream>
using namespace std;
struct node
{
float data;
node *link;
};
class bucketsort
{
node *bucket[10];
long long count1,count2;
float O[100];
  float A[100];
  int a[10];
  int n;
public:

  bucketsort()
  {
cout<<"enter the n  ";
cin>>n;

  }
  void insert()
{

for(int i=0;i<n;i++)
{
A[i]=static_cast<float>(rand())/static_cast<float>(RAND_MAX);
}
     for(int i=0;i<n;i++)
     {
float v=A[i]*10;
int value=(int)v;
node *pnew=new node;
pnew->data=A[i];
pnew->link=bucket[value];
bucket[value]=pnew;
a[value]++;
++count1;
     }
}
  void create()
{
count1=0;count2=0;
for(int i=0;i<10;i++)
{
bucket[i]=NULL;
a[i]=0;
}
}

void display()
{

cout<<" no. of iterations for   "<<n<<"  inputs is  "<<count1+count2<<endl;

}
void sort(int q)
{
  node *temp,*t;
  ++count2;

for(int i=0;i<a[q]&&temp!=NULL;i++)
{
  temp=bucket[q];
    t=bucket[q];
for(int j=0;j<a[q]-1&&t!=NULL;j++)
{
++count2;
if(t->data>t->link->data)
{
float d=t->link->data;
     t->link->data=t->data;
t->data=d;
}
t=t->link;
++count2;
}

temp=temp->link;
++count2;
}


int index=0;
for(int i=0;i<10;i++)
{
node *temp=bucket[i];
while(temp!=NULL)
{
O[index++]=temp->data;
temp=temp->link;
}
}
   }
};


int main()
{
bucketsort b;
b.create();
b.insert();
for(int i=0;i<10;i++)
{ b.sort(i);}
b.display();
} 
