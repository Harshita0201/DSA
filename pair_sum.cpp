// to find the pairs of elements who sum to given sum.
// given array = [1, 3, 5, 7, 10, 11, 12, 13] and given sum = 16

#include<iostream>
using namespace std;
void pair_sum(int a[], int n){
    int i = 0;
    int j = n-1;
    int sum = 16; // given in question
    int current_sum = 0; 
    cout << "Pairs of elements that sum to  = " << sum << " are = " << endl;
    while(i < j){
        current_sum = a[i]+a[j];
        if(current_sum < sum){
            i++;
        }else if(current_sum > sum){
            j--;
        }else if(current_sum == sum){
            cout << a[i] << " " << a[j] << endl;
            j--; 
            i++;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    pair_sum(a,n);
    return 0;
}
