#include <iostream>
using namespace std;

// рекурсивная функция Аккермана
long long ackermann(long long m, long long n) {
    if (m == 0) return n + 1;
    if (m > 0 && n == 0) return ackermann(m - 1, 1);
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    long long m, n;
    cout << "Введите m и n: "; cin >> m >> n;
    cout << "Ackermann A(m, n) = " << ackermann(m, n) << endl;
    return 0;
}