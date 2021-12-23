#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <queue>
#define endl "\n"

using namespace std;

int R, C;
char map[1501][1501];
vector<pair<int, int>> bird;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,1,-1 };
int visited[1501][1501];
queue<pair<int, int>> birdq, waterq;

void water() {
    int T = waterq.size();
    while (T--)
    {
        int x = waterq.front().first;
        int y = waterq.front().second;
        waterq.pop();

        for (int i = 0; i < 4; ++i)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            if (ddx >= 0 && ddx < R && ddy >= 0 && ddy < C)
            {
                if (map[ddx][ddy] == 'X')
                {
                    waterq.push({ ddx,ddy });
                    map[ddx][ddy] = '.';
                }
            }
        }
    }
}

bool seek()
{
    queue<pair<int, int>> q;
    while (!birdq.empty())
    {
        int x = birdq.front().first;
        int y = birdq.front().second;
        birdq.pop();

        if (x == bird[1].first && y == bird[1].second) return true;
        for (int i = 0; i < 4; ++i)
        {
            int ddx = x + dx[i];
            int ddy = y + dy[i];

            if (ddx >= 0 && ddx < R && ddy >= 0 && ddy < C)
            {
                if (!visited[ddx][ddy]) {
                    visited[ddx][ddy] = 1;
                    if (map[ddx][ddy] == 'X') q.push({ ddx,ddy });
                    else birdq.push({ ddx,ddy });
                }
                
            }
        }
    }

    birdq = q;
    return false;
}


int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;

    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
        {
            cin >> map[i][j];
            if (map[i][j] == 'L')
            {
                waterq.push({ i,j });
                bird.push_back({ i,j });
            }
            if (map[i][j] == '.') waterq.push({ i,j });
        }
    }
    birdq.push({ bird[0].first, bird[0].second });

    int cnt = 0;
    while (1)
    {
        if (seek()) break;
        cnt++;
        water();
    }

    cout << cnt << endl;
}


