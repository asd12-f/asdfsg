#include <iostream>
using namespace std;

int main() {
	int n, x;
	cout << "Введите размер матрицы n: "; cin >> n;

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
	cout << "\nВведите значение X: "; cin >> x;
	int count_stl = n;

	for (int j = 0; j < count_stl; j++) { // Удаляем столбцы, содержащие хотя бы один элемент, кратный X
		bool have_kr_x = false; // Проверяем, содержит ли столбец хотя бы один элемент, кратный X
		for (int i = 0; i < n; i++) {
			if (mas[i][j] % x == 0) {
				have_kr_x = true;
				break;
			}
		}
		if (have_kr_x) { // Если столбец содержит хотя бы один элемент, кратный X, удаляем его
			count_stl--; // уменьшаем размер
			for (int h = j; h < count_stl; h++) { // Сдвигаем столбцы влево
				for (int i = 0; i < n; i++) {
					mas[i][h] = mas[i][h + 1];
				}
			}
			j--; // НЕ увеличиваем j, так как после сдвига на позиции j уже другой столбец
		}
	}

	cout << "\nРезультат:" << endl;
	if (count_stl == 0) {
		cout << "Все столбцы удалены" << endl;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < count_stl; j++) {
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