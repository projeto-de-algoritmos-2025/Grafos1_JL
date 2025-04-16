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
        };
    
        vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
    
            Graph g(n);
    
            for (int i = 0; i < invocations.size(); i++)
                g.adj[invocations[i][0]].push_back(invocations[i][1]);
            
    
            vector<int> remainig;
            vector<bool> visited(g.V, false);
            bool flag = false; // if set => dont remove sus nodes
        
            stack<int> stack;
            stack.push(k);
        
            while (!stack.empty()){
                int s = stack.top();
                stack.pop();
        
                if (!visited[s]){
                    visited[s] = true;
                }
        
                for (auto i = g.adj[s].begin(); i != g.adj[s].end(); ++i)
                    if (!visited[*i])
                        stack.push(*i);
            }
    
            for(int i = 0; i < g.V && flag == false; i++){
                if(visited[i] == true) continue;
                for(auto j : g.adj[i]){
                    if(visited[j] == true){
                        flag = true;
                    }
                }
            }
    
            if(flag)
                for(int i = 0; i < g.V; i++) remainig.push_back(i);
            
            else{
                for(int i = 0; i < g.V; i++) if(!visited[i]) remainig.push_back(i);
            }
    
            return remainig;
        }
    };