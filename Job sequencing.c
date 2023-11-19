#include<stdio.h>
#include<stdlib.h>

typedef struct job
{
	int no;
	int pro;
	int ded;
}job;

void sort(job* jobarray, int n)
{
	job key;
	int i,j;
	for(i=2;i<=n;i++)
	{
		key=jobarray[i];
		for (j=i-1;j>=1 && jobarray[j].pro<key.pro;j--)
       {
          jobarray[j+1]=jobarray[j];
       }
       jobarray[j+1]=key;
	}
}
void job_scheduling(job* jobarray,int n, int max)
{
	int sequ[max],j,i,total_pro=0;
	for(i=1;i<=max;i++)
	{
		sequ[i]=-1;
	}
	for(i=1;i<=n;i++)
	{
		j=jobarray[i].ded;
		while(j>=1)
		{
			if(sequ[j]==-1)
			{
				sequ[j]=jobarray[i].no;
				total_pro=total_pro+jobarray[i].pro;
				break;
			}
			j=j-1;
		}
	}
	printf("Scheduled Jobs will be:\n");
	for(i=1;i<=max;i++)
	{
		printf("Job%d   ",sequ[i]);
	}
	printf("\nTotal profit is: %d",total_pro);
}
int main()
{
	int n,i;
	printf("Enter the number of jobs: ");
	scanf("%d",&n);
	job* jobarray=(job*)malloc(n*sizeof(job));
	for(i=1;i<=n;i++)
	{
		printf("Enter the job number: ");
		scanf("%d",&jobarray[i].no);
		printf("Enter the profit of this job: ");
		scanf("%d",&jobarray[i].pro);
		printf("Enter the deadline of this job: ");
		scanf("%d",&jobarray[i].ded);
	}
	for(i=1;i<=n;i++)
	{
		printf("%d   %d   %d",jobarray[i].no,jobarray[i].pro,jobarray[i].ded);
        printf("\n");
	}
	int max=0;
	for(i=1;i<=n;i++)
	{
		if(max<jobarray[i].ded)
		   max=jobarray[i].ded;
	}
	sort(jobarray,n);
	printf("\nSorted Job(In decreasing order of Profit)\n");
	for(i=1;i<=n;i++)
	{
		printf("%d   %d   %d",jobarray[i].no,jobarray[i].pro,jobarray[i].ded);
        printf("\n");
	}
	printf("Maximum deadline is: %d\n",max);
	job_scheduling(jobarray,n,max);
	free(jobarray);
}
