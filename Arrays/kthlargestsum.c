/*
* K-th Largest Sum Contiguous Subarray
* Given an array of integers. Write a program to find the K-th largest sum of contiguous subarray 
* within the array of numbers which has negative and positive numbers.
* Input: a[] = {20, -5, -1},k = 3
* Output: 14
* Explanation: All sum of contiguous 
* subarrays are (20, 15, 14, -5, -6, -1) 
* so the 3rd largest sum is 14.
* Solution:
* 1) Take an temp array of temp[k] size
* 2) Start caculating contiguous some and update temp[k] array for top k contiguous Subarray sums
* 3) At the end temp[0] should be our answer 
* Time Complexity O(n2) + O(k2)
*
*/

#include<stdio.h>
#include<string.h>
#include<math.h>

void print_array(int *array,unsigned int len);
void capture_contiguoussum(int *a,unsigned int len,unsigned int k);
void swap(int *ch1,int *ch2);
void sort(int *ksum,int k);
void storetopksum(int *ksum,int k,int sum);

void capture_contiguoussum(int *a,unsigned int len,unsigned int k)
{
	//{20, -5, -1}
	int i,j=0;
	int cur,next;
	i=j=cur=next=-1;
	int ksum[k];
	memset(ksum,0,sizeof(ksum));	

	for(i=0;i<len;i++)
	{
		//printf("Contiguous Sum -- %d\n",a[i]);
		cur = a[i];
	 	storetopksum(ksum,k,cur);	
		next = cur;
		for(j=i+1;j<len;j++)
		{
			next += a[j];
			//printf("Contiguous Sum -- %d\n",next); 
	 		storetopksum(ksum,k,next);	
		}
		//printf("\n");
	}	
	printf("Kth smallest element %d\n",ksum[0]);
}

void sort(int *ksum,int k)
{
	int i,j,count;
	i=j=-1;
	count = k;
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<count-1;j++)
		{
			if(ksum[j]>ksum[j+1])
			swap(&ksum[j],&ksum[j+1]);
		}
	}
	//printf(" Sorted Array : ");
	//print_array(ksum,k);
}

void swap(int *ch1,int *ch2)
{
    int temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}

void storetopksum(int *ksum,int k,int sum)
{
	static int sortingstart = 0;
	int i,j;
	i=j=-1;

	/*
    * There is catch in this methord. If we don't have filled ksum[k] array it becomes difficult to sort
    * So first fill complete array and then do the sorting
    */
	if(sortingstart < k)
	{
		ksum[sortingstart] = sum;
		sortingstart++;
		if(sortingstart == k)
		sort(ksum,k);
		return;
	}
	if(sum < ksum[0])
	{
		//printf("No need to update\n");
		return;
	}
	else
	{
		ksum[0] = sum;
		sort(ksum,k);
	}	
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
    int array[] = {20, -5, -1};
    unsigned int key=3;
    //int array[] = {10, -10, 20, -40};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    //unsigned int key=6;
    printf("Original array is : ");
    print_array(array,len);
    capture_contiguoussum(array,len,key);
    printf("# Time Complexity O(n2)+O(k2)\n");
}

