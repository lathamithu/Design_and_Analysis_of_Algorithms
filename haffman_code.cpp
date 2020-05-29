#include<iostream>
#include<cstdlib>
#include<climits>
#include<ctime>
using namespace std;
int j;
string c="0",e="1";
struct datanode
{
datanode *left;
datanode *right;
char data;
int frequency;
};
struct headnode
{
int size;
datanode *a[100];
}*h;
void getvalues(headnode *h)
{
cout<<"enter the number of elements\n";
int n;
cin>>n;
for(int j=0;j<n;j++)
{
h->a[j]=new datanode();
}
for(int i=0;i<n;i++)
{
cout<<"enter the"<<i<<"th character and its frequency\n";
cin>>h->a[i]->data;
cin>>h->a[i]->frequency;
(h->size)++;
}
}
void min_heapify(headnode *h,int i)
{
int left,right,largest;
left=(2*i)+1;
right=(2*i)+2;
if(left<h->size&&(h->a[left]->frequency)
<(h->a[i]->frequency))
{
largest=left;
}
else largest=i;
if(right<h->size&&(h->a[right]->frequency)
<(h->a[i]->frequency))
{
largest=right;
}
if(largest!=i)
{
datanode *r=new datanode;
r=h->a[largest];
h->a[largest]=h->a[i];
h->a[i]=r;
min_heapify(h,j);
}
}
void build_min_heap(headnode *h)
{
int size=h->size;
for(j=size/2;j>=0;j--)
{
min_heapify(h,j);
}
}
datanode extract_min(headnode *h)
{
datanode *d=new datanode;
d=h->a[0];
int size=h->size;
h->a[0]=h->a[size-1];
(h->size)--;
min_heapify(h,0);
return *d;
}
void insert(headnode *h,datanode *z)
{
int size=h->size;
datanode *d=new datanode();
d=z;
(h->size)++;
h->a[size]=d;
build_min_heap(h);
}
void huffmann(headnode *h)
{
int size=h->size;
for(int  i=0;i<size-1;i++)
{
datanode *left=new datanode();
datanode *right=new datanode();
datanode *z=new datanode();
*left=extract_min(h);
*right=extract_min(h);
z->left=left;
z->right=right;
z->data='\0';
z->frequency=(left->frequency)+(right->frequency);
insert(h,z);
}
datanode *f=new datanode();
*f=extract_min(h);
cout<<"the final frequency is:\t"<<f->frequency<<endl;
}
void print(datanode *d,string t)
{
 datanode *d1=new datanode();
 datanode *d2=new datanode();
 d1=d->left;
 d2=d->right;
 if(!(d1||d2))
 {
 cout<<d->data<<"\t"<<t<<endl;
 }
 if(d1)
 {
 string s;
 s=t+c;
 print(d1,s);
 }
 if(d2)
 {
 string g;
 g=t+e;
 print(d2,g);
 }
}
int main()
{
headnode *h=new headnode();
h->size=0;
getvalues(h);
build_min_heap(h);
huffmann(h);
datanode *d=new datanode();
d=h->a[0];
print(d->left,c);
print(d->right,e);
}
