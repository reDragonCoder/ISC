# Numerical Methods Course, August-December 2024
# Program for divided differences
# Date: December 7, 2024
# Author: reDragonCoder

def dividedDif(x, f):
    #It is used to obtain the coefficients of the divided differences 
    #of the interpolating polynomial P in the (n+1) different numbers 
    #x0, x1, ..., xn; for the function f

    #Inputs:
    # The numbers x0, x1, ..., xn
    # The values ​​f(x0), f(x1), ..., f(xn) as F0,0, F1,0, ..., Fn,0

    #Outputs:
    # The numbers F0,0, F1,1, ..., Fn,n where P(x)=Σ up to n with i=0 
    # of Fi,i * (∏ up to i-1 with j=0 * (x-xj ))

    n=len(x)
    F=[[0]*n for _ in range(n)]  

    for i in range(n):
        F[i][0]=f[i]

    for j in range(1, n):
        for i in range(n-j):
            F[i][j]=(F[i+1][j-1]-F[i][j-1])/(x[i+j]-x[i])

    return F

def printDividedDiffTable(x, f, F):
    print(f"{'i':<5}{'xi':<10}{'f(xi)':<10}", end="")
    for i in range(1, len(x)):
        print(f"f[x0...x{i}]".ljust(15), end="")
    print()

    for i in range(len(x)):
        row_str=f"{i:<5}{x[i]:<10}{f[i]:<10}"

        for j in range(1, len(F[i])):
            if F[i][j]!=0:
                row_str+=f"{F[i][j]:<15.5f}"
            else:
                row_str+=f"{'':<15}" 
        print(row_str)

def constructPolynomial(x, F):
    n=len(x)
    terms=[f"{F[0][0]}"]  

    for i in range(1, n):
        coef=F[0][i]
        term=f"{coef:.5f}"
        for j in range(i):
            term+=f"*(x - {x[j]})"
        terms.append(term)

    polynomial=" + ".join(terms)

    return polynomial

def simplifyPolynomial(polynomial, x):
    import sympy as sp
    x_sym=sp.symbols('x')
    simplified_poly=sp.simplify(eval(polynomial.replace('x', 'x_sym')))

    return simplified_poly

def P(x_val, x, F):
    n=len(x)
    P_value=F[0][0]

    for i in range(1, n):
        term=F[0][i]
        for j in range(i):
            term*=(x_val - x[j])
        P_value+=term

    return P_value

# TEST ZONE
x_values=[1, 2] 
f_values=[-2, 4]  

# Compute and print the divided differences table
print("Divided differences table: ")
div_diff_table=dividedDif(x_values, f_values)
printDividedDiffTable(x_values, f_values, div_diff_table)

# Display the interpolating polynomial as a string in its long form
polynomial=constructPolynomial(x_values, div_diff_table)
print(f"\nConstructed Polynomial (Long form): \nP(x) = {polynomial}")

# Shows the interpolating polynomial in its simplified form
simplified_polynomial=simplifyPolynomial(polynomial, x_values)
print(f"\nConstructed Polynomial (Simplified form): \nP(x) = {simplified_polynomial}")



