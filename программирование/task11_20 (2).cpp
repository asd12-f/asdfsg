#include <iostream>
using namespace std;

// печать пробелов
void printSpaces(int n) {
    if (n <= 0) return;
    cout << " ";
    printSpaces(n - 1);
}

// печать звёздочек
void printStars(int n) {
    if (n <= 0) return;
    cout << "*";
    printStars(n - 1);
}

// печать одного блока
void printBlock(int stars, int maxWidth) {
    if (stars <= 0) return; 

    int spaces = (maxWidth - stars) / 2;
    printSpaces(spaces);
    printStars(stars);
    cout << endl;

    printBlock(stars - 2, maxWidth);
}

// печать всех блоков
void printAllBlocks(int block, int n, int maxWidth) {
    if (block > n) return;

    int stars = 2 * block + 1;
    printBlock(stars, maxWidth);

    printAllBlocks(block + 1, n, maxWidth);
}

int main() {
    int n;
    cin >> n;

    int maxWidth = 2 * n + 1;  // ширина самого большого блока
    printAllBlocks(1, n, maxWidth);

    return 0;
}