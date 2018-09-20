"""
	Initializing a graph
"""
adj = {}
k = input()
graph = input()
no_of_vertex = input()
if graph == 0:
    for i in range(k):
        n1,m1 = raw_input().split()
        n,m = int(n1),int(m1)
        if adj.has_key(n):
            adj[n].append(m)
        if adj.has_key(m):
            adj[m].append(n)
        if adj.has_key(n) is False:
            adj[n] = [m]
        if adj.has_key(m) is False:
            adj[m] = [n]
if graph == 1:
    for i in range(k):
        n1,m1 = raw_input().split()
        n,m = int(n1),int(m1)
        if adj.has_key(n):
            adj[n].append(m)
        if adj.has_key(n) is False:
            adj[n] = [m]
    
V,T = [],[]
for i in range(1,no_of_vertex + 1):
    V.append(i)

"""
	Doing a DFS
"""
def DFS_Visit(s,adj,path):
    path.append(str(s))
    if adj.has_key(s):
        for v in adj[s]:
            if parent.has_key(v) is False:
                parent[v] = s
                DFS_Visit(v,adj,path)
                T.append(v)

print adj
parent = {}
for s in V:
    if parent.has_key(s) is False:
        parent[s] = None
        """ Doing a DFS Visit"""
        path = []
        DFS_Visit(s,adj,path)
        print " --> ".join(path)

T.reverse()
print T