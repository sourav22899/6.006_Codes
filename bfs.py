adj = {}
k = input()
graph = input()
node = input()
vertex = []
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
		else:
			adj[n] = [m]

for key in adj.keys():
    vertex.append(key)
print adj
"""
	Doing BFS
"""
start = 1
level,parent = {},{}
level[start] = 0
parent[start] = None
i = 1
frontier = [start]
deepest = 1
while frontier:
	new = []
	for u in frontier:
		for v in adj[u]:
			if level.has_key(v) is False:
				level[v] = i
				parent[v] = u
				new.append(v)
				deepest = v
	frontier = new
	i += 1

#print deepest,level,parent

"""
	Printing the shortest path between start and node.
"""
def shortest_path(node,start):
    path = []
    while node != start:
    	path.append(str(node))
    	node = parent[node]
    path.append(str(start))
    path.reverse()
    print " --> ".join(path)
    return len(path)-1
"""
    Finding the diameter of a tree
"""
start = deepest
level,parent = {},{}
level[start] = 0
parent[start] = None
i = 1
frontier = [start]
while frontier:
	new = []
	for u in frontier:
		for v in adj[u]:
			if level.has_key(v) is False:
				level[v] = i
				parent[v] = u
				new.append(v)
				farthest = v
	frontier = new
	i += 1
print level,parent
print shortest_path(farthest,deepest)
