/* 
* Given a sorted and rotated array, find if there is a pair with a given sum
* Time Complexity : 0(logn)
* Given an array that is sorted and then rotated around an unknown point. Find if the array has a pair with a given sum ‘x’. It may
* be assumed that all elements in the array are distinct
* 
* Solution : Once we have sorted array For ex. arr = {1,2,3,4,5} we can apply following alogorithm to get the pair
* sum(arr[min],arr[max]) if sum > required decrement max index or else increment min index
* loop ends where min=max
* For Ex. arr={1,2,3,4,5}, sum=7;
* sum(a[0],a[4]) => 6>sim so increment min index
* sum(a[1],a[4]) => 7.. Found
* In our case as array is sorted and rotated we need to find min and max array index i.e.
* arr = {3,4,5,1,2}, Finding pivot point will provide max index and pivot+1 index will be minimam index point
* 
* Time Complexity
* Finding Pivot point : O(logn)
* Finding pair : O(n)
*/

#include<stdio.h>
#include<stdbool.h>

int binsearch(int *array,unsigned int start,unsigned int end,int key);
int findpair_sorted_rotated_array(int *array,unsigned int start,unsigned int end,int key);
int find_pivot(int *array,unsigned int start,unsigned int end);
void print_array(int *array,unsigned int len);
int sum(int x,int y);
bool searchpair(int *array,unsigned int start,unsigned int end,int len,int key);


int findpair_sorted_rotated_array(int *array,unsigned int start,unsigned int end,int key)
{
	int max,min;
	int status=-1;
	max=min=-1;
	max=find_pivot(array,start,end);
	if(max == -1)
	{
		printf("Array already sorted\n");
		max = end;
		min = start;
	}	
	else
	{
		min = (max+1)%end;
	}
	if(searchpair(array,min,max,end+1,key) == true)
	{
		printf("Found..\n");
		status = 0;
	}
	else
	{
		printf("Not Found..\n");
		status = -1;
	}
	return status;
}


bool searchpair(int *array,unsigned int start,unsigned int end,int len,int key)
{
	bool ret = false;
	int total = 0;
	int min=start;
	int max=end;
	if(key>array[max] || key<array[min])
	{
		return false;
	}
	while(1)
	{
		if(min == max) break;
		total = sum(array[min],array[max]);
		//printf("min = %d, max= %d sum = %d\n",min,max,total);
		if(total == key)
		{
			printf("Found. min =%d, max=%d\n",min,max);
			ret = true;
			break;
		}
		if(total>key)
		{
			if(max>0)
			max = max-1;
			else
			max = len-1;
		}
		else
		{
			min = (min+1)%len;
		}
	}
	return ret;
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
	int key=-1;
	
	unsigned int len = sizeof(array)/sizeof(array[0]);
	print_array(array,len);
	int index=-1;
	printf("Search for pair with sum :%d\n",key);
	findpair_sorted_rotated_array(array,0,len-1,key);
	printf("# Time Complexity for finding pivot O(logn)\n");
	printf("# Time Complexity for pair O(n)\n");
}
