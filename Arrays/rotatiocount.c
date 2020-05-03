/* 
* Find the Rotation Count in Rotated Sorted array
* Consider an array of distinct numbers sorted in increasing order. The array has been rotated (clockwise) k number of times. 
* Given such an array, find the value of k.
* Input : arr[] = {15, 18, 2, 3, 6, 12}
* Output: 2
* Explanation : Initial array must be {2, 3,6, 12, 15, 18}. We get the given array after rotating the initial array twice.
* Input : arr[] = {7, 9, 11, 12, 5}
* Output: 4
* Input: arr[] = {7, 9, 11, 12, 15};
* Output: 0
* 
* Solution : If we look closely number of roation in sorted array is same as index of minimam element in a array
* In our case as array is sorted and rotated we need to find min array index.
* arr = {3,4,5,1,2}, Finding pivot point will provide max index and pivot+1 index will be minimam index point
* Time Complexity
* Finding Pivot point : O(logn)
* Finding Count : O(1)
*/

#include<stdio.h>
#include<stdbool.h>

int findrotation_countin_sorted_array(int *array,unsigned int start,unsigned int end);
int find_pivot(int *array,unsigned int start,unsigned int end);
void print_array(int *array,unsigned int len);


int findrotation_countin_sorted_array(int *array,unsigned int start,unsigned int end)
{
	int max_index,min_index;
	int status=-1;
	max_index=min_index=-1;
	max_index=find_pivot(array,start,end);
	if(max_index == -1)
	{
		printf("No roation in array");
		return 0;
	}
	else
	{
		return(max_index+1);
	}
	return status;
}

int find_pivot(int *array,unsigned int start,unsigned int end)
{
	int middle=-1;
	middle = (start+end)/2;
	if(start>end)
	{
		return -1;
	}
 	if((middle<end) && (array[middle]>array[middle+1]))
	{
		return middle;
	}
	if((middle>start) && (array[middle-1]>array[middle]))
	{
		return middle-1;
	}
	if(array[start]>=array[middle])
		return find_pivot(array,start,middle-1);
	else
		return find_pivot(array,middle+1,end);
}


void print_array(int *array,unsigned int len)
{
	printf("Array = {");
	unsigned int i=0;
	for(i=0;i<len;i++)
	{
		printf("%d,",array[i]);
	}
	printf("\b}\n");
}

int sum(int x,int y)
{
	return (x+y);
}


int main()
{
	int array[] = {10,11,12,13,1,2,3,4,5,6,7};
	unsigned int len = sizeof(array)/sizeof(array[0]);
	print_array(array,len);
	printf("Rotation count : %d\n",findrotation_countin_sorted_array(array,0,len-1));
	printf("# Time Complexity for O(logn)\n");
}
