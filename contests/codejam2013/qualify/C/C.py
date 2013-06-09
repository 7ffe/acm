import math

def isPalin(n):
    s = str(n)
    d = s[::-1]
    return s==d

#infile = open('C.in', 'r')
#outfile = open('C.out', 'w')

infile = open('C-large-1.in', 'r')
outfile = open('C-large-1.out', 'w')

T = int(infile.readline())
#print T
for t in range(1, T+1):
    line = infile.readline()
    parts = line.split()
    A = int(parts[0])
    B = int(parts[1])
    a = int(math.sqrt(A))
    b = int(math.sqrt(B))
    if (a*a !=A):
        a+=1
    cnt =0
    print t, a, b
    for n in range(a, b+1):
        if isPalin(n*n) and isPalin(n):
            cnt+=1
    #print 'Case #'+str(t)+': '+str(cnt)
    outfile.write('Case #'+str(t)+': '+str(cnt)+'\n')
outfile.close()
print 'Done'
