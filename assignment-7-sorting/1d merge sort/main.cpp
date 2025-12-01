#include <iostream>
using namespace std;

// Merge two sorted halves into a single sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;  // size of left half
    int n2 = right - mid;     // size of right half

    int L[n1], R[n2];  // temporary arrays

    // Copy data into temp arrays
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // Merge the temp arrays back into arr
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Recursive merge sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // find middle

        // Divide the array into halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int n;
    cout<<"enter number of elements: ";
    cin>>n;
    
    int arr[n];
    cout<<"enter "<<n<<" elements: ";
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    
    cout<<"unsorted array: ";
    printArray(arr, n);
    
    mergeSort(arr,0,n-1);
    
    cout<<"sorted array: ";
    printArray(arr, n);

    return 0;
}