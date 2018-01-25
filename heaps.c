#include<stdio.h>
#include<malloc.h>
int noofbits=0;
int arr[32];
int heapsize=0;			// GLOBAL variable which stores the number of heaps
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

struct node *max_heapify(struct node *root)
{
	if (root->left==NULL && root->right==NULL)
	{
		printf("\nReached end");
		return root;
	}
	struct node* largest;
	largest=root;
	if(root->left!=NULL &&(root->left->data>largest->data))
	{
		largest=root->left;
	}
		if(root->right!=NULL && (root->right->data > largest->data))
	{
		largest=root->right;
	}
	if(largest->data!=root->data)
	{
		int temp;
		printf("\nSwapped %d with %d",largest->data,root->data);
		temp=largest->data;
		largest->data=root->data;
		root->data=temp;
		return max_heapify(largest);
	}
}


struct node *find_leaf(struct node *root,int noofbits)
{

	
	if(root->left!=NULL || root->right!=NULL)
	{
		if(arr[noofbits]==0)
		{
			printf("\nLeft Traversal");
			
			return find_leaf(root->left,noofbits-1);                   // 0 for left && 1 for right. because for 2nd pos , 2- 1}0 .It means left.For 6th pos,6 -1}10 .One right and then left 
			
		}
		else
		{
			printf("\nRight Traversal");
			return find_leaf(root->right,noofbits-1);
			 
		}
	}
	else
	{
		if(arr[noofbits+1]==0)
		{
			root->parent->left=NULL;
		}
		else if(arr[noofbits+1]==1)

		{
			root->parent->right=NULL;
		}
		return root;
	}
}


int extract_max(struct node *root)
{
	int maxelement; 
	struct node *leaf_node;
	noofbits=numtobit(heapsize);
	leaf_node=find_leaf(root,noofbits);
	maxelement=root->data;
	root->data=leaf_node->data;
//	leaf_node->parent->left=leaf_node->parent->right=NULL;
	free(leaf_node);
	max_heapify(root);
	heapsize=heapsize-1;
	return maxelement;
}



struct node *insert(int data,struct node *root,int bitpointer)    //bitpointer = noofbits-1 .This is given during function call
{

if(root==NULL)
{
		struct node *newnode;
		newnode=newNode(data);
		root=newnode;
		printf("\nROOT insertion");
		heapsize+=1;
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
		heapsize+=1;
		while(newnode->parent!=NULL && (newnode->parent->data<newnode->data))
		{
			
					int temp;
					printf("\nSwapped %d with %d",newnode->parent->data,newnode->data);
					temp=newnode->parent->data;
					newnode->parent->data=newnode->data;
					newnode->data=temp;
				newnode=newnode->parent;	
			
		}
			
}
	else if(root->left!=NULL && root->right!=NULL)
	{
		if(arr[bitpointer]==0)
		{
			printf("\nLeft Traversal");
			return insert(data,root->left,bitpointer-1);                   // 0 for left && 1 for right. because for 2nd pos , 2- 1}0 .It means left.For 6th pos,6 -1}10 .One right and then left 
			
		}
		else
		{
			printf("\nRight Traversal");
			return insert(data,root->right,bitpointer-1);
			 
		}
	}

//	else
//	{
//		if(arr[bitpointer]==0)
//		{
//			printf("\nLeft Traversal-----------");
//			return insert(data,root->left,bitpointer-1,num);                   // 0 for left && 1 for right. because for 2nd pos , 2- 1}0 .It means left.For 6th pos,6 -1}10 .One right and then left 
//			
//		}
//		else if(arr[bitpointer]==1)
//		{
//			printf("\nRight Traversal------------");
//			return insert(data,root->right,bitpointer-1,num);
//			 
//		}
//	}


}


int numtobit(int num)
{
	int dupnum=num;
	int counter=-1;
	int res;
//	printf("\n");
	while(num!=0)
	{
		counter=counter+1;
		res=num%2;
	arr[counter]=res;	
	num=num/2;
	}
//	printf("Max index in the big array for %d are %d",dupnum,counter-1 );
	return counter-1;   //Intentionally I am reducing the length of bit set by 1 because for inserting at 6th position,i.e 110, we exclude the first bit and the remaining bits are the path.

}

void main()
{
 	int noofbits;
 	int num=0;
 	int max_element;
int inparray[8]={1,10,14,9,23,54,21,6};
for(num=1;num<=8;num++)
{
	printf("\n\n\nInserting %d",inparray[num-1]);
	noofbits=numtobit(num);
	if(num==1)
	root=insert(inparray[num-1],root,noofbits);
	else
	insert(inparray[num-1],root,noofbits);
}
printf("\n\n\nValue of heapsize is %d",heapsize);
max_heapify(root);
printf("\n\n\nheapified\n\n");

printf("\nTesting extract_max\n");
while(root!=NULL)
	{
	max_element=extract_max(root);
	printf("\n\n\n MAX is %d\n\n\n",max_element);
	if(root->left==NULL && root->right==NULL && root->parent==NULL)
		{
		max_element=root->data;
		printf("\n\n\n MAX is %d\n\n\n",max_element);
		root=NULL;
		}
	}

}
