#include<iostream>
#include<limits.h>

using namespace std;
const int X = 10000000;
int priceArr[X] = {};
int rodArr[X] = {};

int bucr(int n);//bottom up cut rod

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,lenInput,priInput;
	cin >> n;
	while (cin >> lenInput >> priInput)
	{
		if (lenInput == 0 && priInput == 0) break;
		priceArr[lenInput] = priInput;
	}
	cout << bucr(n) << endl;

	return 0;
}

int bucr(int n)
{
	rodArr[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		int q = INT_MIN;
		for (int i = 1; i <= j; i++)
		{
			q = max(q, priceArr[i] + rodArr[j - i]);
		}
		rodArr[j] = q;
	}


	return rodArr[n];
}