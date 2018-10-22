#include<stdio.h>
#include <stdbool.h>

#define N 3

int A[N][N]={{0,1,0},{1,0,1},{0,1,0}};
//int A[N][N]={{0,0,0,1},{0,0,1,0},{0,1,0,1},{1,0,1,0}};

bool algo(int G[N][N],int soln[],int count,int n,int chi)
{
	int i=0;int j=0;
	
	
//	printf("\n\n");
//			for(i=0;i<n;i++)
//	{
//	printf("%d\t",soln[i]);
//	}
//	printf("Count value is %d",count);
	
	
	if(count==n)
	{
		return true;
	}
	
	if(count==0)
	{
			soln[count]=0;
//			printf("Inside count");
			algo(G,soln,count+1,n,chi);
	}
		
	
	
	for(i=0;i<chi;i++)
	{
		
		int availflag=1;
		//Check method 
//		printf("Murali checked the start");

		for(j=0;j<n;j++)
		{
			if(G[count][j]>0 && soln[j]>-1)
				{
					if(soln[j]==i)
					{
						availflag=0;
						break;
					}
				}
		}
		// End of Check method
//		printf("Murali checked the end");
		
		if(availflag==1)
		{
			soln[count]=i;
			//printf("Assigned");
//			algo(G,soln,count+1,n,chi);
			if(algo(G,soln,count+1,n,chi))
			{
			return true;	
			}
		}
		
		
		
	}
	return false;
	

}

void graph_coloring(int G[N][N],int n)
{
	int i=0;
	bool check;
	int soln[n];
	for(i=0;i<n;i++)
	{
		soln[i]=-1;
	}	
	for(i=0;i<=n;i++)
	{
//		printf("\n\nCalled with %d colors",i);
		check=algo(G,soln,0,n,i);
		if(check==true)
		{
			printf("\n\nChromatic number is %d\n\n",i);
			break;
		}
	}
	
	printf("Solution is \t");
		for(i=0;i<n;i++)
	{
	printf("%d\t",soln[i]);
	}
	
}



void main()
{

	graph_coloring(A,N);

}
