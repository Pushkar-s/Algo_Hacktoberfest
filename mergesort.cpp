#include <iostream>
using namespace std;

// code for merge sort


int main(){
    int arr[100],n;
    cout<<"enter number of elements\n";
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    merge_sort(arr,0,n-1);
    show_array(arr,n);
    return 0;
}
