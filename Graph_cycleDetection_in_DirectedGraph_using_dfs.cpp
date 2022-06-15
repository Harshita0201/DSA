#include<bits/stdc++.h>
bool cycleDFS(int node, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfs_visited,   unordered_map<int, list<int>> &adjList){
    //mark visited[node] and visited_dfs[node] as true
    visited[node] = true;
    dfs_visited[node] =true;
    
    //for all the neighbours of node
    for(auto neighbour: adjList[node]){
        //is not visited, call cycleDFS
        if(!visited[neighbour]){
            bool cycle= cycleDFS(neighbour, visited, dfs_visited, adjList);
            if(cycle){
                return true;
            }
        }else if(dfs_visited[neighbour]){ //if visited[neighbour] && visited_dfs[neighbour] then cycle present
             return true;      
        }
    }
    dfs_visited[node]=0; // after returning for node, mark as unvisited
    return false;
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
  unordered_map<int, list<int>> adjList;
    //create adjacenct list
    for(int i=0; i<n; i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        //directed gragh
        adjList[u].push_back(v);
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfs_visited;
    
    //for all components/ nodes starting from 1 to n
    for(int i=1; i<=n; i++){
        if(!visited[i]){ //if node not visited call dfs func to check cycle
            bool cycle=cycleDFS(i, visited, dfs_visited, adjList); 
            if(cycle){
                return true;
            }
        }
    }
    return false;
    
}
