#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int minDistance(vector<int> dist, vector<bool> sptSet, int graph_size)
{
	int min = INT_MAX, min_index;

	for (int v = 0; v < graph_size; v++)
	{
		if (sptSet[v] == false && dist[v] <= min)
		{
			min = dist[v]; 
			min_index = v;
		}
	}
	return min_index;
}

vector<int> dijkstra(vector<vector<int>> graph, int start)
{
	vector<int> distance(graph.size()); 

	vector<bool> shortest_path_Tree(graph.size()); 

	for (int i = 0; i < graph.size(); i++)
	{
		distance[i] = INT_MAX;
		shortest_path_Tree[i] = false;
	}

	distance[start] = 0;

	for (int count = 0; count < graph.size() - 1; count++) 
	{
		int u = minDistance(distance, shortest_path_Tree, graph.size());

		shortest_path_Tree[u] = true;

		for (int v = 0; v < graph.size(); v++)
		{
			if 
			(
				!shortest_path_Tree[v] && graph[u][v] && 
				distance[u] != INT_MAX && 
				( distance[u] + graph[u][v] ) < distance[v]
			)
			{
				distance[v] = distance[u] + graph[u][v];
			}
		}
	}
    return distance;
}

int main()
{
	vector<vector<int>> sample_graph 
	{ 
		{ 0 , 10 , 0 , 0 , 5 },
        { 0 , 0 , 1 , 0 , 2 },
        { 0 , 0 , 0 , 4 , 0 },
        { 7 , 0 , 6 , 0 , 0 },
        { 0 , 3 , 9 , 2 , 0 }
	};
	for (int i = 0; i < sample_graph.size(); i++)
    {
        vector<int> result = dijkstra(sample_graph,i);

        for (int j = 0; j < sample_graph.size(); j++)
        {
            cout << result[j] << "\t";
        }

        cout << endl;
    }
	return 0;
}
