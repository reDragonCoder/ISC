# Numerical Methods Course, August-December 2024
# Program for the secant method, root search
# Date: September 5, 2024
# Autor: reDragonCoder

from math import*

def g(x):
    # Test function
    return x**3+4*x**2-10

def secant(f, p0, p1, tol, n):
    # Secant method implementation
    # Inputs:
        # f -- function
        # p0 -- initial approach (left end of interval)
        # p1 -- initial approach (right end of interval)
        # tol -- tolerance
        # n -- maximum number of iterations
    # Output: 
        # p approximation to zero of f
        # None in case of finished iterations

    i=2
    while i<=n:
        p=p1-(f(p1)*(p1-p0))/(f(p1)-f(p0))
        print("Iter={0:<2}  p={1:.12f}  f(p)={2:.12f} ".format(i, p, f(p)))
        if abs(p-p1)<tol:
            return p
        p0=p1
        p1=p
        i+=1        
    print("Finished iterations")
    return None

secant(g, 1, 2, 1e-6, 7)
