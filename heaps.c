#include<stdio.h>
#include<malloc.h>
int noofbits=0;
int arr[32];
struct node
{
	int data;
	struct node *right;
	struct node *left;
	struct node *parent;
};
struct node *root=NULL;
struct node* newNode(int data)
{
  // Allocate memory for new node 
  struct node* node = (struct node*)malloc(sizeof(struct node));
 
  // Assign data to this node
  node->data = data;
 
  // Initialize left and right children as NULL
  node->left = NULL;
  node->right = NULL;
    node->parent = NULL;
  return(node);
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
