#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <iostream>

using namespace std;

class Graph{

   public:

    int V;
    vector<pair<int,int>> *adj;  

    Graph(int num)
    {
        V=num;
        adj=new vector<pair<int,int>>[V+1];
    }

    void addEdge(int x,int y,int wt)
    {
        adj[x].push_back({y,wt});
    }

       void printGraph()
   {
    for (int v = 0; v < V; v++)
      {
          cout << "\n 顶点的邻接列表 "
               << v << "\n 头->";
          for (auto x : adj[v])
             cout <<"("<<x.first<<","<<x.second<<")";
          cout<<"\n";
      }  
   }
   ~Graph(){
    delete[] adj;
   }
};


#endif