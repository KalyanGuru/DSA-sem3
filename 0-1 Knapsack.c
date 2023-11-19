#include<stdio.h>
#include<stdlib.h>
typedef struct obj
{
	int no;
	int pro;
	int weight;
}obj;
int max(int a,int b)
{
	return((a+b)+abs(a-b))/2;
}
void sort(obj* objarray, int n)
{
	obj key;
	int i,j;
	for(i=2;i<=n;i++)
	{
		key=objarray[i];
		for (j=i-1;j>=1 && objarray[j].weight>key.weight;j--)
       {
          objarray[j+1]=objarray[j];
       }
       objarray[j+1]=key;
	}
}
void knapsack(obj* objarray,int bag,int num)
{
	int v[num+1][bag+1],i,j;
	for(i=0;i<=num;i++)
	{
		v[i][0]=0;
	}
	for(j=0;j<=bag;j++)
	{
		v[0][j]=0;
	}
	for(i=1;i<=num;i++)
	{
		for(j=1;j<=bag;j++)
		{
			if(objarray[i].weight>j)
			{
				v[i][j]=v[i-1][j];
			}
			else
			{
				v[i][j]=max(v[i-1][j],(v[i-1][j-objarray[i].weight])+objarray[i].pro);
			}
		}
	}
	printf("V Matrix is:\n");
	for(i=0;i<=num;i++)
	{
		for(j=0;j<=bag;j++)
		{
			printf("%d   ",v[i][j]);
		}
		printf("\n");
	}
	printf("\nSelected Jobs are:\n");
	printf("object No    Profit        Weight\n");
	i=num,j=bag;
	while(i>0&&j>0)
	{
		if(v[i][j]!=v[i-1][j])
		{
			printf("%d		%d		%d\n",objarray[i].no,objarray[i].pro,objarray[i].weight);
			j=j-objarray[i].weight;
		}
		i--;
	}
	printf("\nTotal profit is: %d",v[num][bag]);
}
int main()
{
	int i,num,bag;
	printf("Enter the number of objects: ");
	scanf("%d",&num);
	obj* objarray=(obj*)malloc(num*sizeof(obj));	
	for(i=1;i<=num;i++)
	{
		objarray[i].no=i;
		printf("Enter the profit of %d number of object: ",i);
		scanf("%d",&objarray[i].pro);
		printf("Enter the weight of %d number of object: ",i);
		scanf("%d",&objarray[i].weight);
	}
	printf("Enter the bag capacity: ");
	scanf("%d",&bag);
	sort(objarray,num);
	printf("\nSorted objects(In increasing order of Weight)\n");
	printf("object No    Profit         Weight\n");
	for(i=1;i<=num;i++)
	{
		printf("%d		%d		%d",objarray[i].no,objarray[i].pro,objarray[i].weight);
        printf("\n");
	}
     knapsack(objarray,bag,num);
	free(objarray);
}
