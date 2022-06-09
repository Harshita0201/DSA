void addSolution(vector<vector<int>> &ans, vector<vector<int>> &board, int n){
    
    vector<int> temp;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            temp.push_back(board[i][j]);
        }
    }
    
    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n){
    //safe-> no attack
    //not in same row
    //not in same col(gets recursively checked)
    //not in same diagonal
    
    int x=row;
    int y=col;
    
    //check for same row
    //check from left to right till the element --for row check and diagonal check
    while(y>=0){
        if(board[x][y]==1){//if you get a queen in that col of that row
            return false;
        }
        y--;
    }
    
    //check for diagonal
    x=row;
    y=col;
    //for diagonal: ^
    //             /
    //            /
    //           / 
    //          /
    //         /
    while(x>=0 && y>=0){
        if(board[x][y]==1){//if you get a queen in that col of that row
            return false;
        }
        y--;
        x--;
    }
    
    //x-1, y-1
    //for diagonal:/
    //            /
    //           /
    //          /
    //         v   
    //  x+1, y-1
    x=row;
    y=col;
    while(x<n && y>=0){
        if(board[x][y]==1){//if you get a queen in that col of that row
            return false;
        }
        y--;
        x++;
    }
    
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n ){
    //base case, when all cols get filled, push into ans
    if(col==n){
        addSolution(ans, board, n);
        return;
    }
    
    //solve for 1 case, that is put queen in first col, check at all rows
    //if safe proceed
    //then recurse for all the other cols
    for(int row=0; row<n; row++){
        if(isSafe(row, col, board, n)){
            //if it is safe to place queen, place it
            board[row][col]=1;
            solve(col+1, ans, board, n);
            //backtrack when returning from recurisve call
            board[row][col]=0;
        }
    }
}
vector<vector<int>> nQueens(int n)
{
	// Write your code here
	vector<vector<int>> board(n, vector<int>(n,0));
    vector<vector<int>> ans;
    
    solve(0, ans, board, n); //pass initial col as 0
    
    return ans;
    
}
