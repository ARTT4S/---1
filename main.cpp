#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

static const int g_size = 10;

void showMatrix(int[g_size][g_size]);

int main(){
    setlocale(LC_ALL,"Russian");
    srand(time(NULL));
    const int max = 14, min = -14;
    int temp{}, null_element{ g_size }, vector{}, sum{}, quontityNull{};
    bool flag = true;
    int matrix[g_size][g_size]{};
    cout << "Заполнение матрицы (случайные числа из [-14;14])" << endl;
    for (int i{};i < g_size; i++){
        for (int j{}; j < g_size; j++){
            matrix[i][j] = rand() % (2 * max + 1) + min;
        }
    }
    showMatrix(matrix);
    cout << "Сортировка матрицы (-|+|0)" << endl;
    for (int i{}; i < g_size; i++){
        for (int k{}; k < g_size; k++){
            for (int j{}; j < g_size - 1; j++){
                if ((matrix[i][j] > matrix[i][j + 1]) and (matrix[i][j + 1] != 0)) {
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[i][j + 1];
                    matrix[i][j + 1] = temp;
                }
                else if (matrix[i][j] == 0) {
                    ++quontityNull;
                    matrix[i][j] = matrix[i][g_size - quontityNull];
                    matrix[i][g_size - quontityNull] = 0;
                }
            }
        }
    }
    showMatrix(matrix);
    cout << "Замена нулевых элементов матрицы на заданный вектор." << endl << "Введите вектор: ";
    cin >> vector;
    for (int i = 0; i < g_size; ++i) {
        for (int j = 0; j < g_size; ++j) {
            if (matrix[i][j] == 0) {
                flag = false;
                matrix[i][j] = vector;
            }
        }
    }
    if (flag) {
        cout << "В матрице нет нулевых элементов.\n";
    }
    showMatrix(matrix);
    cout << "Нахождение суммы отрицательных элементов по условию варианта №14.\n";
    for (int i = 0; i < g_size; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (matrix[i][j] < 0) {
                sum += matrix[i][j];
            }
        }
    }
    cout << "Сумма отрицательных элементов: " << sum << endl;

    return 0;
}
void showMatrix(int mtrx[g_size][g_size]){
    for (int i{};i < g_size;i++){
        for (int j{}; j < g_size; j++){
            cout << setw(4) << mtrx[i][j];
        }
        cout << endl;
    }
    cout << endl;
}
