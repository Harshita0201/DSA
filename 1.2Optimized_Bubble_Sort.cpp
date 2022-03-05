
#include<iostream>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int arr[], int n){
    
    for(int i = 1; i<=n-1; i++) {
        //for round 1 to n-1
        bool swapped = false;
        
        for(int j =0; j<n-i-1; j++) {
            
            //process element till n-i th index
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
            
        }
        
        if(swapped == false) {
            //already sorted
            break;
        }
           
    }
    
    print(arr,n);
}

int main(){
    int n;
    cin >> n;
    int a[100];
    for(int i=0; i<n; i++){
        cin >>  a[i];
    }
    
    bubble_sort(a,n);
    
    return 0;
}
