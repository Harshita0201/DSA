class Solution{
public: 
    int solve(vector<vector<int>> &mat, int i, int j, int &maxi){
        //base case
        if(i>=mat.size() || j>=mat[0].size()){ //index out of bound
            return 0;
        }
        
        int right = solve(mat, i, j+1, maxi);
        int diagonal = solve(mat, i+1, j+1, maxi);
        int down = solve(mat, i+1, j, maxi);
        
        if(mat[i][j]==1){//if current pos ele is 1
          int ans=1+min(right, min(diagonal, down));
          maxi=max(maxi, ans);
          return ans;
        }else{
            return 0;
        }
    }
    int solveMem(vector<vector<int>> &mat, int i, int j, int &maxi, vector<vector<int>>&dp){
        //base case
        if(i>=mat.size() || j>=mat[0].size()){ //index out of bound
            return 0;
        }
        
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        int right = solveMem(mat, i, j+1, maxi, dp);
        int diagonal = solveMem(mat, i+1, j+1, maxi, dp);
        int down = solveMem(mat, i+1, j, maxi, dp);
        
        
        if(mat[i][j]==1){//if current pos ele is 1
          dp[i][j]=1+min(right, min(diagonal, down));
          maxi=max(maxi, dp[i][j]);
          return dp[i][j];
        }else{
            return dp[i][j]=0;
        }
    }
    int solveTab(vector<vector<int>> &mat, int i, int j, int &maxi){
        int n=mat.size();
        int m=mat[0].size();
        
        //create dp vector
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        
        for(int i=n-1; i>=0; i--){
            for(int j=m-1; j>=0; j--){
                int right = dp[i][j+1];
                int diagonal = dp[i+1][j+1];
                int down = dp[i+1][j];
                
                if(mat[i][j]==1){//if current pos ele is 1
                  dp[i][j]=1+min(right, min(diagonal, down));
                  maxi=max(maxi, dp[i][j]);
                }else{
                  dp[i][j]=0;
               }
            }
        }
        return dp[0][0]; //can return anything the real ans maxi gets updated and is passed to driver func
    }
    
    // int solveSO(vector<vector<int>> &mat, int i, int j, int &maxi){
        
    //     int n=mat.size();
    //     int m=mat[0].size();
        
    //     vector<int> curr(m+1, 0);
    //     vector<int> next(m+1, 0);
        
    //     //here dp[i] in tab becomes curr vector of 1 row
    //     //dp[i+1] in tab becomes next vector of next row
        
    //     for(int i=n-1; i>=0; i--){
    //         for(int j=m-1; j>=0; j--){
                
    //             int right = curr[j+1];
    //             int diagonal = next[j+1];
    //             int down = next[j];
                
    //             if(mat[i][j]==1){//if current pos ele is 1
    //               curr[j]=1+min(right, min(diagonal, down));
    //               maxi=max(maxi, curr[j]);
    //             }else{
    //               curr[j]=0;
    //           }
    //         }
    //         //move ahead
    //         next=curr;
    //     }
            
    //     return next[0]; //can return anything the real ans maxi gets updated and is passed to driver func
    // }
    
    int maxSquare(int n, int m, vector<vector<int>> mat){
        // recursive soln 
        int maxi=0;
        //solve(mat, 0, 0, maxi); //starting from 0th index
        //return maxi;
        
        //dp memoization tc:o(n*m) sc:o(n*m) + o(n*m)
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // solveMem(mat, 0, 0, maxi, dp);
        // return maxi;
        
        //dp tabulation tc:o(n*m) sc:o(n*m)
        solveTab(mat, 0, 0, maxi);
        return maxi;
       
        
    }
};
