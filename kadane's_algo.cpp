#include<iostream>
using namespace std;
void  kadane_max_sum_subarray(int a[], int n){
    int current_sum =0;
    int max_sum=0; //maximum sum so far
    
    for(int i=0; i<n; i++){
        current_sum +=a[i];
        if(current_sum<0){
            current_sum = 0;
        }
        max_sum = max(current_sum, max_sum);
    }
    
    cout << "Maximum sum is = " << max_sum << endl;
    
    
}
void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
     
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    print(a,n);
    
    kadane_max_sum_subarray(a,n);
    
    return 0;
}
