#include<iostream>
using namespace std;
void count(int a[],int b[],int k)
{
    int c[k],i,j;
    for(i=0;i<k+1;i++){
       c[i]=0;}
    for(j=1;j<=k;j++){
       c[a[j]]=c[a[j]]+1;}
    for(i=1;i<=k;i++){
       c[i]=c[i]+c[i-1];}
    for(j=k;j>=1;j--)
    {
       b[c[a[j]]]=a[j];
       c[a[j]]=c[a[j]]-1;
    }
    for(int i=0;i<k;i++)
    cout<<b[i]<<" ";
}
int main()
{
int n;
cout<<"\nEnter n";
cin>>n;
int a[n],b[n];
cout<<"\nEnter elements";
for(int i=1;i<=n;i++)        
cin>>a[i];
cout<<"\nResult:\n";
count(a,b,n);
}
