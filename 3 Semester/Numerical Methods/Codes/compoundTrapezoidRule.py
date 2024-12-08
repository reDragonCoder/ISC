# Numerical Methods Course, August-December 2024
# Program for compound trapezoid rule
# Date: December 7, 2024
# Author: reDragonCoder

import math

def trapezoidRule(a, b, n, f):
    #Useful to approximate the integral I=∫[a, b] f(x)dx

    #Inputs:
    # Ends a, b
    # Positive integer n even

    #Outputs:
    # Approximation X I for I

    h=(b-a)/n
    xI0=f(a)+f(b)
    xI1=0

    for i in range(1, n):
        x=a+i*h
        xI1+=f(x)

    xI=(h/2)*(xI0+2*xI1)
    
    return xI


# TEST ZONE
# Define the function
def my_function(x):
    return math.exp(-0.5*x**2)

# Define the limits of integration
a=0
b=2

# Define the number of subintervals (should be an even number)
n=4

# Calling the trapezoidRule function
result=trapezoidRule(a, b, n, my_function)
print(f'The approximation of the integral is: {result}')
