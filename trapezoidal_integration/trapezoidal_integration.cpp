// name: Kauã de Souza Ferreira

#include <iostream>
#include <cmath>
#include <functional> 
#include <iomanip> 

using namespace std;

// ========== FUNCTIONS ========== //

double f(double x) {
    return (4.0)/(1.0 + pow(x, 2));
}

double integral(function<double(double)> f, double a, double b, int n){ // Function created to calculate the integral.
    double sum = 0.0;

    double h = (b - a)/n; // Width of each subinterval.

    for(int i = 0; i <= n; i++){
        // Iteration to calculate the size of each subinterval.
        double x1 = a + (i*h);
        double x2 = a + ((i + 1.0)*h);

        // Calculate the area of each subinterval, that is, the value of the function (f) for 'x1' and 'x2' multiplied by the width of the subinterval.
        double area = ((f(x1) + f(x2))/2.0)*h;

        sum += area; // By summing the areas of each subinterval.
    }
    
    return sum;
}

int main(){
    int n;

    cout << "enter the value of n: ";
    cin >> n;

    double a = 0.0; // Lower limit of the integral.
    double b = 1.0; // Upper limit of the integral.

    double result = integral(f, a, b, n);

    cout << fixed << setprecision(7);
    cout << "the value of the integral is equal to: " << result << endl;

    return 0;
}