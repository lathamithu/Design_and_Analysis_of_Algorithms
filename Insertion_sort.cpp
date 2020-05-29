#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
#include<iomanip>
using namespace std;
long long count;
void InsertionSort(int *a,int n)
{
	int i,j,key;
	for(j=1;j<=n-1;j++)
	{
		i = j-1;
		key = a[j];
		
		while(i>=0 && a[i]>key)
		{
			
			 count++;
				a[i+1] = a[i];
		       	i = i-1;
		       
		       				
		}
		
		count++;		
		a[i+1] = key;
	}
}
int main()
{
	
		cout<<"\n\nInsertion Sort:";
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
	outf.open("in_random.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<rand()%n;
	}
	outf.close();
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
	//Insertion Sort
	
	//Reading input in array from input file
		
	inf.open("in_random.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	count = 0;
	InsertionSort(a,n);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;



	//Writing sorted numbers to output file
	outf.open("Out_random.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	

	cout<<"\nTotal Active Operations for random sequence: "<<count;
	cout<<"\nExecution Time for random sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	
//for sorted sequence
	

	inf.open("in_sorted.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	count = 0;
	InsertionSort(a,n);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;



	//Writing sorted numbers to output file
	outf.open("Out_sorted.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	

	cout<<"\nTotal Active Operations for sorted sequence: "<<count;
	cout<<"\nExecution Time for sorted sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	

	
	//for Rev_sorted sequence
	

	inf.open("in_reverse.txt");		
	for(int i=0;i<n;i++)
	{
		inf>>a[i];
	}
	inf.close();
	st = clock();
	
	count = 0;
	InsertionSort(a,n);
	
	end = clock();
	
	etime = (double)(end-st)/CLOCKS_PER_SEC;





	//Writing sorted numbers to output file
	outf.open("Out_reverse.txt");
	for(int i=0;i<n;i++)
	{
		outf<<"\t"<<a[i];
	}
	outf.close();
	

	cout<<"\nTotal Active Operations for reverse order sequence: "<<count;
	cout<<"\nExecution Time for reverse order sequence: "<<showpoint<<setprecision(8)<<etime<<" Seconds\n";
	

	
	
	delete(a);
}

