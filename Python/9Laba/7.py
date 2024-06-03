import numpy as np
url = "https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data"
iris = np.genfromtxt(url, delimiter=",", dtype = "object")
unique = []
for i in iris:
    if i[4] not in unique:
        unique.append(i[4])   
print(unique)
print(len(unique))