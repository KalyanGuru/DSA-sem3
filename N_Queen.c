#include<stdio.h>

int board[50];
int col[50];
int ld[50];
int rd[50];
int count=0;
void disply(int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		printf("%d",board[i]);
	}
	printf("\n");
}
void place_queen(int n,int i)
{
	int j;
	for(j=1;j<=n;j++)
	{
		if(col[j]==0&&ld[i+n-j]==0&&rd[i+j-1]==0)
		{
			board[i]=j;
			col[j]=1;
			ld[i+n-j]=1;
			rd[i+j-1]=1;
			if(i==n)
			{
				count=count+1;
				printf("Solution Number: %d\n",count);
				disply(n);
			}
			else
			{
			   place_queen(n,i+1);	
			}
			col[j]=0,ld[i+n-j]=0,rd[i+j-1]=0;
		}
	}
}
int main()
{
	int num;
	printf("Enter The number of Queens you Want: ");
	scanf("%d",&num);
	place_queen(num,1);
}
