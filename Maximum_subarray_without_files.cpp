#include<iostream>
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
int ls=-100,sum=0;
for(int i=mid;i>low;i--)
{
    sum+=a[i];
    if(sum>ls)
    {
      ls=sum;
      ml=i;
    }
}
    int rs=-100;
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
cout<<"Enter n ";
cin>>n;
int a[n];
for(i = 0; i < n; i++)
    cin>>a[i];
cout<<"\nMaximum sub-array sum is: "<<maxsubarr(a, 0, n-1);
}
