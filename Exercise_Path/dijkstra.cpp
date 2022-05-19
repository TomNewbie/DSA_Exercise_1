#include <iostream>
#include <vector>

using namespace std;
/*
    Note that this algorithm is always work well if distance is positive
    It will depend if the distance is not positive
*/
#define INF 1000

template <int V>
class Dijkstra {
private:
    const int *matrix;
    int *parent;
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
    void printDistance(int weight[], const int start)
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
        cout << "\nPath: " << endl;
        for (int i = 1; i < V; i++) {
            findingParent(i, start);
        }
        cout << endl;
    }
    void findingParent(int x, const int start)
    {
        int arr[V], count = 0;
        arr[count] = x;
        cout << "Path to " << x << ": ";
        while (parent[x] != start) {
            count++;
            x = parent[x];
            arr[count] = x;
        }
        count++;
        arr[count] = parent[x];
        for (int i = count; i >= 0; i--) {
            if (i == 0) {
                cout << arr[i];
            }
            else
                cout << arr[i] << "---> ";
        }
        cout << endl;
    }

public:
    Dijkstra(const int *arr)
        : matrix(arr)
    {
        parent = new int[V];
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
                if (hasRun[j] == 0 && matrix[v * V + j] + weight[v] < weight[j]) {
                    weight[j] = matrix[v * V + j] + weight[v];
                    parent[j] = v;
                }
            }
        }
        printDistance(weight, 0);
    }
};
int main()
{
    int quan = 0;
    int graph[5][5] = {{INF, 10, INF, 5, INF},
                       {INF, INF, 1, 2, INF},
                       {INF, INF, INF, INF, 4},
                       {INF, 3, 9, INF, 2},
                       {7, INF, 6, INF, INF}};
    Dijkstra<5> hello(&graph[0][0]);
    hello.algorithm(0);
}