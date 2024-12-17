# Numerical Methods Course, August-December 2024
# Program for Derivatives of 2, 3 and 5 points
# Date: December 17, 2024
# Author: reDragonCoder

import math

def j(x):
    # Test function
    return x*math.e**x

def g(x):
    # Test function
    return math.log(x)

def differential_forward_formula(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(f(x0+h)-f(x0))/h
    print("\nForward difference formula (two points)")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

def differential_backward_formula(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(f(x0)-f(x0-h))/h
    print("\nBackward difference formula (two points)")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

def differential_three_points_far_end(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(1/(2*h))*((-3*f(x0))+(4*f(x0+h))-f(x0+2*h))
    print("\nThree points end formula")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

def differential_three_points_centered(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(1/(2*h))*(f(x0+h)-f(x0-h))
    print("\nThree points centered formula")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

def differential_five_points_far_end(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(1/(12*h))*((-25*f(x0))+(48*f(x0+h))+(-36*f(x0+2*h))+(16*f(x0+3*h))-(3*f(x0+4*h)))
    print("\nFive points end formula")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

def differential_five_points_centered(x0, h, f):
    # Inputs:
    # h - increment
    # x0 - initial value
    # f - function to examine

    # Outputs:
    # Estimated value of differentiation
    fd=(1/(12*h))*(f(x0-2*h)-(8*f(x0-h))+(8*f(x0+h))-f(x0+2*h))
    print("\nFive points centered formula")
    print("     Initial value: {0:<2} \n     Increment: {1:.2f} \n     Calculated derivative: {2:.6f}\n".format(x0, h, fd))

# Example usage
differential_forward_formula(1.8, 0.1, g)
differential_backward_formula(1.8, 0.1, g)
differential_three_points_far_end(2.0, 0.1, j)
differential_three_points_centered(2.0, 0.1, j)
differential_five_points_far_end(2.0, 0.1, j)
differential_five_points_centered(2.0, 0.1, j)
