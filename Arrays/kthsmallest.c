/*
* K’th Smallest/Largest Element in Unsorted Array
* Given an array and a number k where k is smaller than size of array, we need to find 
* the k’th smallest element in the given array. It is given that ll array elements are distinct.
* 
* Input: arr[] = {7, 10, 4, 3, 20, 15}
* k = 3
* Output: 7
* Solution:
* Idea is to use bubble sorting alogorithm. In case of bubble sort, each traversal causes highest values
* valued element to be at last positing i.e. (n-1,n-2,n-3 and so on)
* Under this case we can run main loop for k times only and we can get answer in ko(n) time
*/

#include<stdio.h>


void swap(int *ch1,int *ch2);
int bubble_sortktime(int *array,unsigned int len,unsigned int key);
void print_array(int *array,unsigned int len);


int bubble_sortktime(int *a,unsigned int len,unsigned int key)
{
	int i,j,k;
	i=j=k=-1;
	k =len;
	for(i=0;i<key;i++)
	{
		for(j=0;j<k-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
			}
		}
		k--;
		
	}
	k = (len-key); 
	printf("Kth smallest element : %d\n",a[k]);
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
    //unsigned int array[] = {54, 546, 548, 60};
    int array[] = {1, 34, 3, 98, 9, 76, 45, 4};
    unsigned int len = sizeof(array)/sizeof(array[0]);
	unsigned int key=1;
    printf("Original array is : ");
    print_array(array,len);
    bubble_sortktime(array,len,key);
    printf("# Time Complexity nO(n)\n");
}
