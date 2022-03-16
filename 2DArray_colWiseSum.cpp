// if ip 2D array -> 1 2 3 4 
//                   5 6 7 8 
//                   9 10 11 12
//   output->
// Sum of 1 column is = 15
// Sum of 2 column is = 18
// Sum of 3 column is = 21
// Sum of 4 column is = 24
  


#include <iostream>
using namespace std;

void colWiseSum(int arr[][4], int r, int c){
    for(int col=0; col<4; col++){
        int sum=0;
        for(int row=0; row<3; row++){
            sum+=arr[row][col];
        }
        cout << "Sum of " << col+1 << " column is = " << sum << endl;
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
    
    colWiseSum(arr, 3, 4);
    
    
    
    
    return 0;
}
