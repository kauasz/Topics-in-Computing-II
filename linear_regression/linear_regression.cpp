// name: Kauã de Souza Ferreira

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

void MMQ(const vector<double> &point_X, const vector<double> &point_Y, double &a, double &b){
    const int n = point_X.size();

    double sum_X = 0.0;
    double sum_Y = 0.0;
    double sum_XY = 0.0;
    double sum_X2 = 0.0;

    // Sum of all points on the X-axis.
    for (int i = 0; i < n; i++){
        sum_X += point_X[i];
    }

    // Sum of all points on the Y-axis.
    for (int i = 0; i < n; i++){
        sum_Y += point_Y[i];
    }

    // Sum of all points of XY.
    for (int i = 0; i < n; i++){
        sum_XY += point_X[i] * point_Y[i];
    }

    // Sum of all points of X^2.
    for (int i = 0; i < n; i++){
        sum_X2 += pow(point_X[i], 2);
    }

    a = ((n*sum_XY) - (sum_X*sum_Y)) / ((n*sum_X2) - (pow(sum_X, 2))); // Calculation of the slope (a).

    b = ((sum_Y*sum_X2) - (sum_X*sum_XY)) / ((n*sum_X2) - (pow(sum_X, 2))); // Calculation of the y-intercept (b).
}

int main() {
    int n;
    
    cout << "enter the number of (X, Y) point pairs: ";
    cin >> n;
    
    vector<double> point_X; // Creating vectors for the X points.
    vector<double> point_Y; // Creating vectors for the Y points.

    cout << "\nenter the values of each point: \n";
        
    for (int i = 0; i < n; i++) {
        double X, Y;

        cout << "point " << i + 1 << " - X: ";
        cin >> X;
        cout << "point " << i + 1 << " - Y: ";
        cin >> Y;

        point_X.push_back(X); // Storing all inserted X values.
        point_Y.push_back(Y); // Storing all inserted Y values.
    }

    double a, b;

    MMQ(point_X, point_Y, a, b);

    cout << "\nAngular coefficient (a): " << a << endl;
    cout << "Linear coefficient (b): " << b << endl;
    
    cout << "\nThe equation of the line is: y = " << a << "x + " << b << endl;

    return 0;
}