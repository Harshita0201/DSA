#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int s){
     for(int i=0; i<s; i++){
        cout <<  arr[i] << " ";
    }
    cout << endl;
}

void sort_01(int arr[], int s){
    int i=0;
    int j=s-1;
    while(i<j){
        while(arr[i]==0 && i<j){
            i++;
        }
        
        while(arr[j]==1 && i<j){
            j--;
        }
        
       // if(arr[i]==1 && arr[j]==0)
            swap(arr[i], arr[j]);
            i++;
            j--;
        
    }
    
    print(arr, s);
    
}

int main()
{
    int arr[100];
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    sort_01(arr,n);

    return 0;
}
