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
    cout<<"enter the size of array:"<<endl;
    cin>>size;
    int arr[size];
    cout<<"enter "<<size<<" elements of array"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
     int distinctCount=0;

    for (int i=0; i<size; i++) 
    {
        int isDistinct=1;
        for (int j=0; j<i; j++) {
            if (arr[i]==arr[j]) {
                isDistinct=0;
                break;
            }
        }

        if(isDistinct==1)
        {
            distinctCount++;
        }
    }
    cout<<"Total number of distinct elements: "<<distinctCount<<"\n";
    return 0;
}