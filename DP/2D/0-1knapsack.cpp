int solve(vector<int> &weight, vector<int> &value, int index, int W){
    //base case
    //we reach index 0, or only 1 element left
    //if it's weight is within the 'W' capacity of thief's knapsack, include the value 
    //else return 0
    if(index==0){
        if(weight[0]<=W)
           return value[0];
        else
           return 0;
    }
   
    
    //recursive calls for combinations-> include or exclude
    int include=0;
    //if @i index the weight is within the 'W' capacity of thief's knapsack, include the value
    if(weight[index]<=W)
        include = value[index] + solve(weight, value, index-1, W-weight[index]); //value added, W reduces
    
    int exclude = 0 + solve(weight, value, index-1, W); //no value added W remains same
    
    int ans=max(include, exclude);
    return ans;
}


int solveMem(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int>>&dp){
    //base case
    //we reach index 0, or only 1 element left
    //if it's weight is within the 'W' capacity of thief's knapsack, include the value 
    //else return 0
    if(index==0){
        if(weight[0]<=W)
           return value[0];
        else
           return 0;
    }
   
    //if dp doln already exists
    if(dp[index][W]!=-1)
        return dp[index][W];
    
    //recursive calls for combinations-> include or exclude
    int include=0;
    //if @i index the weight is within the 'W' capacity of thief's knapsack, include the value
    if(weight[index]<=W)
        include = value[index] + solveMem(weight, value, index-1, W-weight[index], dp); //value added, W reduces
    
    int exclude = 0 + solveMem(weight, value, index-1, W, dp); //no value added W remains same
    
    dp[index][W]=max(include, exclude);
    return dp[index][W];
}

int solveTab(vector<int> weight, vector<int> value, int n, int Capacity){
    
    vector<vector<int>> dp(n, vector<int>(Capacity+1, 0));
    
    //base case
    for(int w=weight[0]; w<=Capacity; w++){
        if(weight[0]<=Capacity)
            dp[0][w]=value[0];
        else
            dp[0][w]=0;
    }
    
    //for rest
    for(int index=1; index<n; index++){
        for(int w=0; w<=Capacity; w++){//al possible wieghts within range
            int inc=0;
            
            if(weight[index]<=w)
                inc= value[index] + dp[index-1][w-weight[index]];
            
            int exc= 0 + dp[index-1][w];
            
            dp[index][w]=max(inc, exc);
        }
    }
    return dp[n-1][Capacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	//recursive solution
    //return solve(weight, value, n-1, maxWeight); //starting from last index
    
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1)); //initialised to -1
    //return solveMem(weight, value, n-1, maxWeight, dp);//tc:o(n)  sc:o(n)+o(n)
    
    //dp tabulation tc:o(n) sc:o(n)
    //return solveTab(weight, value, n, maxWeight);
    
    //space optimization
    vector<int> prev(maxWeight+1, 0);
    vector<int> curr(maxWeight+1, 0);
    
    //base case
    for(int w=weight[0]; w<=maxWeight; w++){
        if(weight[0]<=maxWeight)
            prev[w]=value[0];
        else
            prev[w]=0;
    }
    
    for(int index=1; index<n; index++){
        for(int w=0; w<=maxWeight; w++){//al possible wieghts within range
            int inc=0;
            
            if(weight[index]<=w)
                inc= value[index] + prev[w-weight[index]];
            
            int exc= 0 + prev[w];
            
            curr[w]=max(inc, exc);
        }
        prev=curr;
    }
    
    return prev[maxWeight];
}
