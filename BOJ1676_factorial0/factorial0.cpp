//https://www.acmicpc.net/problem/1676
#include <iostream>
using namespace std;

int solve(int n)
{
    int p = 5;
    int result = 0;
    while (n % p != n)
    {
        result += n / p;
        p *= 5;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    cout << solve(n) << '\n';
}