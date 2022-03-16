// if 2D arrray -> 1 2 3 4
//                 5 6 7 8 
//                 9 10 11 12 
  
//   ouput sum -> 
// Sum of 1 row is = 10
// Sum of 2 row is = 26
// Sum of 3 row is = 42
               

#include <iostream>
using namespace std;

void rowWiseSum(int arr[][4], int r, int c){
    for(int i=0; i<3; i++){
        int sum=0;
        for(int j=0; j<4; j++){
            sum+=arr[i][j];
        }
        cout << "Sum of " << i+1 << " row is = " << sum << endl;
    }
    cout << endl;
    
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
    
    rowWiseSum(arr, 3, 4);
    
    
    
    
    return 0;
}
