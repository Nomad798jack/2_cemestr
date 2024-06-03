import numpy as np
import random
data = np.array([[int(random.normalvariate(mu=0.0, sigma=100.0)) for j in range(4)] for i in range(10)])
Standart = ((np.array([((i-(data.sum()/data.size))**2) for i in data]).sum())*(1/data.size))**0.5
print("Данные:", data)
print("Мин знач:", data.min())
print("Макс знач:", data.max())
print("Cp знач:", data.sum() / data.size)
print("Стандартное отклонение", Standart)

lines = data[0:5]