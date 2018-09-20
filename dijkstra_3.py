import heapq
N = 10**16
n1,m1 = raw_input().split()
n,m = int(n1),int(m1)
adj = {}
for i in range(m):
    x1,y1,w1 = raw_input().split()
    x,y,w = int(x1),int(y1),int(w1)
    x -= 1;y -= 1
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
        
parent = {}
start = 0
d = [N for i in range(n)]
d[start] = 0
parent[start] = None
heapq.heappush(H,(0,start))
while H:
    (cost,u) = heapq.heappop(H)
    if adj.has_key(u):
        for c,v in adj[u]:
            if d[v] > d[u] + c:
                d[v] = d[u] + c
                parent[v] = u
                heapq.heappush(d[v],v)

print parent
print d