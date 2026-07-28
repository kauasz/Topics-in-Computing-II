// name: Kauã de Souza Ferreira
// course: Mechatronics Engineering

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

using namespace std;

// ---------- FACTORIAL FUNCTION ---------- //

long double factorial(int num) {
    if (num < 0) {
        cout << "the factorial is not defined for negative numbers" << endl;
        return 0;
    }

    if (num == 0 || num == 1) { // 0! and 1! are both equal to 1.
        return 1.0;

    } else {
        return (long double) (num) * factorial(num - 1); // For example, if num = 4, it returns 4 * factorial(3).
    }
}

// ---------- COSINE FUNCTION ---------- //

double cos(double y, int m) {
    if (m < 0) {
        cout << "the sum cannot be negative" << endl;
        return 0; 
    }

    long double sum = 0.0;

    for (int n = 0; n <= m; n++) {
        long double numerator = pow(-1, n) * pow(y, 2*n); // When performing the operation manually, there was an error in the denominator. So, I had to create an “if” statement to fix it.
        long double denominator = factorial(2 * n);
        
        if (denominator != 0) {
            long double term = numerator / denominator;
            sum += term;
        }
    }
    
    return (double) (sum);
}

int main() {
    const double PI = M_PI;

    double y;
    cout << "enter the value of Y (rad): ";
    cin >> y;

    int m = 20;

    double value_cos = cos(y, m);

    cout << "the cosine of Y is equal to: " << value_cos << endl;

    // ---------- CALCULATION OF VELOCITIES ---------- //

    double v0 = 15.0;
    double c = 1.0;
    double L = 5.0;

    vector <double> values = {0, L/2, L, (3*L/2), 2*L}; // A vector to store the values of x.

    for (double x : values) {

        // Calculating 'Vx' using the 'cos' function.
        double Vx = v0 * (1.0) / sqrt(1.0 + pow((c * PI / L), 2) * pow(cos((PI * x) / L, m), 2)); 

        // Calculating 'Vy' using the 'cos' function.
        double Vy = (v0 * c * PI / L) * cos((PI * x) / L, m) * (1.0 / sqrt(1.0 + pow((c * PI / L), 2) * pow(cos((PI * x) / L, m), 2)));

        cout << "\n For x = " << x << " m :" << endl;

        // Note: When comparing the results (Python), it can be seen that some values are very small instead of 0. Therefore, a 'setprecision' was used to "fix" this.
        cout << fixed << setprecision(4);
        cout << "   Vx = " << Vx << " m/s " << endl;
        cout << "   Vy = " << Vy << " m/s \n" << endl;
    }

    return 0;
}