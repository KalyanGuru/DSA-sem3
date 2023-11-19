#include<stdio.h>
#include<limits.h>
void parenthesizing(int d[100],int a)
{
	int m[100][100],s[100][100],i,j,k,l,q;
	for(i=1;i<=a;i++)
	{
		m[i][i]=0;
	}
	for(l=2;l<=a;l++)
	{
		for(i=1;i<=a-l+1;i++)
		{
			j=i+l-1;
			m[i][j]=INT_MAX;
			for(k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+(d[i-1]*d[k]*d[j]);
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("Minimum Scelar Multiplications:\n");
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			printf(" %d ",m[i][j]);
		}
		printf("\n");
	}
	printf("Optimal Split Points:\n");
	for(i=1;i<=a;i++)
	{
		for(j=1;j<=a;j++)
		{
			printf(" %d ",s[i][j]);
		}
		printf("\n");
	}
}
int main()
{
	int d[100],a,i;
	printf("Enter How Many Matrix You Want: ");
	scanf("%d",&a);
	for(i=1;i<=a;i++)
	{
		printf("Enter The Dimension of %d matrix",i);
		scanf("%d %d",&d[i-1],&d[i]);
	}
	parenthesizing(d,a);
}
