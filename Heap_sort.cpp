#include<iostream>
using namespace std;
void max_heapify(int a[],int i,int n);
void build_max_heap(int a[],int n);
void heapsort(int a[],int n)
{
build_max_heap(a,n);
for(int i=n;i>=2;i--)
{
int t=a[1];
a[1]=a[i];
a[i]=t;
n--;
max_heapify(a,1,n);
}
}
void max_heapify(int a[],int i,int n)
{
int largest;
int l=2*i;
int r=(2*i)+1;
if(l<=n && a[l]>a[i])
largest=l;
else
largest=i;
if(r<=n && a[r]>a[largest])
largest=r;
if(largest=!i)
{
int t=a[i];
a[i]=a[largest];
a[largest]=t;
max_heapify(a,largest,n);
}
}
void build_max_heap(int a[],int n)
{
for(int i=n/2;i>=1;i--)
max_heapify(a,i,n);
}
int main()
{
int n;
cout<<"\n Enter n";
cin>>n;
int a[n+1];
for(int i=1;i<=n;i++)
cin>>a[i];
heapsort(a,n);
cout<<"\n Elements sorted after heapsort";
for(int i=1;i<=n;i++)
cout<<a[i];
}
