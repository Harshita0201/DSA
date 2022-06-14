bool isCyclicDFS(int node, int parent, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj){
    visited[node]=true; //mark node as visited
    
    for(auto neighbour:adj[node]){ //for all the neighbours of current node
        if(!visited[neighbour]){//if neighbour not visisted
            //recursive dfs call
           bool cycle= isCyclicDFS(neighbour, node, visited, adj);
            if(cycle){
                return true;
            }
        }else if(neighbour!=parent){
            //cycle present 
            return true;
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
            bool ans= isCyclicDFS(i, -1, visited, adj); //passing current node and parent, visisted, adj
            if(ans==1){
                return "Yes";
            }
        }
    }
    return "No";
}
