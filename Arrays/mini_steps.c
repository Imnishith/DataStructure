/*
* Minimum number of jumps to reach end
* Given an array of integers where each element represents the max number of steps that can be made 
* forward from that element. Write a function to return the minimum number of jumps to reach the end
* of the array (starting from the first element). If an element is 0, then cannot move through that element.
* Solution:
* 1) Start from index i=1, a[i]
* 2) Verify all possible jumps i.e. i=1 to i=i+a[i]. if (i+a[i]>n) we hit the end or else switch to max value index
* Time Complexity : O(n2)
*/

#include <limits.h> 
#include <stdio.h>
#include <stdbool.h>

// Returns minimum number of jumps to reach arr[n-1] from arr[0] 
int minJumps(int arr[], int n) 
{
	int i,j;
	int jumps=1;
	bool b = false;
	int max=-1;
	int next_index=-1;
	
	if(n==1)
	{
		return 0;
	}
	//int arr[] = {1,1,1,1,1,1,1,1,1,1}; 
	printf("Jump Steps :  {");
	for(i=1;i<n;i=next_index)
	{
		printf("%d, ",arr[i]);
		max = arr[i];
		next_index =i+1;
		for(j=i+1;j<=arr[i];j++)
		{
			if(max <= arr[j])
			{
				next_index = j;
			}
			if((i+arr[j]) >= (n-1))
			{
				printf("%d, ",arr[j]);
				b = true;
				jumps++;
				break;
			}
		}
		jumps++;
		if( b == true || (next_index >= (n-1)) )
		{
			printf("%d}\n",arr[n-1]);
			break;
		}
	}
	return jumps;
}

void print_array(int *array,unsigned int len)
{
    unsigned int i=0;
    printf("{");
    for(i=0;i<len;i++)
    {
        printf("%d,",array[i]);
    }
    printf("\b}\n");
}

// Driver program to test above function 
int main() 
{ 
	//int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}; 
	int arr[] = {1,1,1,1,1,1,1,1,1,1}; 
	int len = sizeof(arr) / sizeof(int); 
	printf("Original array is : ");
    print_array(arr,len);
	printf("Minimum number of jumps to reach end is %d\n", minJumps(arr,len)); 
	return 0; 
} 

