#include <iostream>
using namespace std;

void print(int arr[], int size){
    for(int i=0; i<size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swapAlternate(int arr[], int size){
    for(int i=0; i<size; i+=2){
        if(i+1<size){
            swap(arr[i], arr[i+1]);
        }
    }
    print(arr,size);
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
    swapAlternate(arr,size);
    

    return 0;
}
