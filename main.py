import numpy as np

np.set_printoptions(linewidth=100)

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
    for x in range(0, C.shape[0] - 1):


A,B = read_file("equ1.txt")

Te = np.linalg.det(A)
#print(Te)
Gaus_Jordan(A, B)
