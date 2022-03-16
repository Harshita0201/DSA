
#include <iostream>

using namespace std;

int main()
{
    int arr[3][4];
    
    // //input row-wise
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cin >> arr[i][j];
    //     }
    // }
    
    // //output row-wise
    // for(int i=0; i<3; i++){
    //     for(int j=0; j<4; j++){
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    
     //input col-wise
    for(int col=0; col<4; col++){
        for(int row=0; row<3; row++){
            cin >> arr[row][col];
        }
    }
    
    
    for(int row=0; row<3; row++){
        for(int col=0; col<4; col++){
            cout << arr[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return 0;
}
