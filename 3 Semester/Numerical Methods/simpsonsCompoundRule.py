# Numerical Methods Course, August-December 2024
# Program for Simpson's Compund Rule
# Date: December 12, 2024
# Author: reDragonCoder

import math

def simpson(a, b, n, f):
    #Useful to approximate the integral I=∫[a, b] f(x)dx

    #Inputs:
    # Ends a, b
    # Even positive integer N

    #Outputs:
    #  Approximation X I for I

    if n%2!= 0: 
        raise ValueError("n must be an even positive integer.")

    h=(b-a)/n

    xI0=f(a)+f(b)
    xI1=0
    xI2=0

    for i in range(1, n):
        x=a+i*h
        if i%2==0:
            xI2+=f(x)
        else:
            xI1+=f(x)
    
    xI=(h*(xI0+2*xI2+4*xI1))/3

    return xI

#TEST ZONE
# Define the function
def my_function(x):
    return math.exp(-0.5*x**2)

# Define the limits of integration
a=0
b=2

# Define the number of subintervals (should be an even number)
n=4

# Calling Simpson's function
result=simpson(a, b, n, my_function)
print(f'The approximation of the integral is {result}')
