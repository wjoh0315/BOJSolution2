//https://www.acmicpc.net/problem/2164
#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    queue<int> q;
    for (int i=1; i < n + 1; i++)
        q.push(i);

    while (q.size() > 1)
    {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front() << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}