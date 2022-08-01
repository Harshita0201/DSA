int solve(vector<int> &num, int target){
    //base case
    //if target becoems less than 0
    if(target<0)
        return 0;
    
    //if target becomes 0
    if(target==0)
        return 1;
    
    int ans=0;
    for(int i=0; i<num.size(); i++){
        ans+=solve(num, target-num[i]);
    }
    return ans;
}
int solveMem(vector<int> &num, int target, vector<int>&dp){
    //base case
    //if target becoems less than 0
    if(target<0)
        return 0;
    
    //if target becomes 0
    if(target==0)
        return 1;
    
    //if dp solution already exists
    if(dp[target]!=-1)
        return dp[target];
    
    int ans=0;
    
    for(int i=0; i<num.size(); i++){
        ans+=solveMem(num, target-num[i], dp);
    }
    
    dp[target]=ans;
    return dp[target];
}
int solveTab(vector<int> &num, int tar){
    vector<int> dp(tar+1, 0);
    
    dp[0]=1;//base case
    //traversing from target= 1 to target
    for(int i=1; i<=tar; i++){
        //traversing all indexes of arr
        for(int j=0; j<num.size(); j++){
            if(i-num[j]>=0){
                  dp[i]+=dp[i-num[j]];
            }
        }
    }
    return dp[tar];
}
int findWays(vector<int> &num, int tar)
{
    // recursive 
    //return solve(num, tar);
    
    //dp memoization
    vector<int> dp(tar+1, -1);
    //return solveMem(num, tar, dp);
    return solveTab(num, tar);
}
