#include <iostream>
using namespace std;

// code for merge sort
void merge(int arr[],int start,int end){
    int middle = (start+end)/2;
    int i=start,j = middle+1,k=0;
    int ans[end-start+1];
    while(i<=middle&&j<=end){
        if(arr[i]<arr[j]){
            ans[k] = arr[i];
            i++;
            k++;
        }else{
            ans[k] = arr[j];
            j++;
            k++;
        }
    }
    while(i<=middle){ans[k] = arr[i];i++;k++;}
    while(j<=end){ans[k] = arr[j]; j++; k++;}
    k=0;
    for(int i=start; i<=end; i++){
        arr[i] = ans[k];
        k++;
    }
}
void merge_sort(int arr[],int start, int end){
    if(start<end){
        int middle = (start+end)/2;
        merge_sort(arr,start,middle);
        merge_sort(arr,middle+1,end);
        merge(arr,start,end);
    }
}

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
