import numpy as np

def Gaus_Jordan(A, B):
    B1 = B.reshape(-1,1)
    C = np.hstack((A, B1))
    for i in range(0, C.shape[0]):
        max_row_index = np.argmax(np.abs(C[:, i]))
        if max_row_index != i:
            C_ = C[i].copy()
            C[i] = C[max_row_index].copy()
            C[max_row_index] = C_.copy()
    for x in range(0, C.shape[0]):
        for y in range(x, C.shape[0]):
            C[y] = C[y] / C[y, x]
        for y in range(x+1, C.shape[0]):
            for z in range(0, C.shape[1]):
                C[y, z] = C[y, z] - C[x, z]
    X = np.zeros_like(B1)
    for x_ in range(0, C.shape[0]):
        x = C.shape[0] - x_ - 1
        for y in range(x+1, C.shape[1]-1):
            C[x, C.shape[1] - 1] = C[x, C.shape[1] - 1] - (X[y, 0] * C[x, y])
        X[x, 0] = C[x, C.shape[1] - 1]
    return X