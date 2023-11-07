#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void Sum(int** a, const int k, const int n, int& S);

int main() {
    srand((unsigned)time(NULL));
    int Low = -10;
    int High = 10;
    int k; // rowcount
    int n; // colcount

    cout << "colcount = "; cin >> n;
    cout << "rowcount = "; cin >> k;
    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];
    Create(a, k, n, Low, High);
    Print(a, k, n);

    int S;
    Sum(a, k, n, S);
    cout << "Sum of elements in odd rows and odd columns: " << S << endl;

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;
    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High) {
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n) {
    cout << endl;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

void Sum(int** a, const int k, const int n, int& S) {
    S = 0;
    for (int i = 0; i < k; i++) {
        if (i % 2 != 0) {
            for (int j = 0; j < n; j++) {
                if (j % 2 != 0) {
                    S += a[i][j];
                }
            }
        }
    }
}
