#include<stdio.h>
#include<stdlib.h>
long int* quicksort(long int*x1, int p, int q, int r);
long int *partition(long int *x1, int p, int q, int r);
int main()
{
	int size,i;
	printf("enter the no. of elements\n");
	scanf("%d",&size);
	long int*primary;
	primary=(long int*)malloc(size*sizeof(long int));
	printf("enter the elements\n");
	for(i=0;i<size;i++)
	{
		printf("enter %d element-->",(i+1));
		scanf("%ld",&primary[i]);
	}	
	quicksort(primary, 0,0,size-1);// here value of q has been passed as 0(a DUD)//
	for(i=0;i<size;i++)
		printf("%ld\n",primary[i]);
	return 0;
}
long int* quicksort(long int *x1, int p, int q,int r)
{
	if(p<r)
	{
		q=partition(x1,p,q,r);
		quicksort(x1,p,q,q-1);
		quicksort(x1,q+1,q,r);
	}
}
long int* partition(long int *x1, int p,int q,int r)
{
	long int pivot,i,j,temp1,temp2;
	pivot=x1[r];
	i=p-1;
	for(j=p;j<=r-1;j++)
	{
		if(x1[j]>pivot)
		{
			i=i+1;
			temp1=x1[j];
			x1[j]=x1[i];
			x1[i]=temp1;
		}
	}
	temp2=x1[i+1];
	x1[i+1]=x1[r];
	x1[r]=temp2;
	return(i+1);
}
