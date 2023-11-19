#include<stdio.h>
void merge(int a[],int l,int m,int h)
{
	int i,j,k,aux[100];
	i=l,j=m+1,k=l;
	while(i<=m&&j<=h)
	{
		if(a[i]<a[j])
			aux[k++]=a[i++];
		else
		    aux[k++]=a[j++];   
	}
	while(j<=h)
	{
		aux[k++]=a[j++];
	}
	while(i<=m)
	{
		aux[k++]=a[i++];
	}
	for(i=l;i<=h;i++)
	{
		a[i]=aux[i];
	}
}
void merge_sort(int a[],int l, int h)
{
	int m;
	if(l<h)
	{
		m=(h+l)/2;
		merge_sort(a,l,m);
		merge_sort(a,m+1,h);
		merge(a,l,m,h);
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
	merge_sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf(" %d ",a[i]);
	}
}
