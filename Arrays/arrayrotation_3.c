/* 
* Reversal algorithm for right rotation of an array
* Input: arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10} k = 3
* Output: 8 9 10 1 2 3 4 5 6 7
* Input: arr[] = {121, 232, 33, 43 ,5} k = 2
* Output: 43 5 121 232 33
* Solution:
* step 1: Store last element as "temp" variable
* step 2: shift every element one position right.Copy "temp" variable at first position
* step 3: Do same operation for k times
* Time Complexity : 0(n*k)
*/

#include<stdio.h>

void rotate_array(int *array,unsigned int d,unsigned int len);
void print_array(int *array,unsigned int len);


void rotate_array(int *array,unsigned int k,unsigned int len)
{
	int i,j,temp;
	i=j=temp=-1;
	if(array == NULL)
	{
		return;
	}
	for(i=0;i<k;i++)
	{
		temp=array[len];
		for(j=len;j>0;j--)
		{
		
			array[j] = array[j-1];
		}
		array[j]=temp;
	}
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
	int array[] = {1,2,3,4,5,6,7,8,9,10};
	unsigned int k=3;
	unsigned int len = sizeof(array)/sizeof(array[0]);
	print_array(array,len);
	rotate_array(array,k,len-1);
	print_array(array,len);
	printf("# Time Complexity O(n)\n");
}
