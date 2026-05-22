#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n; cout << "Введите размер массива n: "; cin >> n;
    int x; cout << "Введите x: "; cin >> x;
    int *arr = new int [n];
    for (int j = 0; j < n; j++) {
        cout << "Введите элемент_" << j+1 << ": "; cin >> arr[j];
    }

    cout << "Исходный массив: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int mn = INT16_MAX;
    for (int j = 0; j < n; j++) {
        if (arr[j] < mn) {
            mn = arr[j];
        }
    }
    // Идем с конца, чтобы не перезаписывать элементы
    for (int i = n - 1; i >= 0; i--) {
        if (arr[i] == mn) {
            // Сдвигаем все элементы справа на 1 позицию вправо
            for (int j = n; j > i; j--) {
                arr[j] = arr[j - 1];
            }
            // Вставляем X
            arr[i + 1] = x;
            n++; // Увеличиваем размер массива
        }
    }
    
    cout << "После удаления вставки X после минимальных (n=" << n << "): ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete [] arr;
    return 0;
}