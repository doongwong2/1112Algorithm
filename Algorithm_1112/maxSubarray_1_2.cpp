#include<iostream>
#include<limits.h>
using namespace std;
const int X = 100010;
int arr[X];

int fms(int arr[], int low, int high);//find maximum subarray.

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int idx = 0;
	while (cin >> arr[idx])idx++;

	cout << fms(arr, 0, idx) << endl;

	return 0;
}

int fms(int arr[], int low, int high)
{
	int max_sum = INT_MIN;
	int current_sum = 0;
	for (int i = 0; i < high; i++)
	{
		current_sum = current_sum + arr[i];
		if (current_sum < 0)current_sum = 0;
		if (max_sum < current_sum) max_sum = current_sum;
	}
	return max_sum;

}