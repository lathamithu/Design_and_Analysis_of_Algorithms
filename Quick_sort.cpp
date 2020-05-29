#include<iostream>
using namespace std;
int part(int a[],int p,int r);
void quick(int a[],int p,int r)
{
if(p<r)
{
    int q = part(a,p,r);
    quick(a,p,q-1);
    quick(a,q+1,r);
}
}

int part(int a[],int p,int r)
{
int i=p-1;
for(int j=p;j<r;j++)
{
    if(a[j]<=a[r])
    {
        i++;
        int t=a[i];
        a[i]=a[j];
        a[j]=t;
    }
   
}
int l=a[i+1];
a[i+1]=a[r];
a[r]=l;
return (i+1);
}

int main()
{
int n;
cout<<"Enter n:";
cin>>n;
int a[n];
cout<<"\nEnter elements:";
for(int i=0;i<n;i++)
cin>>a[i];
quick(a,0,n-1);
for(int i=0;i<n;i++)
cout<<a[i]<<"\t";
}
   

