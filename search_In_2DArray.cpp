#include <iostream>
using namespace std;

bool isPresent(int arr[][4], int t, int r, int c){
    for(int row=0; row<r; row++){  //or row<3
        for(int col=0; col<c; col++){ //or col<4
              if(arr[row][col]==t){
                  return true;
              }
        }
    }
    return false;
}

int main()
{
    int arr[3][4];
    
    //input row-wise
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cin >> arr[i][j];
        }
    }
    
    //output row-wise
    for(int i=0; i<3; i++){
        for(int j=0; j<4; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    int target;
    cout << "Enter the element you want to search =" << endl;
    cin >> target;
    
    if(isPresent(arr, target, 3, 4)){
        cout << "Element is found !" << endl;
    }else{
        cout << "Element is not found" << endl;
    }
    
    
    
    
    return 0;
}
