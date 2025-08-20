/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter size of array: ";
    cin>>n;

    int A[100];  
    cout<<"Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin>>A[i];
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (A[i] > A[j]) {
                count++;
            }
        }
    }

    cout<<"Number of inversions: " << count << endl;
    return 0;
}
