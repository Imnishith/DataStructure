/*
* Rearrange an array such that arr[i] = i
* Given an array of elements of length N, ranging from 0 to N – 1. All elements may not be present in the array. 
* If element is not present then there will be -1 present in the array. Rearrange the array such that 
* A[i] = i and if i is not present, display -1 at that place.
* Input : arr = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1}
* Output : [-1, 1, 2, 3, 4, -1, 6, -1, -1, 9]
* Input : arr = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
*               11, 10, 9, 5, 13, 16, 2, 14, 17, 4}
* Output : [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 
*         11, 12, 13, 14, 15, 16, 17, 18, 19]
* Solution:
* This problem can be solved in O(n) using following steps
* step 1: Travel array from 0 to n
* step 2: Check if index or array and value matches (i.e. a[i] == i).If matches no need to do anything OR else if value is '-1'
  do not perform any operation
* step 3: In case index and value does not match replace element with its corrosponding index (i.e. if (a[i] != i) replace a[i] with a[a[i]]  
*/

#include<stdio.h>

int suffle_arr(int *a,int count);
void print_array(int *array,unsigned int len);

int suffle_arr(int *a,int count)
{
	int i,j,temp1,temp2;
	if(a == NULL) return -1;
	for(i=0;i<count;i++) 
	{
		if(a[i] !=-1)
		{
			if(a[i] !=i) 
			{ 
				temp1=a[i];
				temp2=a[temp1];
				a[temp1]=temp1;
				a[i]=temp2; 
			} 
		} 
	} 
	return 0;
}

void print_array(int *array,unsigned int len)
{
    unsigned int i=0;
    for(i=0;i<len;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}

int main()
{
    //int array[] = {-1, -1, 6, 1, 9, 3, 2, -1, 4, -1};
    int array[] = {19, 7, 0, 3, 18, 15, 12, 6, 1, 8,
              11, 10, 9, 5, 13, 16, 2, 14, 17, 4};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
    suffle_arr(array,len);
    print_array(array,len);
    printf("# Time Complexity O(n)\n");
}

