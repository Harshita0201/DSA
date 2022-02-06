// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

//ans func code->

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        vector<int> a;
        
        for(int i=0; i<nums.size(); i++){
            int idx = abs(nums[i])-1;
            
            nums[idx]=-nums[idx];
            
            if(nums[idx]>0){
                a.push_back(idx+1);
            }
            
        }
        
        return a;
    }
};
