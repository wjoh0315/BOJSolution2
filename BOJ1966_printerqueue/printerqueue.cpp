//https://www.acmicpc.net/problem/1966
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        //cout << '\n';
        int n, m;
        cin >> n >> m;
        
        // 인덱스 값 큐
        queue<int> q;
        // front부터 내림차순으로 정렬된 큐
        queue<int> qs;
        int *arr = new int[n];
        int *sorted = new int[n];
        for (int j=0; j < n; j++)
        {
            cin >> arr[j];
            sorted[j] = arr[j];
            q.push(j);
        }
        sort(sorted, sorted + n);
        for (int j=n - 1; j >= 0; j--)
            qs.push(sorted[j]);
        
        int count = 1;
        // front의 인덱스가 입력값과 같고 중요도가 더 높은 문서가 없을 때까지 반복
        while (!(m == q.front() && qs.front() == arr[q.front()]))
        {
            if (qs.front() > arr[q.front()])
            {
                //cout << q.front() << arr[q.front()] << '\n';
                q.push(q.front());
                q.pop();
            }
            else
            {
                q.pop();
                qs.pop();
                count++;
            }
        }
        //cout << '\n';
        cout << count << '\n';
        //cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}