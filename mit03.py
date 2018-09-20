def mergesort(a,l,r):
  while l<r:
    m = l + (r-l)/2
    mergesort(a,l,m)
    mergesort(a,m+1,r)
    merge(a,l,m,r)
def merge(a,l,m,r):
  al = a[l:m]
  ar = a[m+1:r+1]
  i,j,k = 0,0,l
  while i < len(al) and j < len(ar):
    if al[i] <= ar[j]:
      a[k]=al[i]
      i+=1
    elif al[i] > ar[j]:
      a[k]=ar[j]
      j+=1
    k+=1
  if i < len(al):
    for m in range(i,len(al)):
      a[k]=al[m]
      k+=1
  if j < len(ar):
    for m in range(i,len(ar)):
      a[k]=ar[m]
      k+=1
a=[2,4,2,3,6,3,8,4,7]
mergesort(a,0,len(a))
print a