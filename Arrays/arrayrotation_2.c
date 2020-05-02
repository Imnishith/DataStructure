/* 
* Program to rotate an array left/clockwise by d elements
* Methord 2 : Using Juggling algorithm
* Algorith : Read through following steps
* step 1: for input array[]={1,2,3,4}, i.e. n=4, we need to rotate by d=2
* step 2: store first element in temp i.e. for i=0, temp=1
* step 3: after 2 rotations which element will come at position j=i=0, it will be k=2 (i.e. (j+d) %n)
* step 4: jump to j=k i.e. j=2
* step 5: after two rotation which element will come at j=2 position, it will be k=0 (i.e. (j+d) % n )
* step 6: Now we have to store our stored temp variable (i.e. step 2) at j=2 position
* step 7: following step2 to step 6 we have completed one cycle of operation and position with index 0,2 variable corrected 
* step 8: still we need to correct position for element with index 1,2
* step 9: this requires one more repeat cycle from step2 to step6. By end of cycle 2 you will notice all index position will be corre* cted.This also says we have traversed through all the n elements
* Question : How we have determine total number of cycle ?
* Answer: gcd(n,d), mathemetical reason refer (https://stackoverflow.com/questions/23321216/rotating-an-array-using-juggling-algorithm)
* Time Complexity : 0(n)
* Auxiliary Space : 0(1)
*/

#include<stdio.h>

void rotate_array(int *array,unsigned int d,unsigned int len);
void print_array(int *array,unsigned int len);
int gcd(unsigned int a,unsigned b);

int main()
{
	int array[] = {1,2,3,4,5,6,7};
	unsigned int d=2;
	unsigned int len = sizeof(array)/sizeof(array[0]);
	rotate_array(array,d,len);
	print_array(array,len);
	printf("# Time Complexity O(n)\n");
}

void rotate_array(int *array,unsigned int d,unsigned int len)
{
	int i,j,k;
	i=j=k=-1;
	if(array == NULL)
	{
		return;
	}
	for(i=0;i<gcd(len,d);i++)
	{
		unsigned int temp = array[i];
		j=i;
		while(1)
		{
			k =(j+d)%len;
			if(i==k)
			{
				printf("Cycle completed\n");
				break;
			}
			array[j] = array[k];
			j=k;
		}
		array[j] = temp;
	}
}

/*
* GCD of two numbers is the largest number that divides both of them
* Euclidean algorithm
* Methord 1: If we subtract smaller number from larger (we reduce larger number), GCD doesn’t change.
* So if we keep subtracting repeatedly the larger of two, we end up with GCD.
* For ex. a=5,b=2
* step 1: a>b,a=5-2,b=2
* step 2: a>b,a=3-2,b=2
* step 3: a<b a=1,b=2-1
* step 4: a>=b a=1-1,b=1
* GCD is b=1
* Methord 2: instead of subtraction, if we divide smaller number, the algorithm stops when we find remainder 0
* For ex. a=5,b=2
* step 1: a=(5%2),b=2
* step 2: a=(1%2),b=2 Now a will remain constant and a=1 is the GCD
*
*/
int gcd(unsigned int a,unsigned b)
{
    while(1)
    {
        if(a==0 || b==0) break;
        a>=b?(a=a-b):(b=b-a);
    }
    if(a==0) return b;
    else return a;
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
