/*
* Double the first element and move zero to end
* Given an array of integers of size n. Assume ‘0’ as invalid number and all other as valid number. 
* Convert the array in such a way that if next number is a valid number and same as current number, double 
* its value and replace the next number with 0. After the modification, rearrange the array such that all 0’s 
* are shifted to the end.
* Input : arr[] = {2, 2, 0, 4, 0, 8}
* Output : 4 4 8 0 0 0
* Input : arr[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8}
* Output :  4 2 12 8 0 0 0 0 0 0
* Solution:
* This problem has two parts
* Part 1: for each i, double a[i] if a[i+1] !=0 && a[i] == a[i+1]. Under this case replace a[i+1] with Zero.For Ex.
* {2, 2, 0, 4, 0, 8} ==> for a[0], as a[i+1] same as a[i] and not zero we will double a[0] and replace a[i+1] with zero.
* We will do same operation for all other elements. At this point the array will = {4,0,0,4,0,8}
* Part 2: Move all zero towards end
* Time complexity : O(n)
*/

#include<stdio.h>

void swap(int *ch1,int *ch2);
void doublefirst_movezeros(int *array,unsigned int len);
void print_array(int *array,unsigned int len);


void doublefirst_movezeros(int *a,unsigned int len)
{
	//{2, 2, 0, 4, 0, 8}
	int i,j;
	i=j=-1;
	for(i=0;i<len;i++)
	{
		if(a[i] != 0)
		{
			if((a[i] == a[i+1]) && ((i+1)<len))
			{
				a[i] *=2;
				a[i+1] = 0;
			}
			j++;
			if(i!=j)
			swap(&a[i],&a[j]);
		} 
	}
	print_array(a,len);	
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
    int array[] = {0, 2, 2, 2, 0, 6, 6, 0, 0, 8};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
    doublefirst_movezeros(array,len);
    printf("# Time Complexity O(n)\n");
}

