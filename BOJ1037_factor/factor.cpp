//https://www.acmicpc.net/problem/1037
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int *factors, int k)
{
    sort(factors, factors + k);
    return factors[0] * factors[k - 1];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;

    int *factors = new int[k];
    for (int i=0; i < k; i++)
        cin >> factors[i];

    cout << solve(factors, k) << '\n';
}