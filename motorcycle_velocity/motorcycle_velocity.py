# name: Kauã de Souza Ferreira
# course: Mechatronics Engineering

import numpy as np

n = int(input("enter the value of n: ")) 

num = 2*n

# ---------- FACTORIAL FUNCTION ---------- #

def factorial(num): 
    if num < 0:
        print("factorial is not defined for negative numbers")
    
    elif num == 0 or num == 1: # 0! and 1! are equal to 1.
        return 1

    else:
        return num * factorial(num - 1) # For example, if n = 2, then num = 4. Therefore, we have 4 * factorial(3). Thus, the factorial function is called again.
    
resultado = factorial(num)

# print("The factorial of n is equal to: ", resultado)

y = float(input("enter the value of Y (rad): "))

m = 20

# ---------- COSINE FUNCTION ---------- #

def cos(y, m):

    if m < 0:
        print("The limit of the summation cannot be negative")

    sum = 0 

    for n in range(m + 1): # The 'range' function creates a sequence of integers, but we need to do 'm + 1' so that 'm' is included in the calculation.
         numerator = ((-1)**n) * (y**(2*n))

         denominator = factorial(2*n)
         
         term = numerator / denominator

         sum += term
    
    return sum

value_cos = cos(y, m)

print("The cosine of Y is equal to: ", value_cos)

# ---------- CALCULATION OF VELOCITIES ---------- #

v0 = 15
c = 1
L = 5

values = [0, L/2, L, (3*L/2), 2*L] # Vector to store the values of x.

for x in values:

    Vx = v0*(1)/np.sqrt(1 + ((c*np.pi/L)**2)*((cos((np.pi*x)/L, m))**2)) # Calculation of 'Vx' using the 'cos' function.

    Vy = (v0*c*np.pi)/(L)*cos((np.pi*x)/L, m)*((1)/np.sqrt(1 + ((c*np.pi/L)**2)*((cos((np.pi*x)/L, m))**2))) # Calculation of 'Vy' using the 'cos' function.

    print(f"\n For x = {x:.2f} m :")
    print(f"   Vx = {Vx:.4f} m/s ")
    print(f"   Vy = {Vy:.4f} m/s \n")