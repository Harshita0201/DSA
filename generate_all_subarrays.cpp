#include<iostream>
#include<algorithm>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void generate_subarrays(int a[], int n){
    for(int i=0;i<n;i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout << a[k] << ", ";
            }
            cout << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>  a[i];
    }
    
    generate_subarrays(a,n);
    
    return 0;
}
