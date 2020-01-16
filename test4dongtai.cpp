#include<iostream>
#include<stdio.h>
#define N 6
#define W 21

int B[N][W]={0};
int w[6]={0,2,3,4,5,9};
int v[6]={0,3,4,5,8,10};

void knapsack()
{
	int k;
	int C;
	
	for(k=1;k<N;k++)
	{
		for(C=1;C<W;C++)
		{
			if(w[k]>C)
			{
				B[k][C]=B[k-1][C];
			}
			else
			{
				int value1=B[k-1][C-w[k]]+v[k];
				int value2=B[k-1][C];
				
				if(value1>value2)
				{
					B[k][C]=value1;
				}
				else
				{
					B[k][C]=value2;
					if(value1<value2)
						printf("k=%d C=%d\n",k,C);
				}
			}
		}
	}
}

int main()
{
	knapsack();
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<W;j++)
		{
			printf("%4d",B[i][j]);
		}
		printf("\n\n");
	}
	system("pause");
}
