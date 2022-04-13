#include <iostream>
#include <vector>

using namespace std;

int minValue(int a, int b)
{
    if (a < b)
    {
        return a;
    }
    else return b;
}
void minCoins( vector<int> S, int size, int value )
{
	int i, j, x, y;
	vector<vector<int>> table( size+1 , vector<int> (value+1, 0));
	
	for (i = 1; i <= size; i++)
		table[i][0] = 0;

	for (i = 1; i <= size; i++)
	{
		for (j = 1; j <= value; j++)
		{
			if (i==1)
            {
                table[i][j] = table[i][j-S[i-1]]+1;
            }
            else if (j < S[i-1])
            {
                table[i][j] = table[i-1][j];
            }
            else table[i][j] = minValue(table[i-1][j],table[i][j-S[i-1]]+1);
		}
	}
    cout << "->\t";
	for (int i = 0; i <= value; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	for (int i = 1; i <= size; i++)
    {
		cout << S[i-1] <<"\t";
        for (int j = 0 ; j <= value; j++)
        {
            cout << table[i][j] << "\t";
        }
        cout << endl;
    }
//	return table[size][value]; -> Only used for specific size and value, otherwise just draw table
}

int main()
{
	vector<int> coins_type = {1,10,20,25,50,100};
	int length = coins_type.size();
	int total_val_1 = 4;
	int total_val_2 = 3;
	minCoins(coins_type, length, total_val_1);
	cout << endl;
	minCoins(coins_type, length, total_val_2);
	return 0;
}