#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void floyd( vector<vector<int>> sample )
{
    vector<vector<int>> result( sample.size() , vector<int> ( sample.size() , 0 ) );

    for ( int i=0; i < sample.size(); i++ )
    {
        for ( int j=0; j < sample.size(); j++ )
        {
            for ( int k=0; k < sample.size(); k++ )
            {
                if 
                (
                    sample[j][i] != INT_MAX && sample[i][k] != INT_MAX &&
                    ( sample[j][i] + sample[i][k] ) < sample[j][k]
                )
                {
                    sample[j][k] = sample[j][i] + sample[i][k];
                    result[j][k] = (i + 1);
                }
            }
        }
    }
    
    cout << "Matrix of shortest lengths between all nodes: " << endl;
    for ( int i = 0; i < sample.size(); i++ )
    {
        for ( int j = 0; j < sample.size(); j++ )
        {
            cout << sample[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    cout << "Matrix of shortest paths between every pairs of nodes: " << endl;
    for ( int i = 0; i < sample.size(); i++ )
    {
        for ( int j = 0; j < sample.size(); j++ )
        {
            cout << result[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> sample_graph
    {
        { 0 , 10 , INT_MAX , INT_MAX , 5 },
        { INT_MAX , INT_MAX , 1 , INT_MAX , 2 },
        { INT_MAX , INT_MAX , INT_MAX , 4 , INT_MAX },
        { 7 , INT_MAX , 6 , INT_MAX , INT_MAX },
        { INT_MAX , 3 , 9 , 2 , INT_MAX }
    };
    floyd(sample_graph);
    return 0;
}