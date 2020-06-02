/*
* Largest Sum Contiguous Subarray 
* Write an efficient program to find the sum of contiguous subarray within a one-dimensional array 
* of numbers which h* as the largest sum.
* Solution: array  = {-2,-3,4,-1,-2,1,5,4}
* 1) Starting from first index, increment index one by one and find maximan contigous sum for index first
* 2) Do same operation for index starting with two till n. Towards last largest_sum holds the answer
* Time Complexity : O(n2)
*/

#include<stdio.h>

#define MAX_NEG -32768
void sort(int *ksum,int k);
void swap(int *ch1,int *ch2);
void print_array(int *array,unsigned int len);
int larget_contiguous_sum_2(int *array,unsigned int len);
int larget_contiguous_sum(int *array,unsigned int len);
int max(int a,int b);


//O(n2) Method
int larget_contiguous_sum(int *array,unsigned int len)
{
	int largest_sum = MAX_NEG;
	int i,j;
	i=j=-1;
	if(array == NULL)
	{
		return;
	}
	for(i=0;i<(len-1);i++)
	{
		int temp = array[i];
		if(temp > largest_sum)
		{
			largest_sum = temp;
		}
		for(j=i+1;j<len;j++)
		{
			temp+=array[j];
			if(temp > largest_sum)
			{
				largest_sum = temp;
			}
		}
	}
	return largest_sum;
}

//O(n) Method
int larget_contiguous_sum_2(int *array,unsigned int len)
{
	//{-2,-3,4,-1,-2,1,5,-3};
	if(array == NULL)
	{
		return;
	}
	int i=-1;
	int start_index=0;
	int count=-1;
	int end_index = -1;
	int curr_max = array[0];
	int max_so_far = array[0];	
	for(i=0;i<len;i++)
	{
		curr_max = max(array[i],curr_max+array[i]);
		if(curr_max == array[i])
		{
			count=0;
			start_index = i;
		}
		if(curr_max > max_so_far)
		{
			end_index = i;
		}
		max_so_far = max(curr_max,max_so_far);
	}
	printf("Start index : %d, End index : %d\n",start_index,(end_index));
	return max_so_far;
}

int max(int a,int b)
{
	return (a>=b?a:b);
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
int main()
{
    int array[] = {-2,-3,4,-1,-2,1,5,-3};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    printf("Original array is : ");
    print_array(array,len);
	//printf("Final Largest Sum contiguous Subarray : %d \n",larget_contiguous_sum_2(array,len));
	printf("Final Largest Sum contiguous Subarray : %d \n",larget_contiguous_sum(array,len));
    printf("# Time Complexity O(n2)\n");
}

