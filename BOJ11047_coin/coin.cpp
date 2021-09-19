//https://www.acmicpc.net/problem/11047
#include <iostream>
using namespace std;

int solve(int *coins, int n, int k)
{
    if (n == 1)
        return k / coins[0];
    int min = 0;
    int remain = k;
    for (int i=n-1; i >= 0; i--)
    {
        min += remain / coins[i];
        remain = remain % coins[i];
    }
    return min;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int *coins = new int[n];
    for (int i=0; i < n; i++)
        cin >> coins[i];

    cout << solve(coins, n, k) << '\n';
}