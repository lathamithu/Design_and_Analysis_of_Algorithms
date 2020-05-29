//MAXSUBARRAY

#include<iostream>
#include<fstream>
using namespace std;
int ll,lh,ls,rl,rh,rs,cl,ch,cs,mr,ml;
int maxcro(int a[],int low,int mid,int high);
int maxsubarr(int a[],int low,int high)
{

if(low==high)
    return(low,high,a[low]);
else
{
    int mid=(low+high)/2;
    (ll,lh,ls)=maxsubarr(a,low,mid);
    (rl,rh,rs)=maxsubarr(a,mid+1,high);
    (cl,ch,cs)=maxcro(a,low,mid,high);
    if(ls>=rs && ls>=cs)
        return(ll,lh,ls);
    else if(rs>=ls && rs>=cs)
        return(rl,rh,rs);
    else
        return(cl,ch,cs);
}
}

int maxcro(int a[],int low,int mid,int high)
{
int ls=-10000,sum=0;
for(int i=mid;i>low;i--)
{
    sum+=a[i];
    if(sum>ls)
    {
      ls=sum;
      ml=i;
    }
}
    int rs=-10000;
    sum=0;
for(int j=mid+1;j>low;j--)
{
    sum+=a[j];
    if(sum>rs)
    {
      rs=sum;
      mr=j;
    }
}
return(ml,mr,ls+rs);
}

int main()
{
int i,j,n;
ifstream f;
cin>>n;
int a[n];
f.open("Random.txt");
for(i = 0; i < n; i++)
{
    f>>a[i];
    cout<<a[i]<<" ";
}

f.close();
cout<<"\nMaximum sub-array sum is: "<<maxsubarr(a, 0, n-1);
}




//FILE
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
int main()
{
int i;
ofstream s;
s.open("Random.txt");
const int max=1000,min= -1000;
for(i=0;i<1000;i++)
s<<((rand()%(max+1-min))+min)<<" ";
s.close();
}
