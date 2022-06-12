#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph
{

public:
  //graph representation
  unordered_map < int, list < int >>adj;

  void addEdge (int u, int v, bool direction)
  {
      //direction 0->undirected  u-v =1, v-u=1
      //direction 1->directed  
      
      //create edge from u to v
      adj[u].push_back(v);
      
      if(direction==0){
          adj[v].push_back(u);
      }
  }
  
  void printAdjList(){
      for(auto i:adj){
          cout << i.first << "->";
          for(auto j:i.second){
              cout << j << " ,";
          }
          cout << endl;
      }
  }

};


main ()
{
  int n, m;
  cout << "Enter the number of nodes " << endl;
  cin >> n;
  cout << "Enter the number of  edges" << endl;
  cin >> m;

  graph g;

  for (int i = 0; i < m; i++)
    {
      int u, v;
      cin >> u >> v;
      //creating undirected graph
      //direction 0->undirected
      //direction 1->directed
      g.addEdge (u, v, 0);
    }

  //printing the Adjacency list
  g.printAdjList ();
  return 0;
}


// #include <bits/stdc++.h>
//    using namespace std;
//    int main()
//    {
//        // where n is number of vertices and m is number of edges
//        int n, u, v, m;
//        cout << "Enter the number of nodes" << endl;
//        cin>> n;
//        cout<< "Enter the number of edges" <<endl;
//        cin >> m;
//        vector< vector<int> > A(n);
//        for(int i=0; i< m; i++)
//        {
//            cin>> u>> v;
//            A[u].push_back(v);
//            A[v].push_back(u); // In case of directed graph this statement is removed. 
//        }
//        // After above loop Adjcency List is ready.
//         for(int i=0; i<n; i++)
//        {
//             cout<< i<< " ----> ";
//             for(int j=0; j<A[i].size(); j++)
//                 cout<< A[i][j]<< " -->";
//             cout <<  "\n";
//        } 
//        return 0;
//      }


// Q)You are given an undirected graph of 'N' nodes and 'M' edges. Your task is to create the graph and print the adjacency list of the graph. 
//  It is guaranteed that all the edges are unique, i.e., if there is an edge from 'X' to 'Y', then there is no edge present from 'Y' to 'X' and vice versa. Also, there are no self-loops present in the graph.


// vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
//     // Write your code here.
//     vector<int> ans[n];
    
//     for(int i=0; i<m; i++){
//         int u=edges[i][0]; //0th col for node 1 or u
//         int v=edges[i][1]; //1st col for node 2 or v
        
//         //sice undirected
//         ans[u].push_back(v);
//         ans[v].push_back(u);
//     }
    
//     vector<vector<int>> adjList(n);
    
//     for(int i=0; i<n ;i++){
//         adjList[i].push_back(i); 
        
//         //entering neighbours
//         for(int j=0; j<ans[i].size(); j++){
//             adjList[i].push_back(ans[i][j]);
//         }
//     }
    
//     return adjList;
// }
