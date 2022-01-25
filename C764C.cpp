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

		vector<int> who[51];
		vector<bool> used(n, false);
		vector<int> arr(n, 0);
		
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> arr[i];
			tmp = arr[i];
			while (tmp > n)
			{
				tmp /= 2;
			}

			while (tmp > 0)
			{
				who[tmp].push_back(i);
				tmp /= 2;
			}
		}

		bool flag;
		for (int i = n; i >= 1; --i)
		{
			flag = false;
			if (who[i].empty()) {
				flag = false; break;
			}
			for (int j = 0; j < who[i].size(); ++j)
			{
				if (!used[who[i][j]])
				{
					flag = true;
					used[who[i][j]] = true;
					break;
				}
			}
			if (flag == false) {
				break;
			}

		}

		if (flag == true)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}


	}
}
