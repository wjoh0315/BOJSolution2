//https://www.acmicpc.net/problem/1874
#include <iostream>
#include <string>
#include <stack>
using namespace std;

void solve(int n, int *arr)
{
    string out;
    stack<int> s;
    int cur = 0;
    for (int i=1; i < n + 1; i++)
    {
        s.push(i);
        out += "+\n";
        while (!s.empty() && s.top() == arr[cur])
        {
            s.pop();
            cur++;
            out += "-\n";
        }
    }
    if (!s.empty())
        cout << "NO" << '\n'; 
    else 
        cout << out;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *arr = new int[n];
    for (int i=0; i < n; i++)
        cin >> arr[i];

    solve(n, arr);
}