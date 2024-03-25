#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct haha
{
	int value;
	int mass;
}lol;

lol stuff[100000];
void fractionalKnapsack(int cap,int amount);

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int capacity; cin >> capacity;
	int value, mass;
	int idx = 0;

	while (cin >> value >> mass)
	{
		stuff[idx].value = value;
		stuff[idx].mass = mass;
		idx++;
	}
	qsort(stuff[0].value, idx,)

	fractionalKnapsack(capacity,idx);

	return 0;
}

void fractionalKnapsack(int cap, int amount)
{
	int load = 0;
	int i = 0;
	while (load < cap and i <= amount)
	{

	}

	return;
}