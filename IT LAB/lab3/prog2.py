
f=open('prog1.py','r')
f2=open('newfile.txt','w+')
lines=f.readlines()
for line in reversed(lines):
    line=line[::-1]
    f2.write(line)

f2.close()

f2=open('newfile.txt','r')
for line in f2:
    print(line)
   
f.close()
f2.close()