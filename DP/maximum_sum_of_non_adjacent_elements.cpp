//https://www.codingninjas.com/codestudio/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTab=0&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar

int solve(vector<int> &nums, int ind){
    if(ind<0){
        return 0;
    }
    
    if(ind==0){//reached 0 index element
        return nums[0]; 
    }
    
    //2 cases 
    int inc=solve(nums, ind-2) + nums[ind]; //add that ele to sum and mve next to adjacent ele
    int exc=solve(nums, ind-1) + 0; //do not add ele move to next
    
    return max(inc, exc);
}
int solve2(vector<int> &nums, int ind, vector<int> &dp){
    if(ind<0){
        return 0;
    }
    
    if(ind==0){//reached 0 index element
        return nums[0]; 
    }
    
    //if and in dp already exists
    if(dp[ind]!=-1){
        return dp[ind];
    }
    
    //2 cases 
    int inc=solve2(nums, ind-2, dp) + nums[ind]; //add that ele to sum and mve next to adjacent ele
    int exc=solve2(nums, ind-1, dp) + 0; //do not add ele move to next
    dp[ind]=max(inc, exc);
    return dp[ind];
}

int solve3(vector<int> &nums){
    int n=nums.size();
    vector<int> dp(n, 0);
    
    //bottom up
    //base case
    dp[0]=nums[0];
    
    //for rest
    for(int i=1; i<n; i++){
        int inc= nums[i] + dp[i-2];
        int exc= 0 + dp[i-1];
        dp[i]= max(inc, exc);
    }
    return dp[n-1];
}
int solve4(vector<int> &nums){
    int n=nums.size();
    
    int prev2=0;
    int prev1=nums[0];
    
    for(int i=1; i<n; i++){
        int inc= nums[i] + prev2;
        int exc= 0 + prev1;
        int ans=max(prev1, prev2);
        
        //move ahead
        prev2 = prev1;
        prev1 = ans; 
    }
    
    return prev1;
}
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //recursive soln 
    //int ans = solve(nums, n-1); //starting from the end
    //return ans;
    
    //dp soln memoization tc:o(n) +o(n) sc:o(n)
    vector<int> dp(n, -1); //initially -1
    //return solve2(nums, n-1, dp);
    
    //dp tabulation tc:o(n) sc:o(n)
    return solve3(nums);
    
    //space optimized tc:o(n) sc:o(1)
    return solve4(nums);
}
