//https://leetcode.com/problems/reducing-dishes/

class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time){
        //base case, we reached the end of satisfaction index
        if(index==satisfaction.size()){
            return 0;
        }
        
        //2 cases
        int include = satisfaction[index]*(time+1) + solve(satisfaction, index+1, time+1); //like coef + recursive call to for next dish
        int exclude = 0 + solve(satisfaction, index+1, time); // no dish prepared + recursive call for next dish
        return max(include, exclude);
    }
    int solveMem(vector<int>& satisfaction, int index, int time, vector<vector<int>>&dp){
        //base case, we reached the end of satisfaction index
        if(index==satisfaction.size()){
            return 0;
        }
        //if dp soln already exists
        if(dp[index][time]!=-1){
            return dp[index][time];
        }
        
        //2 cases
        int include = satisfaction[index]*(time+1) + solveMem(satisfaction, index+1, time+1, dp); //like coef + recursive call to for next dish
        int exclude = 0 + solveMem(satisfaction, index+1, time, dp); // no dish prepared + recursive call for next dish
        return dp[index][time]=max(include, exclude);
    }
    int solveTab(vector<int>& satisfaction){ //tc: o(n^2) sc:o(n^2)
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        //value at dp[index][time] where index and time are both n is 0
        
        //for rest index and time ..(n-1) to 0
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + dp[index+1][time+1];
                int exclude = 0 + dp[index+1][time];
                
                dp[index][time]=max(include, exclude);
            }
        }
        
        return dp[0][0];
        
    }
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        //recursive call
        //return solve(satisfaction ,0 ,0 ); //initial dish index, initial time
        
        //dp memoization top down approach, both index and time starts from 0 and got to->n
        int n=satisfaction.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        //return solveMem(satisfaction, 0, 0, dp);
        
        //dp tabulation, bottom up approach, both index and time starts from n and go to 0
        //return solveTab(satisfaction);
        
        //space optimization:
        
        vector<int> curr(n+1, 0);
        vector<int> next(n+1, 0);
        
        for(int index=n-1; index>=0; index--){
            for(int time=index; time>=0; time--){
                int include = satisfaction[index]*(time+1) + next[time+1];
                int exclude = 0 + next[time];
                
                curr[time] = max(include, exclude);
            }
            next=curr;
        }
        
        return next[0];
    }
};
