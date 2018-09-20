def AuxCountSort(a,k):
	L = [0]*k
  	for i in a:
  	    L[i]+=1
  	return L
  	
"""    
def CountSort(a,k):
    b=[0]*len(a)
    L = AuxCountSort(a,k)
    for i in range(1,len(L)):
        L[i]+=L[i-1]
    print L
    b=[0]*len(a)
    for i in range(len(a)-1,-1,-1):
        b[L[a[i]]-1] = a[i]
        L[a[i]]-=1
	return b
"""

a = [int(x) for x in raw_input().split()]
L = AuxCountSort(a,7)
for i in range(1,len(L)):
    L[i]+=L[i-1]
print L
b = [0]*len(a)
for i in range(len(a)-1,-1,-1):
    b[L[a[i]]-1] = a[i]
    L[a[i]]-=1
print b

