a=[]

for i in range(10):
    x=int(input('Enter number #%d: '%(i+1)))
    a.append(x)

print('Maximum value =',max(a),'and Minimum value =',min(a))