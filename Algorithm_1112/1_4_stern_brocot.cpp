#include<iostream>
#include<utility>
#include<string>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int a, b;
	pair<int, int> l, r, m;
	while (cin >> a >> b , !(a == 1 && b == 1))
	{
		string output = "";
		l = { 0,1 }; r = { 1,0 }; m = { 1,1 };
		while (m.first != a || m.second != b)
		{
			int v1 = a * m.second, v2 = b * m.first;

			if (v1 < v2)
			{
				r = m;
				m = { l.first + m.first, l.second + m.second };
				output += 'L';

			}
			else 
			{
				l = m;
				m = { m.first + r.first, m.second + r.second };
				output += 'R';
			}
		}
		cout << output << endl;
	}
}