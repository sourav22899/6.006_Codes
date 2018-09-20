"""
    Bellman Ford finds SP from source to any vertrex in O(VE). Negative weights allowed.
"""
E = {}
n1,m1 = raw_input().split()
n,m = int(n1),int(m1)
K = 10**9 + 7
for i in range(m):
    p1,q1,w1 = raw_input().split()
    p,q,w = int(p1),int(q1),int(w1)
    p -= 1;q -= 1
    E[(p,q)],E[(q,p)] = w,w

d,s = [],0
for i in range(n):
    d.append(K)

d[s] = 0
def relax(u,v,d,E):
    if E.has_key((u,v)):
        d[v] = min(d[v],d[u] + E[(u,v)])

for i in range(n):
    for key in E.keys():
        relax(key[0],key[1],d,E)

flag = 1
for key in E.keys():
    if d[key[0]] > d[key[1]] + E[(key[0],key[1])]:
        print "Negative Cycle Exists"
        flag = 0
if flag:
    print d