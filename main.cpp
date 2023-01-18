#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
using namespace std;
void matrica(int a, int b, int** arr)
{
    cout << "Матрица: \n";
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) { cout << arr[i][j] << " "; }
        cout << "\n";
    }
    cout << "\n";
    int arr2[4]{};
    int s1, s2 = 0;
    int t = 0;
    cout << "Введите индекс двух строк (от 1 до 4)\nдля нахождения произведений их элементов \n\n";
    cout << "строка 1 = "; cin >> s1;
    cout << "строка 2 = "; cin >> s2; cout << "\n";
    s1 = s1 - 1;
    s2 = s2 - 1;
    for (int i = 0; i < a; i++) { arr2[t] = arr[s1][i] * arr[s2][i]; t += 1; }
    cout << "Значения произведений: \n";
    cout << "Произведение по 1 столбцу: " << arr2[0] << "\n";
    cout << "Произведение по 2 столбцу: " << arr2[1] << "\n";
    cout << "Произведение по 3 столбцу: " << arr2[2] << "\n\n";
}
int main()
{
    setlocale(0, "");
    int x, y;
    string path = "Matrix.txt";
    ifstream fin;
    fin.open(path);
    if (!fin.is_open()) { cout << "Ошибка"; }
    else {
        cout << "Файл открыт\n";
        int x = 4;
        int y = 3;
        int** arr = new int* [x];
        for (int i = 0; i < x; i++) { arr[i] = new int[y]; }
        for (int i = 0; i < x; i++) { for (int j = 0; j < y; j++) { fin >> arr[i][j]; } }
        matrica(x, y, arr);
        for (int i = 0; i < x; i++) { delete[] arr[i]; }
        delete[] arr;
    }
    fin.close();
    system("Pause");
}