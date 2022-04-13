// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void knapSack(int W, vector<int> weight, vector<int> value, int n)
{
    cout << "i->\t";
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << "\t";
    }
    cout << endl;

    cout << "wt \t";
    for (int i : weight)
    {
        cout << i+1 << "\t";
    }
    cout << endl;

    cout << "val\t";
    for (int i : value)
    {
        cout << i+1 << "\t";
    }
    cout << endl << endl;

	vector<vector<int>> K( n+1 , vector<int> (W+1, 0));
	vector<int> max_obj;

	for (int i = 1; i<=n; i++)
    {
        K[i][0] = 0;
    }
    for (int j = 0; j<=W; j++)
    {
        if (weight[0] <= j)
        {
            K[1][j] = value[0];
        }
        else { K[1][j] = 0;}
    }
    for (int i=2; i<=n; i++)
    {
        for (int j=1; j <= W; j++)
        {
            if ( (j >= weight[i-1]) && ( (K[i-1][j-weight[i-1]] + value[i]) > K[i-1][j]) )
            {
                K[i][j] = K[i-1][j-weight[i-1]] + value[i-1];
            }
            else K[i][j] = K[i-1][j];
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
				max_obj.push_back(i);
			}
        cout << endl;
	}
	cout << endl << "The optimize knapsack contains object ";
	for (int i: max_obj)
	{
		cout << i << " ";
	}
    cout << endl << endl;
}

int main()
{
    int b = 10;
	int a = 1;
	int n = 10;
	vector<int> value;
	vector<int> weight;
	srand((unsigned) time(0));
    for (int i=0; i<n ;++i)
    {
        value.push_back(rand()%(b-a+1)+a);
		weight.push_back(rand()%(b-a+1)+a);
    }
	int W = 30;
    knapSack(W, weight, value, n);
    knapSack(W+20, weight, value, n);
	return 0;
}