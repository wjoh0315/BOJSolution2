//https://www.acmicpc.net/problem/11866
#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    cout << '<';
    queue<int> q;
    for (int i=1; i < n + 1; i++)
        q.push(i);
    while (q.size() > 1)
    {
        for (int i=0; i < k - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
        cout << q.front() << ", ";
        q.pop();
    }
    cout << q.front() << ">\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}