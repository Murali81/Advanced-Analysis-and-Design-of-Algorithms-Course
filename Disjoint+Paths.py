
# coding: utf-8

# In[15]:

import numpy as np
class MaxFlow():
    def __init__(self,graph):
        self.graph=np.copy(graph)
        self.nodes=len(graph)
        self.orgraph=np.copy(graph)
        self.flow=np.zeros([self.nodes,self.nodes],np.int)
        self.mincut=[]
        self.flowi=0
        self.paths=[]
        
        
#         self.x=x    mURALI was here testing for x
    
    
    def convert_to_unit_edges(self):
        for i in range(self.nodes):
            for j in range(self.nodes):
                if self.graph[i][j]>0:
                    self.graph[i][j]=1
                    
                    
        print(self.graph)
            
        
    
    def BFS(self,source,target,parent):
        visited=[-1]*self.nodes
        
        que=[]
        que.append(source)
        visited[source]=1
        
        
        while que:
            
            psrc=que.pop(0)
            
            psrclist=self.graph[psrc]
            for vertex in range(self.nodes):
                if psrclist[vertex]>0 and visited[vertex]==-1:
                    que.append(vertex)
                    visited[vertex]=1
                    parent[vertex]=psrc
        return True if visited[target]==1 else False
    
    def DFS(self,source,target,visitedd):
        visitedd[source]=1
        for vrtx in range(self.nodes):
            if (self.graph[source][vrtx] and visitedd[vrtx]!=1):
                self.DFS(vrtx,target,visitedd)
            
        
    
    
    def ford_fulker(self,source,target):
        parent=[-1]*self.nodes
        self.flowi=0
        while self.BFS(source,target,parent):
            print(parent)
            path_min=999
            s=target
            
            
            path=[]
            while s!=source:
                path.append(s)
                path_min=min(path_min,self.graph[parent[s]][s])
                s=parent[s]
                
                
            path.append(s)
            path=path[::-1]
            self.paths+=[path]


            v=target
            self.flowi+=path_min
            while v!=source:
                u=parent[v]
                print("path from ",u ," to ", v)
                self.flow[u,v]+=path_min   #Q1
                self.graph[u][v]-=path_min
                self.graph[v][u]+=path_min
                v=parent[v]
                

                
#         ## ADJUST THE NEGATIVE EDGES HERE
        
        
#         print(self.flow)
#         for i in range(self.nodes):
#             for j in range(self.nodes):
#                 if(self.flow[i][j]>0 and self.flow[j][i]>0 and (self.orgraph[i][j]==0 or self.orgraph[j][i]==0 )):
#                     self.flow[i][j]=0
#                     self.flow[j][i]=0
                    
                    
# #         print("\n\n\n################ Question 1 ,Flows from all the edges #########")
#         print(self.flow)
        
        
        
#         ## MIN CUT
        
        

#         for i in range(self.nodes):
#             for j in range(self.nodes):
#                 if(self.graph[i][j]==0 and self.orgraph[i][j]):
# #                     print( "Mincut is at ", i, " ",j," ",self.orgraph[i][j])
#                     self.mincut=self.mincut+[tuple((i,j))]
        
        
        
        
        
#         visitedd=[-1]*self.nodes
#         self.DFS(source,target,visitedd)
        
                
    
        
        

            


# In[33]:

# Create a graph given in the above diagram
 
# graph = [[0, 10, 20, 0],
#         [0, 0, 10, 10],
#         [0, 0, 0, 5],
#         [0, 0, 0, 0]]



# #@
graph=[ [0, 9, 9, 0, 0, 0],
        [0, 0, 4, 8, 0, 0],
        [0, 0, 0, 1, 3, 0],
        [0, 0, 0, 0, 8, 10],
        [0, 0, 0, 0, 0, 7],
        [0, 0, 0, 0, 0, 0]
      ];



# graph=[[0,3,2],[0,0,2],[0,0,0]]

#dammNN

source = 0; sink = 5
g = MaxFlow(graph)

g.convert_to_unit_edges()       ## IMPORTANT STEP

g.ford_fulker(source, sink)


print ("\n\n\nThe number of disjoint paths are " ,g.flowi )



print("\n\n\nThe disjoint paths are:")
print(g.paths)
print("\n\n")
for i in range(len(g.paths)):
    lst=g.paths[i]
    strg=str('==>'.join(str(e) for e in lst))
    print(strg)



# print("\n\n\n################ Question 1 ,Flows from all the edges #########")
# print(g.flow)




# In[ ]:




# In[ ]:



