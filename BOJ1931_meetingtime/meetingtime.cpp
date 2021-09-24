//https://www.acmicpc.net/problem/1931
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<pair<int, int>> vec)
{
    int count = 1;
    int t = vec.front().first;
    for (int i=1; i < vec.size(); i++)
    {
        if (vec[i].second >= t)
        {
            t = vec[i].first;
            count++;
        }
    }
    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> vec;
    for (int i=0; i < n; i++)
    {
        int t1, t2;
        cin >> t1 >> t2;
        vec.push_back(make_pair(t2, t1));
    }

    sort(vec.begin(), vec.end());
    cout << solve(vec) << '\n';
}