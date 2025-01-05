# Numerical Methods Course, August-December 2024
# Program for 4th order Runge-Kutta method
# Date: December 12, 2024
# Author: reDragonCoder

from math import *

def rungeKutta(b,a,N,c):
    #Useful to approximate the solution of the initial value 
    # problem y' = f(t, y), a<=t<=b, y(a)=c, in (N+1) numbers 
    # equally spaced in the interval [a, b]

    #Inputs:
    # Ends a, b
    # Integer N
    # Initial condition c

    #Outputs:
    # Approximation w for y in the values ​​(N+1) of t

    e=2.7182818
    for i in range(0,N):
        y=(2*(e**b)-b-1)
        print("x{0:<2} = {1:.6f} - y{0:<2} = {2:.6f} - y{0:<2} exact = {3:.6f}".format(i,b,a,y))
        k1=b+a
        k2=(b+(c/2))+(a+((c/2)*k1))
        k3=(b+(c/2))+(a+((c/2)*k2))
        k4=(b+c)+(a+(c*k3))

        a=a+(c/6*(k1+(2*k2)+(2*k3)+k4))
        b=b+c

# TEST ZONE
rungeKutta(0,1,3,0.2)
