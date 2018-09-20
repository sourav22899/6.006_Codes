def left(i):
  	return 2*(i)+1

def right(i):
  	return 2*(i+1)

def parent(i):
	return (i-1)//2

def max_heapify(a,i,n):
	if i < len(a)//2:
		l = left(i)
		r = right(i)
		temp = max(a[i],a[r],a[l])
		if a[l] == temp and l < n:
			a[i],a[l] = a[l],a[i]
			max_heapify(a,l,n)
		elif a[r] == temp and r < n:
			a[i],a[r] = a[r],a[i]
			max_heapify(a,r,n)

def build_max_heap(a):
    for i in range(len(a)//2 - 1,-1,-1):
        max_heapify(a,i,len(a))

def heap(a):
    for i in range(len(a)-1,-1,-1):
        a[i],a[0] = a[0],a[i]
        max_heapify(a,0,i)
        
a = [int(x) for x in raw_input().split()]
build_max_heap(a)
heap(a)
print a
