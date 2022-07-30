// #include<bits/stdc++.h>
// #define MOD 10000000007
// long long int solve(int n){
//     //base cases
//     if(n==1) //only one element
//         return 0;
//     if(n==2) //2 elements
//         return 1;
    
//     int ans = ( ((n-1)%MOD) * ((solve(n-1))%MOD + (solve(n-2))%MOD)%MOD);
//     return ans;
// }

    
// long long int countDerangements(int n) {
//     //recursive soln
//     //return solve(n);
// }

#define MOD 1000000007
#include <vector>
long long int solve(int n, vector<long long int>& dp){
     if(n==1)
        return 0;
    if(n==2)
        return 1;
    if(dp[n] != -1)
        return dp[n];
    
    dp[n] = ((n-1)%MOD * ((solve(n-1,dp)%MOD)+(solve(n-2,dp)%MOD))%MOD);
    return dp[n];
}

long long int solve2(int n){
    vector<long long int> dp(n+1, 0);
    
    //base cases
    dp[1]=0;
    dp[2]=1;
    
    for(int i=3; i<=n; i++){
        long long int first = dp[i-1]%MOD;
        long long int second = dp[i-2]%MOD;
        
        long long int sum= (first+second)%MOD;
        
        long long int ans = ((i-1)*sum)%MOD;
        
        dp[i]=ans;
    }
    return dp[n];
}
long long int countDerangements(int n) {
    // Write your code here.
    vector<long long int> dp(n+1,-1);
    //return solve(n,dp);
    
    //using tabulation 
    //return solve2(n);
    
    //space optimization 
    long long int prev2=0;
    long long int prev1=1;
    
    for(int i=3; i<=n; i++){
        long long int first = prev1%MOD;
        long long int second = prev2%MOD;
        long long int sum =first + second;
        long long int curr= ((i-1)*sum)%MOD;
        
        //move ahead
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
