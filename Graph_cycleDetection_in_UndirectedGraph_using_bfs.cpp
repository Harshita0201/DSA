#include<unordered_map>
#include<queue>
#include<list>
bool isCyclicBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj ){
    unordered_map<int, int> parent;
    
    parent[src]=-1; //parent of source node is -1
    visited[src]=1; //mark source node as visisted
    queue<int> q;
    q.push(src); //push the source node into queue
    
    while(!q.empty()){
        int front=q.front(); //get the front node
        q.pop();//pop it out of queue
        
        for(auto neighbour:adj[front]){ //for all the neighbours of current front node
            if(visited[neighbour]==true && neighbour!=parent[front]){
                return true; // cycle present
            }else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour]=1; //mark as visited
                parent[neighbour]=front;// add to parent list
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    //prepare adjacency list
    for(int i=0; i<m; i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    unordered_map<int, bool> visited;
    //to handle disconnected components
    for(int i=0; i<n; i++){
        //if not visited
        if(!visited[i]){
            bool ans= isCyclicBFS(i, visited, adj);
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}
