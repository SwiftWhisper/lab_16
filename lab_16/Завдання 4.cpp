#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "ukr");
    const int rows = 4;
    const int cols = 5;
    int arr[rows][cols];
    int temp = 0;
    for (int i = 0; i < rows; ++i) {
        if (temp % 2 == 0) {
            for (int j = 0; j < cols; ++j) {
                cin >> arr[i][j];

            }
        }
        else {
            for (int j = cols - 1; j >= 0; --j) {
                cin >> arr[i][j];
            }
        }
        temp++;
    }
    cout << "Початкова матриця: " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {

            cout << setw(3) << arr[i][j];

        }
        cout << endl;
    }

    return 0;
}