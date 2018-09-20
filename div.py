""" 
	base 10 bignum division
"""
def normalize(L,n):
    if len(L) < n:
        for i in range(n-len(L)):
            L.append(0)
    return L

def compliment(L,base):
	for i in range(len(L)):
		L[i] = base - 1 - L[i]
	return L

def lshift(A,base,n):
	B = A[1:]
	normalize(B,n)
	return B

def rshift(A,base,n):
	B = A[:-1]
	B.insert(0,A[1])
	return B

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

def sub(A,B,base,n):
    normalize(B,n)
    B = compliment(B,base)
    M = [1]
    normalize(M,n)
    B = add(B,M,base,n)
    L = []
    normalize(L,n+1)
    L = add(A,B,base,n)
    return L[:-1]

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
def mul(A,B,base,N):
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
	return S

P = mul(A,B,base,N)	
P.reverse()
T,flag = [],0
for i in P:
    if i != 0:
        flag += 1
    if(flag):
        T.append(str(i))
print "".join(T)

N = []
N = sub(A,B,base,1 + max(len(A),len(B)))
N.reverse()

T,flag = [],0
for i in N:
    if i != 0:
        flag += 1
    if(flag):
        T.append(str(i))
print "".join(T)

#### Division

def compare(A,B):
	if len(A) > len(B):
		return 1
	if len(A) < len(B):
		return -1
	if len(A) == len(B):
		for i in range(len(A)):
			if A[i] > B[i]:
				return 1
			if B[i] > A[i]:
				return -1
		return 0
			
A.reverse()
B.reverse()
Q,R = [],[]
BASE = [1,0]
if compare(A,B) == -1:
	Q,R = [0],A
elif compare(A,B) == 0:
	Q,R = [1],[0]
else:
	C = B
	while compare(A,B) > 0:
		M = [1]
		for i in range(len(A)-len(B)):
			C = lshift(B,base,len(A))
			M.append(0)
		Q = add(Q,M,base,len(A))
		A = sub(A,C,base,len(A))
	R = A
	print Q,R