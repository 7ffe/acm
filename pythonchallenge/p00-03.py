print 2**38
#274877906944

def Change(ch):
    if (ch>='a' and ch<='z'):
        return chr((ord(ch)-ord('a')+2)%26 + ord('a'))
    else:return ch

s = "g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj."
ans = ""
for ch in s:
    ans += Change(ch)
print ans
    
#i hope you didnt translate it by hand. thats what computers are for. doing it in by hand is inefficient and that's why this text is so long. using string.maketrans() is recommended. now apply on the url.

import string
#below is the way it recommended
d =  string.maketrans('abcdefghijklmnopqrstuvwxyz', 'cdefghijklmnopqrstuvwxyzab')
string.translate(s, d)

##2
infile = open('d02.txt', 'r')
s = infile.read()
infile.close()
d = {}
for ch in s:
    if ch in d:
        d[ch] = d[ch]+1
    else:
        d[ch] = 1
print d
t = ""
for ch in d.keys():
    if (d[ch]<2):
        t = t+ch
print t
for ch in s:
    if ch in t:
        print ch
#equality

##3
infile = open('d03.txt', 'r')
s = infile.read()
infile.close()
def big(ch):
    return (ch>='A' and ch<='Z')
s = ''.join(s.split('\n'))
t = ""
for i in range(4, len(s)-4):
    if not big(s[i-4]) and big(s[i-3]) and big(s[i-2]) and big(s[i-1]) and (not big(s[i])) and big(s[i+3]) and big(s[i+2]) and big(s[i+1]) and not big(s[i+4]):
        t += s[i]
print t
#linkedlist    
import re
print "".join(re.findall('[^A-Z][A-Z]{3}([a-z])[A-Z]{3}[^A-Z]', s))
