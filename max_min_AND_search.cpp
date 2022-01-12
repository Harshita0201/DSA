#include<iostream>
#include<climits>
using namespace std;
void print(int a[], int n){
    for(int i=0; i<n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void min_max(int a[], int n){
    int maximum = INT_MIN;
    int minimum = INT_MAX;
    
    for(int i=0; i<n; i++){
        if(a[i]>maximum){
            maximum = a[i];
        }
        if(a[i]<minimum){
            minimum = a[i];
        }
    }
    
    cout << "Maximum element is = " << maximum << endl;
    cout << "Minimum element is = " << minimum << endl;
    
}

int linear_search(int a[], int n, int k){
    for(int i=0; i<n; i++){
        if(a[i]==k){
            return i;
        }
    }
    return -1;
}

int binary_search(int a[], int n, int k){
    int s=0;
    int e=n-1;
    while(s<=e){
        int mid= (s+e)/2;
        if(a[mid]==k){
            return mid;
            
        }else if(a[mid] > k){ //key in LHS of array's mid
            e = mid-1;
        }else{ // key in RHS of array's mid
            s = mid+1;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    
    int a[n];
     
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    print(a,n);
    
    min_max(a,n);
    
    int key, index;
    
    cout << "Enter the element you want to search = ";
    cin >> key;
    
   
    index = linear_search(a,n,key);
    //cout << index << endl;
    if(index >= 0){
        cout << key << " found at index " << index << endl;
    }else{
        cout << "element not found" << endl;
    }
    
    //use sorted array for binary search
    //index = linear_search(a,n,key);
    // if(index >= 0){
    //     cout << key << " found at index " << index << endl;
    // }else{
    //     cout << "element not found" << endl;
    // }
    
    return 0;
}
