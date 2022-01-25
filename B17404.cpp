#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int N;
struct RGB {
    int R;
    int G;
    int B;
};
vector<RGB> arr;
int cache[1002][4][4];

int DP(int idx, int color, int first, int before)
{
    if (idx == N - 1)
    {
        if (first == before && first == 0)
        {
            return min(arr[idx].G, arr[idx].B);
        }
        else if (first == before && first == 1)
        {
            return min(arr[idx].R, arr[idx].B);
        }
        else if (first == before && first == 2)
        {
            return min(arr[idx].R, arr[idx].G);
        }
        else
        {
            int tt;
            for (int i = 0; i < 3; ++i)
            {
                if (first == i || before == i) continue;
                if (i == 0) tt = arr[idx].R;
                if (i == 1) tt = arr[idx].G;
                if (i == 2) tt = arr[idx].B;
            }
            return tt;
        }
    }

        int& ret = cache[idx][color][first];
        if (ret != -1) return ret;

        if (color == 0) ret = arr[idx].R;
        else if (color == 1) ret = arr[idx].G;
        else ret = arr[idx].B;

        ret += min(DP(idx + 1, (color + 1) % 3, first, color), DP(idx + 1, (color + 2) % 3, first, color));
        return ret;
    
}

    int main(void)
    {
        cin >> N;
        memset(cache, -1, sizeof cache);

        for (int i = 0; i < N; ++i)
        {
            int a, b, c;
            cin >> a >> b >> c;

            RGB tmp;
            tmp.R = a;
            tmp.G = b;
            tmp.B = c;

            arr.push_back(tmp);
        }

        int res = 0x3f3f3f3f;
        for (int i = 0; i < 3; ++i)
        {
            res = min(res,DP(0, i, i, -1));
        }

        cout << res << endl;
    }







