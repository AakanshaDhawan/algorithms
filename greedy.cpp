#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int greedy_activity_selector_method(double** x, int* y, int z, int a);
int main()
{
	int i,n,k;
	double sum=0.0d;
	printf("enterno. of events\n");
	scanf("%d",&n);
	double** event=(double**)malloc(n*sizeof(double*));
	for(i=0;i<n;i++)
		event[i]=(double*)malloc(2*sizeof(double));
	int* solution=(int*)malloc(n*sizeof(int));
	int* temp=(int*)malloc(n*sizeof(int));
	int temp_c=0;
	for(i=0;i<n;i++)
		temp[i]=0;
	int random_event;
	printf("enter start time and end time of every event\n");
	for(i=0;i<n;i++)
	{
		printf("enter start time for event A%d:--> ",i+1);
		scanf("%lf",&event[i][0]);
		printf("enter finish time for event A%d:--->",i+1);
		scanf("%lf",&event[i][1]);
	}
	while(temp_c<n)
	{
		random_event=(int)(rand()%(n));		
		if(temp[random_event]==1)
			continue;
		else
		{
			temp_c++;
			temp[random_event]=1;
		    k= greedy_activity_selector_method(event,solution,n, random_event);
		    printf(" the result is according to event A%d\n",random_event+1);
		    printf("printing solution\n");
		    printf("<");
			for(i=0;i<=k;i++)
		 		printf("A%d,",solution[i]+1);
		 	printf("\b>\n");
			printf("total time consumed:-->");
			for(i=0;i<=k;i++)
				sum=sum+(event[solution[i]][1]-event[solution[i]][0]);
			printf(" %lf",sum);
		}
		sum=0.0d;
		printf("\n\n");
	}
	return 0;
  }
int greedy_activity_selector_method(double **x, int* y, int z, int a)
{
	int k=0,m=0,i;
 	int* temp=(int*)malloc(z*sizeof(int));
	y[k]=a;
 	i=a;
	for(m=0;m<z;m++)
 	{
	 	if(a==m)
	 	continue;
	 	if(x[m][0]>=x[i][1])
	 	{
	 		y[++k]=m;
	 		i=m;
	 	}
	}
	return k;
 }

