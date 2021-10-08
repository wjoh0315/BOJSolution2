//https://www.acmicpc.net/problem/2004
#include <iostream>
#define MIN(X,Y) (X<Y?X:Y)
using namespace std;

uint64_t solve1(uint64_t n)
{
    uint64_t p = 5;
    uint64_t result = 0;
    while (n % p != n)
    {
        result += n / p;
        p *= 5;
    }
    return result;
}

uint64_t solve2(uint64_t n)
{
    uint64_t p = 2;
    uint64_t result = 0;
    while (n % p != n)
    {
        result += n / p;
        p *= 2;
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    uint64_t n, m;
    cin >> n >> m;

    cout << MIN(solve1(n) - solve1(n - m) - solve1(m),
        solve2(n) - solve2(n - m) - solve2(m)) << '\n';
}