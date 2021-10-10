//https://www.acmicpc.net/problem/10866
#include <iostream>
#include <deque>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    deque<int> dq;
    string cmd;
    int tmp;
    for (int i=0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (cmd == "push_back")
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (cmd == "pop_front")
        {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
            if (!dq.empty())
                dq.pop_front();
        }
        else if (cmd == "pop_back")
        {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
            if (!dq.empty())
                dq.pop_back();
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << (dq.empty() ? -1 : dq.front()) << '\n';
        }
        else if (cmd == "back")
        {
            cout << (dq.empty() ? -1 : dq.back()) << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}