#include<bits/stdc++.h>
void topsort(int node,unordered_map<int,vector<int>>&adjList,vector<bool>&visited,stack<int>&s){
    visited[node]=true;  //mark node as visited
    for(auto i:adjList[node]){ //for all neighbours(i) of node, if not vsited call topsort
        if(!visited[i]){
        topsort(i,adjList,visited,s);
        }
    }
    s.push(node); //berfore returning for call of node, push nod to stack
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    unordered_map<int,vector<int>>adjList;
    vector<bool>visited(v);
    stack<int>s;
    vector<int>ans;
    //create adjacency list
    for(int i=0;i<e;i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
    }
    //for all vertex/ components of graph
    for(int i=0;i<v;i++){//i=1 when nodes start form 1
        if(!visited[i]){
            topsort(i,adjList,visited,s); //toposort~dfs()
        }
    }
    //put elements of stack into ans vector
    
    while(!s.empty()){
        int onTop=s.top();
        ans.push_back(onTop);
        s.pop();
    }
    return ans;
    
    // Write your code here
}
