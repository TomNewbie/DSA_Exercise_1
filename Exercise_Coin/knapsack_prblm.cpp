// A dynamic programming based
// solution for 0-1 Knapsack problem
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

void knapSack(int W, vector<int> weight, vector<int> value, int n)
{
    cout << "i->\t";
    for (int i = 1; i <= n; i++) {
        cout << i << "\t";
    }
    cout << endl;

    cout << "wt \t";
    for (int i : weight) {
        cout << i << "\t";
    }
    cout << endl;

    cout << "val\t";
    for (int i : value) {
        cout << i << "\t";
    }
    cout << endl
         << endl;

    vector<vector<int>> K(n + 1, vector<int>(W + 1, 0));
    vector<int> max_obj;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= W; j++) {
            if ((j >= weight[i - 1]) && ((K[i - 1][j - weight[i - 1]] + value[i - 1]) > K[i - 1][j])) {
                K[i][j] = K[i - 1][j - weight[i - 1]] + value[i - 1];
            }
            else
                K[i][j] = K[i - 1][j];
        }
    }
    cout << "   ";
    for (int i = 0; i <= W; i++)
        cout << i << "  ";
    cout << endl;
    for (int i = 0; i <= n; i++) {
        cout << i << "  ";
        for (int j = 0; j <= W; j++) {

            cout << K[i][j] << "  ";
        }
        // if (K[i][W] > K[i - 1][W]) {
        //     max_obj.push_back(i);
        // }
        cout << endl;
    }
    int i = n;
    while(i > 0)
    {
        if(K[i][W] > K[i-1][W])
        {
            max_obj.push_back(i);
            W -= weight[i-1];
            i--;
        }
        else
        {
            i--;
        }
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
    int num_obj, max_weight;
    cout << "Enter number of object: ";
    cin >> num_obj;
    cout << endl;
    cout << "Enter max weight: ";
    cin >> max_weight;
    cout << endl;
    vector<int> value;
    vector<int> weight;
    srand((unsigned)time(0));
    for (int i = 0; i < num_obj; ++i) {
        value.push_back(rand() % num_obj + 1);
        weight.push_back(rand() % num_obj + 1);
    }

    knapSack(max_weight, weight, value, num_obj);
    return 0;
}