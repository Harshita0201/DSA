#include<bits/stdc++.h>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
     //create adjacency list 
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first-1;
        int v=edges[i].second-1;
        
        //directed graph
        adj[u].push_back(v);
    }
    
    //stroe indegree of all vertexes
    vector<int> indegree(n);
    for(auto i:adj){
        for(auto j:i.second){
            indegree[j]++;
        }
    }
    
    //push all 0 indegree nodes into queue
    queue<int> q;
    for(int i=0; i<n; i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
        
    //do bfs
    int cnt=0;
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        //increase cnt
        cnt++;
        
        //for all the neighbours of front
        for(auto neighbour:adj[front]){
            indegree[neighbour]--; //reduce the indegree as its parent node is popped
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }
    
    if(cnt==n){//valid topological sort, i.e acyclic graph
        return false;
    }else{ //cycle present, no valid topological sort 
        return true;
    }
}



