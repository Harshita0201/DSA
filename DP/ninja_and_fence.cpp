#define MOD 1000000007

int add(int a, int b){
    return (a%MOD + b%MOD)%MOD;
}
int mul(int a, int b){
    return ((a%MOD)* 1LL * (b%MOD))%MOD;
}

int solve(int n, int k){
    //base case
    if(n==1)
        return k; //k possible ways to paint a fence with 1 post
    
    if(n==2)
        return add(k, mul(k, k-1));
    
    //2 color same + 2 color diff
    int ans = add(mul(solve(n-2, k), k-1), mul(solve(n-1, k), k-1));
    return ans;
    
}
int solve1(int n, int k, vector<int>&dp){
    //base case
    if(n==1)
        return k; //k possible ways to paint a fence with 1 post
    
    if(n==2)
        return add(k, mul(k, k-1));
    if(dp[n]!=-1)
        return dp[n];
    
    //2 color same + 2 color diff
    dp[n] = add(mul(solve1(n-2, k, dp), k-1), mul(solve1(n-1, k, dp), k-1));
    return dp[n];
}

int solve3(int n, int k){
    vector<int> dp(n+1, 0);
    dp[1]=k;
    dp[2]=add(k, mul(k, k-1));
    
    for(int i=3; i<=n; i++){
        dp[i] = add(mul(dp[i-2], k-1), mul(dp[i-1], k-1)); 
    }
    return dp[n];
}
int numberOfWays(int n, int k) {
    // recursive soln
    //return solve(n, k);
    
    //memoization solution tc:o(n)  sc:o(n) +o(n)
    vector<int> dp(n+1, -1);
    return solve1(n, k, dp);
    
    //tabulation tc:o(n) sc:o(n)
    //return solve3(n, k);
    
    //space optimization tc:o(n) sc:o(1)
    int prev2=k;
    int prev1=add(k, mul(k, k-1));
    
    for(int i=3; i<=n; i++){
        int curr=add(mul(prev2, k-1), mul(prev1, k-1));
        
        //move ahead
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
}
