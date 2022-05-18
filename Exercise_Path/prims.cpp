#include <iostream>

using namespace std;
template <int V>
class Prim {
private:
    const int *matrix;
    int minCost(int weight[], int mstarr[])
    {
        int min = INT_MAX, index;
        for (int i = 0; i < V; i++) {
            if (mstarr[i] == 0 && weight[i] < min) {
                index = i;
                min = weight[i];
            }
        }
        return index;
    }
    void printTree(int parent[])
    {
        int total = 0;
        for (int i = 1; i < V; i++) {
            total += matrix[i * V + parent[i]];
            cout << i << "-->" << parent[i] << endl;
        }
        cout << "Total cost is: " << total << endl;
    }

public:
    Prim(const int *arr)
        : matrix(arr)
    {
        // copy(&arr[0][0], &arr[0][0] + V * V, &matrix[0][0]);
    }
    void algorithm()
    {
        int mstarr[V] = {0};
        int parent[V] = {0};
        int weight[V];
        for (int i = 0; i < V; i++) {
            weight[i] = INT_MAX;
        }
        weight[0] = 0;
        for (int i = 0; i < V - 1; i++) { // chon length - 1 tai vi thang cuoi da duoc may thang kia check het roi
            int v = minCost(weight, mstarr);
            mstarr[v] = 1;
            for (int j = 0; j < V; j++) {
                if (mstarr[j] == 0 && matrix[v * V + j] && matrix[v * V + j] < weight[j]) {
                    weight[j] = matrix[v * V + j];
                    parent[j] = v;
                }
            }
        }
        printTree(parent);
    }
};
int main()
{
    int graph[8][8] = {{0, 12, 5, 4, 0, 0, 0, 0},
                       {12, 0, 9, 11, 0, 0, 0, 0},
                       {5, 9, 0, 2, 2, 4, 0, 0},
                       {4, 11, 2, 0, 7, 0, 1, 0},
                       {0, 0, 2, 7, 0, 0, 3, 6},
                       {0, 0, 4, 0, 0, 0, 8, 1},
                       {0, 0, 0, 1, 3, 8, 0, 0},
                       {0, 0, 0, 0, 6, 1, 0, 0}};
    Prim<8> hello(&graph[0][0]);
    hello.algorithm();
}