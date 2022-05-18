#include <iostream>
#include <vector>

using namespace std;
/*
    Note that this algorithm is always work well if distance is positive
    It will depend if the distance is not positive
*/
template <int V>
class Dijkstra {
private:
    const int *matrix;
    int minDistance(int weight[], int hasRun[])
    {
        int min = INT_MAX, index;
        for (int i = 0; i < V; i++) {
            if (hasRun[i] == 0 && weight[i] < min) {
                index = i;
                min = weight[i];
            }
        }
        return index;
    }
    void printDistance(int weight[])
    {
        int total = 0;
        cout << "Vertex: \t";
        for (int i = 0; i < V; i++) {
            cout << i << "\t";
        }
        cout << "\nDistance: \t";
        for (int i = 0; i < V; i++) {
            cout << weight[i] << "\t";
        }
        cout << endl;
    }

public:
    Dijkstra(const int *arr)
        : matrix(arr)
    {
        // if you dont want to modify the array
        // copy(&arr[0][0], &arr[0][0] + V * V, &matrix[0][0]); 
    }
    void algorithm(int start = 0)
    {
        if (start >= V || start < 0)
            start = 0; // make sure that function not broke
        int hasRun[V] = {0};
        int weight[V];
        for (int i = 0; i < V; i++) {
            weight[i] = INT_MAX;
        }
        weight[start] = 0;
        for (int i = 0; i < V - 1; i++) { // chon length - 1 tai vi thang cuoi da duoc may thang kia check het roi
            int v = minDistance(weight, hasRun);
            hasRun[v] = 1;
            for (int j = 0; j < V; j++) {
                if (hasRun[j] == 0 && matrix[v * V + j] && matrix[v * V + j] + weight[v] < weight[j]) {
                    weight[j] = matrix[v * V + j] + weight[v];
                }
            }
        }
        printDistance(weight);
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
    int *test = new int[64];
    Dijkstra<8> hello(&graph[0][0]);
    hello.algorithm(5);
}