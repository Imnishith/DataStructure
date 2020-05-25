/*
* Find the smallest and second smallest elements in an array
* Solution:
* 1) Take two variable smallest and second_smallest
* 2) Run through array variables and update smallest and second_smallest variable value
* Time Complexity : O(n)
*
*/

#include<stdio.h>

void print_array(int *array,unsigned int len);

void smallest_secondsmallest(int *array,unsigned int len);

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

void smallest_secondsmallest(int *array,unsigned int len)
{
	int smallest = 0;
	int second_smallest = 0;
	int i;
	if(len<2)
	{
		printf("Array size incomplete\n");
		return;
	}
	smallest = array[0];
	if(smallest > array[1])
	{
		second_smallest = smallest;
		smallest = array[1];
	}
	else
	{
		second_smallest = array[1];
	}
    //int array[] = {12, 13, 1, 10, 34, 1};
	for(i=2;i<len;i++)
	{
		if(array[i] < smallest)
		{
			second_smallest = smallest;
			smallest = array[i];
		}
		else
		{
			if((array[i] < second_smallest) && (array[i] != smallest))
			{
				second_smallest = array[i];
			}
		}
	}
	printf("Smallest : %d, Second Smallest : %d\n",smallest,second_smallest);	
}


int main()
{
    int array[] = {12, 13, 1, 10, 34, 1};
    unsigned int len = sizeof(array)/sizeof(array[0]);
    printf("Original array is : ");
    print_array(array,len);
    smallest_secondsmallest(array,len);
    printf("# Time Complexity O(n)\n");
}

