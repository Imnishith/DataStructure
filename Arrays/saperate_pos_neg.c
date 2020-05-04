/*
* Rearrange positive and negative numbers in O(n) time and O(1) extra space
* An array contains both positive and negative numbers in random order. Rearrange the array elements so 
* that positive and negative numbers are placed alternatively. Number of positive and negative numbers 
* need not be equal. If there are more positive numbers they appear at the end of the array. 
* Iaperate_pos_neg there are more negative numbers, they too appear in the end of the array.
*
* For example, if the input array is [-1, 2, -3, 4, 5, 6, -7, 8, 9], then the output should be [9, -7, 8, -3, 5, -1, 2, 4, 6]
* step 1: Saperate positive and negative numbers
* step 2: Swap pos/negative number
* Time Complexity O(2n) ==> O(n)
*/
#include<stdio.h>
void print_array(int *array,unsigned int len);
void saperate_pos_neg(int *array,unsigned int len);
void swap(int *ch1,int *ch2);

void saperate_pos_neg(int *array,unsigned int len)
{
	int i,j,pos,neg;
	i=j=pos=neg=-1;
	for(i=0;i<len;i++)
	{
		if(array[i]<0)
		{
			j++;
			swap(&array[i],&array[j]);
		}
	}
	print_array(array,len);
	//{-1,2,-3,4,5,6,-7,8,9}
	//After saperation
	//{-1,-3-7,4,5,6,2,8,9}

	/*j+1 position hold starting index of positive number and 
	* 0th index holds the starting point for negative number
	* step 1:  
	*/
	pos = j+1;
	neg = 0;
	while( (neg<pos) && (pos<len) && (array[neg]<0))
	{
		swap(&array[pos],&array[neg]);
		neg+=2;
		pos++;
	}
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
    int array[] = {-1, 2, -3, 4, 5, 6, -7, 8, 9};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    print_array(array,len);
    saperate_pos_neg(array,len);
    print_array(array,len);
    printf("# Time Complexity O(2n)\n");
}



