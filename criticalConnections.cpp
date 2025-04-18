#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
    
        class Graph {
            public:
            int V;    
            list<int> *adj; 
            Graph(int V){
                this->V = V;
                adj = new list<int>[V];
            } 
            void addEdge(int u, int v){
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        };
    
        int dfs(const Graph &g, vector<int> &rank, vector<vector<int>> &result, int node, int depth){
            
            if(rank[node] != -2) return rank[node];
                
            int min_back_depth = g.V;
            rank[node] = depth;
    
            int back_depth;
            for(auto neighbor : g.adj[node]){
    
                if(rank[neighbor] == depth - 1 || rank[neighbor] == g.V) continue;
    
                back_depth = dfs(g, rank, result, neighbor, depth+1);
    
                if (back_depth > depth)
                    result.push_back({node, neighbor});
                
                min_back_depth = min(min_back_depth, back_depth);
            }
    
            rank[node] = g.V;
            return min_back_depth;
        }
    
        vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
            Graph g(n);
            vector<int> rank(n, -2);
            vector<vector<int>> result;
    
            for(int i = 0; i < connections.size(); i++)
                g.addEdge(connections[i][0], connections[i][1]);
            
            dfs(g, rank, result, 0, 0);
    
            return result;
        }
    };