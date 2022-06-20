#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adjacency list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++){
        int u=g[i].first.first;
        int v=g[i].first.second;
        int w=g[i].second;
        
        //undirected graph
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1);
    vector<bool> mst(n+1);
    vector<int> parent(n+1);
    
    for(int i=0; i<=n; i++){ //initial state of vectors- key, mst, parent
        key[i]=INT_MAX;
        mst[i]=false;
        parent[i]=-1;
    }
    
    key[1]=0; //dist of src node from itself
    parent[1]=-1; //parent of src node
    
    for(int i=1; i<n; i++){
        int mini=INT_MAX;
        //find minimum value node, u in key
        int u;
        for(int j=1; j<=n; j++){//nodes from 1 to n in key n mst 
            if(mst[j]==false && key[j]<mini){
                u=j; //node
                mini=key[u]; //minimum so far
            }
        }
        
        //mark min node as true; (include in mst)
        mst[u]=true;
        
        //check its adjacent nodes of u
        for(auto it: adj[u]){
            int v=it.first;
            int w=it.second;
            //update weight in key , and add its parent as u
            if(mst[v]==false && w<key[v]){
                parent[v]=u;
                key[v]=w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>>  ans;
    for(int i=2; i<=n; i++){
        ans.push_back({{parent[i], i}, key[i]});
    }
    
    
    return ans;
    
}
    
