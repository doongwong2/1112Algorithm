#include<iostream>
#include<string>
using namespace std;

#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()

void hammingDistance(string d, int s, int o) {
	if ((int)d.size() == s) {
		if (!o)
			cout << d << endl;
		return;
	}
	hammingDistance(d + '0', s, o);
	hammingDistance(d + '1', s, o - 1);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, s, o;
	cin >> n;
	while (n--) {
		cin >> s >> o;
		string d = "";
		hammingDistance(d, s, o);
		if (n)
			cout << endl;
	}
}