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

    int diag[n];  
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) {
        cin >> diag[i];
    }

    // Store as sparse matrix (row, col, value)
    cout << "\nSparse Matrix Representation (row col value):\n";
    for (int i = 0; i < n; i++) {
        if (diag[i] != 0) {   
            cout << i << " " << i << " " << diag[i] << endl;
        }
    }

    
    cout << "\nFull Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}
