# Numerical Methods Course, August-December 2024
# Program for multiple regression
# Date: December 17, 2024
# Author: reDragonCoder

import numpy as np

def multiple_regression_method(X, y):
    # Useful for performing multiple linear regression

    # Inputs:
    # X (ndarray): Matrix of independent variables.
    # y (ndarray): Vector of the dependent variable.

    # Outputs:
    # tuple: Model coefficients and the coefficient of determination R^2.

    if X.shape[0]!=y.shape[0]:
        raise ValueError("The number of rows in X must be equal to the number of elements in y.")
    if np.any(np.isnan(X)) or np.any(np.isnan(y)):
        raise ValueError("X and y must not contain null values.")
    
    coefficients, _, _, _=np.linalg.lstsq(X, y, rcond=None)
    
    y_pred=np.dot(X, coefficients)

    ss_total=np.sum((y-np.mean(y))**2)
    ss_residual=np.sum((y-y_pred)**2)
    r2=1-(ss_residual/ss_total)

    return coefficients, r2

if __name__=="__main__":
    X=np.array([[1, 0, 0], [1, 2, 1], [1, 2.5, 2], [1, 1, 3], [1, 4, 6], [1, 7, 2]])
    y=np.array([5, 10, 9, 0, 3, 27])

    try:
        coefficients, r2=multiple_regression_method(X, y)
        print("Coefficients:", coefficients)
        print("R^2 correlation index:", r2)
    except np.linalg.LinAlgError as e:
        print(f"Error solving the system of equations: {e}")
