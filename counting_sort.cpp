#include<iostream>
#include<fstream>
using namespace std;
 void counting (int *arr, int length) {
    int i, j, k;

    for (i = 0; i < length; i++) {
      if (arr[i] >= 100) {
        return;
      }
    }

    int *count_arr = new int[100]();
    int *sorted_arr = new int[length]();
    for (i = 0; i < length; i++) {
      count_arr[arr[i]]++;
    }
 
    for (k = 1; k < 100; k++) {
      count_arr[k] += count_arr[k-1];
    }

    for (j = length; j > 0; j--) {
      sorted_arr[count_arr[arr[j-1]]-1] = arr[j-1];
       count_arr[arr[j-1]]--;
    }

    for (j = 0; j < length; j++) {
      arr[j] = sorted_arr[j];
    }
    for (j = 0; j < length; j++) {
      cout<<arr[j]<<" ";
    }

    delete[] count_arr;
    delete[] sorted_arr;
  }
int main()
{
	
   ifstream ifs;
	ifs.open("input.txt");
	int ar[1000],i=1,j,k,key,p[6],l;
	if(!ifs)
	{
		cout<<"no such file exists";
	}
	while(!ifs.eof())
    {
        ifs >> ar[i];
        i++;
    }
      counting(ar,i);  
   return 0;
}
