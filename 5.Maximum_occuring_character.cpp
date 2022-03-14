// Given a string str. The task is to find the maximum occurring character in the string str. If more than one character occurs the maximum number of time then print the lexicographically smaller character.

// Example 1:

// Input:
// str = testsample
// Output: e
// Explanation: e is the character which
// is having the highest frequency.


// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to find the maximum occurring character in a string.
    char getMaxOccuringChar(string str)
    {
        // Your code here
        int arr[26]= {0};
        
        for(int i=0; i<str.length(); i++){
            char ch=str[i];
            int number=0; //index on arr
            //lower case
            if(ch>='a' && ch<='z'){
                number=ch-'a'; //gives the indedex of character
            }else{ //upper case
                number=ch-'A'; //gives the index of character
            } 
            
            arr[number]++; //increase the count of that character
        }
        
        int maxi=-1;
        int ans=0;
        for(int i=0; i<26; i++){
            if(maxi<arr[i]){
                ans=i;
                maxi=arr[i];
            }
        }
        char finalAns='a'+ans;
        return finalAns;
    }

};

// { Driver Code Starts.

int main()
{
   
    int t;
    cin >> t;
    while(t--)
    {
        string str;
        cin >> str;
    	Solution obj;
        cout<< obj.getMaxOccuringChar(str)<<endl;
    }
}  // } Driver Code Ends


//TC: O(n)
//SC: 26 array size there O(1) or constant space complexity.  
