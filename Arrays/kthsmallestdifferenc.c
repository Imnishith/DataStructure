/*
* k-th smallest absolute difference of two elements in an array
* We are given an array of size n containing positive integers. The absolute difference 
* between values at indices i and j is |a[i] – a[j]|. There are n*(n-1)/2 such pairs 
* and we are asked to print the kth (1 <= k <= n*(n-1)/2) smallest absolute difference among all these pairs.
*
* Solution:
* 1) Take one temparray of size temp[n*(n-1)/2]. 
* 2) Update temp array with all possible differences
* 3) Bubble sort temp array till kth position
*
*/

#include<stdio.h>
#include<string.h>

void sort(int *ksum,int k);
void swap(int *ch1,int *ch2);
void print_array(int *array,unsigned int len);

void kthsmallest_diff(int *array,unsigned int len,unsigned int k);
unsigned int mode_difference(int a,int b);


void kthsmallest_diff(int *array,unsigned int n,unsigned int k)
{
	//{1,2,3,4}
	//(1,2), (1,3), (1,4)
	//(2,3), (2,4)
	//(3,4)
	unsigned int i,j,count;
	unsigned int temp[(n*(n-1))/2];
	memset(temp,0,sizeof(temp));
	i=j=count=-1;
	for(i=0;i<(n-1);i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp[++count] = mode_difference(array[i],array[j]);
		}
	}
	sort(temp,(n*(n-1))/2);
	print_array(temp,(n*(n-1))/2);
	printf("kth smallest difference : %d\n",temp[k-1]);
}

unsigned int mode_difference(int a,int b)
{
	return (a>b?(a-b):(b-a));
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
    int array[] = {1, 2, 3, 4, 5, 1000};
    unsigned int k=5;
    unsigned int len = sizeof(array)/sizeof(array[0]);
    //unsigned int key=6;
    printf("Original array is : ");
    print_array(array,len);
	kthsmallest_diff(array,len,k);
    printf("# Time Complexity O(n2)+O(n2)\n");
}
