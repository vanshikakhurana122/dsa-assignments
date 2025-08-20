/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout<<"Enter size of array ";
    cin>>n;

    int arr[100];  

    cout<<"Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++) 
    {
        cin>>arr[i];
    }

    int element;
    cout<<"Enter element to search: ";
    cin>>element;

    int start = 0, end = n - 1;
    bool found = false;

    while (start <= end) {
        int mid = (start + end) / 2;

        if (arr[mid] == element) {
            cout << "Element found at index " << mid << endl;
            found = true;
            break;
        }
        else if (arr[mid] < element) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    if (!found) {
        cout << "Element not found" << endl;
    }

    return 0;
}
