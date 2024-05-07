print("Номер 1")

str = input("Введите символы через запятую\n").split(',')
Setstr = set(str)
print(len(Setstr))

print("Номер 2")

Mnoj1 = input("Введите первое множество через запятую\n").split(',')
Mnoj2 = input("Введите второе множество через запятую\n").split(',')
k = 0
for i in Mnoj1:
    if i in Mnoj2:
        k+=1
if k == len(Mnoj1):
    print('True')
else:
    print('False')

print("Номер 3")
n = int(input("Введите кол-во городов\n"))
Set = set()
m = 1
cnt = 0
while m == 1:
    gorod = input("Введите название города\n")
    if gorod in Set:
        print("REPEAT")
        break
    else:
        Set.add(gorod)
        print('OK')
        cnt+=1
    if cnt == n:
        print("END")
        break
    
print("Номер 4")
liststr = input("Введите слова\n").split()

dict = {}

for i in liststr:
    if i in dict:
        print(dict[i], end = " ")
        dict[i] += 1
    else:
        print(0, end = " ")
        dict[i] = 1

print("Номер 5")
k = int(input("Введите количество записей\n"))
data = {}
for i in range(k):
    log = input().split()
    if log[0] not in data:
        data[log[0]] = {}
    if log[1] not in data[log[0]]:
        data[log[0]][log[1]] = int(log[2])
    else:
        data[log[0]][log[1]] += int(log[2])

print("Результат:")
for i in data.keys():
    print()
    print(i + ":")
    for j in data[i].keys():
        print(j + " - ", end = "")
        print(data[i][j])

print("Номер 6")
txt = input("Введите текст\n").split()
txtdict = {}
for i in txt:
    if i in txtdict:
        txtdict[i] += 1
    else:
        txtdict[i] = 1
txtlist = [[i, txtdict[i]] for i in txtdict]
txtlist.sort(key = lambda word: [-word[1], word[0]])
for i in txtlist:
    print(i[0])


