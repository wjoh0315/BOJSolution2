//https://www.acmicpc.net/problem/13305
#include <iostream>
using namespace std;

uint64_t solve(uint64_t *dist, uint64_t *cost, uint64_t n)
{
    uint64_t sum = 0;
    uint64_t bcost = cost[0];
    for (int i=1; i < n; i++)
    {
        sum += bcost * dist[i - 1];
        if (cost[i] < bcost)
            bcost = cost[i];
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    uint64_t *dist = new uint64_t[n - 1];
    for (int i=0; i < n - 1; i++)
        cin >> dist[i];

    uint64_t *cost = new uint64_t[n];
    for (int i=0; i < n; i++)
        cin >> cost[i];

    cout << solve(dist, cost, n) << '\n';
}