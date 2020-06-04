/*
* Find the subarray with least average 
* Given an array arr[] of size n and integer k such that k <= n. 
*
* Solution: arr = {3, 7, 90, 20, 10, 50, 40}, k =3
* 1) take index=0, sum = a[0]+a[1]+a[2], mini_index = 0, minisum=0
* 2) Traverse from i=3 to i=n. For each i, sum = (sum-a[index]+a[i]).Compare and update mini_index if minisum>sum
* Time Complexity : O(n)
*/

#include<stdio.h>

void print_array(int *array,unsigned int len);
void find_subarr_leastavg(int *array,unsigned int len, unsigned int k);

void find_subarr_leastavg(int *a,unsigned int len, unsigned int k)
{
	if(a == NULL) return;
	int index = 0;
	int mini_index = index;
	int sum = a[0]+a[1]+a[2];
	int mini_sum = sum;
	int j=-1;
	for(j=3;j<len;j++)
	{
		sum = sum - a[index] + a[j];
		if (sum < mini_sum)
		{
			//printf("sum : %d index = %d\n",sum,index);
			mini_sum = sum;
			mini_index = index+1;
		}
		index++;
	}
	printf("minisum = %d, minimum index = [%d,%d]\n",mini_sum,mini_index,(mini_index+k-1));
		
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
    int array[] = {3, 7, 5, 20, -10, 0, 12};
    unsigned int k=2;
    unsigned int len = sizeof(array)/sizeof(array[0]);
    //unsigned int key=6;
    printf("Original array is : ");
    print_array(array,len);
    find_subarr_leastavg(array,len,k);
    printf("# Time Complexity O(n2)\n");
}

