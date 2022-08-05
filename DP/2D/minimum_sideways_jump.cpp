class Solution {
public:
    int solve(vector<int>& obstacles, int currLane, int currPos){
        int n= obstacles.size()-1;
        
        //base case
        if(currPos == n){
            //reached target
            return 0;
        }
        
        if(obstacles[currPos+1]!=currLane){//no obstacle
            //move forward 
            return solve(obstacles, currLane, currPos+1); //remain in same lane and move to next pos
        }else{
            //side ways jump
            int ans=INT_MAX;
            for(int i=1; i<=3; i++){//for all lanes
                if(currLane!=i && obstacles[currPos]!=i){//condition: not in same lane and no obstacle
                    ans=min(ans, 1 + solve(obstacles, i, currPos)); //+1 for sideways jump
                }
            }
            return ans;
        }
    }
    
    int solveMem(vector<int>& obstacles, int currLane, int currPos, vector<vector<int>> &dp){
        int n= obstacles.size()-1;
        
        //base case
        if(currPos == n){
            //reached target
            return 0;
        }
        
        if(dp[currLane][currPos]!=-1){
            return dp[currLane][currPos];
        }
        
        if(obstacles[currPos+1]!=currLane){//no obstacle
            //move forward 
            return solveMem(obstacles, currLane, currPos+1, dp); //remain in same lane and move to next pos
        }else{
            //side ways jump
            int ans=INT_MAX;
            for(int i=1; i<=3; i++){//for all lanes
                if(currLane!=i && obstacles[currPos]!=i){//condition: not in same lane and no obstacle
                    ans=min(ans, 1 + solveMem(obstacles, i, currPos, dp)); //+1 for sideways jump
                    
                }
            }
            dp[currLane][currPos]=ans;
            return dp[currLane][currPos];
        }
    }
    
    int solveTab(vector<int>& obstacles){
        int n=obstacles.size()-1;
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        
        //base cases in bottom up 
        dp[0][n]=0;
        dp[1][n]=0;
        dp[2][n]=0;
        dp[3][n]=0; 
        
        for(int currPos=n-1; currPos>=0; currPos--){
            for(int currLane=1; currLane<=3; currLane++){
                
                if(obstacles[currPos+1]!=currLane){//no obstacle
                    //move forward 
                    dp[currLane][currPos]= dp[currLane][currPos+1]; //remain in same lane and move to next pos
                }else{
                    //side ways jump
                    int ans=1e9;
                    for(int i=1; i<=3; i++){//for all lanes
                        if(currLane!=i && obstacles[currPos]!=i){//condition: not in same lane and no obstacle
                            ans=min(ans, 1 + dp[i][currPos+1]); //+1 for sideways jump
                        }
                    }
                    dp[currLane][currPos]=ans;
                }
            }
        }
        return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
    }

    int minSideJumps(vector<int>& obstacles) {
        //recursive soln
        //return solve(obstacles, 2, 0); //currlan-2, currpos-0
        
        //dp memoization top down 
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        //return solveMem(obstacles, 2, 0 ,dp);
        
        //dp tabulation bottom up
        //return solveTab(obstacles);
        
        //space optimization 
        int n=obstacles.size()-1;
        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);
         
        //base cases 
        next[0]=0;
        next[1]=0;
        next[2]=0;
        next[3]=0; 
        
        for(int currPos=n-1; currPos>=0; currPos--){
            for(int currLane=1; currLane<=3; currLane++){
                
                if(obstacles[currPos+1]!=currLane){//no obstacle
                    //move forward 
                    curr[currLane]= next[currLane]; //remain in same lane and move to next pos
                }else{
                    //side ways jump
                    int ans=1e9;
                    for(int i=1; i<=3; i++){//for all lanes
                        if(currLane!=i && obstacles[currPos]!=i){//condition: not in same lane and no obstacle
                            ans=min(ans, 1 + next[i]); //+1 for sideways jump
                        }
                    }
                    curr[currLane]=ans;
                }
            }
            next=curr;
        }
        return min(next[2], min(1+next[1], 1+next[3]));
        
        
    }
};
