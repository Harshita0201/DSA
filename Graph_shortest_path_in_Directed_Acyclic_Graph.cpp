#include <bits/stdc++.h>
using namespace std;

class graph{
    
    public:
       //creating graoh using adjacency list
       unordered_map<int, list<pair<int, int>>> adj;
       void addEdge(int u, int v, int weight){
           pair<int, int> p=make_pair(v,weight);
           adj[u].push_back(p);
       }
       
       void printAdj(){
           for(auto i:adj){
               cout << i.first << " -> ";
               for(auto j:i.second){
                   cout << "(" << j.first << "," << j.second << "),";
               }cout << endl;
           }
       }
       
       void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s){
           //mark node as visited
           visited[node]=true;
           
           //for all the neighbouring nodes of node
           for(auto neighbour : adj[node]){
               if(!visited[neighbour.first]){ //since neighbour is a pair of vertex and weight, we need vertex only
                   dfs(neighbour.first, visited, s);
               }
           }//normal dfs
           
           s.push(node); //before retuning from call for node, push into stack->topologicalorder
       }
       
       void getShortestPath(int src, vector<int> &distance, stack<int> &s){
           distance[src]=0; //dist of src node from itself
    
           while(!s.empty()){
               int top=s.top();
               s.pop();
               
               if(distance[top]!=INT_MAX){//IF distance Of node is not infinity
                   //get all adjancent nodes to src node
                   for(auto i:adj[top]){
                       if(distance[top]+ i.second < distance[i.first]){ //i.first- node, i.second=weight
                           distance[i.first]=distance[top]+i.second; //update distance
                       }
                   }
               }
           }
    
       }
};

int main()
{
    graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    
    g.printAdj();
    int n=6; //number of nodes
    //topological short
    
    unordered_map<int, bool> visited;
    stack<int> s;
    
    for(int i=0; i<n; i++){
        if(!visited[i]){ ///call dfs() if node not visited
            g.dfs(i, visited, s);
        }
    }
    
    int src=1; //source node is 1  
    vector<int> distance(n); //a DS that stores shortest distance of every node from source node
    
    for(int i=0; i<n; i++){
        distance[i]=INT_MAX; //initially all the distances are marked as infinity
    }
    
    g.getShortestPath(src, distance, s);
    
    cout << "Answer is:" << endl;
    
    for(int i=0; i<distance.size(); i++){
        cout << distance[i] << " ";
    }cout << endl;
    
    return 0;
}
