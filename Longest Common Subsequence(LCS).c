#include<stdio.h>
#include<math.h>
#include<string.h>
int max(int a,int b)
{
	return ((a+b)+abs(a-b))/2;
}
int lcs(char *a,char *b)
{
	int i,j,l,s,lcs[50][50];
	s=strlen(a);
	l=strlen(b);
	if(l>=s)
	{
		for(i=0;i<=s;i++)
		{
			lcs[i][0]=0;
		}
		for(j=0;j<=l;j++)
		{
			lcs[0][j]=0;
		}
		for(i=1;i<=s;i++)
		{
			for(j=1;j<=l;j++)
			{
				if(a[i-1]==b[j-1])
				{
					lcs[i][j]=1+lcs[i-1][j-1];
				}
				else
				   lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		printf("LCS array:\n");
		for(i=0;i<=s;i++)
		{
			for(j=0;j<=l;j++)
			{
				printf("%d    ",lcs[i][j]);
		    }
		    printf("\n");
	    }
	    return lcs[s][l];
	}
	else
	{
		for(i=0;i<=l;i++)
		{
			lcs[i][0]=0;
		}
		for(j=0;j<=s;j++)
		{
			lcs[0][j]=0;
		}
		for(i=1;i<=l;i++)
		{
			for(j=1;j<=s;j++)
			{
				if(b[i-1]==a[j-1])
				{
					lcs[i][j]=1+lcs[i-1][j-1];
				}
				else
				   lcs[i][j]=max(lcs[i-1][j],lcs[i][j-1]);
			}
		}
		printf("\nLCS array:\n");
		for(i=0;i<=l;i++)
		{
			for(j=0;j<=s;j++)
			{
				printf("%d    ",lcs[i][j]);
		    }
		    printf("\n");
	    }
	    return lcs[l][s];
	}
}
int main()
{
	char a[50],b[50],len;
	printf("Enter the first string: ");
	scanf("%s",a);
	printf("You Entered '%s' as First String\n",a);
	printf("Enter the second string: ");
	scanf("%s",b);
	printf("You Entered '%s' as second String\n",b);
	printf("The length of longest commone subsequent is: %d",lcs(a,b));
}

