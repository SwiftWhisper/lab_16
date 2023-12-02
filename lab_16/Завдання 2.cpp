#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;
const int arrSize = 5;
int main() {
    setlocale(LC_ALL, "ukr");
    srand(static_cast<unsigned>(std::time(0)));

    int arr[arrSize][arrSize];
    pair<int, int> arrMax[arrSize];

    for (int i = 0; i < arrSize; ++i) {
        for (int j = 0; j < arrSize; ++j) {
            arr[i][j] = rand() % 50;
        }
    }

    cout << "Початкова матриця: " << endl;
    for (int i = 0; i < arrSize; ++i) {
        int maxInRow = INT_MIN;

        for (int j = 0; j < arrSize; ++j) {
            cout << arr[i][j] << " ";
            if (maxInRow < arr[i][j]) { // Знахадження найбільшого числа у кожному рядку
                maxInRow = arr[i][j];
            }

        }

        arrMax[i] = make_pair(maxInRow, i); // Заповнення масиву парами які складаються з найбільшого числа і рядка в якому це число найбільше
        cout << endl;
    }
    sort(arrMax, arrMax + arrSize);
    vector<pair<int, int>>maxFromMax;
    maxFromMax.push_back(arrMax[arrSize - 1]);
    for (int i = arrSize - 1; i > 1; --i) {
        if (arrMax[i].first == arrMax[i - 1].first) { // Знаходження дублікатів найбільшого числа на різних рядках
            maxFromMax.push_back(arrMax[i - 1]);
        }
        else {
            break;
        }
    }
    if (maxFromMax.size() == 1) {
        int sumInRow = 0;
        for (int j = 0; j < arrSize; ++j) {
            sumInRow += arr[maxFromMax[0].second][j];
        }
        cout << "Найбільше значення у матриці це: " << maxFromMax[0].first << endl;
        cout << "Рядок у якому заходиться найбільше значення: " << maxFromMax[0].second << " Та сума елементів у ньому: " << sumInRow << endl;
    }
    else if (maxFromMax.size() > 1) {

        cout << "Найбільше значення у матриці це: " << maxFromMax[0].first << endl;
        for (int i = 0; i < maxFromMax.size(); ++i) {
            int sumInRow = 0;
            for (int j = 0; j < arrSize; ++j) {
                sumInRow += arr[maxFromMax[i].second][j];
            }
            cout << "Один з рядків у якому заходиться найбільше значення: " << maxFromMax[i].second << " Та сума елементів у ньому: " << sumInRow << endl;

        }
    }
    return 0;
}