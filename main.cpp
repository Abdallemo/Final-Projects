#include <iostream>

using namespace std;

// Conversion functions
double meterToKilometer(double meter) {
    return meter / 1000;
}

double gramToKilogram(double gram) {
    return gram / 1000;
}

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double usdToMyr(double usd) {
    return usd * 4.3;  // Example rate
}

double euroToYen(double euro) {
    return euro * 130.0;  // Example rate
}

double sarToUsd(double sar) {
    return sar * 0.27;  // Example rate
}

int main() {
    int choice;

    do {
        // Main menu
        cout << "\n1 - Unit Converter\n";
        cout << "2 - Currency Converter\n";
        cout << "3 - Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {  // Unit Converter
            int unitChoice;
            double value;

            cout << "1 - Meter to Kilometer\n";
            cout << "2 - Gram to Kilogram\n";
            cout << "3 - Celsius to Fahrenheit\n";
            cout << "Enter your choice: ";
            cin >> unitChoice;
            cout << "Enter value: ";
            cin >> value;

            switch (unitChoice) {
                case 1:
                    cout << value << " meters = " << meterToKilometer(value) << " kilometers\n";
                    break;
                case 2:
                    cout << value << " grams = " << gramToKilogram(value) << " kilograms\n";
                    break;
                case 3:
                    cout << value << " Celsius = " << celsiusToFahrenheit(value) << " Fahrenheit\n";
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } else if (choice == 2) {  // Currency Converter
            int currencyChoice;
            double amount;

            cout << "1 - USD to MYR\n";
            cout << "2 - EURO to YEN\n";
            cout << "3 - SAR to USD\n";
            cout << "Enter your choice: ";
            cin >> currencyChoice;
            cout << "Enter amount: ";
            cin >> amount;

            switch (currencyChoice) {
                case 1:
                    cout << amount << " USD = " << usdToMyr(amount) << " MYR\n";
                    break;
                case 2:
                    cout << amount << " EURO = " << euroToYen(amount) << " YEN\n";
                    break;
                case 3:
                    cout << amount << " SAR = " << sarToUsd(amount) << " USD\n";
                    break;
                default:
                    cout << "Invalid choice\n";
            }
        } else if (choice != 3) {
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    cout << "Program exited.\n";
    return 0;
}
