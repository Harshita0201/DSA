#include<bits/stdc++.h>
void dfs(int node, unordered_map<int, bool> &vis, stack<int> &s, unordered_map<int, list<int>> &adj){
    //mark node as visited
    vis[node]=true;
    
    //for all the neigbours of node
    for(auto i:adj[node]){
        if(!vis[i]){//if neighbour not visited call topological sort for that neighbour
            dfs(i, vis, s, adj);
        }
    }
    //while returning call for node, push node into stack
    s.push(node); //topo sort
}

void Revdfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &transpose){
    //mark node as visited
    vis[node]=true;
    
    //for all the neighbours of node
    for(auto i:transpose[node]){
        if(!vis[i]){
            Revdfs(i, vis, transpose);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v); //directed graph
        
    }
    
    stack<int> s; //For Topological sort(TS)
    unordered_map<int, bool> vis;
    
    //step 1:
    //topological sort for all nodes of graph
    for(int i=0; i<v; i++){
        if(!vis[i]){
            dfs(i, vis, s, adj);
        }
    }
    
    //step 2:
    //transpose the matrix of edges (reverse all the edges)
    unordered_map<int, list<int>> transpose;
    for(int i=0; i<v; i++){
        vis[i]=false; //mark all nodes as false for following dfs call (as it got updated in topo sort)
        for(auto nbr: adj[i]){
            transpose[nbr].push_back(i);
        }
    }
    
    //step 3:
    //dfs on topo sort order
    int count=0;
    while(!s.empty()){
        int top=s.top();
        s.pop();
        
        if(!vis[top]){
            count++;
            Revdfs(top, vis, transpose);
        }
    }
    
    return count;
}
