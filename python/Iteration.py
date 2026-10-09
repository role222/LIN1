import numpy as np
from read import read_file

def Iteration(A, B):
    Te = np.linalg.det(A)
















def main():
    A, B = read_file("../data_for_test/equ2.txt")
    X = Iteration(A, B)
    print(X)

if __name__ == "__main__":
    main()