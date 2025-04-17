#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool isBipartite (vector<vector<int>>& graph) {
    int n = graph.size ();
    vector<int> level (n, -1);
    
    queue<int> lista;

    for (int inicio = 0; inicio < n; ++inicio) {
        if (level[inicio] != -1)
            continue;

        lista.push (inicio);
        level[inicio] = 0;

        while (!lista.empty ()) {
            int elemento = lista.front ();
            lista.pop ();

            for (int vizinho : graph[elemento]) {
                if (level[vizinho] != -1) {
                    if (level[vizinho] == level[elemento]) {
                        return false;
                    }
                } else {
                    level[vizinho] = level[elemento] + 1;
                    lista.push(vizinho);
                }
            }
        }
    }

    return true;
}
