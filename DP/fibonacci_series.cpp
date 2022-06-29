// Nth term of Fibonacci series F(n), where F(n) is a function, is calculated using the following formula -
//     F(n) = F(n-1) + F(n-2), 
//     Where, F(1) = F(2) = 1

// Sample Input 1:
// 6
// Sample Output 1:
// 8

#include<bits/stdc++.h>
using namespace std;

//method 3: space optimization
int main(){
    int n;
    cin >> n;
    
    int prev1=1;
    int prev2=0;
    
    if(n==0){
        return prev2;
    }
    
    for(int i=2; i<=n; i++){
        int curr= prev1 + prev2;
        
        //move forward
        prev2=prev1;
        prev1=curr;
    }
    cout << prev1 << endl;
    return 0;
}//TC:O(N) SC:O(N)

//method 1: top down dp--> recursion + memoisation
// int fib(int n, vector<int> &dp){
//        //base case
//         if(n<=1){
//             return n;
//         }
//         //do not repeat step
//         if(dp[n]!=-1){
//             return dp[n];
//         }
//         //memoization
//         dp[n]=fib(n-1, dp)+fib(n-2, dp);
        
//         return dp[n];
// } //tc: O(N) sc: O(N) +O(N)
// int main()
// {     //method 2-> tabulation or bottom up DP
//         int n;
//         cin >> n;
//         vector<int> dp(n+1);
    
//         dp[0]=0;
//         dp[1]=1;
//         for(int i=2; i<=n; i++){
//             dp[i]=dp[i-1] + dp[i-2];
//         }
//        cout << dp[n] << endl;
// //         for(int i=0; i<=n; i++){
// //             dp[i]=-1;
// //         }
// //         cout << fib(n, dp) << endl;
    
//         return 0;
// }//tc:O(N)  sc:O(N) 
