#include<iostream>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void bubble_sort(int a[], int n){
    
    for(int i=1; i<=n-1; i++){
        for(int j=0; j<=(n-i-1); j++){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    print(a,n);
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>  a[i];
    }
    
    bubble_sort(a,n);
    
    return 0;
}
