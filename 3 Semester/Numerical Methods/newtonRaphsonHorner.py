# Numerical Methods Course, August-December 2024
# Program for Newton-Raphson-Horner method
# Date: November 10, 2024
# Autor: reDragonCoder

# It is useful for calculating roots of polynomials quickly

import sympy as sp
from sympy import symbols, diff
from math import *

def newtonRaphsonHorner(coeffs, n, p0, tol, N):
    #Newton-Raphson-Horner method implementation
    # Inputs:
        # coeffs -- coefficients
        # n -- degree
        # p0 -- initial approach
        # tol -- tolerance
        # N -- total amount of runs
    #Outputs: 
        # y = f(p0)
        # z = f'(p0)
    i=1
    while i<=N:
        y=coeffs[0]
        z=coeffs[0]
        k=i-1
        print(f"p{k} = {p0:.6f}")
        for j in range(1, n):
            y=p0*y+coeffs[j]
            z=p0*z+y
            
        y=p0*y+coeffs[n]
        print(f"Iteration {i}: p({i})={y:.6f}, p'({i})={z:.6f}")
        p=p0-(y/z)
        if abs(p-p0)<tol:
            return y
        i+=1
        p0=p
        print()
        
n=3
coeffs=[1, 0, 2, -2] # Polynomial: p(x)=4x^3-2x^2+5x+4
p0=0.5
raiz = newtonRaphsonHorner(coeffs, n, p0, 1.e-3, 5)
print(f"\nApproximate root: {raiz:.6f}")

