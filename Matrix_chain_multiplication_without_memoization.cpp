#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
int m[100][100],s[100][100];
long long count;
void matrix(int *p,int length)
{
int n=length-1;
for(int i=1;i<=n;i++)
{
m[i][i]=0;
}
for(int l=2;l<=n;l++)
{
++count;
for(int i=1;i<=n-l+1;i++)
{
++count;
int j=i+l-1;
m[i][j]=999999;
for(int k=i;k<j;k++)
{
++count;
int q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
if(q<m[i][j])
{
m[i][j]=q;
s[i][j]=k;
}
}
++count;
}
++count;
}
++count;
return;
}
void print(int i,int j)
{
for(int k=i;k<=j;k++)
{
for(int l=i;l<=j;l++)
{
cout<<m[k][l]<<"  ";
}
}
}
int main()
{
int *p,n;
count=0;
cout<<"enter n"<<"      ";
cin>>n;
p=new int[n];
for(int i=0;i<n;i++)
p[i]=rand()%n;
matrix(p,n);
cout<<"no. of iterations for "<<n<<" inputs  "<<count<<endl;
print(1,n-1);
}
