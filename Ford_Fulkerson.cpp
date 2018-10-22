// C++ program for implementation of Ford Fulkerson algorithm
#include <iostream>
#include <limits.h>
#include <string.h>
#include <queue>
using namespace std;
 
#define V 6
 
//bfs returns shortest path
bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
    
    bool visited[V];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
 
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<V; v++)
        {
            if (visited[v]==false && rGraph[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
 
    
    return (visited[t] == true);
}
 
// To find max flow
int fordFulkerson(int graph[V][V], int s, int t)
{
    int u, v;
 
    //Residual graph
    int rGraph[V][V]; 
	 
    for (u = 0; u < V; u++)
    {
    	for (v = 0; v < V; v++)
    	{
    		rGraph[u][v] = graph[u][v];
		}
	}
       
	//To store path 
    int parent[V];
 
    int max_flow = 0; 
 
    //Loop will run until path is available
    while (bfs(rGraph, s, t, parent))
    {

        int path_flow = rGraph[parent[t]][t];
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = path_flow < rGraph[u][v] ? path_flow : rGraph[u][v];
        }
 
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
 
        max_flow += path_flow;
        
        
        //To print matrix after every iteration.
        /*int z,w;
        printf("[");
        for(z=0;z<V;z++)
        {
        	for(w=0;w<V;w++)
        	{
        		printf("%d,",rGraph[z][w]);
			}
			printf("\n");
		}
		printf("]\n");*/
    }
 	int z,w;
 	
 	printf("First graph\n");
    for(z=0;z<V;z++)
    {
        for(w=0;w<V;w++)
        {
        	printf("%d\t",graph[z][w]);
		}
		printf("\n");
	}
	printf("\n");
 	
    printf("After max flow with reverse\n");
    for(z=0;z<V;z++)
    {
        for(w=0;w<V;w++)
        {
        	printf("%d\t",rGraph[z][w]);
		}
		printf("\n");
	}
	printf("\n");
	
	
	int d;
	printf("After max flow\n");
    for(z=0;z<V;z++)
    {
        for(w=0;w<V;w++)
        {
        	if(graph[z][w]>0)
        	{
        		printf("%d\t",rGraph[w][z]);
        	}
        	else
        	{
        		printf("0\t");
        	}
		}
		printf("\n");
	}
	printf("\n");
	
	cout << "The maximum possible flow is " << max_flow;
	int x,opt;
	do
	{
		cout<<"Enter x:";
		cin>>x;
		
		cout<<"Enter 0 to exit:";
		cin>>opt;
	}while(opt != 0);
	
	
    return max_flow;
}
 

int main()
{
    int graph[V][V] = { {0, 9, 9, 0, 0, 0},
                        {0, 0, 4, 8, 0, 0},
                        {0, 0, 0, 1, 3, 0},
                        {0, 0, 0, 0, 8, 10},
                        {0, 0, 0, 0, 0, 7},
                        {0, 0, 0, 0, 0, 0}
                      };
 
    cout << "The maximum possible flow is " << fordFulkerson(graph, 0, 5);
 
    return 0;
}
