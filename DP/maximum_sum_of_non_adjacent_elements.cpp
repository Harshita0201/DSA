int solve(vector<int> &nums, int ind){
    if(ind<0){ //no element left 
        return 0;
    }
    
    if(ind==0){//reached 0 index element or one element
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
int maximumNonAdjacentSum(vector<int> &nums){
    int n = nums.size();
    //recursive soln 
    //int ans = solve(nums, n-1); //starting from the end
    //return ans;
    
    //dp soln
    vector<int> dp(n, -1); //initially -1
    return solve2(nums, n-1, dp);
}
