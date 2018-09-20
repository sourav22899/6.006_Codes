import heapq
n1,m1 = raw_input().split()
n,m = int(n1),int(m1)
adj = {}
for i in range(m):
    x1,y1,w1 = raw_input().split()
    x,y,w = int(x1),int(y1),int(w1)
    if adj.has_key(x) and adj.has_key(y):
        adj[x].append((w,y))
        adj[y].append((w,x))
    elif adj.has_key(x) and adj.has_key(y) is False:
        adj[x].append((w,y))
        adj[y] = [(w,x)]
    elif adj.has_key(x) is False and adj.has_key(y):
        adj[x] = [(w,y)]
        adj[y].append((w,x))
    elif adj.has_key(x) is False and adj.has_key(y) is False:
        adj[x] = [(w,y)]
        adj[y] = [(w,x)]
        
start = 1
q,S,d,P = [(0,start)],set(),{},{}

d[start],P[start] = 0,None

#print adj
while q:
    (cost,u) = heapq.heappop(q)
    S.add(u)
    for c,v in adj.get(u,()):
        if v not in d or cost + c < d[v]:
            d[v] = cost + c
            P[v] = u
            heapq.heappush(q,(d[v],v))

node,L = n,[]
if P.has_key(node) is False:
    print -1
else:
    while node is not None:
        L.append(node)
        node = P[node]
    L.reverse()
    for i in L:
        print i,