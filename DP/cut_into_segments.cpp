#include<bits/stdc++.h>
int solve(int n, int x, int y, int z){
    //base case 
    //if rod lenght is 0
    if(n==0)
        return 0; //no segments can be formed
    
    //if rod length is negative
    if(n<0)
        return INT_MIN;
    
    //3 possibilities
    int a = solve(n-x, x, y, z) + 1;
    int b = solve(n-y, x, y, z) + 1;
    int c = solve(n-z, x, y, z) + 1;
    
    int ans=max(a, max(b,c));
    return ans;
}
int solve1(int n, int x, int y, int z, vector<int>&dp){
    //base case 
    //if rod lenght is 0
    if(n==0)
        return 0; //no segments can be formed
    
    //if rod length is negative
    if(n<0)
        return INT_MIN;
    
    //do not repeat step
    if(dp[n]!=-1)
        return dp[n];
    
    
    //3 possibilities
    int a = solve1(n-x, x, y, z, dp) + 1;
    int b = solve1(n-y, x, y, z, dp) + 1;
    int c = solve1(n-z, x, y, z, dp) + 1;
    
    dp[n]=max(a, max(b,c));
    return dp[n];
}
int solve2(int n, int x, int y, int z){
    vector<int> dp(n+1, INT_MIN); 
    
    //base case
    dp[0]=0;
    
    for(int i=1; i<=n; i++){
        if(i-x >=0) //if a valid segment
            dp[i] = max(dp[i], dp[i-x]+1);
        if(i-y >=0) //if a valid segment
            dp[i] = max(dp[i], dp[i-y]+1);
        if(i-z >=0) //if a valid segment
            dp[i] = max(dp[i], dp[i-z]+1);
    }
    
    if(dp[n] < 0)
        return 0;
    return dp[n];
}
int cutSegments(int n, int x, int y, int z) {
	// recursive 
//     int ans=solve(n, x, y, z);
    
//     if(ans<0)
//         return 0;
//     else
//         return ans;
    
    //dp memoization, top down tc:o(n) sc:o(n) + o(n)
//     vector<int> dp(n+1, -1);
//     int ans=solve1(n, x, y, z, dp);
//      if(ans<0)
//         return 0;
//      else
//         return ans;
    
    //dp- tabulation tc:o(n) sc:o(n)
    return solve2(n, x, y, z);
}
