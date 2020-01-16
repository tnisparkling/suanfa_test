#include<iostream>
#include<stdio.h>
using namespace std;
#define MAX 100
int num[MAX];
void Copy(int a[],int b[],int left,int right)
{
	for(int i=left;i<=right;i++)
		a[i]=b[i];
 } 
 
 void Merge(int a[],int b[],int left,int mid,int right)
 {
 	int i=left;
 	int j=mid+1;
 	int k=left;
 	while(i<=mid&&j<=right)
 	{
 		if(a[i]<a[j])
 			b[k++]=a[i++];
 		else
 			b[k++]=a[j++];
	 }
	if(i>mid)
	 	for(int z=j;z<=right;z++)
	 		b[k++]=a[z];
	else
		for(int z=i;i<=mid;i++)
			b[k++]=a[z];
 }
 
 void Mergesort(int a[],int left,int right)
 {
 	int *b=new int [MAX];
 	if(left<right)
 	{
 		int i=(left+right)/2;
 		Mergesort(a,left,i);
 		Mergesort(a,i+1,right);
 		Merge(a,b,left,i,right);
 		Copy(a,b,left,right);
	 }
	 delete[] b;
 }
 
 int main()
 {
 	int n;
 	while(cin>>n)
 	{
 		for(int i=0;i<n;i++)
 			cin>>num[i];
 		Mergesort(num,0,n-1);
 		for(int i=0;i<n;i++)
 			cout<<num[i]<<endl;
	 }
	 return 0;
 }
