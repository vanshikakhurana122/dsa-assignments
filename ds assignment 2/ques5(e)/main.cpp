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

    int size = n * (n + 1) / 2; // elements in lower triangle (including diagonal)
    int sym[size];

    cout << "Enter " << size << " elements of Symmetric Matrix (row-wise, lower triangle):\n";
    for (int i = 0; i < size; i++) {
        cin >> sym[i];
    }

    // Sparse Representation (row col value)
    cout << "\nSparse Matrix Representation (row col value):\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << i << " " << j << " " << sym[k] << endl;
            if (i != j) // symmetric counterpart
                cout << j << " " << i << " " << sym[k] << endl;
            k++;
        }
    }

    // Reconstruct full matrix
    cout << "\nFull Symmetric Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) {   
                cout << sym[k++] << " ";
            } else {        
                int idx = (j * (j + 1)) / 2 + i;
                cout << sym[idx] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
