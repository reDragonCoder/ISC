# Numerical Methods Course, August-December 2024
# Program for simple linear regression
# Date: November 10, 2024
# Author: Cesar Andres Zuleta Malanco

# Useful to estimate the coefficients a0 and a1 in the 
# simple linear regression model y=a0+a1x+E

from math import *

def get_couples_run_regression():
    n=int(input("Enter the number of couples (xi, yi): "))

    couples=[]
    for i in range(n):
        xi=float(input(f"Enter the x{i+1} value: "))
        yi=float(input(f"Enter the y{i+1} value: "))
        couples.append((xi, yi))

    a0, a1, r=Regression(n, couples)

    print(f"\na0 coefficient: {a0}")
    print(f"a1 coefficient: {a1}")
    print(f"Correlation r coefficient: {r}")

def Regression(n, couples):
    #Simple linear regression implementation
    # Inputs:
        # n -- (xi, yi) couple number 
        # (xi, yi) -- couples for i=1, 2, 3, ..., n
    # Outputs: 
        # a0, a1 -- coefficients
        # r --correlation coefficient

    Sx, Sy, Sxy, Sx_square, Sy_square=0,0,0,0,0

    for i in range(n):
        xi, yi=couples[i]
        Sx+=xi
        Sy+=yi
        Sxy+=xi*yi
        Sx_square+=xi**2
        Sy_square+=yi**2
    
    a1=(n*Sxy-Sx*Sy)/(n*Sx_square-Sx**2)
    a0=(Sy/n)-a1*(Sx/n)


    SSy=sqrt((Sy_square-(Sy/n)**2)/(n-1))
   
    SSyiX=sqrt(sum((yi-(a0+a1*xi))**2 for xi, yi in couples)/(n-2))

    r_square=((n-1)*SSy**2-(n-2)*SSyiX**2)/((n-1)*SSy**2)
    r=sqrt(r_square)
    
    return a0, a1, r

get_couples_run_regression()

