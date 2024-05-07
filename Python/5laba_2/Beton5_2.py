file = open('input2.txt','r')
list = file.read().split('\n')
listmas = [int (x) for x in list]
listmas.sort()
file.close()
file = open('output2.txt','w')
for a in listmas:
    file.write(str(a) + '\n')
file.close()


print(listmas)