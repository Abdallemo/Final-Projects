#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    double radius[5];
    double pi = 3.14;
    
    for (int i = 0; i < 5; ++i) {
        cout << "Enter the radius of sphere " << i + 1 << ": ";
        cin >> radius[i];
    }

    cout << "\nSphere Volumes (in reverse order):" << endl;
    for (int i = 5 - 1; i >= 0; --i) {
        // Calculate volume using the correct formula for a sphere
        double volume = (4.0 / 3.0) * pi * pow(radius[i], 3);
        cout << "Sphere " << i + 1 << ": " << fixed << setprecision(2) << volume << endl;
    }

    return 0;
}
