#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
#define MAX 100
void LCSLength(int m,int n,char *X,char *Y,int c[][MAX],int b[][MAX])
{
	int i,j;
	for(i=1;i<=m;i++)
		c[i][0]=0;
	for(i=1;i<=n;i++)
		c[0][i]=0;
	for(i=1;i<=m;i++)
		for(j=1;j<=n;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				c[i][j]=c[i-1][j-1]+1;
				b[i][j]=1;
			}
			else if(c[i-1][j]>=c[i][j-1])
			{
				c[i][j]=c[i-1][j];
				b[i][j]=2;
			}
			else
			{
				c[i][j]=c[i][j-1];
				b[i][j]=3;
			}
			
		}
}


void LCS(int i,int j,char *X,int b[][MAX])
{
	if(i==0||j==0)
		return;
	if(b[i][j]==1)
	{
		LCS(i-1,j-1,X,b);
		cout<<X[i-1];
	}
	else if(b[i][j]==2)
		LCS(i-1,j,X,b);
	else
		LCS(i,j-1,X,b);
}

int main()
{
	char X[MAX];
	char Y[MAX];
	int b[MAX][MAX];
	int c[MAX][MAX];
	int m,n;
	while(1)
	{
		cout<<endl;
		cout<<"请输入两个字符串："<<endl;
		cin>>X>>Y;
		m=strlen(X);
		n=strlen(Y);
		LCSLength(m,n,X,Y,c,b);
		cout<<"最长公共子序列的长度为："<<c[m][n]<<endl;
		cout<<"最长公共子序列为："<<endl;
		LCS(m,n,X,b);
		cout<<endl;
	}
}
