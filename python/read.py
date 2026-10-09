import numpy as np

def read_file(filename):
    with open(filename, "rt", encoding="utf-8") as src:
        B = [float (x.strip()) for x in next(src).split(",")]
        A = []
        for line in src:
            A.append([float (x.strip()) for x in line.split(",")])
    return np.array(A, dtype = np.float64), np.array(B, dtype = np.float64)