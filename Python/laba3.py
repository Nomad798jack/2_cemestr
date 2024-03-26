print('НОМЕР 1')
str = "FFFggZZZZbbBBbbbHHH"
k = 1
list = []
for i in range(len(str)-1):
    if str[i] != str[i+1]:
        list.append(k)
        list.append(str[i])
        k =1
    else: k += 1
list.append(k)
list.append(str[-1])

print(list)

print('НОМЕР 2')
tmp = 0
bukva = ''
newlist = []
for i in range(0,len(list),2):
    tmp = list[i]
    bukva = list[i+1]
    for j in range(tmp):
        newlist.append(bukva)
print(newlist)

print('НОМЕР 3')
res = ''
n = int(input())
if n < 10:
    if (n == 1):
        res += ' один'
    elif (n == 0):
        res += ' ноль'
    elif (n == 2):
        res += ' два'
    elif (n == 3):
        res += ' три'
    elif (n == 4):
        res += ' четыре'
    elif (n == 5):
        res += ' пять'
    elif (n == 6):
        res += ' шесть'
    elif (n == 7):
        res += ' семь'
    elif (n == 8):
        res += ' восемь'
    elif (n == 9):
        res += ' девять'
if n > 99:
    if (n // 100 == 1):
        res += 'сто'
    elif (n // 100 == 2):
        res += 'двести'
    elif (n // 100 == 3):
        res += 'триста'
    elif (n // 100 == 4):
        res += 'четыреста'
    elif (n // 100 == 5):
        res += 'пятьсот'
    elif (n // 100 == 6):
        res += 'шестьсот'
    elif (n // 100 == 7):
        res += 'семьсот'
    elif (n // 100 == 8):
        res += 'восемьсот'
    elif (n // 100 == 9):
        res += 'девятьсот'
    n = n % 100
if n > 9:
    if (n == 11):
        res += ' одиннадцать'
    elif (n == 12):
        res += ' двенадцать'
    elif (n == 13):
        res += ' тринадцать'
    elif (n == 14):
        res += ' четырнадцать'
    elif (n == 15):
        res += ' пятнадцать'
    elif (n == 16):
        res += ' шестнадцать'
    elif (n == 17):
        res += ' семнадцать'
    elif (n == 18):
        res += ' восемнадцать'
    elif (n == 19):
        res += ' девятнадцать'
    elif (n == 10):
        res += ' десять'
    elif (n // 10 == 2):
        res += ' двадцать'
    elif (n //10 == 3):
        res += ' тридцать'
    elif (n // 10 == 4):
        res += ' сорок'
    elif (n // 10 == 5):
        res += ' пятьдесят'
    elif (n // 10 == 6):
        res += ' шестьдесят'
    elif (n // 10 == 7):
        res += ' семьдесят'
    elif (n // 10== 8):
        res += ' восемьдесят'
    elif (n // 10 == 9):
        res += ' девяносто'
if (n//10>1):
    n = n % 10
    if n > 0:
        if (n == 1):
            res += ' один'
        elif (n == 2):
            res += ' два'
        elif (n == 3):
            res += ' три'
        elif (n == 4):
            res += ' четыре'
        elif (n == 5):
            res += ' пять'
        elif (n == 6):
            res += ' шесть'
        elif (n == 7):
            res += ' семь'
        elif (n == 8):
            res += ' восемь'
        elif (n == 9):
            res += ' девять'
n // 10
if n == 1000:
    res += 'тысяча'
print(res)

print('НОМЕР 4')
spisokstr = input("введите строки: ").split()
slovar = {}

for i in spisokstr:
    if i in slovar: slovar[i] += 1
    else: slovar[i] = 1

print(slovar)


print('НОМЕР 5')
#Столбцы можно выразить через линейную комбинацию других столбцов <=> определитель равен нулю
def determinant(a):    
    determinant = int(a[0][0]) * int(a[1][1]) * int(a[2][2]) \
                  + int(a[0][1]) * int(a[1][2]) * int(a[2][0]) \
                  + int(a[0][2]) * int(a[1][0]) * int(a[2][1]) \
        - int(a[0][2]) * int(a[1][1]) * int(a[2][0]) \
        - int(a[0][0]) * int(a[1][2]) * int(a[2][1]) \
        - int(a[0][1]) * int(a[1][0]) * int(a[2][2])
    
    if determinant == 0: print("столбцы линейно зависимы, матрица показана сверху")
    else: print("столбцы линейно независимы, матрица показана сверху" )

print("Введите матрицу 3х3:")
A = [input().split() for i in range(3)]

print('НОМЕР 6')

strinput = input("введите слова")
stroutput = ""

for i in range(len(strinput)):
    if i == 0: stroutput += strinput[i]
    elif strinput[i - 1] == " ": stroutput += strinput[i]

stroutput = stroutput.upper()

print(stroutput)



    
    
    
    

