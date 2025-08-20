/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    string result = "";
    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        // check if character is not a vowel
        if (ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u' &&
            ch!='A' && ch!='E' && ch!='I' && ch!='O' && ch!='U') {
            result += ch;
        }
    }

    cout << "String after deleting vowels: " << result << endl;

    return 0;
}
