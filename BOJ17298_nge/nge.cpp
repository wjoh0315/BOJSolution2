//https://www.acmicpc.net/problem/17298
#include <iostream>
#include <string>
#include <stack>
#include <map>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    stack<int> nge;
    int *arr = new int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];
    int tmp;
    for (int i=n-1; i >= 0; i--)
    {
        while (!nge.empty() && nge.top() <= arr[i])
            nge.pop();
        tmp = arr[i];
        arr[i] = nge.empty() ? -1 : nge.top();
        nge.push(tmp);
    }
    for (int i=0; i < n; i++)
        cout << arr[i] << ' ';
    cout << '\n';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}