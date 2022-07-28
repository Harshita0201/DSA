#include<bits/stdc++.h>
int f(int ind, vector<int>&heights){
    if(ind==0)
        return 0;
    
    int left = f(ind-1, heights) + abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)
        right=f(ind-2, heights) + abs(heights[ind]-heights[ind-2]);
    
    return min(left, right);
}
int f1(int ind, vector<int> heights, vector<int>&dp){
    if(ind==0)
        return 0;
    
    if(dp[ind]!=-1) 
        return dp[ind];
    
    int left = f1(ind-1, heights, dp) + abs(heights[ind]-heights[ind-1]);
    int right=INT_MAX;
    if(ind>1)
        right=f1(ind-2, heights, dp) + abs(heights[ind]-heights[ind-2]);
    
    dp[ind] = min(left, right);
    return dp[ind];
}
int frogJump(int n, vector<int> &heights)
{
    //recursive 
    //return f(n-1, heights);
    
    //dp memoization tc:o(n)+o(n) sc:o(n)
    //vector<int> dp(n+1, -1);
    //return f1(n-1, heights, dp);
    
    //tabulation tc:o(n)+o(n) sc:o(n)
    vector<int> dp(n, 0);
    //base case
    dp[0]=0;
    for(int i=1; i<n; i++){
        int fs= dp[i-1] + abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
            ss=dp[i-2] + abs(heights[i]-heights[i-2]);
        
        dp[i]=min(fs, ss);
    }
   // return dp[n-1];
    
    //space optimization
    int prev=0;
    int prev2=0;
    for(int i=1; i<n; i++){
        int fs = prev + abs(heights[i]-heights[i-1]);
        int ss=INT_MAX;
        if(i>1)
            ss= prev2 + abs(heights[i]-heights[i-2]);
        
        int curr= min(fs, ss);
        
        //move ahead
        prev2=prev;
        prev=curr;
    }
    
    return prev;
}
