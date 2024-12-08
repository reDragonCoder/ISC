# Numerical Methods Course, August-December 2024
# Program for euler method
# Date: December 7, 2024
# Author: reDragonCoder

def euler(a, b, N, alpha, f):
    #Useful to approximate the solution of the initial value problem 
    #y'=f(t,y), a<=t<=b, y(a)=α in (N+1) numbers equally spaced in 
    # the interval [a, b ]

    #Inputs:
    # Ends a, b
    # Integer N
    # Initial condition α

    #Outputs:
    # Approximation w for y at (N+1) values ​​of t

    h=(b-a)/N 
    t=a 
    w=alpha 
    t_values=[t] 
    w_values=[w] 
    
    for i in range(1, N+1): 
        w=w+h*f(t, w)
        t=a+i*h 
        t_values.append(t) 
        w_values.append(w) 
    
    return t_values, w_values

#TEST ZONE
# Define the function f(t, y)
def f(t, y):
    return -2*y  # Example: dy/dt=t*y

# Define the limits of the interval
a=0
b=1

# Define the step size 
h=0.2

# Define the number of subintervals
#N=10
N=int((b-a)/h)

# Define the initial condition
alpha=1

# Calling the euler function
t_values, w_values=euler(a, b, N, alpha, f)

# Print the approximations
for t, w in zip(t_values, w_values):
    print(f'Approximation at t = {t}: {w}')

