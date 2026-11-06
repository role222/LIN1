import numpy as np
from read import read_file

def Gaus_Jordan(A, B):
    B1 = B.reshape(-1,1)
    C = np.hstack((A, B1))
    for i in range(0, C.shape[0]):
        max_row_index = i + np.argmax(np.abs(C[i:, i]))
        if max_row_index != i:
            C_ = C[i, :].copy()
            C[i, :] = C[max_row_index, :].copy()
            C[max_row_index, :] = C_.copy()
    for x in range(0, C.shape[0]):
        C[x] = C[x] / C[x, x]
        for y in range(x + 1, C.shape[0]):
            C[y] = C[y] - (C[x] * C[y, x])
    X = np.zeros_like(B1)
    for x_ in range(0, C.shape[0]):
        x = C.shape[0] - x_ - 1
        for y in range(x+1, C.shape[1]-1):
            C[x, C.shape[1] - 1] = C[x, C.shape[1] - 1] - (X[y, 0] * C[x, y])
        X[x, 0] = C[x, C.shape[1] - 1]
    return X.reshape(-1)

def main():
    A, B = read_file("../data_for_test/equ2.txt")
    X = Gaus_Jordan(A, B)
    print(X)

if __name__ == "__main__":
    np.set_printoptions(linewidth=10000)
    main()