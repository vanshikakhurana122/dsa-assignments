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
    int size;
    cout<<"Enter the size of the array: ";
    cin>>size;
    
    int arr[size];
    cout<<"Enter the elements of the array: ";
    
    for(int i=0; i<size; i++){
        cin>>arr[i];
    }
    cout<<"the array is: ";
    for(int i=0; i<size; i++){
    cout<<arr[i]<<" ";
    }
   
    cout<<"\nthe uniques array is:";
    for(int i=0; i<size; i++){
       int duplicate=0;
        for(int j=i+1; j<size; j++){
            if(arr[i]==arr[j]){
                duplicate=1;
                break;
            }
        }
            if(duplicate==0)
            
            cout<<arr[i]<<" ";
    }
    return 0;
}