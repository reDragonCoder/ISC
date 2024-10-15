# Numerical Methods Course, August-December 2024
# Program for bisection methods, root search
# Date: September 5, 2024
# Autor: reDragonCoder

# The solution of f(x)=0 is sought in an interval [a, b]
# where f(x) is continuous on the interval [a, b], and f(a)*f(b)<0

from math import*

def pol(x):
    # Test function
    return x**3+4*x**2-10

def bisec(f, a, b, tol, n):
    #Implementation of bisection method
    # Inputs:
        # f -- function
        # a -- far left
        # b -- far right
        # tol -- tolerance
        # n -- maximum number of iterations
    # Outputs:
        # p=approximation to the root of f
        # None in case of finished iterations
    i=1
    while i<=n:
        p=a+(b-a)/2
        fa=f(a)
        fb=f(b)
        fp=f(p)
        print("i={0:<2}, a={1:.6f}, b={2:.6f}, p={3:.6f}, fa={4:.6f}, fb={5:.6f}, fp={6:.6f}". format(i,a,b,p,fa,fb,fp))
        if abs(fp)<=1e-6 or (b-a)/1<tol:
            return p
        i+=1
        if fa*fp>0:
            a=p
        else:
            b=p
    print("Finished iterations")
    return None

bisec(pol, 1, 2, 1.e-6, 11)
