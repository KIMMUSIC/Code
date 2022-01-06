#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <queue>

using namespace std;

int N, M, K;
vector<pair<int, pair<int, int>>> adj[101];

vector<vector<int>> dijkstra(int src)
{
    vector<vector<int>> dist(N, vector<int>(10001, 0x3f3f3f3f));
    dist[src][0] = 0;
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({ 0,{0,0} });

    while (!pq.empty()) {
        int here = pq.top().second.second;
        int time = -pq.top().first;
        int cost = pq.top().second.first;
        pq.pop();

        if (dist[here][cost] < time) continue;

        for (int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int nextTime = adj[here][i].second.second;
            int nextCost = adj[here][i].second.first;

            if (dist[there][cost + nextCost] > dist[here][cost] + nextTime && cost + nextCost <= M) {
                dist[there][cost + nextCost] = dist[here][cost] + nextTime;
                pq.push({ -dist[there][cost + nextCost], {cost + nextCost, there} });
            }
        }

    }
    return dist;
}

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        for (int i = 0; i < 101; ++i)
        {
            adj[i].clear();
        }
        cin >> N >> M >> K;

        for (int i = 0; i < K; ++i)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            u--; v--;

            adj[u].push_back({ v,{c,d} });
        }

        vector<vector<int>> res = dijkstra(0);

        int ans = 0x3f3f3f3f;
        for (int i = 0; i <= 10000; ++i)
        {
            ans = min(ans, res[N - 1][i]);
        }

        if (ans == 0x3f3f3f3f) cout << "Poor KCM" << endl;
        else
        {

            cout << ans << endl;
        }
    }
}
