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

struct node *min_heapify(struct node *root)
{
	if (root->left==NULL && root->right==NULL)
	{
		printf("\nReached end");
		return root;
	}
	struct node* smallest;
	smallest=root;
	if(root->left!=NULL &&(root->left->data<smallest->data))
	{
		smallest=root->left;
	}
		if(root->right!=NULL && (root->right->data < smallest->data))
	{
		smallest=root->right;
	}
	if(smallest->data!=root->data)
	{
		int temp;
		printf("\nSwapped %d with %d",smallest->data,root->data);
		temp=smallest->data;
		smallest->data=root->data;
		root->data=temp;
		return min_heapify(smallest);
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


int extract_min()
{
	int minelement; 
	if(root==NULL)
	{
		printf("\n\nHEAP IS EMPTY");
		return -2342;
	}
	if(root->left ==NULL && root->right==NULL)
	{
		minelement=root->data;
		root=NULL;
		return minelement;
	}

	struct node *leaf_node;
	noofbits=numtobit(heapsize);
	leaf_node=find_leaf(root,noofbits);
	minelement=root->data;
	root->data=leaf_node->data;
//	leaf_node->parent->left=leaf_node->parent->right=NULL;
	free(leaf_node);
	min_heapify(root);
	heapsize=heapsize-1;
	return minelement;
}


int isEmpty()
{
	if(root==NULL)
	{
				printf("\n\nHEAP IS EMPTY");
		return 0;
	}
	else
			return 1;
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
		while(newnode->parent!=NULL && (newnode->parent->data>newnode->data))
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
 	int min_element;
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
min_heapify(root);
printf("\n\n\nheapified\n\n");

printf("\n\n\nTesting extract_min\n");
while(root!=NULL)
	{
	min_element=extract_min();
	printf("\n\n\n MIN is %d\n\n\n",min_element);
	}



printf("\n\n\nTesting 'is_empty' FUNCTION");

isEmpty();

}
