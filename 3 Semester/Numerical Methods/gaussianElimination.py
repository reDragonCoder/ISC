# Numerical Methods Course, August-December 2024
# Program for gaussian elimination method
# Date: November 10, 2024
# Autor: reDragonCoder

# Useful to solve the nxn linear system
# R1: a11X1 + a12X2 + ... + a1nXn = a1, n+1
# R1: a21X1 + a22X2 + ... + a2nXn = a2, n+1
# ...
# Rn: an1X1 + an2X2 + ... + anmXn = an, n+1
 
from math import *

def Gauss(A):
    #Gaussian elimination method implementation
    # Inputs:
        # n -- number of equations
        # A=(aij) -- extended matrix
    # Outputs: 
        # x1, x2, ..., xn -- solutions
        # ERROR -- fail message

    n=len(A)
    x=[0.0 for i in range(n)]
    for i in range(0,n-1):
            for j in range (i+1,n):
                mji=A[j][i]/A[i][i]
                rt=[A[j][k]-mji*A[i][k] for k in range(0,n+1)]
                A[j][:]=rt
    if A[n-1][n-1]==0:
        print("There is no single solution")
        return None
    print(A)

    x[n-1]=A[n-1][n]/A[n-1][n-1]
    for s in range(0,n-1):
        i=(n-1)-(s+1)
        x[i]=(A[i][n]-sum([A[i][j]*x[j] for j in range(i+1,n)]))/A[i][i]
    print("\nSolution:")
    print(x)

A=[[ 1, 1,2, 8],
   [ -1, -2, 3, 1],
   [ 3,-7, 4, 10]]

Gauss(A)


