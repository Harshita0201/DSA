class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int index){
        //base case: when we have covered all days
        if(index>=n){
            return 0;
        }
        
        //1 day pass
        int op1= costs[0] + solve(n, days, costs, index+1);
        
        //7 day pass
        //include all next 7 days
        int i;
        for(i=index; i<n && days[i]<days[index]+7; i++);
        int op2 = costs[1] + solve(n, days, costs, i);
        
        //30 day pass
        //include all next 30 days
        for(i =index; i<n && days[i]<days[index]+30; i++);
        int op3=costs[2] + solve(n, days, costs, i);
        
        return min(op1, min(op2, op3));
        
    }//tc:eponential sc:o(n) {recursive stack call}
    
    int solveMem(int n, vector<int>& days, vector<int>& costs, int index, vector<int> &dp){
        //base case: when we have covered all days
        if(index>=n){
            return 0;
        }
        //if dp soln already exists
        if(dp[index]!=-1){
            return dp[index];
        }
        
        //1 day pass
        int op1= costs[0] + solveMem(n, days, costs, index+1, dp);
        
        //7 day pass
        //include all next 7 days
        int i;
        for(i=index; i<n && days[i]<days[index]+7; i++);
        int op2 = costs[1] + solveMem(n, days, costs, i, dp);
        
        //30 day pass
        //include all next 30 days
        for(i =index; i<n && days[i]<days[index]+30; i++);
        int op3=costs[2] + solveMem(n, days, costs, i, dp);
        
        dp[index]= min(op1, min(op2, op3));
        return dp[index];
        
    }//tc: o(n) bcz dp[index] can have 1 to 365 possible solutions
    //sc:o(n)+o(n)
    
    int solveTab(int n, vector<int>& days, vector<int>& costs){
        vector<int> dp(n+1, INT_MAX);
        //base case
        dp[n]=0;
        
        //for rest of indexes
        for(int k=n-1; k>=0; k--){
            //1 day pass
            int op1= costs[0] + dp[k+1];
            
            //7 day pass
            //include all next 7 days
            int i;
            for(i=k; i<n && days[i]<days[k]+7; i++);
            int op2 = costs[1] + dp[i];
            
            //30 day pass
            //include all next 30 days
            for(i =k; i<n && days[i]<days[k]+30; i++);
            int op3=costs[2] + dp[i];
            
            dp[k]= min(op1, min(op2, op3));
        }
        
        return dp[0];
    }//tc:o(n) sc:o(n)
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        //recursive method
        //return solve(n, days, costs, 0); //passing 0 index
        
        //memoization top down, starting from 0 to n
        vector<int> dp(n+1, -1);
        //return solveMem(n, days, costs, 0, dp);
        
        //tabulation bottom up, starting from n to 0
        //return solveTab(n, days, costs);
        
        //space optimization 
        int ans=0;
        queue<pair<int, int>> month;
        queue<pair<int, int>> week; 
        //first int -> day second int-> cost till that day
        
        
        //traverse all days
        for(int day:days){
            //step 1: remove all expired days
            while(!month.empty() && month.front().first+30<=day){
                month.pop();
            }
            while(!week.empty() && week.front().first+7<=day){
                week.pop();
            }
            
            //step 2: add cost of current day 
            week.push({day, ans+costs[1]});
            month.push({day, ans+costs[2]});
            
            //step 3: update ans
            ans=min(ans+costs[0], min(week.front().second, month.front().second));
        }
        
        return ans;
    }
};
