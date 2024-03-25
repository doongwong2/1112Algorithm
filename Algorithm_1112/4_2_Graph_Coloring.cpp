#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <bitset>
using namespace std;

typedef vector<int> specialVector;

static int W = 0;
static int B = 1;

bitset<110> colored;
int color[110];
vector<specialVector> AdjacencyList;
int tc, n, k, ans;
specialVector ansls;

void dfs(int u) {
	if (u == n) {
		int b = 0, w = 0;
		for (int i = 0; i < n; i++) {
			if (color[i] == B)b++;
			else w++;
		}
		if (b > ans) {
			ans = b;
			ansls.clear();
			for (int i = 0; i < n; i++)
				if (color[i] == B) ansls.push_back(i);
		}
		return;
	}

	bool canBlack = true;

	//check allowed color
	for (int i = 0; i < (int)AdjacencyList[u].size(); i++) {
		int v = AdjacencyList[u][i];
		if (colored[v] && color[v] == B) {
			canBlack = false;
			break;
		}
	}

	colored.set(u);
	if (canBlack) {
		color[u] = B;
		dfs(u + 1);
	}
	color[u] = W;
	dfs(u + 1);
	colored.reset(u);
}

int main() {
	ios_base::sync_with_stdio(0), std::cin.tie(0), std::cout.tie(0);
	int u, v;cin >> tc;
	while (tc--) {
		cin >> n >> k;

		AdjacencyList.assign(n, specialVector());
		colored.reset();
		ans = -1;
		for (int i = 0; i < k; i++) {
			cin >> u >> v;
			u--;v--;
			AdjacencyList[u].push_back(v);
			AdjacencyList[v].push_back(u);
		}

		dfs(0);

		cout << ans << endl;
		for (int i = 0; i < (int)ansls.size(); i++) {
			cout << ansls[i] + 1;
			if (i < (int)ansls.size() - 1)cout << " ";
		}
		cout << endl;
	}

	return 0;
}