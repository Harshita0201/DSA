#include<bits/stdc++.h>
void dfs(int node, int parent, int &timer, vector<int> &disc_time, vector<int> &low,  unordered_map<int, bool> &visited, vector<vector<int>> &result, unordered_map<int, list<int>> &adj ){
    //mark node as visited
    visited[node]=true;
    //in the start both the disc_time and the lowest time for a node is set to timer
    disc_time[node]=low[node]=timer++; 
 
    //for all the neighbours of node
    for(auto i: adj[node]){
        if(i==parent){
            continue; //ignore
        }
        
        if(!visited[i]){//if neighbour node is not visited
            dfs(i, node, timer, disc_time, low, visited, result, adj);
            low[node]=min(low[node], low[i]);
            //check if edge is bridge or not
            if(low[i] > disc_time[node]){
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(i);
                result.push_back(ans);
            }
            
        }
        else{
            //node already visited and back edge
            low[node]=min(low[node], disc_time[i]);
        }
    }
    
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    //adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i< edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer=0;
    vector<int> disc_time(v);
    vector<int> low(v);
    unordered_map<int, bool> visited;
    int parent=-1;// initially for node 0 parent is -1
    
    for(int i=0; i<v; i++){ //initialise disc_time and low as -1
        disc_time[i]=-1;
        low[i]=-1;
    }
    
    vector<vector<int>> result;
    
    //dfs
    for(int i=0; i<v; i++){
        if(!visited[i]){ //call dfs for not visited nodes
             dfs(i, parent, timer, disc_time, low, visited, result, adj);
        }
    }
    
    return result;
}
