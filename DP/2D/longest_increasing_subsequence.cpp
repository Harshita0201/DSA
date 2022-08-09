//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int solve(int n, int a[], int curr, int prev){
        //base case
        //we have traversed all the elements or reached the end
        if(curr==n){
            return 0;
        }
        
        //2 cases
        int include=0;
        //conditional include
        if(prev==-1 || a[curr]>a[prev]){ //if it is the first element or current index ele is greater than prev index ele
            include = 1 + solve(n, a, curr+1, curr); //inlcude in lenght, move ahead
        }
        
        int exclude= 0 + solve(n, a, curr+1, prev); //since ele not included no lenght increase and move ahead but prev remains same
        
        return max(include, exclude);
        
    }
    
    int solveMem(int n, int a[], int curr, int prev, vector<vector<int>>& dp){
        //base case
        //we have traversed all the elements or reached the end
        if(curr==n){
            return 0;
        }
        //if dp soln already exisits
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        
        //2 cases
        int include=0;
        //conditional include
        if(prev==-1 || a[curr]>a[prev]){ //if it is the first element or current index ele is greater than prev index ele
            include = 1 + solveMem(n, a, curr+1, curr, dp); //inlcude in lenght, move ahead
        }
        
        int exclude= 0 + solveMem(n, a, curr+1, prev, dp); //since ele not included no lenght increase and move ahead but prev remains same
        
        return dp[curr][prev+1]=max(include, exclude);
        
    }
    int solveTab(int n, int a[]){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); 
        
        //bottom up:->from n to 0
        for(int curr=n-1; curr>=0; curr--){
            for(int prev=curr-1; prev>=-1; prev--){
                int include=0;
                if(prev==-1 || a[curr]>a[prev]){
                    include = 1 + dp[curr+1][curr+1];
                }
                int exclude= 0 + dp[curr+1][prev+1];
                dp[curr][prev+1]=max(include, exclude);
            }
        }
        return dp[0][0]; //prev=-1 and we return prev+1 as -1 does not exists
    }
    
    int optimal(int n, int a[]){
        if(n==0){
            return 0; //for array lenght of 0 there is no subsequence present
        }
        
        vector<int> ans;
        ans.push_back(a[0]); //always include first element
        for(int i=1; i<n; i++){
            if(a[i]>ans.back()){
                ans.push_back(a[i]);
            }else{
                //find index of just greater element in ans vector
                int index=lower_bound(ans.begin(), ans.end(), a[i]) -ans.begin();
                //replace ans[index] with a[i]
                ans[index]=a[i];
            }
        }
        return ans.size();
        
    }
    int longestSubsequence(int n, int a[])
    {
        //recursive appproach 
       //return solve(n, a, 0, -1); //initially current index is at 0 and prev index is at -1
       
       //dp top down/ memoization tc:o(n^2) sc:o(n^2) + o(n)
       //vector<vector<int>> dp(n, vector<int>(n+1, -1));
       //since curr goes from 0 to n-1 therefore: n
       //since prev goes from -1 to n-1 therefore: n+1
       //return solveMem(n, a, 0, -1, dp);
       
       //recursion bottom up: tabulation tc:o(n^2) sc:o(n^2)
       //return solveTab(n, a);
       
       //space optimized solution //tc:o(n^2)   sc:o(n)
       //vector<int> currRow(n+1, 0);
       //vector<int> nextRow(n+1, 0);
       
    //   for(int curr=n-1; curr>=0; curr--){
    //       for(int prev=curr-1; prev>=-1; prev--){
    //           int include=0;
    //           if(prev==-1 || a[curr]>a[prev]){
    //               include= 1 + nextRow[curr+1];
    //           }
    //           int exclude= 0 + nextRow[prev+1];
               
    //           currRow[prev+1]=max(include, exclude);
    //       }
    //       //mpve ahead
    //       nextRow=currRow;
    //   }
    
       //return nextRow[0];
       
       
       //optimal soln: tc:o(nlogn) sc:o(n)
       return optimal(n, a);
    
     }
     
     
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends
