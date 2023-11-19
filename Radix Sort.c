#include<stdio.h>
#include<limits.h>
void counting_sort(int a[100],int pos,int num)
{
	int c[100],b[100],i;
	for(i=0;i<=10;i++)
	{
		c[i]=0;
	}
	for(i=1;i<=num;i++)
	{
		c[(a[i]/pos)%10]=c[(a[i]/pos)%10]+1;
	}
	for(i=1;i<=10;i++)
	{
		c[i]=c[i]+c[i-1];
	}
	for(i=num;i>=1;i--)
	{
		b[c[(a[i]/pos)%10]]=a[i];
		c[(a[i]/pos)%10]=c[(a[i]/pos)%10]-1;
	}
	for(i=1;i<=num;i++)
	{
		a[i]=b[i];
	}
}
void radix_sort(int a[],int num, int max)
{
	int pos,i;
	for(pos=1;max/pos>0;pos=pos*10)
	{
		counting_sort(a,pos,num);
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
	printf("Given Array is:\n");
	for(i=1;i<=num;i++)
	{
		printf(" %d ",a[i]);
	}
	int max=INT_MIN;
	for(i=1;i<=num;i++)
	{
		if(a[i]>max)
		  max=a[i];
	}
	printf("\nSorted Array is:\n");
	radix_sort(a,num,max);
}
