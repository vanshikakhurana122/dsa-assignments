/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    int size = n * (n + 1) / 2; // non-zero elements count
    int lower[size];

    cout << "Enter " << size << " elements of Lower Triangular Matrix (row-wise):\n";
    for (int i = 0; i < size; i++) {
        cin >> lower[i];
    }

    // Sparse Representation (row, col, value)
    cout << "\nSparse Matrix Representation (row col value):\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i << " " << j << " " << lower[k++] << endl;
        }
    }

    // Reconstruct full matrix
    cout << "\nFull Lower Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j)
                cout << lower[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
