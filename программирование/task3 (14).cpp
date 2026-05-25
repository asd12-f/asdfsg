#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");

    int n;
    cout << "n = ";
    cin >> n;

    int* a = new int[n];

    srand((unsigned)time(NULL));
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 15;
        cout << a[i] << " ";
    }
    cout << endl;

    int X;
    cout << "X = ";
    cin >> X;

    int k = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < X) {
            k++;
            sum += a[i];
        }
    }

    if (!k)
        cout << "Таких элементов нет\n";
    else
        cout << "Сумма = " << sum << endl;

    delete[] a;
    return 0;
}