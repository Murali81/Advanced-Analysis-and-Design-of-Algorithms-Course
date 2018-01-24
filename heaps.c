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
struct node *insert(int data,struct node *root,int bitpointer,int num)    //bitpointer = noofbits-1 .This is given during function call
{

//	printf("Value of bitpointer is  %d",bitpointer);
if(num==1)
{
		struct node *newnode;
		newnode=newNode(data);
		root=newnode;
		printf("\nROOT insertion");
		return root;	
		
}
if(bitpointer==0)
{
		struct node *newnode;
		newnode=newNode(data);
		newnode->parent=root;
		if(arr[bitpointer]==0)
		{
						printf("\nLeft to root");
			root->left=newnode;
		}	
		else if(arr[bitpointer]==1)
		{
						printf("\nRight to root");
			root->right=newnode;
		}
			
}
	else if(root->left!=NULL && root->right!=NULL)
	{
		if(arr[bitpointer]==0)
		{
			printf("\nLeft Traversal");
			return insert(data,root->left,bitpointer-1,num);                   // 0 for left && 1 for right. because for 2nd pos , 2- 1}0 .It means left.For 6th pos,6 -1}10 .One right and then left 
			
		}
		else
		{
			printf("\nRight Traversal");
			return insert(data,root->right,bitpointer-1,num);
			 
		}
	}

	else
	{
		if(arr[bitpointer]==0)
		{
			printf("\nLeft Traversal");
			return insert(data,root->left,bitpointer-1,num);                   // 0 for left && 1 for right. because for 2nd pos , 2- 1}0 .It means left.For 6th pos,6 -1}10 .One right and then left 
			
		}
		else if(arr[bitpointer]==1)
		{
			printf("\nRight Traversal");
			return insert(data,root->right,bitpointer-1,num);
			 
		}
	}


}


int numtobit(int num)
{
	int dupnum=num;
	int counter=-1;
	int res;
	printf("\n");
	while(num!=0)
	{
		counter=counter+1;
		res=num%2;
	arr[counter]=res;	
	num=num/2;
	}
	printf("Max index in the big array for %d are %d",dupnum,counter-1 );
	return counter-1;   //Intentionally I am reducing the length of bit set by 1 because for inserting at 6th position,i.e 110, we exclude the first bit and the remaining bits are the path.

}

void main()
{
 	int noofbits;
 	int num=0;
int inparray[8]={16,10,14,9,23,54,21,6};
//int num;
for(num=1;num<=8;num++)
{
	noofbits=numtobit(num);
	if(num==1)
	root=insert(inparray[num-1],root,noofbits,num);
	else
	insert(inparray[num-1],root,noofbits,num);
}
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",7);
//	root=insert(7,root,noofbits,num);
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",19);
//	insert(19,root,noofbits,num);
//
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",10);
//	insert(10,root,noofbits,num);
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",13);
//	insert(13,root,noofbits,num);
//
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",18);
//	insert(18,root,noofbits,num);
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",19);
//	insert(19,root,noofbits,num);
//
//	num=num+1;
//	noofbits=numtobit(num);
//	printf("\nFunction called with data %d",20);
//	insert(20,root,noofbits,num);
	
}
