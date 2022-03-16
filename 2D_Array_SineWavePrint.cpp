// Problem Statement
// For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.
// For eg:-

// input->
// 1 2 3 4
// 5 6 7 8
// 9 10 11 12

// output->
// 1 5 9 10 6 2 3 7 11 12 8 4



vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    //Write your code here
    vector<int> ans;
    
    for(int col=0; col<mCols; col++){
        if(col&1){//odd -> Bottom to Top
            for(int row=nRows-1; row>=0; row--){
                ans.push_back(arr[row][col]);
            }
        }else{// even -> Top to Bottom
            for(int row=0; row<nRows; row++){
                ans.push_back(arr[row][col]);
            }
        }
     }
     
    return ans;
}
