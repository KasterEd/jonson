#ifndef DIJKSTRAFIBHEAP_HPP
#define DIJKSTRAFIBHEAP_HPP
#include <vector>
#include <iostream>
#include <stdlib.h>
#include "fibonacciHeap.hpp"

using namespace std;

vector<vector<int>> DijkstraFib(int V, vector<pair<int,int>> adj[]){
    vector<vector<int>> list(V,vector<int>(V,INT32_MAX));

    for(int i=0;i<V;i++){
        int src=i;
        list[i][i]=0;
        fibonacciHeap q;
        q.insertion({0,src});

        while(!q.is_empty()){
            int node=q.get_min().second;
            int currlist=q.get_min().first;
            q.Extract_min();
            if(list[i][node]<currlist)
                continue;
            for(auto x:adj[node]){
                int ver=x.first;
                int wt=x.second;
                if(wt+list[i][node]<list[i][ver]){
                    list[i][ver]=wt+list[i][node];
                    q.insertion({list[i][ver],ver});
                
                }
            } 
        }
    }
    
    return list;
}
#endif