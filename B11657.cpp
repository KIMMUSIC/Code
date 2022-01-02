#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<pair<int,int>> adj[502];

vector<long long> bellmanFord(int src){
    vector<long long> upper(N+1,0x3f3f3f3f);
    upper[src] = 0;
    bool updated;

    for(int iter = 0; iter < N; ++iter){
        updated = false;
        for(int here = 1; here <= N; ++here)
        {
            if(upper[here] == 0x3f3f3f3f) continue;
            for(int i = 0; i < adj[here].size(); ++i)
            {
                int there = adj[here][i].first;
                int cost = adj[here][i].second;

                if(upper[there] > upper[here]+cost){
                    upper[there] = upper[here] + cost;
                    updated = true;
                }
            }
        }
        if(!updated) break;
    }

    if(updated) upper.clear();
    return upper;
}

int main(void)
{

    cin >> N >> M;

    for(int i = 0; i < M; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b,c});
    }

    vector<long long> res = bellmanFord(1);

    if(res.empty()) cout << -1 << endl;
    else{
    for(int i = 2; i <= N; ++i)
    {
        if(res[i] == 0x3f3f3f3f) cout << -1 << endl;
        else cout << res[i] << endl;
    }
    }
}
