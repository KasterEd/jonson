#ifndef BELLMANFORD_HPP_
#define BELLMANFORD_HPP_

#include <vector>
#include <stdlib.h>
#include <iostream>

using namespace std;

vector<int> BellmanFord(int V,vector<pair<int,int>> adj[])
{
    vector<int> list(V+1,INT32_MAX);
    list[V]=0;

    for(int i=0;i<V;i++)
    {
        for(int u=V;u>=0;u--)
        {
            for(auto x:adj[u])
            {
                int v=x.first;
                int wt=x.second;

                if(list[u]!=INT32_MAX && list[u]+wt<list[v])
                list[v]=list[u]+wt;
            }
        }
    }

   for(int u=V;u>=0;u--)
   {
       for(auto x:adj[u])
            {
                int v=x.first;
                int wt=x.second;

                if(list[u]!=INT32_MAX && list[u]+wt<list[v])
                {
                    cout<<"负循环";
                    exit(1);
                }
            }
   }
    return list;
}

#endif