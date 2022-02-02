// Q You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
// Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
// You need to find and return that number which is unique in the array/list.

#include <iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int findUnique(int *arr, int size)
{
    //Write your code here
    int ans=0;
    for(int i=0; i<size; i++){
        ans^=arr[i];   // a^a=0 ; a^0=a;
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
    int a= findUnique(arr,size);
    cout << a << endl;

    return 0;
}
