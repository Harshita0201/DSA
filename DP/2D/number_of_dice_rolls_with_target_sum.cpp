//https://practice.geeksforgeeks.org/problems/dice-throw5349/1

class Solution {
  public:
    long long int solve(int dices, int faces, int target){
        //base cases
        if(target<0){
            return 0; //negative target can never be acheived
        }
        if(dices!=0 && target==0){
            //we have dices but no target
            return 0;
        }
        if(dices==0 && target!=0){
            //we have target but no dices to throw
            return 0;
        }
        if(target==0 && dices==0){
            return 1; //no target no throw 1 sol
        }
        
        long long int ans=0;
        for(int i=1; i<=faces; i++){
            ans= ans+ solve(dices-1, faces, target-i); //num of faces will remain same, 1 dice occupied, target reduces by face used
        }
        
        return ans;
    }
    
    long long int solveMem(int dices, int faces, int target, vector<vector<long long>>&dp){//from n to 0
        //base cases
        if(target<0){
            return 0; //negative target can never be acheived
        }
        if(dices!=0 && target==0){
            //we have dices but no target
            return 0;
        }
        if(dices==0 && target!=0){
            //we have target but no dices to throw
            return 0;
        }
        if(target==0 && dices==0){
            return 1; //no target no throw 1 sol
        }
        
        if(dp[dices][target]!=-1){
            return dp[dices][target];
        }
        
        long long int ans=0;
        for(int i=1; i<=faces; i++){
            ans= ans+ solveMem(dices-1, faces, target-i, dp); //num of faces will remain same, 1 dice occupied, target reduces by face used
        }
        
        return dp[dices][target]=ans;
    }
    long long int solveTab(int dices, int faces, int target){// from 0 to n
        vector<vector<long long>> dp(dices+1, vector<long long>(target+1, 0));
        //base case
        dp[0][0]=1; //no dice, no target
        
        for(int d=1; d<=dices; d++){
            for(int t=1; t<=target; t++){
                long long ans=0;
                //for all faces
                for(int i=1; i<=faces; i++){
                    if(t-i>=0){
                        ans=ans+dp[d-1][t-i];
                    }
                        
                }
                dp[d][t]=ans;
            }
        }
        
        return dp[dices][target];
        
    }
    long long noOfWays(int M , int N , int X) {
        //recursive approach
        //return solve(N, M, X); //passing N faces M dices ...starting from nth face ...mth dice ...and target
        
        //TOP DOWN DP MEMOIZATION APPROACH
        //vector<vector<long long>> dp(N+1, vector<long long>(X+1, -1));
        //return solveMem(N, M, X, dp);
        
        //bottom up dp : tabulation method
        //return solveTab(N, M, X); //tc: o(n*m*x) sc:(n*x)
        
        //spcae optimization TC:O(N*M*X) Sc:O(2*x) or 2*(x+1)
        vector<long long> curr(X+1, 0);
        vector<long long> prev(X+1, 0);
        
        //after analysing base case
        prev[0]=1;
        
        for(int d=1; d<=N; d++){
            for(int t=1; t<=X; t++){
                long long ans=0;
                for(int i=1; i<=M; i++){
                    if(t-i>=0){
                        ans=ans+prev[t-i];
                    }
                    curr[t]=ans;
                }
            }
            prev=curr;
        }
        return prev[X];
    }
};
