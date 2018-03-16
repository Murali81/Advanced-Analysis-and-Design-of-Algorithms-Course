
# coding: utf-8

# ## CLASS FOR IMPLEMENTING FORDFULKERSON

# In[63]:

import numpy as np
class MaxFlow():
    def __init__(self,graph):
        self.graph=np.copy(graph)
        self.nodes=len(graph)
        self.orgraph=np.copy(graph)
        self.flow=np.zeros([self.nodes,self.nodes],np.int)
        self.mincut=[]
#         self.x=x    mURALI was here testing for x
        
    

        
    
    
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
        flowi=0
        while self.BFS(source,target,parent):
            print(parent)
            path_min=999
            s=target

            while s!=source:
                path_min=min(path_min,self.graph[parent[s]][s])
                s=parent[s]



            v=target
            flowi+=path_min
            while v!=source:
                u=parent[v]
                print("path from ",u ," to ", v)
                self.flow[u,v]+=path_min   #Q1
                self.graph[u][v]-=path_min
                self.graph[v][u]+=path_min
                v=parent[v]
                
                
        ## ADJUST THE NEGATIVE EDGES HERE
        
        
#         print(self.flow)
        for i in range(self.nodes):
            for j in range(self.nodes):
                if(self.flow[i][j]>0 and self.flow[j][i]>0 and (self.orgraph[i][j]==0 or self.orgraph[j][i]==0 )):
                    self.flow[i][j]=0
                    self.flow[j][i]=0
                    
                    
#         print("\n\n\n################ Question 1 ,Flows from all the edges #########")
#         print(self.flow)
        
        
        
        ## MIN CUT
        
        

        for i in range(self.nodes):
            for j in range(self.nodes):
                if(self.graph[i][j]==0 and self.orgraph[i][j]):
#                     print( "Mincut is at ", i, " ",j," ",self.orgraph[i][j])
                    self.mincut=self.mincut+[tuple((i,j))]
        
        
        
        
        
        visitedd=[-1]*self.nodes
        self.DFS(source,target,visitedd)
        
        
#         x=input("Enter x")
#         x=int(x)
        
#         for i in range(self.nodes):
#             for j in range(self.nodes):
#                 if(visitedd[i]==1 and visitedd[j]!=1 and self.orgraph[i][j]):
#                     print( "Mincut is at ", i, " ",j," ",self.orgraph[i][j])
#                     if [tuple((i,j))] not in self.mincut:
#                         self.mincut=self.mincut+[tuple((i,j))]
                
                
    
        
        
        return flowi
            
        
        
            


# ## BIPARTITE QUESTION

# In[68]:

import numpy as np
# fslow=np.random.randint(2,size=(5,5))
# fslow=np.zeros([8,8],dtype=np.int)
fslow=np.array([[0,0,0,0,1,0,1,0],
       [0,0,0,0,0,0,1,1],
       [0,0,0,0,1,0,0,0],
       [0,0,0,0,0,1,0,0],
       [0,0,0,0,0,0,0,0],
       [0,0,0,0,0,0,0,0],
       [0,0,0,0,0,0,0,0],
       [0,0,0,0,0,0,0,0]
      ])
# print(fslow)
print(fslow.shape)

fslow=np.pad(fslow,(1,1),'constant')
# print(fslow)
print(fslow.shape)


# In[65]:

L=[]
R=[]
def findLR():
    for indx,row in enumerate(fslow):
        if indx==0 or indx==len(fslow)-1:continue
        if np.any(row>0):
            L.append(indx)
        else:
            R.append(indx)
        
    print("Left subset nodes are ", L)
    print("Left subset nodes are ", R)
findLR()


# In[66]:



s=0
t=len(fslow)-1
def connectLRwithST():

    
    for indx in L:
        fslow[s][indx]=1
        
    for indx in R:
        fslow[indx][t]=1
        

    
connectLRwithST()


# In[67]:

source = s; sink = t
g = MaxFlow(fslow)
maxflow=g.ford_fulker(source, sink)
print ("The maximum possible flow is " ,maxflow )

# print(g.mincut)


print(g.flow)

print("\n\nThe maximal matching is \n\n")
def findFlow(flowgraph):
    for indx,row in enumerate(flowgraph):
        if indx==0 or indx==len(flowgraph)-1:continue
        if np.any(row>0):
            for indix,val in enumerate(row):
                if indix==0 or indix==len(flowgraph)-1:continue
                if val>0:
                    print(indx,"===>",indix)
            
        else:
            pass
findFlow(g.flow)


# In[ ]:




# In[ ]:



