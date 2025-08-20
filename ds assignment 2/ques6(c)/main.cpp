/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    int m, n, p, t1, t2;
    cout << "Enter rows and cols of Matrix A: ";
    cin >> m >> n;

    cout << "Enter non-zeros in A: ";
    cin >> t1;
    int A[100][3];
    A[0][0] = m; A[0][1] = n; A[0][2] = t1;
    cout << "Enter row col val for A:\n";
    for (int i = 1; i <= t1; i++) cin >> A[i][0] >> A[i][1] >> A[i][2];

    cout << "Enter cols of Matrix B: ";
    cin >> p;
    cout << "Enter non-zeros in B: ";
    cin >> t2;
    int B[100][3];
    B[0][0] = n; B[0][1] = p; B[0][2] = t2;
    cout << "Enter row col val for B:\n";
    for (int i = 1; i <= t2; i++) cin >> B[i][0] >> B[i][1] >> B[i][2];

    int C[200][3], k = 1;
    C[0][0] = m; C[0][1] = p; C[0][2] = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            int sum = 0;
            for (int a = 1; a <= t1; a++) {
                if (A[a][0] == i) {
                    for (int b = 1; b <= t2; b++) {
                        if (B[b][1] == j && A[a][1] == B[b][0]) {
                            sum += A[a][2] * B[b][2];
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k][0] = i; C[k][1] = j; C[k][2] = sum;
                k++;
            }
        }
    }
    C[0][2] = k - 1;

    cout << "\nMultiplication Result (Triplet form):\n";
    for (int i = 0; i < k; i++) {
        cout << C[i][0] << " " << C[i][1] << " " << C[i][2] << endl;
    }
    return 0;
}
