# Numerical Methods Course, August-December 2024
# Program for lagrangian interpolation
# Date: November 19, 2024
# Author: reDragonCoder

def inter_lag(x_d, y_d, x):
   #Calculate the interpolated value of a function at a given point
    #using Lagrange's method

    #Inputs:
    # x_d: List of x values ​​in data points
    # y_d: List of y values ​​in data points
    # x: The value of x at which you want to calculate the interpolated value

    #Outputs:
    # The interpolated value of y at point x

    n=len(x_d)
    y=0
    for i in range (n):
        #Calculate the term L_i(x)
        l=1
        for j in range(n):
            if i!=j:
                l*=(x-x_d[j])/(x_d[i]-x_d[j])
        y+=y_d[i]*l
    return y

#Example of use:
x_data=[-3, -1, 1, 2]
y_data=[1, -1, 2, -4]
print('Points x: ', x_data)
print('Points y: ', y_data)

x1=-3
y1_int =inter_lag(x_data, y_data, x1)
print("The interpolated value at x =", x1, "is: ", y1_int)

x2=-2
y2_int =inter_lag(x_data, y_data, x2)
print("The interpolated value at x =", x2, "is: ", y2_int)

x3=-1
y3_int =inter_lag(x_data, y_data, x3)
print("The interpolated value at x =", x3, "is: ", y3_int)

x4=0
y4_int =inter_lag(x_data, y_data, x4)
print("The interpolated value at x =", x4, "is: ", y4_int)

x5=1
y5_int =inter_lag(x_data, y_data, x5)
print("The interpolated value at x =", x5, "is: ", y5_int)

x6=1.5
y6_int =inter_lag(x_data, y_data, x6)
print("The interpolated value at x =", x6, "is: ", y6_int)

x7=2
y7_int =inter_lag(x_data, y_data, x4)
print("The interpolated value at x =", x7, "is: ", y7_int)

#x={x1, x2, x3, x4, x5, x6, x7}
#f=[y1_int, y2_int, y3_int, y4_int, y5_int, y6_int, y7_int]

import numpy as np
import matplotlib.pyplot as plt

x=np.linspace(x1, x7, 100)
y=inter_lag(x_data, y_data, x)
plt.plot(x, y)
plt.show()
