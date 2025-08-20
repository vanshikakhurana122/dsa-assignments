/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter size of square matrix (n): ";
    cin >> n;

    int mainDiag[n], upperDiag[n - 1], lowerDiag[n - 1];

    cout << "Enter " << n << " main diagonal elements: ";
    for (int i = 0; i < n; i++) 
    cin >> mainDiag[i];

    cout << "Enter " << n - 1 << " upper diagonal elements: ";
    for (int i = 0; i < n - 1; i++)
    cin >> upperDiag[i];

    cout << "Enter " << n - 1 << " lower diagonal elements: ";
    for (int i = 0; i < n - 1; i++) 
    cin >> lowerDiag[i];

    // Sparse Representation
    cout << "\nSparse Matrix Representation (row col value):\n";
    for (int i = 0; i < n; i++) {
        cout << i << " " << i << " " << mainDiag[i] << endl; // main diag
    }
    for (int i = 0; i < n - 1; i++) {
        cout << i << " " << i + 1 << " " << upperDiag[i] << endl; // upper diag
    }
    for (int i = 0; i < n - 1; i++) {
        cout << i + 1 << " " << i << " " << lowerDiag[i] << endl; // lower diag
    }

    // Reconstruct full matrix (to visualize)
    cout << "\nFull Tri-Diagonal Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << mainDiag[i] << " ";
            else if (j == i + 1)
                cout << upperDiag[i] << " ";
            else if (i == j + 1)
                cout << lowerDiag[j] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
