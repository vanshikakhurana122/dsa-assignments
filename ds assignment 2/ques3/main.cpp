#include <iostream>
using namespace std;

//(a)linear
int findMissingLinear(int arr[], int n) {
    for (int i=0; i<n-1; i++) {
        if (arr[i]!=i+1) {
            return i+1; //missing number
        }
    }
    return n;
}

//(b)Binary
int findMissingBinary(int arr[], int n) {
    int left=0, right=n-2; 
    
    while (left<=right) {
        int mid=left+(right-left)/2;
        
        // if value matches its position (arr[mid] == mid+1), missing is in right half
        if (arr[mid]==mid+1) {
            left=mid+1;
        }
        else {
            right=mid-1; // missing in left half
        }
    }
    return left + 1; // missing number
}

int main() {
    int n;
    cout<<"Enter n (array size will be n-1): ";
    cin>>n;

    int arr[n-1];
    cout<<"Enter "<<n-1<<" sorted elements from 1 to "<<n<<" with one missing: ";
    for (int i=0; i<n-1; i++) {
        cin>>arr[i];
    }

    cout<<"Missing number using Linear method: "<<findMissingLinear(arr, n)<<endl;
    cout<<"Missing number using Binary Search: "<<findMissingBinary(arr, n)<<endl;

    return 0;
}
