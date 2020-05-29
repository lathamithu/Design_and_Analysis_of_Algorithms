#include<iostream>
#include<climits>
#include<math.h>
using namespace std;
int m[5][5],s[5][5];
void OPT_PAR(int s[][5],int i,int j)
{
    if(i==j)
        cout<<s[i];
    else
        cout<<" \" ";
    OPT_PAR(s,i,s[i][j]);
    OPT_PAR(s,s[i][j]+1,j);
    cout<<" \" ";
}
int* MCM(int p[],int n)
{
    int i,q,l,k,j;
    n=sizeof(p)-1;
    OPT_PAR(s,i,j);
    for(i=1;i<=n;i++)
        m[i][i]=0;
    for(int l=2;i<=n;i++)
    {
      for(i=1;i<=n-l+1;i++)
      { 
        j=i+l-1;
        m[i][j]=INT_MAX;
        for(k=i;k<=j-1;k++)
        {
        q = m[i][k] + m[k + 1][j] + 
                          p[i - 1] * p[k] * p[j];
          if (q < m[i][j] )
          {
                      m[i][j] = q;
            s[i][j] = k;
                  }
                }
          }
      }

}


int main()
{
   
    int arr[5]; int n;
  cout<<"Enter ele:";
for(int i=0;i<5;i++)
cin>>arr[i];
    cout << "Minimum number of multiplications is "
        << MCM(arr,n);
}
