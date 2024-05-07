file = open('input.txt','r')
list = file.read().split(' ')
proizvedenie = 1
a = [int (x) for x in list]
for i in range(len(a)):
    proizvedenie = proizvedenie*a[i]

file.close()
file = open('output.txt', 'w')
file.write(str(proizvedenie) + '\n')
file.close()

