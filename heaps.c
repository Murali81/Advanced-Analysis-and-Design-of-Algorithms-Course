#include<stdio.h>
#include<malloc.h>
int noofbits=0;
int arr[32];
struct node
{
	int val;
	struct node *right;
	struct node *left;
	struct node *parent;
}

int numtobit(int num)
{
	int counter=-1;
	int res;
	while(num!=0)
	{
		counter=counter+1;
		res=num%2;
	printf("%d\t",res);
	num=num/2;
	}
	return counter;   //Intentionally I am reducing the length of bit set by 1 because for inserting at 6th position,i.e 110, we exclude the first bit and the remaining bits are the path.
}

void main()
{
 	int noofbits;
 	int num;
    printf("Enter a decimal integer \n");
    scanf("%d", &num);
    //decimal_num = num;
	noofbits=numtobit(num);
	printf("\n No of bits are %d",noofbits);
	
}
