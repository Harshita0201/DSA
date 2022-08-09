//https://leetcode.com/problems/russian-doll-envelopes/

class Solution {
public:
    static bool compare(vector<int>&a, vector<int>&b){
        if(a[0]==b[0]){
            return a[1]>b[1]; //if widhts of same size sort heights on the basis of heights
        }
        return a[0]<b[0];
    }
    int optimal_lcs(vector<int>& arr){
        int n=arr.size();
        //base case
        if(n==0){
            return 0;
        }
        vector<int> res;
        res.push_back(arr[0]); //always include first element
        for(int i=1; i<n; i++){
            if(arr[i]>res.back()){
                res.push_back(arr[i]);
            }else{
                //find the just greater element's index in res
                int index=lower_bound(res.begin(), res.end(), arr[i])- res.begin();
                //replace res[index] with arr[i]
                res[index]=arr[i];
            }
        }
        return res.size();
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), compare);
        
        //apply longest common subsequence on height, as we took care of widths
        vector<int> arr;
        for(auto i:envelopes){
            arr.push_back(i[1]);
        }
        return optimal_lcs(arr);
    }
};
//tc:o(n*logn) sc:o(n)
