#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
long long count;
void merge(int a[],int f,int m,int l);
void mergesort(int a[],int f,int l)
{
    if(f<l)
    {
        int m=(f+l)/2;
        mergesort(a,f,m);
        mergesort(a,m+1,l);
        merge(a,f,m,l);
        count++;
    }
    count++;
}
        
void merge(int a[],int f,int m,int l)
{ 
    int i,j,k;
    int n1 = m - f + 1; 
    int n2 =  l - m; 
   
     
    int L[n1+1];
     
    int R[n2+1]; 
   
     
    for (i = 1; i <= n1; i++){
        L[i] = a[f + i-1];
        count++;
    }
    count++;
         
    for (j = 1; j <= n2; j++) {
    R[j] = a[m +j];
    count++;
    }
         count++;
   
     L[n1+1]=100000;
     R[n2+1]=100000;
    i = 1; 
    j = 1; 
    for(k=f;k<=l;k++)
    { 
        if (L[i] <= R[j]) 
            a[k] = L[i++]; 
        else
        a[k] = R[j++]; 
    count++;
    } 
    count++;
    if (i < n1) 
    { 
        a[k++] = L[i++]; 

    } 
    if (j < n2) 
    { 
        a[k++] = R[j++]; 
 
    } 

} 
int main()
{
	
	cout<<"\n\nMerge Sort:";
	ofstream outf;
	ifstream inf;

	clock_t st,end;
	double etime;

	int n;
	int *a;
	
	cout<<"\nEnter n:";
	cin>>n;
	
	a = new int [n];
	//Loading numbers to input file
/*	outf.open("in_random.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%n;
	}
	outf.close();*/
	outf.open("in_sorted.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<i;
	}
	outf.close();
	
	outf.open("in_reverse.txt");
	for(int i=n;i>=1;i--)
	{
		outf<<"\t"<<i;
	}
	outf.close();
	
	
	//Reading input in array from input file
/*		
	inf.open("in_random.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	//count = 0;
	mergesort(a, 0, n );
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;
*/


	//Writing sorted numbers to output file
/*	
	outf.open("Out_random.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	

	//cout<<"\nTotal Active Operations for random sequence: "<<count;
	cout<<"\nExecution Time for random sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	*/
//for sorted sequence
	count=0;

	inf.open("in_sorted.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	//count = 0;
	mergesort(a, 0, n );
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;



	//Writing sorted numbers to output file
	outf.open("Out_sorted.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	
	outf.close();
	

	//cout<<"\nTotal Active Operations for sorted sequence: "<<count;
	cout<<"\nExecution Time for sorted sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	
    cout<<"\nBest case comparisons : "<<count;
	
	//for Rev_sorted sequence
	count=0;

	inf.open("in_reverse.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	//count = 0;
	mergesort(a, 0, n );
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;





	//Writing sorted numbers to output file
	outf.open("Out_reverse.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	

	//cout<<"\nTotal Active Operations for reverse order sequence: "<<count;
	cout<<"\nExecution Time for reverse order sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	
    cout<<"\nWorst case comparisons : "<<count;
	
	
	delete(a);
}

