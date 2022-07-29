long long int solve(vector<int>&nums, int ind){
    //base case
    if(ind<0)
        return 0;
    
    if(ind==0)
        return nums[0];
    
    //2 cases
    long long int inc = nums[ind]  + solve(nums, ind-2);
    long long int exc = 0 + solve(nums, ind-1);
    
    return max(inc, exc);
}


long long int solve2(vector<int>&nums, int ind, vector<long long int> &dp){
    //base case
    if(ind<0)
        return 0;
    
    if(ind==0)
        return nums[0];
    
    if(dp[ind]!=-1)
        return dp[ind];
    
    //2 cases
    long long int inc = nums[ind]  + solve2(nums, ind-2, dp);
    long long int exc = 0 + solve2(nums, ind-1, dp);
    
    dp[ind] =  max(inc, exc);
    return dp[ind];
}

long long int solve3(vector<int>& nums){
    
    int n=nums.size();
    vector<long long int> dp(n, 0);
    
    //base case
    dp[0]=nums[0];
    
    //for rest
    for(int i=1; i<n; i++){
        long long int inc = nums[i] + dp[i-2];
        long long int exc= 0 + dp[i];
        dp[i] = max(inc, exc);
    }
    
    return dp[n-1];
}
long long int solve4(vector<int>& valueInHouse){
    int n=valueInHouse.size();
    
    long long int prev2= 0; 
    long long int prev1=valueInHouse[0];
    
    for(int i=1; i<n; i++){
        long long int inc = prev2 + valueInHouse[i];
        long long int exc = prev1 + 0;
        
        long long int ans = max(inc, exc);
        prev2=prev1;
        prev1=ans;
    }
    return prev1;
    
}
long long int houseRobber(vector<int>& valueInHouse)
{
     int n=valueInHouse.size();
    
    //base case
    if(n==1) //only one house
        return valueInHouse[0];
    
    vector<int> first, second;
    //first-> contains 0 to n-2 elements including first ind but not last of valueInHouse
    //second-> contains 1 to n-1 elements including last ind but not first of valueInHouse
    for(int i=0; i<n; i++){
        if(i!=n-1){
            first.push_back(valueInHouse[i]);
        }
        if(i!=0){
           second.push_back(valueInHouse[i]); 
        }
    }
    int f=first.size();
    int s=second.size();
    
    //recursive soln
    //return max(solve(first, f-1), solve(second, s-1));
    
    //dp memoization soln
    //f ans s are equal 
    vector<long long int> dp(f+1, -1);
    //return max(solve2(first, f-1, dp), solve2(second, s-1, dp)); 
    
    //tabulation method WRONG
    //return max(solve3(first), solve3(second));
    
    //space optimization //tc: o(n) sc:o(n)---
    return max(solve4(first), solve4(second));
    
}


