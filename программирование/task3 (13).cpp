#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");

    int n;
    float x;
    cout << "n="; cin >> n;
    cout << "x="; cin >> x;

    float a = x;
    //начальные условия

    cout << left << setw(3) << "i\t" << setw(10) << "a" << endl;
    //заголовок

    cout << left << setw(3) << 1 << "\t" << setw(10) << a << endl;
    //1 шаг

    for (int i = 2; i <= n; i++) {
        //i-ый шаг
        a *= x / i;
        cout << left << setw(3) << i << "\t" << setw(10) << a << endl;
    }

    return 0;
}