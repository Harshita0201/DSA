#include<iostream>
#include<algorithm>
using namespace std;
void print(int a[], int size){
    for(int i=0; i<size; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void max_sum_subarray(int a[], int n){
    int max_sum =0;
    int current_sum=0;
    int s=-1;
    int e=-1;
    
    for(int i=0;i<n;i++){
        for(int j=i; j<n; j++){
            //generate all possible subarrays and their sum
            //current sum for current subarray intialised to 0
           // cout << "subbarray between " << i << " and " << j <<  " and it's sum : " <<endl;
            current_sum=0;
            for(int k=i; k<=j; k++){
                //cout  <<  a[k] << ",  ";
                current_sum +=a[k];
                //cout << " sum = " << current_sum;
            }
            cout << endl;
            //update max_sum if current_sum > max_sum
            if(current_sum>max_sum){
                max_sum = current_sum;
                s=i;
                e=j;
            }
        }
    }
    
    cout << "Maximum sum is = " << max_sum << endl;
    cout << "Array is = ";
    for(int j=s; j<e; j++){
        cout << a[j] << " ";
    }
    cout << endl;
}


int main(){
    int n;
    cin >> n;
    int a[n];
    for(int i=0; i<n; i++){
        cin >>  a[i];
    }
    
    max_sum_subarray(a,n);
    
    return 0;
    
}
