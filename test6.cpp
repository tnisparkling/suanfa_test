#include<stdio.h>
#define N 5

struct node
{
	float value;
	float weight;
	int flag;
 } Node[N],temp;
 float Value,curvalue=0;
 float Weight,curweight=0;
 
void sort()
{
	int i,j;
	for(i=0;i<N-1;i++)
	{
		for(j=i+1;j<N;j++)
		{
			if()(Node[i].value/(float)Node[i].weight)<Node[j].value/(float)Node[j]weight)
			{
				temp=Node[i];
				Node[i]=Node[j];
				Node[j]=temp;
			}
		}
	}
}

void load()
{
	int i;
	for(i=0;i<N;i++)
	{
		if((Node[i].weight+curweight)<=Weight)
		{
			curvalue+=Node[i].value;
			curweight+=Node[i].weight;
			Node[i].flag=1;
		}
		else
		{
			Node[i].flag=0;
		}
	}
}

void put()
{
	int i;
	printf("已选中物品的重量分别为：")；
	for(i=0;i<N;i++)
	{
		if(Node[i].flag)
		{
			printf("%.2f",Node[i].weight);
		}
	 } 
	 printf("\n总的价值为：%.2f",curvalue);
}

int main()
{
	int i;
	printf("请输入物品的重量和价值：\n");
	for(i=0;i<N;i++)
	{
		printf("请输入第%d个物品的重量和价值：",i+1);
		scanf("%f%f",&Node[i].weight,&Node[i].value);
	}
	printf("\n请输入背包的容积：");
	scanf("%f",&Weight);
	sort();
	load();
	put();
	return 0;
}
