import numpy as np
matrix = np.loadtxt('1_txt.txt', delimiter=',')
sum = np.sum(matrix)
max_el = np.max(matrix)
min_el = np.min(matrix)
print(sum)
print(max_el)
print(min_el)