#include<stdio.h>
#include<stdlib.h>
long int* heapsort(long int*x1, int y);
long int* build_max_heap(long int*x1,int y);
long int* max_heapify(long int* x1, int y, int z);
int main()
{
	int i,size;
	printf("enter the no. of elements\n");
	scanf("%d",&size);
	long int*primary;
	primary=(long int*)malloc(size*sizeof(long int));
	printf("enter the elements-->>\n");
	for(i=0;i<size;i++)
	{ 
    	scanf("%ld",&primary[i]);
	}
	printf("\n");
	heapsort(primary,size-1);
	for(i=0;i<size;i++)
    	printf("%ld\n",primary[i]);
    return 0;
}
long int*heapsort(long int*x1,int y)
{
    int i,temp, heapsize;
    heapsize=y;
    build_max_heap(x1,y);
    for(i=y;i>=1;i--)
    {
    temp=x1[0];// exchange of first[[ that is the maximum element of the whole tree ]] and last [[ the minimum element of the whole tree]] //
    x1[0]=x1[i];
    x1[i]=temp;
    heapsize=heapsize-1;
           max_heapify(x1,heapsize,0);// always start from 1 and go to last level unless and untill max heap is build//
    }
}

long int* build_max_heap(long int*x1,int y)
{
   int i,heapsize;
    heapsize=y;
    for(i=(y/2);i>=0;i--)
    {
        max_heapify(x1,heapsize,i);
    }
}


long int*max_heapify(long int*x1, int y, int z)
{

    int left=2*z+1;
    int right=2*z+2;
    int largest;
    int temp;
    if(left<=y && x1[left]>x1[z])
    {
    largest=left;
    }
        else
            largest=z;
        if(right<=y && x1[right]>x1[largest])
        {
           largest=right;
        }
    if(largest!=z)
    {
     temp=x1[largest];
     x1[largest]=x1[z];
     x1[z]=temp;
     max_heapify(x1,y,largest);
    }
}
