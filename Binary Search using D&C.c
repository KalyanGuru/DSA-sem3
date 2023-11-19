#include<stdio.h>
int binary_search(int l,int h,int key,int a[])
{
	if(l==h)
	{
		if(a[l]==key)
		    return l;
		else 
		   return -1;    
	}
	else
	{
		int mid=(l+h)/2;
		if(a[mid]==key)
		{
			return mid;
		}
		else if(key<a[mid])
		{
			binary_search(l,mid-1,key,a);
		}
		else
		{
			binary_search(mid+1,h,key,a);
		}
	}
}
int main()
{
	int i,n,a[100],key,pos;
	printf("Enter the how many elements you want to put: ");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("Enter the %d number of data: ",i);
		scanf("%d",&a[i]);
	}
	printf("Enter the number you want to find: ");
	scanf("%d",&key);
	pos=binary_search(1,n,key,a);
	if(pos==-1)
		printf("Entered number is not found.");
	else
	    printf("Entered data %d found in %d position.",key,pos);
	
}
