class Solution{
public: 

    bool solve(int index, int arr[], int N, int target){
        //base case
        if(target<0){
            //with all positive number arr we cannot form a negative target
            return 0;
        }
        
        //we go out of bound
        if(index>=N){
            return 0;
        }
        
        //we created target
        if(target==0){
            return 1;
        }
        
        //2 cases
        bool inc = solve(index+1, arr, N, target-arr[index]); //since we included ele @index, we reduce target and go to next index
        bool exc = solve(index+1, arr, N, target); //nothing included in target, therefore target remains same and we move ahead
        
        return inc or exc;
    }
    int solveMem(int index, int arr[], int N, int target, vector<vector<int>>&dp){
        //base case
        if(target<0){
            //with all positive number arr we cannot form a negative target
            return 0;
        }
        
        //we go out of bound
        if(index>=N){
            return 0;
        }
        
        //we created target
        if(target==0){
            return 1;
        }
        
        if(dp[index][target]!=-1){
            return dp[index][target];
        }
        //2 cases
        bool inc = solveMem(index+1, arr, N, target-arr[index], dp); //since we included ele @index, we reduce target and go to next index
        bool exc = solveMem(index+1, arr, N, target, dp); //nothing included in target, therefore target remains same and we move ahead
        
        return dp[index][target]=inc or exc;
    }
    
    int solveTab(int arr[], int N, int total){
        vector<vector<int>> dp(N+1, vector<int>(total+1, 0));
        
        //base case
        for(int i=0; i<=N; i++){
            dp[i][0]=1; //when target is 0 we have created subbary equal to target hence 1
        }

        for(int index=N-1; index>=0; index--){
            for(int t=0; t<=total/2; t++){
                bool inc=0;
                if(t-arr[index]>=0){
                     inc= dp[index+1][t-arr[index]];
                }
                bool exc= dp[index+1][t-0];
                
                dp[index][t]= inc or exc;
            }
        }
        return dp[0][total/2];
    }
    
    int equalPartition(int N, int arr[])
    {
        int total=0;
        for(int i=0; i<N; i++){//find sum of all eles or total
            total=total+arr[i];
        }
        
        if(total&1){
            return 0; //if sum of all eles is odd, there is no way we can form equal subset sum
        }
        
        //else even, there is possibility 
        int target= total/2;
        // recursive solution
        //return solve(0, arr, N, target); //we find if we can form a target with arr eles starting from 0 inde
        
        //top down dp/ memoization
        // vector<vector<int>> dp(N, vector<int>(target+1, -1));
        // return solveMem(0, arr, N, target, dp);
        
        //bottom uo dp/ tabulation
        //return solveTab(arr, N, total);
        
        //space optimization
        vector<int> curr(total+1, 0);
        vector<int> next(total+1, 0);
        
        
        //base case
        curr[0]=1;
        next[0]=1;
        
        for(int index=N-1; index>=0; index--){
            for(int t=0; t<=total/2; t++){
                bool inc=0;
                if(t-arr[index]>=0){
                     inc= next[t-arr[index]];
                }
                bool exc= next[t-0];
                
                curr[t]= inc or exc;
            }
            next=curr;
        }
        return next[total/2];
        
        
    }
};
