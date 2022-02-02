// q)You are given an array ‘ARR’ of size ‘N’ containing each number between 1 and ‘N’ - 1 at least once. 
//  There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.


#include <iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findDuplicate(int arr[], int size) 
{
    // Write your code here
     int ans=0;
     for (int i=0; i<size; i++){
            ans = ans^arr[i];
     }
    
     for (int i=1; i<size; i++){
            ans= ans^i;
     }
      return ans;
}


int main()
{
    int arr[100];
    int size;
    cin >> size;
    for(int i=0; i<size; i++){
        cin >> arr[i];
    }
    print(arr,size);
    cout << endl;
    int a=findDuplicate(arr,size);
    
    cout << a << endl;
    return 0;
}
