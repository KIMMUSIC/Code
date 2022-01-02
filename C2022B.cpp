#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    int T;
    cin >> T;

    while (T--)
    {
        int n;
        cin >> n;

        string s;
        string ans = "";
        cin >> s;

        int target = n - 1;

        for (int i = 0; i < n - 1; ++i)
        {
            if (s[i] < s[i + 1] || (s[i] == s[i+1] && i < 1))
            {
                target = i;
                break;
            }
        }

        for (int i = 0; i <= target; ++i)
        {
            ans += s[i];
        }

        for (int i = target; i >= 0; --i)
        {
            ans += s[i];
        }

        cout << ans << endl;
    }
}


