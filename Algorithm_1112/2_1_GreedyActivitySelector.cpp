#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

typedef struct tt
{
	int start;
	int finish;
}timeTable;

timeTable tableTime[100000];
vector <int> ans;
void greedyActivitySelector(int totalEvents);

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int idx, s, f;
	while (cin >> idx >> s >> f)
	{
		tableTime[idx].start = s;
		tableTime[idx].finish = f;
	}

	greedyActivitySelector(idx);

	return 0;
}

void greedyActivitySelector(int totalEvents)
{
	ans.push_back(69);
	ans.push_back(1);
	for (int m = 2; m <= totalEvents; m++)
	{
		if (tableTime[m].start >= tableTime[ans.back()].finish)
		{
			ans.push_back(m);
		}
	}

	for (int z = 1; z < ans.size(); z++) cout << ans[z] << " ";
	cout << "\n";

	return;
}