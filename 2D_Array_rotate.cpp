// You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).

// You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

//  Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//                   1 2 3
//                   4 5 6
//                   7 8 9
// Output: [[7,4,1],[8,5,2],[9,6,3]]
//                   7 4 1
//                   8 5 2
//                   9 6 3

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        
        //1.Transpose of matrix
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(i!=j){ //in transpose diagonal elements remain same
                    int temp=matrix[i][j];
                    matrix[i][j]=matrix[j][i];
                    matrix[j][i]=temp;
                }
            }
        }
        
        
        //2. Swap first and last column elements respectively
        for(int i=0; i<n; i++){
            for(int j=0; j<n/2; j++){
                int temp=matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = temp;
            }
        }
    }
};
