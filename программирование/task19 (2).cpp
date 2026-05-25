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
    
    int maxEvenIdx = -1;
    int maxEven = INT_MIN;
    int minOddIdx = -1;
    int minOdd = INT_MAX;
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0 && a[i] > maxEven) {
            maxEven = a[i];
            maxEvenIdx = i;
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0 && a[i] < minOdd) {
            minOdd = a[i];
            minOddIdx = i;
        }
    }
    
    if (maxEvenIdx == -1 || minOddIdx == -1) {
        cout << "Нет нужных элементов для обмена" << endl;
    } else {
        swap(a[maxEvenIdx], a[minOddIdx]);
        cout << "Результат: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
    
    delete[] a;
    return 0;
}