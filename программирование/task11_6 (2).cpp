#include <iostream>
using namespace std;

// рекурсивный вариант
double hermiteRec(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return 2 * x;
    return 2 * x * hermiteRec(n - 1, x)
         - 2 * (n - 1) * hermiteRec(n - 2, x);
}

// нерекурсивный вариант
double hermiteIter(int n, double x) {
    if (n == 0) return 1;
    if (n == 1) return 2 * x;

    double Hn_2 = 1;      // H0
    double Hn_1 = 2 * x;  // H1
    double Hn;

    for (int i = 2; i <= n; i++) {
        Hn = 2 * x * Hn_1 - 2 * (i - 1) * Hn_2;
        Hn_2 = Hn_1;
        Hn_1 = Hn;
    }
    return Hn;
}

int main() {
    int n; double x;
    cout << "Введите n и x: "; cin >> n >> x;

    cout << "Hermite (рекурсия): " << hermiteRec(n, x) << endl;
    cout << "Hermite (итерация): " << hermiteIter(n, x) << endl;

    return 0;
}