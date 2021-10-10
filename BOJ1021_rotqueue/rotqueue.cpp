//https://www.acmicpc.net/problem/1021
#include <iostream>
#include <queue>
#include <deque>
#include <algorithm>
using namespace std;

int findidx(deque<int> dq, int target)
{
    return find(dq.begin(), dq.end(), target) - dq.begin();
}

void solve()
{
    int n, m;
    cin >> n >> m;
    
    // 뽑아야할 수들
    queue<int> q;
    // 현재 수들
    deque<int> dq;

    int tmp;
    for (int i=0; i < m; i++)
    {
        cin >> tmp;
        q.push(tmp);
    }

    for (int i=1; i < n + 1; i++)
        dq.push_back(i);

    int count = 0;
    while(!q.empty())
    {
        int findtar = findidx(dq, q.front());
        while (dq.front() != q.front())
        {
            if (findtar <= dq.size() / 2)
            {
                dq.push_back(dq.front());
                dq.pop_front();
                count++;
            }
            else
            {
                dq.push_front(dq.back());
                dq.pop_back();
                count++;
            }
        }

        dq.pop_front();
        q.pop();
    }
    cout << count << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}