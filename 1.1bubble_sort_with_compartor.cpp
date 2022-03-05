#include<iostream>
#include<algorithm>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

bool compare(int a, int b){
    return a>b;
}

void bubble_sort(int a[], int n, bool (&cmp)(int x, int y)){
    for(int i=1; i<=(n-1); i++){
        for(int j=0; j<=(n-i-1); j++){
            if(cmp(a[j], a[j+1])){
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
    
    bubble_sort(a,n,compare);
    
    return 0;
}


//time complexity  in case of sorted -> O(n) Best Case
//                 in case of unsorted ->O(n^2) worst case
