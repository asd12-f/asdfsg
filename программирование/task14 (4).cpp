#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <limits.h>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    
    int n;
    cout << "n = ";
    cin >> n;
    
    int *a = new int[n];
    
    srand((unsigned)time(NULL));
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 10 + 1;
        cout << a[i] << " ";
    }
    cout << endl;
    
    int maxEven = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] > maxEven) {
            maxEven = a[i];
        }
    }
    
    if (maxEven == INT_MIN) {
        cout << "Четных элементов нет" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            if (a[i] == maxEven) {
                a[i] *= 2;
            }
        }
        cout << "Результат: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    delete[] a;
    return 0;
}