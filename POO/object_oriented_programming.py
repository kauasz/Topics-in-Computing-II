# Nome: Kauã de Souza Ferreira.

class Calculo:
    def __init__(self, a, b, n): # Declaração do construtor.
        # Variáveis usadas no cálculo da integral.
        self.a = float(a)
        self.b = float(b)
        self.n = int(n)

    # As funções do cálculo da integral foram aproveitadas dos exercícios anteriores.
    def f(self, x):
        return (4)/(1 + x**2) # Função criada para possíveis mudanças futuras.

    def integral(self): # Função criada para o cálculo da integral.
        a = self.a
        b = self.b
        n = self.n
        
        soma = 0.0

        h = (b - a)/n # Largura de cada subintervalo.

        for i in range(n):
            # Varedura para calcular o tamanho de cada subintervalo.
            x1 = a + (i*h)
            x2 = a + ((i + 1)*h)

            # Cálculo da área de cada subintervalo, ou seja, o valor da função (f) para 'x1' e 'x2' vezes a largura do subintervalo.
            area = (((self.f(x1) + self.f(x2))/2)*h)

            soma += area # Somando todas as áreas de cada subintervalo.
        
        return soma
    
    def raiz(self, Y): # Função para o cálculo da raiz quadrada.
        iteracoes = 0.0

        if Y == 0:
            return 0.0
        
        tolerancia = 0.000001

        x = Y / 2.0 # Primeira aproximação.

        while True:
            iteracoes += 1

            x_n = 0.5*(x + (Y/x)) # Aproximações sucessivas.

            diferenca = x_n - x

            if diferenca < 0: # Condição para o módulo da 'diferença'. 
                diferenca = -diferenca

            if diferenca < tolerancia: # Condição de parada.
                return x_n, iteracoes
            
            x = x_n 

# ========== Cálculo da integral ========== #

a = 0.0
b = 1.0

# Objetos criados para cada valor de 'n'.
calc1 = Calculo(a, b, n = 1)
calc2 = Calculo(a, b, n = 10)
calc3 = Calculo(a, b, n = 100)
calc4 = Calculo(a, b, n = 200)
calc5 = Calculo(a, b, n = 500)

resultado1 = calc1.integral()
print(f"\nPara n = 1, o resultado da integral é: {resultado1:.5f}")

resultado2 = calc2.integral()
print(f"Para n = 10, o resultado da integral é: {resultado2:.5f}")

resultado3 = calc3.integral()
print(f"Para n = 100, o resultado da integral é: {resultado3:.5f}")

resultado4 = calc4.integral()
print(f"Para n = 200, o resultado da integral é: {resultado4:.5f}")

resultado5 = calc5.integral()
print(f"Para n = 500, o resultado da integral é: {resultado5:.5f}")

print("\n-----------------------------------------------------\n")

# ========== Cálculo da raiz quadrada ========== #

num1 = 88.0

raiz1, iteracao1 = calc1.raiz(num1)
print(f"A raiz quadrada de 88 é igual a: {raiz1:.2f}")
print(f"Número de iterações: {iteracao1}\n")

num2 = 10050.66

raiz2, iteracao2 = calc1.raiz(num2)
print(f"A raiz quadrada de 10050.66 é igual a: {raiz2:.2f}")
print(f"Número de iterações: {iteracao2} \n")
