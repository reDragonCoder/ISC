# Numerical Methods Course, August-December 2024
# Program for Horner Method
# Date: November 10, 2024
# Author: Cesar Andres Zuleta Malanco

# Implementation of the Horner Method to evaluate polynomials of the form
# p(x)=anx^n+an-1x^n-1+...+a2x^2+a1x+a0 as well as its derivative p'(x) at 
# a given point x0

from math import *

def Horner(n, coefficients, x0):
    #Horner method implementation
    # Inputs:
        # n -- degree
        # an, an-1, ..., a2, a1, a0 -- coefficients
        # x0 -- point
    # Outputs: 
        # y = X0Y + aj 
        # z = X0Z + y 

    y=coefficients[0]
    z=coefficients[0]

    print(f"Iteration 0: y={y}, z={z}")

    for j in range(1, n):
        y=x0*y+coefficients[j]
        z=x0*z+y
        print(f"Iteration {j}: y={y}, z={z}")
    
    y=x0*y+coefficients[n]
    print(f"Iteration {n}: y={y}, z={z}")
    
    return y, z

# FOR TESTING
# Polynomial: p(x)=2x^5-3x^4+2x^3-5x^2+6x-4

n=3
coeffs=[4, -2, 5, 4] # Polynomial: p(x)=4x^3-2x^2+5x+4
x0=2

y, z=Horner(n, coeffs, x0)
print(f"\nThe polynomial value p({x0}) is: {y}")
print(f"The derivate p'({x0}) value is: {z}")


