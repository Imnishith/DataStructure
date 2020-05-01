// Program to rotate an array by 
// d elements

#include<stdio.h>

void rotate_array(int *array,unsigned int d,unsigned int len);

int main()
{
	int array[] = {1,2,3,4,5,6,7};
	unsigned int i,d;
	d=2;
	unsigned int len = sizeof(array)/sizeof(array[0]);
	
	printf("\n# Original Array\n");
	for(i=0;i<len;i++)
	{
		printf("%d ",array[i]);		
	}
	printf("\n");
	
	printf("#After %d rotation\n",d);
	rotate_array(array,d,len-1);
	for(i=0;i<len;i++)
	{
		printf("%d ",array[i]);		
	}
	printf("\n");
	printf("#Time Complexity O(n*d)\n");
	
	printf("\n");
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
		
		// {1,2,3,4,5}
    	// 1) Store first element in temp
    	// 2) Shift each element towards left
    	// 3) last element will be replaced with temp
		temp = array[0];
		for(j=0;j<len;j++)
		{
			array[j] = array[j+1];
		}
		array[j] = temp;
	}
}
