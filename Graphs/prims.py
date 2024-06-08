def primlist(WList):
    # Initialization
    infinity = 1 + max([d for u in WList.keys() for (v,d) in WList[u]])
    (visited,distance,TreeEdges) = ({},{},[])
    for v in WList.keys():
        (visited[v],distance[v]) = (False,infinity)
    
    # Start from vertex 0, marked visited and update the distance of adjacents from 0
    visited[0] = True
    for (v,d) in WList[0]:
        distance[v] = d
    
    # Repeat the below process (number of vertices-1) times
    for i in range(1,len(WList.keys())):
        mindist = infinity
        nextv = None
        #Finding the minimum weight edge (u,v) where vertex u is visited and v is not visited 
        for u in WList.keys():
            for (v,d) in WList[u]:
                if visited[u] and (not visited[v]) and d < mindist:
                    mindist = d
                    nextv = v
                    nexte = (u,v)
        
        # Mark nextv as visited and append the nexte in MST
        visited[nextv] = True
        TreeEdges.append(nexte)
        
        # Update the distance of unvisited adjacents of nextv if smaller than current
        for (v,d) in WList[nextv]:
            if not visited[v]:
                if d < distance[v]:
                    distance[v] = d
    return(TreeEdges)


dedges = [(0,2,4),(2,0,4),(0,3,5),(3,0,5),(1,2,9),(2,1,9),(1,3,8),(3,1,8),(2,3,6),(3,2,6)]
edges = dedges + [(j,i,w) for (i,j,w) in dedges]
size = 4
WL = {}
for i in range(size): 
    WL[i] = []
for (i,j,d) in edges:
    WL[i].append((j,d))
print(primlist(WL))