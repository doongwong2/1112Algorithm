#include<iostream>
#include<algorithm>

using namespace std;

int wArr[10000];
int vArr[10000];
int c[10000][10000];
bool items[10000][10000];

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int capacity;
	int n, w, v,nn;// n = number, w = weight, v = value, nn = redundancy variable for n.
	
	cin >> capacity;
	while (cin >> n >> w >> v)
	{
		if (n == -1) break;
		if (w == -1) break;
		if (v == -1) break;
		nn = n;
		wArr[n] = w;
		vArr[n] = v;
	}

	for (int i = 0; i < nn; i++)// for nn total items
		for (int j = 0; j <= capacity; j++)//for j within capacity
			if (j - wArr[i] < 0) //wArr = array of object weights.
				c[i + 1][j] = c[i][j];//cannot add to c array.
			else {//still within capacity.
				c[i + 1][j] = max(c[i][j - wArr[i]] + vArr[i], c[i][j]);//vArr = array of object values.
				if (c[i][j - wArr[i]] + vArr[i] > c[i][j])
					items[i][j] = 1;//object is added to bag.
			}

	for (int i = nn, j = capacity; i >= 0; i--)
	{
		if (items[i][j] == 1)
		{
			printf("%d ", i); j -= wArr[i];
		}
			
	}
	printf("\n%d\n", c[nn][capacity]);

	return 0;
}
