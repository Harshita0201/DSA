//https://leetcode.com/problems/maximum-height-by-stacking-cuboids/

class Solution {
public:
    bool check(vector<int> &base, vector<int> &newBox){
        if(newBox[0]<=base[0] && newBox[1]<=base[1] && newBox[2]<=base[2]){//w, l, h of new box should be respectively smaller than w, l, h of base or prev box
            return true;
        }else{
            return false;
        }
    }
    int solve(int n, vector<vector<int>>& a){
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); 
        
         vector<int> currRow(n+1, 0);
         vector<int> nextRow(n+1, 0);
       
         for(int curr=n-1; curr>=0; curr--){
             for(int prev=curr-1; prev>=-1; prev--){
                 int include=0;
                 if(prev==-1 || check(a[curr],a[prev])){
                     include= a[curr][2] + nextRow[curr+1]; //include height
                 }
                 int exclude= 0 + nextRow[prev+1];
                  
                 currRow[prev+1]=max(include, exclude);
             }
             //mpve ahead
             nextRow=currRow;
         }
        return nextRow[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        //step 1 : sort all dimenions of every cuboid
        for(auto &i:cuboids){
            sort(i.begin(), i.end());
        }
        
        //step 2: sort all cuboids on the basis of their width
        sort(cuboids.begin(), cuboids.end());
        
        //step 3:use LIS logic
        return solve(cuboids.size(), cuboids);
        
    }
};
