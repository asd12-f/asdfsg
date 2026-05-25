#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int N = 10000;
    float x, eps;
    cout << "x="; cin >> x;
    cout << "eps="; cin >> eps;

    float a = x, S = a;

    cout << left << setw(3) << "i\t" << setw(10) << "a\t";
    cout << setw(10) << "S" << endl;

    cout << left << setw(3) << 1 << "\t" << setw(10) << a;
    cout << "\t" << setw(10) << S << endl;

    int i;
    for (i = 2; fabs(a) > eps && i <= N; i++) {
        a *= (-x * x) * (2 * i - 3) / (2 * i - 1);
        S += a;
        cout << left << setw(3) << i << "\t" << setw(10) << a;
        cout << "\t" << setw(10) << S << endl;
    }

    if (i > N && fabs(a) > eps) {
        cout << "Ряд расходится" << endl;
    } else {
        cout << "Сумма ряда = " << S << endl;
    }

    return 0;
}