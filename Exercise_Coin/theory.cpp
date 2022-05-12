#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

void calculateCoin(vector<int> coin, int amount)
{
    vector<vector<int>> count(coin.size(), vector<int>(amount + 1, 0));
    vector<int> countCoin(coin.size(), 0);
    for (int i = 0; i < coin.size(); i++) {
        for (int j = 1; j < amount + 1; j++) {
            if (i == 0) {
                count[i][j] = count[i][j - coin[i]] + 1;
            }
            else if (coin[i] > j) {
                count[i][j] = count[i - 1][j];
            }
            else {
                count[i][j] = min(count[i - 1][j], count[i][j - coin[i]] + 1);
            }
        }
    }
    int i = coin.size() - 1, j = amount;
    while (j > 0) {
        if (i > 0 && count[i][j] == count[i - 1][j]) {
            i--;
        }
        if (j >= coin[i] && count[i][j] == count[i][j - coin[i]] + 1) {
            j -= coin[i];
            countCoin[i]++;
        }
    }
    cout << "helo";

    cout << "Smallest number of coin: " << count[coin.size() - 1][amount] << endl;
    for (int i = 0; i < coin.size(); i++) {
        cout << "Coin " << coin[i] << " : " << countCoin[i] << endl;
    }
}

int main()
{
    vector<int> coin{1, 10, 20, 25, 50, 100};
    int amount;
    cin >> amount;
    calculateCoin(coin, amount);
    return 0;
}