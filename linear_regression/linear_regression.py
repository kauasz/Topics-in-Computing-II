# name: Kauã de Souza Ferreira

import matplotlib.pyplot as plt

# ========== FUNCTIONS ========== #

def MMQ(point_X, point_Y, n):
    sum_X = 0.0
    sum_Y = 0.0
    sum_XY = 0.0
    sum_X2 = 0.0
    
    sum_X = sum(point_X)
    sum_Y = sum(point_Y)
    
    for i in range(n):
        sum_XY += point_X[i] * point_Y[i]
        
    for x in point_X:
        sum_X2 += x**2
        
    a = ((n*sum_XY) - (sum_X*sum_Y)) / ((n*sum_X2) - ((sum_X)**2)) 
    
    b = ((sum_Y*sum_X2) - (sum_X*sum_XY)) / ((n*sum_X2) - ((sum_X)**2))
    
    return a, b

n = int(input("enter the number of pairs of points (X, Y): "))

if n < 2:
    print("you need at least 2 points to draw a line.")
    
else:
    point_X = []
    point_Y = []

    print("\nenter the values for each point: \n")
        
    for i in range(n):
        while True:    
            X = float(input(f"  point {i+1} - X: "))
            Y = float(input(f"  point {i+1} - Y: "))
            point_X.append(X)
            point_Y.append(Y)
        
            break

a, b = MMQ(point_X, point_Y, n)

print(f"\nangular coefficient (a): {a:.4f}")
print(f"linear coefficient (b): {b:.4f}")

print(f"\nthe equation of the line is: y = {a:.4f}x + {b:.4f}")

plt.scatter(point_X, point_Y, color='blue')

X_min = min(point_X) 
X_max = max(point_X) 

X_reta = [X_min, X_max]
Y_reta = [(a * X_min) + b, (a * X_max) + b]

plt.plot(X_reta, Y_reta, color='red', linewidth=2)

plt.title('Method of Least Squares')
plt.xlabel('X Axis')
plt.ylabel('Y Axis')
plt.legend()
plt.grid()
plt.show()