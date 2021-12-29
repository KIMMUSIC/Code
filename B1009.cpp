#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;

        int cnt = 1;
        vector<int> ans;
        int num = 1;
        while (1)
        {
            cnt *= a;
            cnt %= 10;
            if (cnt == 0) cnt = 10;
            ans.push_back(cnt);
            if (num != 1 && ans[0] == cnt) {
                ans.pop_back();
                break;
            }
            
            if (num == b) break;
            num++;
        }

        int len = b % ans.size();
        if (len == 0) cout << ans.back() << endl;
        else
         cout << ans[len - 1] << endl;
    }
}

        







