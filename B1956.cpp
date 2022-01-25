#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#define MAX_V 402

using namespace std;

int adj[MAX_V][MAX_V];
vector<int> arr[MAX_V];

int main(void)
{
    int V, E;
    cin >> V >> E;

    for (int i = 0; i < MAX_V; ++i)
        memset(adj[i], 0x3f3f3f3f, sizeof adj[i]);

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a][b] = c;
        arr[b].push_back(a);
    }

	for(int i = 0; i < V; ++i) adj[i][i] = 0;
    
    for(int k = 0; k < V; ++k)
        for(int i = 0; i < V; ++i)
            for(int j = 0; j < V; ++j)
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int res = 0x3f3f3f3f;
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < arr[i].size(); ++j)
        {
            res = min(res, adj[i][arr[i][j]] + adj[arr[i][j]][i]);
        }
    }
   if(res >= 0x3f3f3f3f) cout << -1 << endl;
    else cout << res << endl;
}

