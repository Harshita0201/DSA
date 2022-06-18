#include<bits/stdc++.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    // create adjacecny list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<edges; i++){
        int u=vec[i][0]; //node 1
        int v=vec[i][1]; //node 2
        int w=vec[i][2]; //distance btw node1 and node2
        
        //undirected graph
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    vector<int> distance(vertices); //DS to store distances of all nodes from source node
    //initialise distance vector to infinity (initially)
    for(int i=0; i<vertices; i++){
        distance[i]=INT_MAX;
    }
    
    set<pair<int, int>> s;
    distance[source]=0; //make distance of src node=0 (distance from itself)
    s.insert(make_pair(0, source)); // src node's dis, and src node
    
    while(!s.empty()){
        //fetch top node
        auto top=*(s.begin());
        
        int nodeDist= top.first;
        int topNode=top.second;
        
        //remove top node
        s.erase(s.begin());
        
        //for all the neighbors of top node
        for(auto neighbour:adj[topNode]){
            if(nodeDist + neighbour.second < distance[neighbour.first]){ ///neighbour.seocnd= weight, neighbour.frist=node
                
                //find record
                auto record = s.find(make_pair(distance[neighbour.first], neighbour.first));
                //if record found remove it
                if(record!=s.end()){
                    s.erase(record);
                }
                //update distance
                distance[neighbour.first]=nodeDist + neighbour.second;
                //insert into stack ->updated node's dist and node
                s.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
            
    }
    
    return distance;
    
}
