import matplotlib.pyplot as plt
fig = plt.figure()
ax = fig.add_subplot(111)



f=open('file2.txt','r')
lines=f.readlines()

strFinal=""

for line in lines:
    strFinal=strFinal+line

wordlist=strFinal.split(' ')
wordfreq=[]
wordlist.sort()

# res = [] 
# for i in wordlist: 
#     if i not in res: 
#         res.append(i) 

for w in wordlist:
    wordfreq.append(wordlist.count(w))


print(res)
print(wordfreq)


ax.plot(wordfreq, wordlist, color='lightblue', linewidth=3)

ax.set_xlim(0.5, 4.5)
plt.show()