#include <iostream>

using namespace std;

void printArray(int arr[], int n)
{
    for(int i{0};i<n;i++){
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int a[], int left[], int right[],int nl, int nr){
    // int nl = sizeof(left)/sizeof(left[0]);
    // int nr = sizeof(right)/sizeof(right[0]);
    int i{0},j{0},k{0};
    while(i<nl&&j<nr){
        if(left[i]<right[j]){
            a[k] = left[i];
            i++;
        }else{
            a[k] = right[j];
            j++;
        }
        k++;
    }
    while(i<nl){
        a[k] = left[i];
        i++;k++;
    }
    while(j<nr){
         a[k] = right[j];
        j++;k++;
    }
    printArray(a,nl+nr);

}

void mergeSort(int a[],int n){
    if(n<=1) return;
    // int n = sizeof(a)/sizeof(a[0]);
    int mid = n/2;
    // cout<<"n = "<<n<<"\tmid="<<mid<<endl;
    // if(mid==0)return;
    int right [mid]{0};
    int left [n-mid]{0};
    for(int i{0};i<mid;i++){
        left[i] = a[i];
        // cout<<"left\t"<<left[i]<<endl;
    }
    for(int i{mid};i<n;i++){
       right[i-mid] = a[i];
    //    cout<<"right\t"<<right[i-mid]<<endl;
    }
    mergeSort(left,mid);
    mergeSort(right,n-mid);
    merge(a,left,right,mid,n-mid);
}

int main(){
    int arr[] {6,2,1,-8,0,-5,3,7};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i{0};i<n;i++){
        cout<< arr[i]<<endl;
    }

    mergeSort(arr,n);

    cout<< "new array:"<<endl;

    for(int i{0};i<n;i++){
        cout<< arr[i]<<endl;
    }

    return 0;
}