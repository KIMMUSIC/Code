#include <iostream>
#include <vector>
#include <queue>
 
using namespace std;
 
int main(void)
{
	int T;
	cin >> T;
	while (T--)
	{
		int n;
		cin >> n;
 
		queue<pair<int, int>> q;
		vector<int> p;
		vector<pair<pair<int, int>, int>> ans;
		p.resize(n+1, 1);
		for(int i = 0; i < n; ++i)
		{
			int a, b;
			cin >> a >> b;
			q.push({ a,b });
 
		}
 
		while (!q.empty())
		{
			int l = q.front().first;
			int r = q.front().second;
			q.pop();
 
			if (l == r) {
				p[l] = 0;
				ans.push_back({ {l,r},l });
				continue;
			}
			else
			{
				int flag = 0;
				int target;
				int cnt = 0;
				for (int i = l; i <= r; ++i)
				{
					if (p[i] > 0)
					{
						flag = 1;
						target = i;
						cnt++;
					}
				}
 
				if (flag == 1 && cnt == 1)
				{
					p[target] = 0;
					ans.push_back({ {l,r},target });
					continue;
				}
 
				if (cnt > 1) {
					q.push({ l,r });
				}
			}
 
		}
		for (int i = 0; i < ans.size(); ++i)
		{
			cout << ans[i].first.first << " " << ans[i].first.second << " " << ans[i].second << endl;
		}
 
 
	}
}
