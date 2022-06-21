#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, vector<int> &disc_time, vector<int> &low, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &ap, int &timer){
    //mark node as visited
    visited[node]=true;
    disc_time[node]=low[node]=timer++; 
    
    int child=0;
    
    //for all the neighbours of node
    for(auto i:adj[node]){
         if(i==parent){
                continue; //ignore
         }
         
         if(!visited[i]){ //if neighbour not visited, call dfs for neighbour
            dfs(i, node, disc_time, low, visited, adj, ap, timer);
            //after returning for neighbour update node's low
            low[node]= min(low[node], low[i]);
            
            //check AP or not 
            if(low[i] >= disc_time[node] && parent!=-1){ //node is AP
                ap[node]=1;
            }
            child++;
         }else{//neighbour already visited
            low[node]= min(low[node], disc_time[i]);     
         }
         
      } 
      
     //for source node, special case
     if( parent==-1 && child>1){
             ap[node]=1; 
    }
}


int main(){
    int n=5; //number of nodes
    int e=5; //number of edges
    
    vector<pair< int, int>> edges;
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(3,4));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));
    
    
    //adjacency list ;
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i].first;
        int v=edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer=0;
    vector<int> disc_time(n);
    vector<int> low(n);
    unordered_map<int, bool> visited;
    vector<int> ap(n, 0);
    
    for(int i=0; i<n; i++){ //initially discovery time and lowest time for every node marked as -1
        disc_time[i]=-1;
        low[i]=-1;
    }
    
    //dfs
    for(int i=0; i<n; i++){
        if(!visited[i]){//if node is not visited
            dfs(i, -1, disc_time, low, visited, adj, ap, timer); //for source node 0 the parent is -1
        }
        
    }
    
    //print all the articulation points or aps
    cout << "Articulation points are as follows : " << endl;
    for(int i=0; i<n; i++){
        if(ap[i]!=0){
            cout << i << " " ;
        }
    }cout << endl;
    
    return 0;
    
}
