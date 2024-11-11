# Numerical Methods Course, August-December 2024
# Program for Fixed-Point Method
# Date: November 10, 2024
# Author: Cesar Andres Zuleta Malanco

# Useful to obtain a solution of x=g(x) given an initial 
# approximation p0

import math

def pol(x):
    return math.sqrt((10/(x+4)))

def fixedPoint(g,p0,tol,n):
    #Fixed-Point method implementation
    # Inputs:
        # g -- function already cleared
        # p0 -- initial approach
        # tol -- tolerance
        # n -- maximum number of iterations
    # Outputs:
        # p -- approach to the root
    i=1
    while i<=n:
        p=g(p0)
        print(f"i={i:<2}, p0={p0:.6f}, p={p:.6f}")
        if abs(p-p0)<tol:
            return p
        i=+1
        p0=p
    print("Exhausted iterations")
    return None

root=fixedPoint(pol, 1.5, 1.e-3, 100)
print(f"\nApproximate root: {root:.6f}")