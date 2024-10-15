# Numerical Methods Course, August-December 2024
# Program for false rule method, root search
# Date: September 27, 2024
# Autor: reDragonCoder

# Used to find a solution of f(x)=0, where f(x) is a continuous function that has 
# p0=a and p1=b as initial approximations to the root.

from math import*

def pol(x):
    # Test function
    return cos(x)-x

def falseRule(f, p0, p1, tol, n):
    # False rule implementation
    # Inputs:
        # f -- function
        # p0 -- initial approach
        # p1 -- initial approach
        # n -- maximum number of iterations
    # Outputs:
        # p=approximation to the root of f
        # None in case of finished iterations

    i=2 
    q0=f(p0)
    q1=f(p1)
    while i<=n:
        p=p1-q1*((p1-p0)/(q1-q0))
        print("Iter={0:<2}  p={1:.12f}  f(p)={2:.12f}".format(i,p,f(p)))
        if abs(p-p1)<tol:
            return p;
        q=f(p)
        i+=1
        if q*q1<0:
            p0=p1
            q0=q1 
        p1=p
        q1=q
    print ("Iteraciones agotadas")
    return None

falseRule(pol, 0, 1, 1e-6, 100)
