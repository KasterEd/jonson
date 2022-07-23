#ifndef DIJKSTRA_HPP_
#define DIJKSTRA_HPP_

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<utility>
#include<queue>

using namespace std;

vector<vector<int>> DijkstraBin(int V, vector<pair<int,int>> adj[]){
    vector<vector<int>> list(V,vector<int>(V,INT32_MAX));
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

    for(int i=0;i<V;i++){
        int src=i;
        list[i][i]=0;
        q.push({0,src});

        while(!q.empty()){
            int node=q.top().second;
            int currlist=q.top().first;
            q.pop();
            if(list[i][node]<currlist)
                continue;
            for(auto x:adj[node]){
                int ver=x.first;
                int wt=x.second;
                if(wt+list[i][node]<list[i][ver]){
                    list[i][ver]=wt+list[i][node];
                    q.push({list[i][ver],ver});
                
                }
            } 
        }
    }
    
    return list;
}

#endif