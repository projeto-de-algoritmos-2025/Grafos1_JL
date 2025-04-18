#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        class Graph {
            public:
            int V;    
            list<int> *adj; 
            Graph(int V) {
                this->V = V;
                adj = new list<int>[V];
            }
        };
    
        vector<int> topologicalOrder(const list<int> *adj, int V){
    
            vector<int> incomingEdges(V,0), canditades, order(V,0);
            int node, pos = 0;
    
            for(int i = 0; i < V; i++){
                for(auto &node : adj[i]){
                    incomingEdges[node]++;
                }
            }
            for(int i = 0; i < V; i++) if(incomingEdges[i] == 0) canditades.push_back(i);
    
            if(canditades.empty()) return {};
    
            while(!canditades.empty()){
                node = canditades.back();
                canditades.pop_back();
                order[node] = pos++;
    
                for(auto& a: adj[node]){
    
                    incomingEdges[a]--;
                    if(incomingEdges[a] == 0) canditades.push_back(a);
                }
            }
            if(pos != V) return {};
            cout << endl;
            return order;
        }
    
        vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
            vector<vector<int>> result(k, vector<int>(k, 0));
    
            Graph rowGraph(k);
            Graph collumGraph(k);
    
            for(int i = 0; i < rowConditions.size(); i++){
                rowGraph.adj[rowConditions[i][0]-1].push_back(rowConditions[i][1]-1);
            }
            for(int i = 0; i < colConditions.size(); i++){
                collumGraph.adj[colConditions[i][0]-1].push_back(colConditions[i][1]-1);
            }
    
            vector<int> rowOrder = topologicalOrder(rowGraph.adj, rowGraph.V);
            if(rowOrder.empty()) return {};
    
            vector<int> collumOrder = topologicalOrder(collumGraph.adj, collumGraph.V);
            if(collumOrder.empty()) return {};
            
    
            for(int i = 0; i < k; i++){
                result[rowOrder[i]][collumOrder[i]] = i+1;
            }
    
            return result;
        }
    };