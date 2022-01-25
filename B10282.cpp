#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

int V;
vector<pair<int,int>> adj[10002];

vector<int> dijkstra(int src)
{
    vector<int> dist(V,INF);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost) continue;
        for(int i = 0; i < adj[here].size(); ++i)
        {
            int there = adj[here][i].first;
            int nextDist = cost + adj[here][i].second;
            if(dist[there] > nextDist)
            {
                dist[there] = nextDist;
                pq.push({-nextDist,there});
            }
        }
    }
    return dist;
}

int main(void)
{
    int T;
    cin >> T;

    while(T--)
    {
        for(int i =  0; i < 10002; ++i)
        {
            adj[i].clear();
        }
        int n;
        int d;
        int c;
        cin >> n >> d >> c;

        for(int i = 0; i < d; ++i)
        {
            int a, b, s;
            cin >> a >> b >> s;
            adj[b].push_back({a,s});
            //adj[a].push_back({b,s});
        }

        V = n+1;

        vector<int> res =  dijkstra(c);
        int ret = -1;
        int cnt = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(res[i] == INF) continue;

            ret = max(ret, res[i]);
            cnt++;
        }

        cout << cnt << " " << ret << endl;
    }
}


