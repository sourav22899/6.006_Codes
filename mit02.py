def ins_sort(a):
  for i in range(len(a)):
    for j in range(i,len(a)):
      if a[i]>a[j]:
        a[i],a[j]=a[j],a[i]

a=[5,8,2,7,6,4,1,1,9,9]
ins_sort(a)
print a
