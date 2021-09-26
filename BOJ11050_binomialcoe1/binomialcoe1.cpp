//https://www.acmicpc.net/problem/11050
#include <iostream>
using namespace std;

int factorial(int x)
{
    if (x <= 1)
        return 1;
    return x * factorial(x - 1);
}

int solve(int n, int k)
{
    return factorial(n) / (factorial(k) * factorial(n - k));
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    cout << solve(n, k) << '\n';
}