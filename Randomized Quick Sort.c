#include<stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
	int temp=*x;
	*x=*y;
	*y=temp;
}
int partition(int a[],int l,int h)
{
	int up=h;
	int down=l;
	int pindex=l+rand()%(h-l+1);
	swap(&a[l],&a[pindex]);
	int pivot=a[l];
	while(down<up)
	{
		while(pivot<a[up]&&up>l)
		{
			up--;
		}
		while(pivot>a[down]&&down<h)
		{
			down++;
		}
		if(up>down)
		{
			swap(&a[up],&a[down]);
		}
	}
	swap(&a[up],&pivot);
	return up;
}
void Quick_sort(int a[],int l,int h)
{
	if(l<h)
	{
		int p=partition(a,l,h);
		Quick_sort(a,l,p-1);
		Quick_sort(a,p+1,h);
	}
}
int main()
{
	int n,a[100],i;
	printf("Enter the size of array: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter the %d number element: ",i+1);
		scanf("%d",&a[i]);
	}
	printf("Shorted Array is:\n");
	Quick_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}	
}
