#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    int V;    
    list<int> *adj; 
    Graph(int V);  
    void addEdge(int v, int w); 
    void displayGraph(); 
};

Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); 
}

void Graph::displayGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "Vertex " << v << ":";
        for (auto x : adj[v])
            cout << " -> " << x;
        cout << endl;
    }
}

void DFS_i(int s, list<int> *adj, int V){

    vector<bool> visited(V, false);
 
    stack<int> stack;
    stack.push(s);
 
    while (!stack.empty()){
        int s = stack.top();
        stack.pop();
 
        if (!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }
 
        for (auto i = adj[s].begin(); i != adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }
}

vector<int> remainingMethods(int n, int k, Graph g) {

    vector<int> remainig;
    vector<bool> visited(g.V, false);
    bool flag = false;
 
    stack<int> stack;
    stack.push(k);
 
    while (!stack.empty()){
        int s = stack.top();
        stack.pop();
 
        if (!visited[s]){
            cout << s << " ";
            visited[s] = true;
        }
 
        for (auto i = g.adj[s].begin(); i != g.adj[s].end(); ++i)
            if (!visited[*i])
                stack.push(*i);
    }

    for(int i = 0; i < g.V && flag == 0; i++){
        if(visited[i] == true) break;
        for(auto j : g.adj[i]){
            if(visited[j] == true){
                flag = true;
            }
        }
    }

    if(!flag){
        for(int i = 0; i < g.V; i++)
            if(visited[i] == false)remainig.push_back(i);
        
    }
    else{
        for(int i = 0; i < g.V; i++)
            remainig.push_back(i);
    }

    return remainig;
}

int main(){

    int n, k, source, dest;
    vector<int> d;

    cin >> n >> k;

    Graph g(n);
    for(int i = 0; i < 3; i++){
        cin >> source >> dest;
        g.addEdge(source, dest);
    }

    d = remainingMethods(n, k, g);

    for (auto i = d.begin(); i != d.end(); i++) cout << d[*i] << " ";
    cout << endl;

    return 0;
}