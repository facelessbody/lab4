#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int **allocate(int x, int y) {
    int **arr = new int *[x];
    for (int i = 0; i < x; i++) { arr[i] = new int[y]; }
    return arr;
}

void release(int x, int y, int **arr) {
    for (int i = 0; i < x; i++) { delete[] arr[i]; }
    delete[] arr;
}

void readMatrix(istream &is, int x, int y, int **arr) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            is >> arr[i][j];
        }
    }
}

void printMatrix(int a, int b, int **arr) {
    cout << "Матрица: \n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) { cout << arr[i][j] << " "; }
        cout << "\n";
    }
    cout << "\n";
}

int getRow(const string &prompt, int minValue, int maxValue) {
    int input;
    while (true) {
        cout << prompt;
        cin >> input;

        if (input < minValue || input > maxValue) {
            cout << "Ошибка: значение должно быть от " << minValue << " до " << maxValue << "\n";
        } else {
            break;
        }
    }
    return input;
}

void processMatrix(int a, int b, int **arr) {
    cout << "Введите индексы двух строк (от 1 до " << a << ")\nдля нахождения произведений их элементов \n\n";

    int s1 = getRow("строка 1 = ", 1, a) - 1;
    int s2 = getRow("строка 2 = ", 1, a) - 1;
    cout << "\n";

    cout << "Значения произведений: \n";
    for (int i = 0; i < b; ++i) {
        int prod = arr[s1][i] * arr[s2][i];
        cout << "Произведение по " << i << " столбцу: " << prod << "\n";
    }
    cout << "\n\n";
}

int main() {
    setlocale(0, "");
    string path = "Matrix.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) { cout << "Ошибка"; }
    else {
        cout << "Файл открыт\n";
        int x = 4;
        int y = 3;
        int **arr = allocate(x, y);
        readMatrix(fin, x, y, arr);
        printMatrix(x, y, arr);
        processMatrix(x, y, arr);
        release(x, y, arr);
    }
    fin.close();
    system("Pause");
}