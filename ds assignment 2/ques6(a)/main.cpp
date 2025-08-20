/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int rows, cols, t;
    cout << "Enter rows and cols of matrix: ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> t;

    int A[100][3], T[100][3]; // triplet representation

    A[0][0] = rows; A[0][1] = cols; A[0][2] = t;

    cout << "Enter row col value for each non-zero element:\n";
    for (int i = 1; i <= t; i++) {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    // Transpose
    T[0][0] = cols;
    T[0][1] = rows;
    T[0][2] = t;

    int k = 1;
    for (int c = 0; c < cols; c++) {
        for (int i = 1; i <= t; i++) {
            if (A[i][1] == c) {
                T[k][0] = A[i][1];
                T[k][1] = A[i][0];
                T[k][2] = A[i][2];
                k++;
            }
        }
    }

    cout << "\nTranspose (Triplet form):\n";
    for (int i = 0; i <= t; i++) {
        cout << T[i][0] << " " << T[i][1] << " " << T[i][2] << endl;
    }
    return 0;
}
