/*
* Minimum swaps required to bring all elements less than or equal to k together
* Given an array of n positive integers and a number k. Find the minimum number of swaps required to 
* bring all the numbers less than or equal to k together.
* Input:  arr[] = {2, 1, 5, 6, 3}, k = 3
* Output: 1
*
* Explanation: 
* To bring elements 2, 1, 3 together, swap element '5' with '3' such that final array will be- &arr[] = {2, 1, 3, 6, 5}
* Input:  arr[] = {2, 7, 9, 5, 8, 7, 4}, k = 5
* Output: 2
* Solution:
* step 1: Traverse array element one by one
* step 2: If element <=K swap with >0 element index
* Time complexity : O(n)
*/

#include<stdio.h>

int total_swaps(int *array,unsigned int len,int k);
void swap(int *ch1,int *ch2);
void print_array(int *array,unsigned int len);


int total_swaps(int *array,unsigned int len,int k)
{
	//{2,1,5,6,3}
	int i,j;
	i=j=-1;
	int swaps=0;
	for(i=0;i<len;i++)
	{
		if(array[i]<=k)
		{
			j++;
			if(i!=j)
			{
				swaps++;
				swap(&array[i],&array[j]);
			}
		}
	}
	print_array(array,len);	
	return swaps;
}

void swap(int *ch1,int *ch2)
{
    int temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
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
	int k=-1;
    int array[] = {2, 7, 9, 5, 8, 7, 4};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
	k=5;
    printf("%d ",total_swaps(array,len,k));
    printf("# Time Complexity O(n)\n");
}

