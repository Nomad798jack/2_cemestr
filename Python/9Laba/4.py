import numpy as np
import random
x = np.array([random.randint(0, 10) for i in range(random.randint(0, 100))])
maX = -1
for i in range(1, x.size):
        if x[i - 1] == 0:
            maX = max(maX, x[i])
print(x)
print(maX)