import numpy as np
from read import read_file
from GausJordan import Gaus_Jordan
from Cramer import Cramer

np.set_printoptions(linewidth=10000)

A,B = read_file("equ1.txt")
C = Cramer(A, B)
GJ = Gaus_Jordan(A, B)
print(C)
print(GJ)