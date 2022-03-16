
// if 2D arrray -> 1 2 3 4
//                 5 6 7 8 
//                 9 10 11 12 
  
//   oupu-> max row sum, sum is 42, at index 2
// Sum of 1 row is = 10   row index 0
// Sum of 2 row is = 26   "   "     1
// Sum of 3 row is = 42   "   "    2


#include <iostream>
#include<climits>
using namespace std;

void maxRowSum(int arr[][4], int r, int c){
     int maxi=INT_MIN;
     int index=-1;
    for(int i=0; i<3; i++){
        int sum=0;
        for(int j=0; j<4; j++){
            sum+=arr[i][j];
        }
        if(sum>maxi){
            maxi=sum;
            index=i;
        }
        
    }
    cout << "Largest sum row sum, sum  is " << maxi << " at index(0 indexed) " << index << endl;
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
    
    maxRowSum(arr, 3, 4);
    
    
    
    
    return 0;
}
