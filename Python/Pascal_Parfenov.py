def next_row(row):
    row = [1] + row
    for i in range(1, len(row)-1):
        row[i] += row[i+1]
    return row

n = int(input("Введите число"))

row = []

for i in range(n):
    row = next_row(row)
    print(row)
