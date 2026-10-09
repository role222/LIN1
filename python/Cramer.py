import numpy as np
from read import read_file

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
        X[x] = Tx
    X = X / Te
    return X

def main():
    A, B = read_file("../data_for_test/equ1.txt")
    X = Cramer(A, B)
    print(X)

if __name__ == "__main__":
    np.set_printoptions(linewidth=10000)
    main()