n = int(input("Введите число"))

mas = [[" "]*((2**n)-1) for i in range(2**(n-1))]

mas[0][((2**n)//2)-1] = "^"

x1 = ((2**n)//2)-1
y1 = 0
x2 = ((2**n)//2)-1
y2 = 0
 
for i in range(1, n):
    for j in range(y1, y2 + 1):
        for k in range(x1, x2 + 1):
            mas[j+(2**(i-1))][k-(2**(i-1))] = mas[j][k]
            mas[j+(2**(i-1))][k+(2**(i-1))] = mas[j][k]
    x1 -= 2**(i-1)
    x2 += 2**(i-1)
    y2 = ((y2+1)*2)-1

for i in range(2**(n-1)):
    for j in range((2**n)-1):
        print(mas[i][j], end = "")
    print()
