// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique, or false otherwise.

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences

//ans func()->

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        
         vector<int> occurrence;
         sort(arr.begin(),arr.end());
         int digit=0;
         for(int i=0;i<arr.size();i++)
         {
             if(arr[i]!=digit)
             {
                 int num=count(arr.begin(),arr.end(),arr[i]);
                 occurrence.push_back(num);
                 digit=arr[i];
             }
         }
  
         for(int i=0;i<occurrence.size();i++)
         {
             int n=count(occurrence.begin(),occurrence.end(),occurrence[i]);
                 if(n>1)
                 {
                     return false;
                 }
         }
         return true;
    }
};
