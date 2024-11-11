# Numerical Methods Course, August-December 2024
# Program for Gauss-Seidel Method
# Date: November 10, 2024
# Author: Cesar Andres Zuleta Malanco

# Useful to solve the quadratic linear system Ax=b

from math import *

# TESTING
n, N=4, 6
a, b=[], []

x=[0,0,0,0]
a=[[10, -1, 2, 0],[-1,11,-1,3],[2,-1,10,-1],[0,3,-1,8]]
b=[6,25,-11,15]

def gaussSeidel(n,a,x,b):
    #Gauss-Seidel method implementation
    # Inputs:
        # n -- number of equations and unknown variables
        # a -- equations system
        # x -- initial response
        # b -- systems responses
        # N -- maximum number of iterations
    # Outputs:
        # x -- solutions
    n=len(a)                   
    for j in range(0,n):
        d=b[j]
        for i in range (0,n):
            if(j!=i):
                d-=a[j][i]*x[i]
        x[j]=d/a[j][j]
    return x

for i in range(0, N):            
    x=gaussSeidel(n, a, x, b)
    for j in range(0,n): print(f"x{j}={x[j]:.6f}")
    print()