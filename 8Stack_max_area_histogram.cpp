class Solution {
private: 
    vector<int> nextSmallest(vector<int> heights, int n){
        stack<int> s;
        s.push(-1); //initially
        vector<int> ans(n);
        
        
        for(int i=n-1; i>=0; i--){
            int curr=heights[i];
            while( s.top() !=-1 && heights[s.top()]>=curr ){ //s.top() is index there arr[s.top()] will give val , so to compare value of curr
                s.pop();
            }
            ans[i]=s.top();
            s.push(i); //not the element but the index
        }
        
        return ans;
    }
    
    vector<int> prevSmallest(vector<int> heights, int n){
        stack<int> s;
        s.push(-1); //initially
        vector<int> ans(n);
        
        
        for(int i=0; i<n; i++){
            int curr=heights[i];
            while( s.top()!=-1 && heights[s.top()]>=curr ){
                s.pop();
            }
            ans[i]=s.top();
            s.push(i); //not the element but the index
        }
        
        return ans;
    }
    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        
        vector<int> next(n);
        next= nextSmallest(heights, n); //stores the indexses of next smaller bar in histogram corresponding to current bar
        
        vector<int> prev(n);
        prev= prevSmallest(heights, n); //stores the indexses of next smaller bar in histogram corresponding to current bar
        
        int area=INT_MIN;
        for(int i=0; i<n; i++){
            int l=heights[i];
            
            
            if(next[i]==-1){ //all bars of same height there is no next smaller or prev smaller, place next int the end
                next[i]=n;
                
            }
            
            int b=next[i] - prev[i] -1;
            int newArea = l*b;
            area=max(area, newArea);
        }
        
        return area;
        
    }
};
