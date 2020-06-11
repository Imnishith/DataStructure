/*
* Maximum Sum Increasing Subsequence | DP-14
* Given an array of n positive integers. Write a program to find the sum of maximum sum subsequence 
* of the given array such that the integers in the subsequence are sorted in increasing order. 
* For example, if input is {1, 101, 2, 3, 100, 4, 5}, then output should be 106 (1 + 2 + 3 + 100)
* ,if the input array is {3, 4, 5, 10}, then output should be 22 (3 + 4 + 5 + 10) and if the 
* input array is {10, 5, 4, 3}, then output should be 10
* 
* Solution: a = {1,101,2,3,100,4,5}, length of array = n
* 1) Create msis[] of size of n.This array will hold max_Sum_increasing_subsequence for each index i
* 2) For i=0, msis[0] will be a[0];
* 3) For i=1,i<n increment i by 1 on each iteration
*		msis[i] = a[i];
*		For j=0,j<i increment j by 1 on each iteration
*			if(a[j]<a[i])
*			msis[i] = msis[i] + msis[j];
* 4) Seatch max value within msis[] array   
* Time Complexity : O(n2)
*/
#include<math.h>
#include<stdio.h>
#include<string.h>
void print_array(unsigned int *array,unsigned int len);

void max_sum_subsequence(unsigned int *a,unsigned int n);

void max_sum_subsequence(unsigned int *a,unsigned int n)
{
	unsigned int msis[n];
	unsigned int maxsum=0;
	int i,j;
	i=j=-1;
	memset(msis,0,sizeof(msis));
	msis[0] = a[0];
	maxsum = a[0];
	for(i=1;i<n;i++)
	{
		msis[i] = a[i];
		for(j=0;j<i;j++)
		{
			if( (a[j]<=a[i]) && (msis[i]<(a[i]+msis[j])) )
			{
				msis[i] = a[i]+msis[j];
			}
		}
		//printf("msis[%d] = %u\n",i,msis[i]);
		if(maxsum<msis[i])
		{
			maxsum = msis[i];
		}
	}
	printf("Answer : %u\n",maxsum);
}


void print_array(unsigned int *array,unsigned int len)
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
    unsigned int array[] = {1, 101, 2, 3, 100, 4, 5};
    //unsigned int array[] = {3,4,5,10};
    //unsigned int array[] = {100,3,6,105,110};
    //unsigned int array[] = {10,5,4,3};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    //unsigned int key=6;
    printf("Original array is : ");
    print_array(array,len);
	max_sum_subsequence(array,len);
    printf("# Time Complexity O(n2)\n");
}
