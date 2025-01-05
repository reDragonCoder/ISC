# Numerical Methods Course, August-December 2024
# Program for Newton-Raphson method
# Date: November 10, 2024
# Autor: reDragonCoder

# Useful to find a solution f(x)=0 in an interval [a, b], given an initial 
# approximation p0 E (a, b) with the assumptions that f(x) is continuous in 
# [a, b], of that f(a) and f(b) are non-zero and of opposite signs, and that 
# the derivative f'(x) exists at every point in [a, b]

import sympy as sp
from sympy import symbols, diff
from math import *

def pol(x):
    return x**3-2

def newtonRaphson(f,p0,tol,n):
    #Newton-Raphson method implementation
    # Inputs:
        # f -- function
        # p0 -- initial approach a+b/2
        # tol -- tolerance
        # n -- maximum number of iterations
    # Outputs:
        # p -- approach to the root
    i=1
    x=symbols('x')
    while i<=n:
        df=diff(f(x), x)
        f_p0=f(p0)
        df_p0=df.subs(x, p0)
        p=p0-f_p0/df_p0
        print(f"i={i:<2}, p0={p0:.6f}, p={p:.6f}")
        if abs(p-p0)<tol:
            return p
        i+=1
        p0=p
    print("Exhausted iterations")
    return None

root=newtonRaphson(pol, 1, 1.e-3, 100)
print(f"\nApproximate root: {root:.6f}")
