#include <iostream>
using namespace std;

int main() {
    int n, x;
    cout << "Введите размер матрицы n: "; 
    cin >> n;
    
    // Создаем матрицу с запасом
    int** mas = new int* [n];
    for (int i = 0; i < n; i++) {
        mas[i] = new int[2 * n];
    }
    
    cout << "Введите элементы матрицы:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
        }
    }
    
    cout << "\nВведите значение X: "; 
    cin >> x;
    
    int count_stl = n;
    
    // Проходим слева направо (более сложная логика из-за вставки)
    for (int j = 0; j < count_stl; j++) {
        bool all_odd = true;
        
        for (int i = 0; i < n; i++) {
            if (mas[i][j] % 2 == 0) {
                all_odd = false;
                break;
            }
        }
        
        if (all_odd) {
            // Вставляем столбец X перед текущим столбцом
            // 1. Сдвигаем все столбцы начиная с j вправо
            for (int col = count_stl; col > j; col--) {
                for (int i = 0; i < n; i++) {
                    mas[i][col] = mas[i][col - 1];
                }
            }
            
            // 2. Вставляем новый столбец на позицию j
            for (int i = 0; i < n; i++) {
                mas[i][j] = x;
            }
            
            count_stl++; // увеличиваем счетчик столбцов
            j++; // пропускаем вставленный столбец
        }
    }
    
    cout << "\nРезультат:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < count_stl; j++) {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
    
    // Освобождаем память
    for (int i = 0; i < n; i++) {
        delete[] mas[i];
    }
    delete[] mas;
    
    return 0;
}