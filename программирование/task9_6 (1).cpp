#include <iostream>
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

    int i = 0;
    while (i < n) {
        if (abs(arr[i]) % 10 == x) {
            // Сдвигаем все элементы справа на одну позицию влево
            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }
            n--; // Уменьшаем размер массива
        } else {
            i++; // Переходим к следующему элементу
        }
    }

    cout << "После удаления тех, которые не оканчиваются на X (n=" << n << "): ";
    if (n == 0) {
        cout << "массив пуст";
    } 
    else {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
    }
    delete [] arr;
    return 0;
}