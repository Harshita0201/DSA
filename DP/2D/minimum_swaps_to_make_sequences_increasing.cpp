class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2, int index, bool swapped){
        //base case 
        if(index==nums1.size()){
            return 0; //we have traversed all the elements
        }
        
        int ans=INT_MAX; //initially
        
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        
        //catch
        if(swapped){
            swap(prev1, prev2);
        }
        
        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
            ans= 0 + solve(nums1, nums2, index+1, 0); // no swap, move to next index
            
        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1 + solve(nums1, nums2, index+1, 1)); //swapped therefore add 1 and go to next indexe
        }
        
        return ans;
    }
    
     int solveMem(vector<int>& nums1, vector<int>& nums2, int index, bool swapped, vector<vector<int>>&dp){
        //base case 
        if(index==nums1.size()){
            return 0; //we have traversed all the elements
        }
        
        if(dp[index][swapped]!=-1){
             return dp[index][swapped];
        }
         
        int ans=INT_MAX; //initially
        
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];
        
        //catch
        if(swapped){
            swap(prev1, prev2);
        }
        
        //noswap
        if(nums1[index]>prev1 && nums2[index]>prev2)
            ans= 0 + solveMem(nums1, nums2, index+1, 0, dp); // no swap, move to next index
            
        //swap
        if(nums1[index]>prev2 && nums2[index]>prev1){
            ans=min(ans,1 + solveMem(nums1, nums2, index+1, 1, dp)); //swapped therefore add 1 and go to next indexe
        }
        
        return dp[index][swapped]=ans;
    }
    
    int solveTab(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        vector<vector<int>> dp(n+1, vector<int>(2, 0));
        
        for(int index=n-1; index>=1; index--){
            for(int swapped=1; swapped>=0; swapped--){
                   int ans=INT_MAX; //initially
        
                   int prev1=nums1[index-1];
                   int prev2=nums2[index-1];
                   
                   //catch
                   if(swapped){
                       swap(prev1, prev2);
                   }
                   
                   //noswap
                   if(nums1[index]>prev1 && nums2[index]>prev2)
                       ans= 0 + dp[index+1][0]; // no swap, move to next index
                       
                   //swap
                   if(nums1[index]>prev2 && nums2[index]>prev1){
                       ans=min(ans, 1 + dp[index+1][1]); //swapped therefore add 1 and go to next index
                   }
                   dp[index][swapped]=ans;
            }
        }
        
        return dp[1][0];
    }
    
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        //step 1, insert -1 in the beginning of both the arrays
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        
        //swapped depicts if we have swapped nums1[index] or nums2[index] yet
        bool swapped = 0;
        //recursive soln
        //return solve(nums1, nums2, 1, swapped); //starting from index 1
        
        //TOP DOWN MEMOIZATION DP
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));// 2 bcz swapped only takes two values either true or false
        //return solveMem(nums1, nums2, 1, swapped, dp); index from 1 to n, bool from 0 to 1
        
        //bottom up dp, tabulation
        return solveTab(nums1, nums2); //index from n to 1 and bool from 1 to 0
    }
};
