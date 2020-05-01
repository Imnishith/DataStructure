// Program to rotate an array by 
// d elements

#include<stdio.h>

void rotate_array(int *array,unsigned int d,unsigned int len);
void print_array(int *array,unsigned int len);

int main()
{
	int array[] = {1,2,3,4,5,6,7};
	unsigned int i,d;
	unsigned int len = sizeof(array)/sizeof(array[0]);
	rotate_array(array,2,len);
	print_array(array,len);
	printf("#Time Complexity O(n*d)\n");
}

void rotate_array(int *array,unsigned int d,unsigned int len)
{
	unsigned int i,j;
	int temp=0;
	i=j=0;
	if(array == NULL)
	{
		return;
	}
	//Outer for loop will run for d times
	for(i=0;i<d;i++)
	{
    	// 1) Store first element in temp
    	// 2) Shift each element towards left
    	// 3) last element will be replaced with temp
		temp = array[0];
		for(j=0;j<len-1;j++)
		{
			array[j] = array[j+1];
		}
		array[j] = temp;
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
