#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
 
using namespace std;
 
int n, m;
int rx, ry;
int dx, dy;
int second;
 
void func(int x, int y, int tx, int ty)
{
    if (x == dx || y == dy)
    {
        return;
    }
 
    int nx, ny;
 
    if (tx > 0)
        nx = x + 1;
    else
        nx = x - 1;
    if (ty > 0)
        ny = y + 1;
    else
        ny = y - 1;
 
    if (nx > n) {
        nx -= 2;
        tx *= -1;
    }
    if (ny > m) {
        ny -= 2;
        ty *= -1;
    }
 
    if (nx <= 0) {
        nx += 2;
        tx *= -1;
    }
 
    if (ny <= 0)
    {
        ny += 2;
        ty *= -1;
    }
 
    second++;
    func(nx, ny, tx, ty);
}
 
 
 
int main(void)
{
    int T;
    cin >> T;
 
    while (T--)
    {
        second = 0;
        cin >> n >> m >> rx >> ry >> dx >> dy;
 
        func(rx, ry, 1, 1);
 
        cout << second << endl;
    }
}
