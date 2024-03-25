#include<iostream>
#include<string>
const int P = 25000;
string x, y;
int c[P][P] = { 0 };
using namespace std;
int lcsLen(string x, string y);

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> x >> y;
	 
	return 0;
}

int lcsLen(string x, string y)
{
	int m, n;
	m = x.length(); n = y.length();
	for (int i = 1; i <= m; i++) c[i][0] = 0;
	for (int j = 1; j <= m; j++) c[0][j] = 0;

	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= m; j++)
			if 

}