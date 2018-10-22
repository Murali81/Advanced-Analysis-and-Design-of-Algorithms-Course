from  pulp import *

#graph=[[0,0,1,0,0],
#       [0,0,0,0,1],
#       [1,0,0,0,1],
#       [0,0,0,0,1],
#       [0,1,1,1,0]]

#        a,b,c,d,e,f,g
graph=[[0,1,1,0,0,0,0],
       [1,0,1,1,0,0,0],
       [1,1,0,0,1,0,1],
       [0,1,0,0,0,1,0],
       [0,0,1,0,0,1,0],
       [0,0,0,1,1,0,1],
       [0,0,1,0,0,1,0],
]


nodes=[LpVariable("A"+str(i), 0, 1) for i in range(len(graph))]
constraints=[]


prob = LpProblem("myProblem", LpMinimize)
for i,row in enumerate(graph):
    for j,colval in enumerate(row):
        if colval==1:
            prob += nodes[i]+nodes[j]>=1

eq=nodes[0]
for x in range(1,len(graph)):
    eq+= nodes[x]


prob+=eq

status=prob.solve()
print(status)
print("SOLUTION IS ",LpStatus[status])

optimalvalues=[]
for node in nodes:
    #print(value(node))
    optimalvalues.append(value(node))

print("Optimal values through Linear Programming are ",optimalvalues)
roundedvalues=[]
for optimalnode in optimalvalues:
    if optimalnode<0.5:
        roundedvalues.append(0)
    else:
        roundedvalues.append(1)
    
print("Rounded values are ",roundedvalues)
