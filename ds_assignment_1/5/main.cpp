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
   int n,m;
   cout<<"Enter the no of rows: ";
   cin>>n;
   
   cout<<"Enter the no of columns: ";
   cin>>m;
   
   cout<<"Enter the elements of the array:\n";
   int arr[n][m];
   for(int i=0; i<n;i++){
       for(int j=0; j<m; j++){
           cin>>arr[i][j];
       }
   }
   cout<<"The array is:\n";
   for(int i=0; i<n;i++){
       for(int j=0; j<m; j++){
           cout<<arr[i][j]<<" ";
       }
       cout<<"\n";
   }
    cout<<"\nSum of each row:"<<endl;
    for (int i=0; i<n; i++) {
        int rowSum = 0;
        for (int j=0; j<m; j++) {
            rowSum +=arr[i][j];
        }
        cout<<"Row "<<i+1<<" sum = "<<rowSum<<endl;
    }
    
    cout<<"\nSum of each column:"<<endl;
    for(int j=0; j<m; j++) {
        int colSum=0;
        for (int i=0; i<n; i++) {
            colSum += arr[i][j];
        }
        cout<<"Column "<<j+1<<" sum = "<<colSum<<endl;
    }
    return 0;
}
