#include <iostream>
using namespace std;

void insertionSort(int arr[], int n){
    for(int i=1; i<n; i++){
        int temp=arr[i];
        int j=i;
        while(j>0 && arr[j-1]>temp){
            arr[j]=arr[j-1];
            j--;
        }
        arr[j]=temp;
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
    
    insertionSort(arr,n);
    
    cout<<"sorted array: ";
    printArray(arr, n);

    return 0;
}