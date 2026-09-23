import numpy as np

np.set_printoptions(linewidth=10000)

def read_file(filename):
    with open(filename, "rt", encoding="utf-8") as src:
        B = [float (x.strip()) for x in next(src).split(",")]
        A = []
        for line in src:
            A.append([float (x.strip()) for x in line.split(",")])
    return np.array(A, dtype = np.float64), np.array(B, dtype = np.float64)

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
    print(X)



A,B = read_file("equ1.txt")

Te = np.linalg.det(A)
#print(Te)
Gaus_Jordan(A, B)
