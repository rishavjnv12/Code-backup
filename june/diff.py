f=open("op","r")
f2=open("output.txt","r")

lst1=[]
lst2=[]
for x in f:
    lst1.append(int(x))
    
for x in f2:
    lst2.append(int(x))

for i in range(len(lst1)):
    if(lst1[i]!=lst2[i] and lst1[i]!=-1):
        print(i+1)
        