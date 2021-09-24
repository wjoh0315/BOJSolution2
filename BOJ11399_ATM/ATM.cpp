//https://www.acmicpc.net/problem/11399
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int *arr, int n)
{
    int sum = 0;
    int *results = new int[n] { 0, };
    for (int i=0; i < n; i++)
    {
        if (i > 0)
            results[i] += results[i - 1];
        results[i] += arr[i];
        sum += results[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];

    sort(arr, arr + n);
    cout << solve(arr, n) << '\n';
}