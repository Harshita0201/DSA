#include<unordered_map>
#include<queue>
#include<list>
//#inlcude<algorithm>
void bfs(vector<int> &ans, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis, int node)
{
    queue<int> q;
    q.push(node);
    vis[node] = 1; //mark as visited
    
    while(!q.empty())
    {
        int frontnode = q.front();
        q.pop();
        
        //store frontnode in ans
        ans.push_back(frontnode);
        
        //traverse all adjacent nodes
        for(auto i: adj[frontnode])
        {
            if(!vis[i])
            {
                q.push(i);// push all adjacent nodes into ans
                vis[i] = 1; //mark as visited
            }
        }
    }
    
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int> ans;
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> vis;
    
    //Adjacency list creation
    for(int i=0; i<edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    for(int i = 0; i < vertex; i++)
           adj[i].sort(); //as ans requied in sorted way (complementry step)
    
    //for all the components of graph
    for(int i=0; i<vertex; i++)
    {
        if(!vis[i])
        {
            bfs(ans, adj, vis, i);
        }
    }
    
    return ans;
}
