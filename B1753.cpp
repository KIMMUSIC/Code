#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
#define endl "\n"
using namespace std;

int V, E;
vector<pair<int,int>> adj[20001];

vector<int> Dijkstra(int src)
{
    vector<int> dist(V,0x3f3f3f3f);
    dist[src] = 0;
    priority_queue<pair<int,int>> pq;
    pq.push({0,src});
    while(!pq.empty()){
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
                pq.push({-nextDist, there});
            }
        }
    }

    return dist;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> V >> E;
    int start;
    cin >> start;
    start--;
    for(int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;

        a--; b--;
        adj[a].push_back({b,c});
    }

    vector<int> res = Dijkstra(start);

    for(int i = 0; i < V; ++i)
    {
        if(res[i] == 0x3f3f3f3f)
        {
            cout << "INF" << endl;
        }
        else
            cout << res[i] << endl;
    }
}




