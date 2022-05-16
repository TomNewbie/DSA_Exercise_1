#include <bits/stdc++.h>
using namespace std;
const int V = 8;
int MinPriorityQueue (int key[], bool Q[]){
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++){
        if (Q[v] == false && key[v] < min)
            min = key[v], min_index = v;
    }
    return min_index;
}

void print(int parent [], int graph[V][V]){
    cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++){
         cout << parent [i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
    }
}

void primMST (int graph[V][V]){
    int parent[V];
    int key[V];
    bool Q[V];
    for (int i = 0; i < V; i++) {key[i] = INT_MAX, Q[i] = false;}
    key[0] = 0;
    parent[0] = -1;
    for (int i = 0; i < V - 1; i++){
        int u = MinPriorityQueue (key, Q);
        Q[u] = true;
        for (int v = 0; v < V; v++){
            if (graph[u][v] && Q[v] == false && graph[u][v] < key[v])
            parent[v] = u, key[v] = graph[u][v];
        }
    }
    print (parent, graph);
}

int main()
{
    int graph[V][V] = { {0, 12, 5, 4, 0, 0, 0, 0},
                        {12, 0, 9, 11, 0, 0, 0, 0},
                        {5, 9, 0, 2, 2, 4, 0, 0},
                        {4, 11, 2, 0, 7, 0, 1, 0},
                        {0, 0, 2, 7, 0, 0, 3, 6},
                        {0, 0, 4, 0, 0, 0, 8, 1},
                        {0, 0, 0, 1, 3, 8, 0, 0},
                        {0, 0, 0, 0, 6, 1, 0, 0} };
    primMST (graph);
    return 0;
}
