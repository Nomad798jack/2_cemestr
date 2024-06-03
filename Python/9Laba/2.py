import numpy as np
x = np.array([2,2,2,3,3,4,4,4,7,7,7,7])
a = b = []
lastN = x[0]
lastCnt = 1
for i in range(1, len(x)):
    if x[i] == lastN:
          lastCnt += 1
    else:
        a.append(lastN)
        b.append(lastCnt)
        lastN = x[i]
        lastCnt = 1
a.append(lastN)
b.append(lastCnt)   
output = (np.array(a), np.array(b))
print(x)
print(output)
