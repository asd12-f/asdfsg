#include <iostream>
using namespace std;

int main() {
	int n; cout << "Введите размер матрицы n: "; cin >> n;

	int** mas = new int* [2 * n];
	for (int i = 0; i < 2 * n; i++) {
		mas[i] = new int[n];
	}

	cout << "Введите элементы матрицы:" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mas[i][j];
		}
	}

	// Вводим строку X (используем последнюю запасную строку матрицы)
	cout << "\nВведите строку X:" << endl;
	for (int j = 0; j < n; j++) {
		cin >> mas[2 * n - 1][j];
	}

	int count_str = n;

	for (int i = 0; i < count_str; i++) { // Проходим по строкам и вставляем строку X после строк с только положительными элементами
		bool flag = true; // Проверяем, содержит ли строка только положительные элементы
		for (int j = 0; j < n; j++) {
			if (mas[i][j] <= 0) {
				flag = false;
				break;
			}
		}

		// Если строка содержит только положительные элементы, вставляем строку X
		if (flag) {
			count_str++;
			for (int h = count_str - 1; h > i + 1; h--) {
				for (int j = 0; j < n; j++) {
					mas[h][j] = mas[h - 1][j];
				}
			}
			for (int j = 0; j < n; j++) {
				mas[i + 1][j] = mas[2 * n - 1][j];
			}
			i++;
		}
	}

	cout << "\nРезультат:" << endl;
	for (int i = 0; i < count_str; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < 2*n-1; j++) {
		delete [] mas[j];
	}
	delete [] mas;
	return 0;
}
