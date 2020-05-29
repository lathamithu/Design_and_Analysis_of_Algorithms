#include<iostream>
#include<stdlib.h>
using namespace std;
int Max(int *A,int n)
{
int lar;
lar=-1;
for(int i=1;i<n;i++)
{
  if(lar<=A[i])
   lar=A[i];
}

return lar;
}


long long countingsort(int *A,int n,int exp)
{
long long count=0;
int *C,*B,*a;
C=new int[10];
B=new int[n];
a=new int[n];
for(int i=1;i<n;i++)
{
a[i]=(A[i]/exp)%10;
}
/* for(int i=1;i<n;i++)
{
  cout<<a[i]<<endl;
}*/
for(int i=0;i<10;i++)
{
  C[i]=0;
}
for(int i=1;i<n;i++)
{
++count;
  ++C[a[i]];
}

for(int i=1;i<10;i++)
{
  C[i]=C[i]+C[i-1];
}
for(int i=n-1;i>0;i--)
{
  B[C[a[i]]]=A[i];
  --C[a[i]];
  ++count;
}
for(int i=1;i<n;i++)
{
  A[i]=B[i];
}
return count;
}
void radixsort(int *A,int n)
{
int max=Max(A,n);
long long count1=0,count=0;
for(int exp=1;max/exp>0;exp*=10)
{
++count1;
  count=count+countingsort(A,n,exp);
}
cout<<"no.of iterations for "<<n-1<<"  inputs is "<<count1+count<<endl;
}

int main()
{
int *A,n;
cout<<"Enter n: ";
cin>>n;
A=new int[n+1];
for(int i=1;i<=n;i++)
{
  A[i]=rand()%1000;
}
radixsort(A,n+1);
for(int i=1;i<=n;i++)
{
  cout<<A[i]<<"  ";
}

}

