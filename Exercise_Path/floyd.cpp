#include <iostream>

using namespace std;
template <int V>
#define INF 1000
class Floyd {

private:
    int *matrix;
    void printArray()
    {
        cout << "Shortest path vertex: " << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << matrix[i * V + j] << "\t";
            }
            cout << endl;
        }
    }

public:
    Floyd(int *arr)
        : matrix(arr)
    {
        // if you dont want to modify the array
        // copy(&arr[0][0], &arr[0][0] + V * V, &matrix[0][0]);
    }
    void algorithm()
    {
        for (int a = 0; a < V; a++) {
            for (int i = 0; i < V; i++) {
                for (int j = 0; j < V; j++) {
                    if (matrix[i * V + j] > (matrix[i * V + a] + matrix[a * V + j]) && matrix[i * V + a] != INF && matrix[a * V + j] != INF) {
                        matrix[i * V + j] = matrix[i * V + a] + matrix[a * V + j];
                    }
                }
            }
        }

        printArray();
    }
};

int main()
{
    int graph[4][4] = {{0, 3, INF, 7},
                       {8, 0, 2, INF},
                       {5, INF, 0, 1},
                       {2, INF, INF, 0}};
    Floyd<4> test(&graph[0][0]);
    test.algorithm();
}