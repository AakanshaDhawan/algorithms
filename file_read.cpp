#include<iostream>
#include<fstream>
using namespace std;
void merge_sort(int arr[],int p,int r)
{  int q;
	if(p<r)
	{
		q=(p+r)/2;
		merge_sort(arr,p,q);
		merge_sort(arr,q+1,r);
	}
	merge(arr,p,q,r);
}
int* merge(int arr[],int p,int q,int r)
{
	int n1=q-p+1,i,j,k;
	int n2=r-q;
	int arr1[n1+1],arr2[n2+1];
	for(i=1;i<=n1;i++)
	{
		arr1[i]=arr[p+i-1];
	}
	for(j=1;j<=n2;j++)
	{
		arr2[i]=arr[q+j];
	}
	arr1[n1+1]=32000;
	arr1[n2+1]=32000;
	i=1;j=1;
	for(k=p;k<=r;k++)
	{
		if(arr1[i]<=arr2[j])
		{
			arr[k]=arr1[i];
			i++;
		}
	    else 
	    {
			arr[k]=arr1[j];
			j++;
		}
	     
	}
	return arr;
}
int main()
{
	ifstream ifs;
	ifs.open("input.txt");
	int ar[1000],i=1,j,k;
	if(!ifs)
	{
		cout<<"no such file exists";
	}
	while(!ifs.eof())
    {
        ifs >> ar[i];
        cout<<ar[i];
        i++;
    }
    for(j=0;j<i;j++)
    {
    	cout<<ar[j];
	}
    
    return 0;
}
