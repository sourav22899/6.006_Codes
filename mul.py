""" 
	base 10 bignum multiplication
"""
def normalize(L,n):
    if len(L) < n:
        for i in range(n-len(L)):
            L.append(0)
    return L

def add(A,B,base,n):
	normalize(A,n)
	normalize(B,n)
	L = []
	normalize(L,n+1)
	carry = 0
	for i in range(n):
		x = A[i] + B[i] + carry
		L[i] = x % base
		carry = x//base
	L[n] = carry
	return L

n,m = raw_input().split()
A,B = [],[]
for i in n:
    A.append(int(i))
for i in m:
    B.append(int(i))
A.reverse()
B.reverse()
"""
A = [int(x) for x in raw_input().split()]
B = [int(x) for x in raw_input().split()]
"""
base = 10
N = len(A)+len(B)
S = [0]*(N)
for i in range(len(B)):
	L = [0]*(N)
	M = []
	carry = 0
	for j in range(len(A)):
		x = A[j]*B[i] + carry
		M.append(x % base)
		carry = x//base
		if j == len(A)-1:
			M.append(carry)
	L[i:] = M
	L = normalize(L,N)
	S = add(S,L,base,N)
	
S.reverse()
T,flag = [],0
for i in S:
    if i != 0:
        flag += 1
    if(flag):
        T.append(str(i))
print "".join(T)
