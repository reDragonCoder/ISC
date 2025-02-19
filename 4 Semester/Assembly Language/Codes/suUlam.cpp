// Succession de Ulam
// Celia Fernanda Vela Uribe y César Andrés Zuleta Malanco
// 04/02/2025
// Ensamblador

#include <iostream>
#include <limits>

using namespace std;

int main() {
    long long int n;
    cout << "Ingrese n: ";
    cin >> n;

    while (n <= 0) {
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Por favor, ingrese un numero." << endl << endl;
            cout << "Ingrese n: ";
            cin >> n;
        } else {
            cout << "Por favor, ingrese n de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin >> n;
        }
    }

    while (n > 1) {
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
        cout << " " << n << " ";
    }
    return 0;

}