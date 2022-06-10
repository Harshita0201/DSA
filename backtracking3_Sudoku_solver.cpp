//using backtracking and recursion
//TC: 9^m, m is no. of empty cells.
//SC: O(1)

bool isSafe(int row, int col, vector<vector<int>>& board, int val){
    for(int i=0; i<board.size(); i++){
        //row check
        if(board[row][i]==val){ //if value present in a row already
            return false;
        }
        //col check
        if(board[i][col]==val){ //if value present in a col already
            return false;
        }
        //3*3 matrix check
        if(board[3*(row/3) + i/3][3*(col/3) +i%3]==val){
            return false;
        }
    }
    
    return true;
}

bool solve(vector<vector<int>>& board){
    int n=board[0].size();
    
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            
            //if cell empty
            if(board[row][col]==0){
                //try values from 1 to 9
                for(int val=1; val<=9; val++){
                    //put value if it is safe
                    if(isSafe(row, col, board, val)){
                        board[row][col]=val;
                        //recursive check for further possible soltion
                        bool isPossible = solve(board);
                        
                        if(isPossible){
                            return true;
                        }else{
                            //backtrack
                            board[row][col]=0;
                        }
                    }
                }
                return false; //when all values tried but sol still not possible
            }
        }
    }
    return true; 
}
void solveSudoku(vector<vector<int>>& sudoku)
{
    
    solve(sudoku);
}
