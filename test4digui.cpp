#include<iostream>
#include<stdio.h>
using namespace std;
const int n=5;
int weight[5];
int value[5];
int select[5];
int temp_select[5];

int W=10;
int temp_value=0;

void dfs(int k,int t_v,int t_w)
{
	if(k==n)
		return;
	for(int i=k;i<n;++i)
	{
		if(t_w+weight[i]<=W)
		{
			select[i]=1;
			t_w+=weight[i];
			t_v+=value[i];
			if(t_v>temp_value)
			{
				for(int j=0;j<5;++j)
				{
					temp_select[j]=select[j];
				}
				temp_value=t_v;
			}
			dfs(i+1,t_v,t_w);
		}
		else
			dfs(i+1,t_v,t_w);
	
		if(select[i]==1)
		{
			select[i]=0;
			t_v-=value[i];
			t_w-=weight[i];
		}
	}
}

int main()
{
	weight[0]=2;
	weight[1]=2;
	weight[2]=6;
	weight[3]=5;
	weight[4]=4;
	
	value[0]=6;
	value[1]=3;
	value[2]=4;
	value[3]=2;
	value[4]=4;
	dfs(0,0,0);
	for(int i=0;i<5;i++)
		cout<<temp_select[i]<<endl;
	cout<<temp_value<<endl;
	return 0;
}
