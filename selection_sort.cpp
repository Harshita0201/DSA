#include<iostream>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void selection_sort(int a[], int n){
    
    //to bring the smallest element towards the beginning 
    for(int i=0; i<(n-1); i++){
        int min_index = i;
        for(int j=i; j<=(n-1); j++){
            if(a[j]<a[min_index]){
                min_index = j;
            }
        }
        swap(a[i], a[min_index]);
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
    
    selection_sort(a,n);
    
    return 0;
}
