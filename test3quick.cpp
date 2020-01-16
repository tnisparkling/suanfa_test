#include<stdio.h>
#define N 10
void quicksort(int arr[],int start,int end)
{
	if(start<end)
	{
		int stard=arr[start];
		int low=start;
		int high=end;
		while(low<high)
		{
			while(low<high&&stard<=arr[high])
			{
				high--;
			}
			arr[low]=arr[high];
			while(low<high&&arr[low]<=stard)
			{
				low++;
			}
			arr[high]=arr[low];
		}
		arr[low]=stard;
		quicksort(arr,start,low);
		quicksort(arr,low+1,end);
	}
}

int main()
{
	int k;
	int arr[]={5,3,4,1,2,23,78,96,11,36};
	quicksort(arr,0,N-1);
	scanf("%d",&k);
	for(int i=1;i<k;i++)
	{
		printf("%d",arr[i]);
	}
}
