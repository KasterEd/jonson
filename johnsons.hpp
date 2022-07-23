#ifndef JOHNSONS_HPP_
#define JOHNSONS_HPP_

#include <vector>
#include <stdlib.h>
#include <iostream>
#include "bellmanFord.hpp"
#include "dijkstraBinHeap.hpp"
#include "dijkstraFibHeap.hpp"

using namespace std;


void Johnson(int V,vector<pair<int,int>> adj[],int funcName){

    // 1. 添加权重为0的node
    for(int i=0;i<V;i++){
        adj[V].push_back({i,0});
    }
    // 2. 为每个V找到h(v)
    vector<int> h=BellmanFord(V,adj);
    // 3. 从adj列表中删除s（连同其边），同时删除h(V)。
    auto it= h.end()-1;
    h.erase(it); 
    adj[V].clear();
    // 4. 重新权重
    for(int u=0;u<V;u++){
      
        for(int v=0;v < adj[u].size();v++){    
            adj[u][v].second=adj[u][v].second+h[u]-h[adj[u][v].first];
        }  
   }
    // 5.Dijk算法
    if (funcName == 1){                                     // 斐波那契堆
        // 6. 最终答案(原始权重返回)
        vector<vector<int>> SP=DijkstraFib(V,adj);
        for(int u=0;u<V;u++){
        for(int v=0;v<V;v++){
            SP[u][v]=SP[u][v]+h[v]-h[u];
        }
        }
        // 7. 显示出来
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                cout<<SP[u][v]<<" ";
            }
            cout<<endl;
        }
    }else{
        // 6. 最终答案(原始权重返回)
        vector<vector<int>> SP=DijkstraBin(V,adj);          // 二叉堆
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                SP[u][v]=SP[u][v]+h[v]-h[u];
            }
        }
        // 7. 显示出来
        for(int u=0;u<V;u++){
            for(int v=0;v<V;v++){
                cout<<SP[u][v]<<" ";
            }
            cout<<endl;
        }
    }
 
    //------------//

    
}

#endif