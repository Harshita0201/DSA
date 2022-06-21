#include<bits/stdc++.h>

bool cmp(vector<int>&a, vector<int> &b){
    return a[2] < b[2]; //weight lies in second index of the edges vector
}

void makeSet(vector<int> &parent, vector<int>& rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i; //every element is parent of itself, as they are individual components
        rank[i]=0;
    }
}

int findParent(vector<int> &parent, int node){
    if(parent[node]==node){
        return node;
    }
    //recursive call
    //return findParent(parent, parent[node]);
    
    return parent[node]=findParent(parent, parent[node]);//path compression
}

void unionSet(int u, int v, vector<int>&parent, vector<int> &rank){
    u=findParent(parent, u);
    v=findParent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u]=v;
    }else if(rank[v] < rank[u]){
        parent[v]=u;
    }else{
        parent[v]=u; //any node can be made parent, here we make u as parent
        rank[u]++;//update it's rank
    }
}

int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
  
    sort(edges.begin(), edges.end(), cmp); //sort the edges vector to store u, v, w in sorted order in a linear DS
    
    vector <int> parent(n);
    vector <int> rank(n);
    makeSet(parent, rank, n);
    
    int minWeight=0;
    
    for(int i=0; i<edges.size(); i++){
        int u=findParent(parent, edges[i][0]);
        int v=findParent(parent, edges[i][1]);
        int wt=edges[i][2];
        
        if(u!=v){  // if parents of both the nodes are not same, or nodes in diff componenet do->merge, union
            minWeight+=wt;
            unionSet(u, v, parent, rank);
        } //else ignore
    }
    return minWeight;
}
