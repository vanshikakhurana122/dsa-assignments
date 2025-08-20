/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <string>
using namespace std;
int main(){
    cout<<"Enter a string in lowercase ";
    string str;
    cin>>str;
    for(int i=1;i<=str.length()-1;i++){
        for(int j=0;j<=str.length()-i-1;j++){
            if(str[j]-'a'>str[j+1]-'a'){
                swap(str[j],str[j+1]);
            }
        }
    }
    cout<<str;

}