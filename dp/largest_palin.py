def largest(s,i,j):
    if i>j:
        return 0
    if i==j:
        return str(s[i])
    if s[i]==s[j]:
        return 2+largest(s,i+1,j-1)
    else:
        return max(largest(s,i+1,j),largest(s,i,j-1)) 


s="heflffddslsdse"
print(largest(s,0,len(s)-1))