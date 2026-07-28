# name: Kauã de Souza Ferreira

import matplotlib.pyplot as plt 

# ========== FUNCTIONS ========== #

def f(x):
    return (4)/(1 + x**2) # Function created for possible future changes.

def integral(f, a, b, n): # Function created for the calculation of the integral.
    sum = 0.0

    h = (b - a)/n # Width of each subinterval.

    for i in range(n):
        # Iteration to calculate the size of each subinterval.
        x1 = a + (i*h)
        x2 = a + ((i + 1)*h)

        # Calculation of the area of each subinterval, or rather, the value of the function (f) for 'x1' and 'x2' times the width of the subinterval.
        area = (((f(x1) + f(x2))/2)*h)

        sum += area # Summing all the areas of each subinterval.
    
    return sum

n = int(input("enter the value of n: "))

a = 0 # Lower limit of the integral.
b = 1 # Upper limit of the integral.

result = integral(f, a, b, n)

print("the value of the integral is equal to: ", result)


n_values = [2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000]
    
z_values = []

for n in n_values:
    result = integral(f, a, b, n)
    numerical_result = integral(f, a, b, n)
    z_values.append(numerical_result)
    print(f"\nFor n = {n:<5}, the value of the integral (z) is: {numerical_result:.8f}")

plt.figure(figsize=(12, 7))
plt.plot(n_values, z_values, marker='o', linestyle='-', label='Calculated Value (z)')
plt.xscale('log')
plt.title('Convergence of the Integrals Value as n Increases', fontsize=16)
plt.xlabel('Number of Subintervals (n) - Logarithmic Scale', fontsize=12)
plt.ylabel('Calculated Value of the Integral (z)', fontsize=12)
plt.legend(fontsize=12)
plt.grid(True, which="both", linestyle='--')
plt.show()