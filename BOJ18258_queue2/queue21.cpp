//https://www.acmicpc.net/problem/18258
#include <iostream>
#include <queue>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int tmp;
    string cmd;
    queue<int> q;
    for (int i=0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> tmp;
            q.push(tmp);
        }
        else if (cmd == "pop")
        {
            cout << (q.empty() ? -1 : q.front()) << '\n';
            if (!q.empty())
                q.pop();
        }
        else if (cmd == "size")
            cout << q.size() << '\n';
        else if (cmd == "empty")
            cout << q.empty() << '\n';
        else if (cmd == "front")
            cout << (q.empty() ? -1 : q.front()) << '\n';
        else if (cmd == "back")
            cout << (q.empty() ? -1 : q.back()) << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}