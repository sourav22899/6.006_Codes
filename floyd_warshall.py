"""
    Floyd Warshall finds SP from any vertex to any vertrex in O(V^3).
"""
n1,m1 = raw_input().split()
n,m = int(n1),int(m1)
K = 10**9 + 7
L = [[K]*n for i in range(n)]
for i in range(n):
    L[i][i] = 0
for i in range(m):
    x1,y1,w1 = raw_input().split()
    x,y,w = int(x1),int(y1),int(w1)
    x -= 1;y -= 1
    L[x][y] = w
    L[y][x] = w
for k in range(n):
    for i in range(n):
        for j in range(n):
            L[i][j] = min(L[i][j],L[i][k]+L[j][k])
for i in L:
    print i