#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int main() {
	//ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, d, r;
	int hrs, am[100], pm[100];
	int cost;

	while (scanf("%d %d %d", &n, &d, &r), n || d || r) {
		cost = 0;

		for (int i = 0; i < n; i++) {
			scanf("%d", &am[i]);
		}
		sort(am, am + n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &pm[i]);
		}
		sort(pm, pm + n, greater<int>());

		for (int i = 0; i < n; i++) {
			hrs = am[i] + pm[i];
			if (hrs > d)
				cost += (hrs - d) * r;
		}

		printf("%d\n", cost);
	}

	return 0;
}