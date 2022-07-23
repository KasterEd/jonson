#include<iostream>
#include<vector>
#include<stdlib.h>
#include<stdio.h>
#include<utility>
#include<queue>
#include <chrono> 

#include "graph.hpp"
#include "johnsons.hpp"

using namespace std;

void Johnson(int,vector<pair<int,int>>[]);
vector<int> BellmanFord(int,vector<pair<int,int>>[]);
vector<vector<int>> Dijkstra(int,vector<pair<int,int>>[]);




int main(){

  Graph g(9);

  g.addEdge(0,1,4);
  g.addEdge(1,0,4);
  g.addEdge(0,7,8);
  g.addEdge(7,0,8);
  g.addEdge(1,7,11);
  g.addEdge(7,1,11);
  g.addEdge(1,2,8);
  g.addEdge(2,1,8);
  g.addEdge(7,6,1);
  g.addEdge(6,7,1);
  g.addEdge(7,8,7);
  g.addEdge(8,7,7);
  g.addEdge(2,8,2);
  g.addEdge(8,2,2);
  g.addEdge(8,6,6);
  g.addEdge(6,8,6);
  g.addEdge(2,3,7);
  g.addEdge(3,2,7);
  g.addEdge(6,5,2);
  g.addEdge(5,6,2);
  g.addEdge(2,5,4);
  g.addEdge(5,2,4);
  g.addEdge(3,5,14);
  g.addEdge(5,3,14);
  g.addEdge(3,4,9);
  g.addEdge(4,3,9);
  g.addEdge(5,4,10);
  g.addEdge(4,5,10);

  auto startBin = std::chrono::high_resolution_clock::now();	

  Johnson(g.V,g.adj,0);           //dijkstra with binary heap

  auto stopBin = std::chrono::high_resolution_clock::now();
	auto durationBin = std::chrono::duration_cast<std::chrono::microseconds>(stopBin - startBin);

	cout << "\nTime taken by dijkstra with binary heap: "<< durationBin.count() << " microseconds" << "\n\n";

  auto startFib = std::chrono::high_resolution_clock::now();

  Johnson(g.V,g.adj,1);           //dijkstra with fibonacci heap
  
  auto stopFib = std::chrono::high_resolution_clock::now();
	auto durationFib = std::chrono::duration_cast<std::chrono::microseconds>(stopFib - startFib);

	cout << "\nTime taken by dijkstra with fibonacci heap: "<< durationFib.count() << " microseconds" << "\n\n";
  return 1;
}

