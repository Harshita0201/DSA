class Solution {
public:
    int solve(vector<int>& v, int i, int j){
        //base case
        if(i+1==j){ //only 2 vertices
            return 0;
        }
        
        int ans=INT_MAX;
        
        for(int k=i+1; k<j; k++){
            ans=min(ans, v[i]*v[j]*v[k]+solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }
    
    int solveMem(vector<int>& v, int i, int j, vector<vector<int>>&dp){
        
        //base case
        if(i+1==j){ //only 2 vertices
            return 0;
        }
        
        if(dp[i][j]!=-1){//if dp solution already exists
            return dp[i][j];
        }
        
        int ans=INT_MAX;
        
        for(int k=i+1; k<j; k++){
            ans=min(ans, v[i]*v[j]*v[k]+solveMem(v, i, k, dp) + solveMem(v, k, j, dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
     
    int solveTab(vector<int>&v){
        int n=v.size();
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        //opposite of what happens in memo
        //j dtarts from j=i+2 bcz @j=i+1 (2 points) no traingle can be formed
        for(int i=n-1; i>=0; i--){
            for(int j=i+2; j<n; j++){
                        int ans=INT_MAX;
                        for(int k=i+1; k<j; k++){
                             ans=min(ans, v[i]*v[j]*v[k]+dp[i][k] + dp[k][j]);
                             dp[i][j]=ans;
                        }
                }
            }
        
        return dp[0][n-1];
    }
    
    
    int minScoreTriangulation(vector<int>& values) {
        int n=values.size();
        
        //recursive solution 
        //return solve(values, 0, n-1); //paasing first and last index as i and j(adjacent vertices)
        
        //dp memoization top-down approach
        vector<vector<int>> dp(n, vector<int>(n, -1)); //since i, j are changing params therefore 2d dp
        
        //return solveMem(values, 0, n-1, dp);
        
        //dp tabulation bottom-up approach
        return solveTab(values); // tc:o(n^3) sc:o(n^2)
    }
    
};
