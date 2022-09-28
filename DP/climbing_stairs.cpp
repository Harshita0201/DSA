// You are climbing a staircase. It takes n steps to reach the top.

// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

class Solution {
public:
    int solve(int stair){
        if(stair<0){
            return 0;
        }
        if(stair==0 || stair==1){
            return 1;
        }
        
        return solve(stair-1)+solve(stair-2);
        
    }
    int solveMem(int stair, vector<int>&dp){
       if(stair<0){
            return 0;
        }
        if(stair==0 || stair==1){
            return 1;
        }
        
        if(dp[stair]!=-1){
            return dp[stair];
        }
        
        return dp[stair]=solveMem(stair-1, dp)+solveMem(stair-2, dp);
    }
    int climbStairs(int n) {
    
        //recurisve approach
        //return solve(n);
        //return ans;
        
        //memoization dp
        //vector<int> dp(n+1, -1);
        //return solveMem(n, dp);
        
        //dp tabulation
        if(n == 1 || n == 2){
            return n;
        }
        vector<int> v;
        v.push_back(1);
        v.push_back(2);
        for(int i = 2; i<n; i++){
            int num = v[i-1]+v[i-2];
            v.push_back(num);
        }
        return v.back();
    
    }
};
