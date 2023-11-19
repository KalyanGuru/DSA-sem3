#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
void counting_sort(int a[100],int max,int num)
{
	int c[100],b[100],i;
	for(i=0;i<=max;i++)
	{
		c[i]=0;
	}
	for(i=1;i<=num;i++)
	{
		c[a[i]]=c[a[i]]+1;
	}
	for(i=1;i<=max;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=num;i>=1;i--)
	{
		b[c[a[i]]]=a[i];
		c[a[i]]=c[a[i]]-1;
	}
	for(i=1;i<=num;i++)
	{
		a[i]=b[i];
	}
	for(i=1;i<=num;i++)
	{
		printf(" %d ",a[i]);
	}
}
int main()
{
	int a[100],i,num;
	printf("Enter the size of the array: ");
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		printf("Enter the %d number data: ",i);
		scanf("%d",&a[i]);
	}
	int max=INT_MIN;
	for(i=1;i<=num;i++)
	{
		if(a[i]>max)
		  max=a[i];
	}
	printf("Sorted Array is:\n");
	counting_sort(a,max,num);
}
