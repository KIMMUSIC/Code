#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int w,h;
char map[21][21];
pair<int,int> robots;
int cnt;
int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};
int visited[21][21];

int dfs(int x, int y, int cnt){
    if(cnt == 0){
        return 0;
    }

    int tmp = cnt;
    if(map[x][y] == '*') tmp--; 

    int ret = 404;
    for(int i = 0; i < 4; ++i)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && ny >= 0 && nx < w && ny < h)
        {
            if(!visited[nx][ny] && map[nx][ny] != 'x')
            {
                visited[nx][ny] = 1;
                ret = min(ret, dfs(nx,ny,tmp) + 1);
                visited[nx][ny] = 0;
            }
        }
    }

    return ret;
}


int main(void)
{
    while(1)
    {
        cin >> w >> h;
        memset(visited, 0, sizeof visited);
        if(w == 0 && h == 0) break;
        cnt = 0;

        for(int i = 0; i < h; ++i)
        {
            for(int j = 0; j < w; ++j)
            {
                cin >> map[i][j];
                if(map[i][j] == 'o')
                    robots = {i,j};
                if(map[i][j] == '*')
                    cnt++;
            }
        }

        cout << dfs(robots.first, robots.second, cnt) << endl;
    }
}


