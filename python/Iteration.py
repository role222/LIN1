import numpy as np
from read import read_file

def Iteration(A, B, Eps = 1e-8):
    B1 = B.reshape(-1,1)
    C = np.hstack((A, B1))
    X1 = np.zeros(C.shape[0])
    X2 = np.zeros(C.shape[0])
    for i in range(0, C.shape[0]):
        C[i] = C[i] / C[i, i]
    while 1:
        for i in range(0, C.shape[0]):
            X1[i] = C[i, C.shape[0]]
            for j in range(0, C.shape[0]):
                if i != j:
                    X1[i] = X1[i] - X2[j] * C[i, j]

        if np.all(np.abs(X1 - X2) <= Eps):
            break

        X2 = X1.copy()
    return X2


def main():
    A, B = read_file("../data_for_test/equ3.txt")
    X = Iteration(A, B)
    print(X)

if __name__ == "__main__":
    np.set_printoptions(linewidth=10000)
    main()