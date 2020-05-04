/*
* Move all zeroes to end of array
* Given an array of random numbers, Push all the zero’s of a given array to the end of the array.
* For example, if the given arrays is {1, 9, 8, 4, 0, 0, 2, 7, 0, 6, 0}, it should be 
* changed to {1, 9, 8, 4, 2, 7, 6, 0, 0, 0, 0}. The order of all other elements should be same.
* Expected time complexity is O(n) and extra space is O(1).
*
* Solution:
* step 1: Traverse array element one by one
* step 2: If element !=0 swap with >0 element index
* Time complexity : O(n)
*/

#include<stdio.h>

void swap(int *ch1,int *ch2);
void print_array(int *array,unsigned int len);
void movezeros_atend(int *array,unsigned int len);


void movezeros_atend(int *array,unsigned int len)
{
	int i,j;
	i=j=-1;
	for(i=0;i<len;i++)
	{
		if(array[i] !=0)
		{
			j++;
			swap(&array[i],&array[j]);
		}
	}
	print_array(array,len);	
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
    int array[] = {1, 2, 0, 0, 0, 3, 6};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
    movezeros_atend(array,len);
    printf("# Time Complexity O(2n)\n");
}

