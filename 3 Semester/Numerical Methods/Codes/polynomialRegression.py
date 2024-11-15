# Numerical Methods Course, August-December 2024
# Program for polynomial regression
# Date: November 14, 2024
# Author: reDragonCoder

# Useful to find the coefficients a0, a1, a2, ..., am of the 
# multiderivative linear model y=a0+a1x1+a2x2+...+amxm

import numpy as np

# x=np.array([ [5.1], [2.9], [1.8], [1.7], [4.1] ])
# y=np.array([ [40.5], [25.05], [17.55], [16.55], [33.7] ])

# Linear regression with two independent variables
# x=np.array([ [0, 0], [2, 1], [2.5, 2], [1, 3], [4, 6], [7, 2] ])
# y=np.array([ [5], [10], [0], [3], [27] ])

# Polynomial regression of degree two
x=np.array([ [0, 0], [1, 1], [2, 4], [3, 9], [4, 16], [5, 25] ])
y=np.array([ [2.1], [7.7], [13.6], [27.2], [40.9], [61.1] ])

print('X: ')
print(x)
print('Y: ')
print(y)

# Add a column of ones to X to include the intersection term
x_b=np.c_[np.ones((x.shape[0], 1)), x]
print('X_b: ')
print(x_b)

# We calculate the coefficients using the minimum squares formula
# a = (x_b.T * x_b)^(-1) * x_b.T * y
a=np.linalg.inv(x_b.T.dot(x_b)).dot(x_b.T).dot(y)
print('Coefficient vector: ')
print(a)

# Make predictions on the data set
y_pred=x_b.dot(a)
print('Values ​​estimated by the model: ')
print(y_pred)

# Model evaluation: calculate the mean square error (MSE) and the coefficient of determination
mse=np.mean((y-y_pred)**2)
ss_total=np.sum((y-np.mean(y))**2)
ss_residual=np.sum((y-y_pred)**2)
r2=1-(ss_residual/ss_total)

print("Mean square error (MSE): ", mse)
print("Determination coefficient (R^2): ", r2)