import numpy as np

def Cramer(A, B):
    Te = np.linalg.det(A)
    C = A.copy()
    if Te == 0:
        return
    X = np.zeros(B.shape[0])
    for x in range(0, B.shape[0]):
        C1 = C.copy()
        C1[:, x] = B
        Tx = np.linalg.det(C1)
        X[x] = Tx/Te
    return X.reshape(-1,1)