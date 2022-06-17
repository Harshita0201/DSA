#include<bits/stdc++.h>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	// create adjacency list
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
    // undirected graph
        adj[u].push_back(v); 
        adj[v].push_back(u);
    }
    
    //do bfs to create parent array
    unordered_map<int, bool>visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);//push source node
    visited[s]=true; //mark src node as visited
    parent[s]=-1; //make parent of source node as -1
    
    while(!q.empty()){
        int front=q.front();
        q.pop();
        
        for(auto i:adj[front]){ //for all the neighbours of front
            if(!visited[i]){
                visited[i]=true;
                parent[i]=front;
                q.push(i);
            }
        }
    }
    
    //prepare shorted path
    vector<int> ans;
    int currentNode=t; //back track from dest to src
    ans.push_back(t);
    while(currentNode!=s){
        //update current node
        currentNode=parent[currentNode];
        ans.push_back(currentNode);
    }
    reverse(ans.begin(), ans.end());
	return ans;
}
