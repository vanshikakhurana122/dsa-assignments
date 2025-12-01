#include <iostream>
using namespace std;

void bubblesort(int arr[], int n){
    for(int i=0; i<n; i++){
        bool swapped=false;
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped=true;
            }
        }
        if(!swapped)
            break;
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
    
    bubblesort(arr,n);
    
    cout<<"sorted array: ";
    printArray(arr, n);

    return 0;
}