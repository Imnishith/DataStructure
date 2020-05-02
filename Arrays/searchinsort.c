/* 
* Search an element in sorted array
* Binary Search
* Time Complexity : 0(logn)
*/

#include<stdio.h>

int binsearch_sortedarray(int *array,unsigned int start,unsigned int end,int key);
void print_array(int *array,unsigned int len);

int binsearch_sortedarray(int *array,unsigned int start,unsigned int end,int key)
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
		return binsearch_sortedarray(array,start,middle-1,key);
	}
	if(array[middle]<key && array[end]>=key)
	{
		return binsearch_sortedarray(array,middle+1,end,key);
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
	int array[] = {-2,-1,3,4,500,600,700};
	unsigned int len = sizeof(array)/sizeof(array[0]);
	print_array(array,len);
	int key=-2;
	int index=-1;
	printf("Searching for element :%d\n",key);
	index = binsearch_sortedarray(array,0,len-1,key);
	if(index != -1)
		printf("Found, Index : %d\n",index);
	else
	printf("Not found\n");
	printf("# Time Complexity O(logn)\n");
}
