#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <iomanip>
using namespace std;
const int arrSize = 5;

int main() {
    setlocale(LC_ALL, "ukr");
    srand(static_cast<unsigned>(std::time(0)));

    int arr[arrSize][arrSize];

    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            arr[i][j] = rand() % 50;
        }
    }

    cout << "ѕочаткова матриц€: " << endl;
    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {

            cout << setw(3) << arr[i][j];

        }
        cout << endl;
    }
    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            for (int k = i; k > 0 && j < i; --k) {
                arr[i][j] = 0;
            }
        }
        cout << endl;
    }
    cout << "ћатриц€ п≥сл€ перетворень: " << endl;

    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {

            cout << setw(3) << arr[i][j];

        }
        cout << endl;
    }
    return 0;
}