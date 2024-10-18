# Numerical Methods Course, August-December 2024
# Program for Jacobi Method
# Date: October 18, 2024
# Author: reDragonCoder

# Implementation of the Jacobi Method to solve
# quadratic linear systems Ax=b

from math import *

def distinf(x, y):
    # Test function
    return max([abs(x[i]-y[i]) for i in range (len(x))])

def Jacobi(A, b, x0, TOL, MAX):
    #Jacobi method implementation
    # Inputs:
        # A -- square matrix
        # b -- vector
        # x0 -- initial approach
        # TOL -- tolerance
        # MAX -- maximum number of iterations
    # Outputs: 
        # x -- approximation to the solution of the system Ax=b
        # None -- in case of finished iterations
    
    n=len(A)
    x=[0.0 for x in range(n)]
    k=1
    while k<=MAX:
        for i in range(n):
            if abs(A[i][i])<=1e-15:
                print("Can't iterate")
                return None
            s=sum([A[i][j]*x0[j] for j in range(n) if j!=i])
            x[i]=(b[i]-s)/A[i][i]
        print(x)
        if distinf(x, x0)<TOL:
            print("Solution found")
            return x
        k+=1
        for i in range(n):
            x0[i]=x[i]
    print("Finished Iterations")
    return None

# A=[[2, 1], [5, 7]]
# b=[11, 13]
# x0=[1, 1]
# Jacobi(A, b, x0, 1e-5, 50)


A1=[[5, -1, 1, 1], [1, 4, 0, 1], [3, -1, 6, 0], [0, 1, -1, 3]]
b1=[5, 2, -3, 4]
x01=[-1, 5, 3, 2]
sol=Jacobi(A1, b1, x01, 1e-15, 50)
print(sol)
