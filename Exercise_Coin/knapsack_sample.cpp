// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

// A utility function that returns
// maximum of two integers
int max(int a, int b)
{
	if ( a > b )
	{
		return a;
	}
	else { return b; }
//	return (a > b) ? a : b;
}

// Returns the maximum value that
// can be put in a knapsack of capacity W
void knapSack(int W, int weight[], int value[], int n)
{
	int i, w;
//	int* K = (int*) 
	vector<vector<int>> K( n+1 , vector<int> (W+1, 0));
	vector<int> maxvalue;

	// Build table K[][] in bottom up manner
	for(i = 0; i <= n; i++)
	{
		for(w = 0; w <= W; w++)
		{
			if (i == 0 || w == 0)
				K[i][w] = 0;
			else if (weight[i - 1] <= w)
				K[i][w] = max(value[i - 1] + K[i - 1][w - weight[i - 1]], K[i - 1][w]);
			else
				K[i][w] = K[i - 1][w];
		}
	}
	cout << "\t";
	for (int i = 0; i <= W; i++)
	{
		cout << i << "\t\t";
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
    {
		cout << i <<"\t";
        for (int j = 0 ; j <= W; j++)
        {
			
            cout << K[i][j] << "\t";
            cout << "  ";
        }
		if ( K[i][W] > K[i-1][W] )
			{
				maxvalue.push_back(i);
			}
        cout << endl;
	}
	cout << endl << "The optimize knapsack contains ";
	for (int i: maxvalue)
	{
		cout << i << "  ";
	}
}

// Driver Code
int main()
{
	int n = 6;
	int val[] = { 7,10,2,3,2,6 };
	int wt[] = { 3,2,6,1,7,4 };
	int W = 10;
    knapSack(W, wt, val, n);
	return 0;
}

// This code is contributed by Debojyoti Mandal
