bool isSafe(int newx,int newy,vector < vector < int >> & arr, vector<vector<bool> >&visited, int n){
    if((newx >= 0 && newy>= 0) && (newx<=n-1 && newy<=n-1) && (arr[newx][newy]==1 && visited[newx][newy]==0)){
        return true;
    }else{
        return false;
    }
    
}

void solve(int x, int y, vector<vector<int>> & arr, int n, vector<string> &ans, vector<vector<bool>> &vis, string path){
    //base case if we reached the destination, store ans and return 
    if(x==n-1 && y==n-1){
        ans.push_back(path);
        return;
    }
    
    // D L R U
    
    //Down
    if(isSafe(x+1, y, arr, vis, n)){
        vis[x][y]=1; //mark visited
        solve(x+1, y, arr, n, ans, vis, path+'D');
        vis[x][y]=0; //mark as not visited after returning
    }
    
    //Left
    if(isSafe(x, y-1, arr, vis, n)){
        vis[x][y]=1; //mark visited
        solve(x, y-1, arr, n, ans, vis, path+'L');
        vis[x][y]=0; //mark as not visited after returning
    }
    
    //Right
    if(isSafe(x, y+1, arr, vis, n)){
        vis[x][y]=1; //mark visited
        solve(x, y+1, arr, n, ans, vis, path+'R');
        vis[x][y]=0; //mark as not visited after returning
    }
    
    //Up
    if(isSafe(x-1, y, arr, vis, n)){
        vis[x][y]=1; //mark visited
        solve(x-1, y, arr, n, ans, vis, path+'U');
        vis[x][y]=0; //mark as not visited after returning
    }
}

vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    // Write your code here.
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    
    string path="";
    if(arr[0][0]==0){
        return ans;
    }
    solve(0, 0, arr, n, ans, visited, path);
    
    return ans;
}
