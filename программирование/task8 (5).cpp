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
    
    int *a = new int[n];
    
    srand((unsigned)time(NULL));
    cout << "Массив: ";
    for (int i = 0; i < n; i++) {
        a[i] = rand() % 20 + 1; // числа от 1 до 20
        cout << a[i] << " ";
    }
    cout << endl;
    
    int left, right;
    cout << "Левая граница интервала: ";
    cin >> left;
    cout << "Правая граница интервала: ";
    cin >> right;
    
    if (left > right) swap(left, right);
    
    bool found = false;
    cout << "Номера элементов (кратные 3, не в интервале [" << left << ", " << right << "]): ";
    for (int i = 0; i < n; i++) {
        if (a[i] % 3 == 0 && (a[i] < left || a[i] > right)) {
            cout << i << " ";
            found = true;
        }
    }
    
    if (!found)
        cout << "Таких элементов нет";
    cout << endl;
    
    delete[] a;
    return 0;
}