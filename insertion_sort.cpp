#include<iostream>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void insertion_sort(int a[], int n){
    
    for(int i=1; i<=n-1; i++){
        int e=a[i]; //to insert or place this at the correct postion
        int j=i-1;
        while(j>=0 && a[j]>e){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=e;
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
    
    insertion_sort(a,n);
    
    return 0;
}
