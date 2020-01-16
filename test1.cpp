#include<stdio.h>
#include<iostream>
using namespace std;
//循环 
int BinarySearch(int array[],int value,int length )
{
	if(array==NULL||length<1)
		return -1;
	int lp=0;
	int rp=length-1;
	while(rp>lp)
	{
		int mid=(lp+rp)/2;
		if(array[mid]==value)
			return mid;
		if(array[mid]>value)
			rp= mid-1;
		else
			lp=mid+1;
	}
}
//递归 
int BinarySearch2(const int array[],int value,int lp,int rp)
{
	if(array==NULL||lp>rp)
		return -1;
	int mid=(lp+rp)/2;
	if(lp>rp){
		return -1;
	}
	if(array[mid]==value)
		return mid;
	else
	{
		if(array[mid]>value)
			BinarySearch2(array,value,lp,mid-1);
		else
			BinarySearch2(array,value,mid+1,rp);
			
	}
}

int main()
{
	const int length=10;
	int a[length]={1,2,3,4,5,6,7,8,9,100};
	cout<<"循环的结果是:"<<BinarySearch(a,100,length)<<endl;
	cout<<"递归的结果是:"<<BinarySearch2<<(a,100,0,length-1)<<endl;
	system("PAUSE");
	return 0;
}
