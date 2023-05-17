#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include<Windows.h>

using namespace std;

// Функция для чтения матрицы из файла
vector<vector<int>> readMatrixFromFile(const string& filename) {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ifstream file(filename);
    if (!file) {
        cout << "Не удалось открыть файл: " << filename << endl;
        return {};
    }

    int rows, columns;
    file >> rows >> columns;

    vector<vector<int>> matrix(rows, vector<int>(columns));
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            file >> matrix[i][j];
        }
    }

    file.close();
    return matrix;
}

// Функция для вывода матрицы на экран
void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            cout << element << ' ';
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    vector<vector<int>> matrix = readMatrixFromFile("matr.txt");

    if (matrix.empty()) {
        return 0;
    }

    // Вывод матрицы на экран
    cout << "Матрица:" << endl;
    printMatrix(matrix);

    // Обработка матрицы в соответствии с вариантом
    int smallestAbsElement = abs(matrix[2][0]); // Первый элемент третьей строки
    int largestElement = matrix[0][1]; // Первый элемент второго столбца

    for (int i = 0; i < matrix[2].size(); ++i) {
        int element = matrix[2][i];
        if (abs(element) < smallestAbsElement) {
            smallestAbsElement = abs(element);
        }
    }

    for (int i = 0; i < matrix.size(); ++i) {
        int element = matrix[i][1];
        if (element > largestElement) {
            largestElement = element;
        }
    }

    int product = smallestAbsElement * largestElement;

    // Вывод результата
    cout << "Добуток найменшого за модулем елемента третього рядка и найбільшого елемента другого стовпчика: "
        << product << endl;

    return 0;
}
