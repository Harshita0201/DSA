void dfs(int node, unordered_map<int, bool> &vis, unordered_map<int, list<int>> &adjList, vector<int> &component){
    //push that node into componenet
    component.push_back(node);
    
    vis[node]=true; //mark node as visited
    
    //recursive call for every connected node to node
    for(auto i:adjList[node]){
        if(!vis[i]){
            dfs(i, vis, adjList, component);
        }
    }
}
vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    // prerpare adjList
    unordered_map<int, list<int>> adjList;
    for(int i=0; i<edges.size(); i++){
        int u=edges[i][0];
        int v=edges[i][1];
        
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    
    vector<vector<int>> ans;
    unordered_map<int, bool> vis;
    
    //call dfs on nodes which are not visited 
    for(int i=0; i<V; i++){
        if(!vis[i]){ 
            vector<int> component;
            dfs(i, vis, adjList, component);
            ans.push_back(component);
        }
    }
    return ans;
}
