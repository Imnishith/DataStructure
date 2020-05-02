/* 
* Search an element in a sorted and rotated array
* An element in a sorted array can be found in O(log n) time via binary search. 
* But suppose we rotate an ascending order sorted array* at some pivot unknown to you beforehand.
* So for instance, 1 2 3 4 5 might become 3 4 5 1 2. Devise a way to find an element in the * rotated array in O(log n) time 
* Thought:
* Here array is sorted and/or rotated.
* case 1: For sorted array,using binary search we can search any elemenet within O(logn) time.
* case 2: For sorted and rotated array also we can apply binary search with some condition.
* For Ex. arr={3,4,5,6,1,2} is sorted and rotated (i.e. by two place) array and we want to check if Key=2 available
* step 1: For sorted/rotated array, first is to find pivot point (i.e. point after which array is rotated).
* In our example if you look carefully element "6" is the pivot point.Following are properties of "pivot" point
* 1) Element after pivot point will be less than the pivot point OR
* 2) pivot point value will be higher than its coming element
* step 2: Once pivot point identified compare if pivot value>key Or pivot value<key.
* step 3: if pivot point<key && start point value>key,apply binary search in (pivot+1,end)
* step 4: otherwise apply binary search in (start,pivot-1)
* Time Complexity : 0(logn)
*/

#include<stdio.h>

int binsearch(int *array,unsigned int start,unsigned int end,int key);
int search_sorted_rotated_array(int *array,unsigned int start,unsigned int end,int key);
int find_pivot(int *array,unsigned int start,unsigned int end);
void print_array(int *array,unsigned int len);


int search_sorted_rotated_array(int *array,unsigned int start,unsigned int end,int key)
{
	int pivot=-1;
	int index=-1;
	pivot=find_pivot(array,start,end);
	printf("pivot = %d\n",pivot);
	if(pivot == -1)
	{
		printf("Array not rotated,apply binsearch rightaway\n");
		index=binsearch(array,start,end,key);
		return index;
	}
	else
	{
		if(array[start] > key)
		{
			index = binsearch(array,pivot+1,end,key);
			return index;
		}
		else
		{
			index = binsearch(array,start,pivot,key);
			return index;
		}
	}
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

int binsearch(int *array,unsigned int start,unsigned int end,int key)
{
	int middle=-1;
	middle = (start+end)/2;
	if(start>end)
	{
		return -1;
	}
	if(array[middle]==key)
	{
		return middle;
	}
	if(array[middle]>key && array[start]<=key)
	{
		return binsearch(array,start,middle-1,key);
	}
	if(array[middle]<key && array[end]>=key)
	{
		return binsearch(array,middle+1,end,key);
	}
	return -1;
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

int main()
{
	int array[] = {10,11,12,13,1,2,3,4,5,6,7};
	unsigned int len = sizeof(array)/sizeof(array[0]);
	print_array(array,len);
	int key=15;
	int index=-1;
	printf("Search for element :%d\n",key);
	index = search_sorted_rotated_array(array,0,len-1,key);
	if(index != -1)
		printf("Found, Index : %d\n",index);
	else
	printf("Not found\n");
	printf("# Time Complexity O(logn)\n");
}
