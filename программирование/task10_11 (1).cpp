#include <iostream>
using namespace std;

int main() {
	int n; cout << "Введите размер матрицы n: "; cin >> n;

	int** mas = new int* [n];
	for (int i = 0; i < n; i++) {
		mas[i] = new int[n];
	}

	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j];
		}
	}
	
	int min = mas[0][0]; // Находим минимальный элемент во всей матрице
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas[i][j] < min) {
				min = mas[i][j];
			}
		}
	}
	int count_str = n;

	for (int i = 0; i < count_str; i++) { // Удаляем строки, содержащие минимальный элемент
		bool have_min = false; // Проверяем, содержит ли строка минимальный элемент
		for (int j = 0; j < n; j++) {
			if (mas[i][j] == min) {
				have_min = true;
				break;
			}
		}
		if (have_min) { // Если строка содержит минимальный элемент, удаляем её
			count_str--;
			for (int h = i; h < count_str; h++) { // Сдвигаем строки вверх
				for (int j = 0; j < n; j++) {
					mas[h][j] = mas[h + 1][j];
				}
			}
			i--; // НЕ увеличиваем i, так как после сдвига на позиции i уже другая строка
		}
	}

	cout << "\nРезультат:" << endl;
	if (count_str == 0) {
		cout << "Все строки удалены" << endl;
	}
	else {
		for (int i = 0; i < count_str; i++) {
			for (int j = 0; j < n; j++) {
				cout << mas[i][j] << " ";
			}
			cout << endl;
		}
	}
	for (int j = 0; j < n; j++) {
		delete [] mas[j];
	}
	delete [] mas;
    
	return 0;
}
