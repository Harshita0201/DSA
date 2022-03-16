
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
  
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        
        int low=0;
        int end=row*col-1;
        int mid=low+(end-low)/2;
        
        while(low<=end){
            int element= matrix[mid/col][mid%col];
            if(element == target){
                return true;
            }
            if(element<target){ //go to left part
                low=mid+1;
            }
            else{ //go to right part
                end=mid-1;
            }
            mid=low+(end-low)/2;
        }
        return false;
    }
};
