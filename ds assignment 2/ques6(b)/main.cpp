/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int rows, cols, t1, t2;
    cout << "Enter rows and cols of matrices: ";
    cin >> rows >> cols;

    cout << "Enter non-zeros in Matrix A: ";
    cin >> t1;
    int A[100][3];
    A[0][0] = rows; A[0][1] = cols; A[0][2] = t1;
    cout << "Enter row col val for A:\n";
    for (int i = 1; i <= t1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter non-zeros in Matrix B: ";
    cin >> t2;
    int B[100][3];
    B[0][0] = rows; B[0][1] = cols; B[0][2] = t2;
    cout << "Enter row col val for B:\n";
    for (int i = 1; i <= t2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[200][3];
    int i = 1, j = 1, k = 1;

    while (i <= t1 && j <= t2) {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1]) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1];
            C[k][2] = A[i][2] + B[j][2];
            i++; j++; k++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1])) {
            C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2];
            i++; k++;
        } else {
            C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2];
            j++; k++;
        }
    }
    while (i <= t1) { C[k][0] = A[i][0]; C[k][1] = A[i][1]; C[k][2] = A[i][2]; i++; k++; }
    while (j <= t2) { C[k][0] = B[j][0]; C[k][1] = B[j][1]; C[k][2] = B[j][2]; j++; k++; }

    C[0][0] = rows; C[0][1] = cols; C[0][2] = k - 1;

    cout << "\nAddition Result (Triplet form):\n";
    for (int x = 0; x < k; x++) {
        cout << C[x][0] << " " << C[x][1] << " " << C[x][2] << endl;
    }
    return 0;
}
