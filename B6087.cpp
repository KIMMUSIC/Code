#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int W, H;
char map[101][101];
vector<pair<int, int>> razer;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int visited[101][101];
queue<pair<pair<int, int>, pair<int, int>>> q;



void bfs()
{
    while (!q.empty())
    {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dir = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            int tcnt = cnt;

            if (nx >= 0 && ny >= 0 && nx < H && ny < W)
            {
                if (map[nx][ny] != '*')
                {
                    if (dir != i)
                    {
                        tcnt += 1;
                    }
                    if (visited[nx][ny] >= tcnt)
                    {
                        visited[nx][ny] = tcnt;
                        q.push({ {nx,ny},{i,tcnt} });
                    }
                }
            }


        }
    }
   
}

int main(void)
{
    
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> W >> H;

    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 'C')
            {
                razer.push_back({ i,j });
            }
            visited[i][j] = 987654321;
        }
    }
    
   
    visited[razer[0].first][razer[0].second] = 0;
    for(int i = 0; i < 4; ++i){
        q.push({ {razer[0].first,razer[0].second},{i,0 }});
     }
    bfs();

    cout << visited[razer[1].first][razer[1].second] << endl;
}

