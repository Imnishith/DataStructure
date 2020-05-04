/*
* Rearrange array such that arr[i] >= arr[j] if i is even and arr[i]<=arr[j] if i is odd and j < i
* Given an array of n elements. Our task is to write a program to rearrange the array such that elements 
* even positions are greater than all elements before it and elements at odd positions are less than all elements before it.
* Input : arr[] = {1, 2, 3, 4, 5, 6, 7}
* Output : 4 5 3 6 2 7 1
* Input : arr[] = {1, 2, 1, 4, 5, 6, 8, 8} 
* Output : 4 5 2 6 1 8 1 8
* Solution
* 1) Sort Array ( Here using bubble sort O(n2)) i.e. input a[] = {1,2,3,4,5}
* 2) Create output array of same size as input i.e. output a[5];
* 3) Traverse from last end (i.e. n-1 position). Start from last digit of input a[] and copy at last even index number 
* and continue doing it till first even index.Once that is done start from frist odd index number and continue same till
* last odd number output = (X,4,X,5,X} ==> (3,4,2,5,1} ==> Total time O(2n)
* 
*/
#include<stdio.h>
#include<string.h>

void print_array(int *array,unsigned int len);
void bubble_sort(int *a,int n);
void rearrange(int *a,int n);


void rearrange(int *a,int n)
{
	int i,j;
	i=j=-1;
	j=n-1;
	//{1,2,3,5,7}
	int temp[n];
	memset(temp,-1,sizeof(temp));
	for(i=(n-1);i>=0;i--)
	{
		if((i+1)%2 == 0)
		{
			temp[i] = a[j];
			j--;
		}
		if(i==0)
		{
			temp[i] = a[j];
			j--;
		}
	}
	for(i=1;i<n;i++)
	{
		if((i+1)%2 != 0)
		{
			temp[i] = a[j];
			j--;
		}
	}
	print_array(temp,n);
}

void bubble_sort(int *a,int n)
{
	//{5,2,7,1,3};
	int i,j,k,temp;
 	i=j=k=-1;
	if(a == NULL)
	{
		return;
	}
	k=n;
	for(i=0;i<n;i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
		k--;
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
	int array[] = {1, 2, 1, 4, 5, 6, 8, 8};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
    bubble_sort(array,len);
    print_array(array,len);
    rearrange(array,len);
    printf("# Time Complexity O(n*k)\n");
}
