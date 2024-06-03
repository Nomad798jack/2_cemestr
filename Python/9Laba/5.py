import numpy as np
from scipy.stats import multivariate_normal
def log_normal(x, m, c):
    l = len(m)
    det_C = np.linalg.det(c)
    inv_C = np.linalg.inv(c)
    log_term = -0.5*np.sum((x-m)@inv_C*(x-m), axis=1)
    const_term = -0.5*l*np.log(2*np.pi)-0.5*np.log(det_C)
    return log_term + const_term

x = np.random.randn(100, 2)
m = np.array([0, 0])
c = np.array([[1, 0.5], [0.5, 2]])
logcustom = log_normal(x, m, c)
logscipy = multivariate_normal(m, c).logpdf(x)

print(np.allclose(logcustom, logscipy))