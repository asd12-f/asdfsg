#include <iostream>
using namespace std;

// рекурсивный факториал
long long factRec(int n) {
    if (n <= 1) return 1;
    return n * factRec(n - 1);
}

// нерекурсивный факториал
long long factIter(int n) {
    long long res = 1;
    for (int i = 2; i <= n; i++)
        res *= i;
    return res;
}

int main() {
    int n; cout << "Введите n: "; cin >> n;
    cout << "Factorial (рекурсия): " << factRec(n) << endl;
    cout << "Factorial (итерация): " << factIter(n) << endl;
    return 0;
}