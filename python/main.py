import numpy as np
from read import read_file
from GausJordan import Gaus_Jordan
from Cramer import Cramer
from Iteration import Iteration

np.set_printoptions(linewidth=10000)

A,B = read_file("../data_for_test/equ3.txt")
C = Cramer(A, B)
print(C)
GJ = Gaus_Jordan(A, B)
print(GJ)
I = Iteration(A, B)
print(I)