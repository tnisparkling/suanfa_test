#include<stdio.h>
#include<iostream>
using namespace std;

void quick_sort(int a[],int start,int end)
{
	if(start<end)
	{
		int s=a[start];
		int i=start;
		int j=end;
		while(i<j)
		{
			while(i<j&&a[j]>=s)
				j--;
			if(i<j)
				a[i++]=a[j];
			while(i<j&&a[i]<s)
				i++;
			if(i<j)
			{
				a[j--]=a[i];
			}
		}
		
		a[i]=s;//返回最初的值 
		quick_sort(a,start,i-1);
		quick_sort(a,i+1,end);
	}
}


void output(int a[],int length)
{
	for(int i=0;i<length;i++)
	{
		cout<<a[i]<<'';
	}
}

int main()
{
	int a[10]={10,9,8,7,6,5,4,3,2,1};
	cout<<"排序前：";
	output(a,10);
	quick_sort(a,0,9);
	cout<<"排序后：";
	output(a,10);
	system("pause");
	return 0;
}

