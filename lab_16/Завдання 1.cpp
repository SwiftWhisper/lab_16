#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;
const int arrSize = 5;

int main() {
    setlocale(LC_ALL, "ukr");
    srand(static_cast<unsigned>(std::time(0)));

    int arr[arrSize][arrSize];
    int sumMain = 0;
    int sumSecond = 0;

    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            arr[i][j] = rand() % 10;
        }
    }

    cout << "Початкова матриця: " << endl;
    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            if (i == j) {
                sumMain += arr[i][j];
            }
            if (i + j == arrSize - 1) {
                sumSecond += arr[i][j];
            }
            cout << arr[i][j] << " ";

        }
        cout << endl;
    }
    cout << "Сума елементів на головній діагоналі: " << sumMain << endl;
    cout << "Сума елементів на побічній діагоналі: " << sumSecond << endl;
    return 0;
}