//Given an m x n matrix, return all elements of the matrix in spiral order.

// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
//input matrix-> 1 2 3
//               4 5 6
//               7 8 9  
                   
                   
                   
// Output: [1,2,3,6,9,8,7,4,5]

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int row=matrix.size();
        int col=matrix[0].size();
        
        int total=row*col;
        
        //indexs
        int startingRow=0;
        int startingCol=0;
        int endingRow=row-1;
        int endingCol=col-1;
        
        int count=0;
        while(count < total){
            //print starting row
            for(int i=startingCol; count<total && i<=endingCol; i++){
                ans.push_back(matrix[startingRow][i]);
                count++;
            }
            startingRow++;
            
            //print ending column
            for(int i=startingRow; count<total && i<=endingRow; i++){
                ans.push_back(matrix[i][endingCol]);
                count++;
            }
            endingCol--;
            
            //print ending row
            for(int i=endingCol; count<total && i>=startingCol; i--){
                ans.push_back(matrix[endingRow][i]);
                count++;
            }
            endingRow--;
            
            //print starting column
            for(int i=endingRow; count<total && i>=startingRow; i--){
                ans.push_back(matrix[i][startingCol]);
                count++;
            }
            startingCol++;
            
            
        }
       return ans;     
    }
};
