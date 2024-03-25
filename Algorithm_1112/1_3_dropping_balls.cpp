#include<iostream>
#include<stdbool.h>
#include<cstring>

using namespace std;
const int A = 524300;
const int X = 1050000;
bool visited[X] = {};
int answers[23][A] = { 0 };

int dropball_pos(int d, int D, int node);

int main()
{
	int T, depth, I;

	for (int j = 2; j < 21; j++)
	{
		memset(visited, false, sizeof(visited));//reset the tree values for every new tree depth.
		for (int i = 1; i < A; i++)
			answers[j][i] = dropball_pos(1, j, 0) + 1;
	}
	cin >> T;
	while (cin >> depth >> I)
	{
		if (depth == -1)break;

		cout << answers[depth][I] << "\n";
	}
		
	return 0;
}

int dropball_pos(int d, int D, int node)
{
	//cout << d << " " << D << " " << node << endl;
	if (d == D) return node;
	if (!visited[node])
	{
		visited[node] = true;
		return dropball_pos(d + 1, D, (node * 2) + 1);
	}
	visited[node] = false;
	return dropball_pos(d + 1, D, (node * 2) + 2);
}