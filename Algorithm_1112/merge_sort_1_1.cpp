#include<iostream>  
#include<limits.h>  
using namespace std;

int a[1000002];

void merge(int a[], int l, int m, int r);
void mergeSort(int a[], int l, int r);


int main()
{
    ios_base::sync_with_stdio(false);
    int aLen = 0;
    while (cin >> a[aLen])
    {
        aLen++;
    }

    mergeSort(a, 0, aLen - 1);

    for (int x = 0; x < aLen; x++)
    {
        cout << a[x] << " ";
    }
    cout << endl;

    return 0;
}

void mergeSort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

void merge(int a[], int l, int m, int r)
{
    int idx_subL, idx_subR, idx_a;
    int subleft = m - l + 1;
    int subright = r - m;

    int aL[25000], aR[25000];
    for (idx_subL = 0; idx_subL < subleft; idx_subL++) aL[idx_subL] = a[l + idx_subL];
    for (idx_subR = 0; idx_subR < subright; idx_subR++) aR[idx_subR] = a[m + 1 + idx_subR];
    idx_subL = 0; idx_subR = 0; idx_a = l;

    while (idx_subL < subleft && idx_subR < subright)
    {
        if (aL[idx_subL] <= aR[idx_subR])
        {
            a[idx_a] = aL[idx_subL]; idx_subL++;
        }
        else
        {
            a[idx_a] = aR[idx_subR];
            idx_subR++;
        }
        idx_a++;
    }

    while (idx_subL < subleft)
    {
        a[idx_a] = aL[idx_subL]; idx_subL++; idx_a++;
    }

    while (idx_subR < subright)
    {
        a[idx_a] = aR[idx_subR]; idx_subR++; idx_a++;
    }

}