/*
* Arrange given numbers to form the biggest number
* Given an array of numbers, arrange them in a way that yields the largest value. For example, if the given 
* numbers are {54, 546, 548, 60}, the arrangement 6054854654 gives the largest value. And if the 
* given numbers are {1, 34, 3, 98, 9, 76, 45, 4}, then the arrangement 998764543431 gives the largest value.
* 
* Solution: a=(54,546,548,60)
* This example of classic "Comparition based sorting". For ex. in bubble sort we swap element only if
* current element greater than immidiate next element. Here in this case as well we can apply
* bubble sort with condition as for current X and immidiate element Y. Swap only if YX > XY.
* step 1: For example array swap 54,546 as 54654>54546 and simillart swap 54,548 as 54843>54548 and same for 6054>5460
* step 2: At end of step 1, array format will be a={546,548,60,54}. Do same operation for all other elements as well
* step 3: At end of step1/step2, the array will rearranged as a = {60,548,546,54} and we can print number from i=0 to 
* i<n and get the answer
* Time Complexity O(n2)
*/

#include<stdio.h>
#include<stdbool.h>
#include<math.h>

void swap(unsigned int *ch1,unsigned int *ch2);
void print_array(unsigned int *array,unsigned int len);
bool checkifswapneeded(unsigned int x,unsigned int y);
void bubblesortoncomparition(unsigned int *array,unsigned int len);


void bubblesortoncomparition(unsigned int *array,unsigned int len)
{
    //unsigned int array[] = {2, 7, 9, 5, 8, 7, 4};
	int i,j,k;
	i=j=k=-1;
	k = len;
	for(i=0;i<len;i++)
	{
		for(j=0;j<k-1;j++)
		{
			//printf("Y = %u Y = %u ",array[j],array[j+1]);
			if(checkifswapneeded(array[j],array[j+1]) == true)
			{
				swap(&array[j],&array[j+1]);
			}
		}
		k--;
	}
	printf("Biggest number is : ");
	print_array(array,len);
}


bool checkifswapneeded(unsigned int x,unsigned int y)
{
	//X=54,Y=546;
	unsigned int xdigits=x;
	unsigned int ydigits=y;
	unsigned int count=0;
	while(xdigits!=0)
	{
		count++;
		xdigits = xdigits/10;
	}
    xdigits = count;
	count=0;
	//printf("xdigits = %d, ydigits = %d ",xdigits,ydigits);
	while(ydigits!=0)
	{
		count++;
		//printf("count : %d ",count);
		ydigits = ydigits/10;
	}
    ydigits = count;
	//printf("xdigits = %d, ydigits = %d ",xdigits,ydigits);
	unsigned long int xy = (unsigned long) (x*pow(10,ydigits) + y);
	unsigned long int yx = (unsigned long) (y*pow(10,xdigits) + x);
	//printf("XY = %ld YX = %ld\n",xy,yx);
	if(yx>xy) return true;
	return false;
}


void swap(unsigned int *ch1,unsigned int *ch2)
{
    unsigned int temp;
    temp = *ch1;
    *ch1 = *ch2;
    *ch2 = temp;
}
void print_array(unsigned int *array,unsigned int len)
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
    unsigned int array[] = {1, 34, 3, 98, 9, 76, 45, 4};
    unsigned int len = sizeof(array)/sizeof(array[0]);
	printf("Original array is : ");
    print_array(array,len);
	bubblesortoncomparition(array,len);
    printf("# Time Complexity O(n2)\n");
}

