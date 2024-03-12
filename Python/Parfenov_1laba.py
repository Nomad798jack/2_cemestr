#Задание 1
a = int(input("Введите число"))
b = int(input("Введите число"))
c = int(input("Введите число"))
if a==b==c:
    print(3)
if (a==b!=c) or (a!=b==c) or (a!=c==b):
    print(2)
if (a!=b!=c):
    print(0)



#Задание 2.1
n = int(input("Введите число"))
b = 0
s = ''
while b<n:
    b+=1
    for i in range(n):
        s+=str(b)
        break
    print(s)

#Задание 2.2
n = int(input("Введите число"))
x = ""
for i in range(1, n + 1):
    x = x + str(i)
    print(' ' * (n-i) + x + x[-2::-1])

        

        
