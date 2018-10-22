#include<stdio.h>
#include <stdlib.h>
int cmpfunc (const void * a, const void * b) 
{
   return (  *(int*)b - *(int*)a );
}

void main()
{
	int m,n;
	m=4;
	n=10;
	
	int assgnm[m];
//	int arr[]={9,1,4,3,6,2,8,7,5,10,14,12,15,13,11};
	int arr[]={2, 6, 8, 10, 950, 960, 970, 980, 990, 1000};
//	int arr[]={1002,996,988,980,1910};
//	int arr[]={1,980,990,1000};

//	 qsort(arr, n, sizeof(int), cmpfunc);   //This is for optimization.Switch it on if needed by uncommenting.


	
	//Direct assignment
	int i,j;
	i=j=0;
	for(i=0;i<m && i<n;i++)
	{
		assgnm[i]=arr[i];
	}
	
	for(i=0;i<m;i++)
	{
		printf("%d\t",assgnm[i]);
	}


	//Greedy approach
	
	
	
	int k,min,minpos;
	
	for(j=m;j<n;j++)
	{
		
	k=0;
	min=9999;
	minpos=-1;
	
	for(k=0;k<m;k++)
	{
	//	printf("\nMin is %d == Element is  %d",min,assgnm[k]);
		if(assgnm[k]<min)
		{
			min=assgnm[k];
			minpos=k;	
		}
	}
	printf("\nMin position is %d == %d + %d ",minpos,assgnm[minpos],arr[j]);
	assgnm[minpos]+=arr[j];

	}
	printf("\n\n");
	for(i=0;i<m && i<n;i++)
	{
		printf("%d\t",assgnm[i]);
	}
			
	
}
