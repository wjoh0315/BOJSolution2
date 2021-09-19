//https://www.acmicpc.net/problem/12865
#include <iostream>
#define MAX(x,y) x>y?x:y
using namespace std;

int solve(int **arr, int n, int k)
{
    int max = 0;
    int **routes = new int*[k + 1];
    routes[0] = new int[n + 1] { 0, };
    for (int i=1; i < k + 1; i++)
    {
        routes[i] = new int[n + 1] { 0, };

        for (int j=1; j < n + 1; j++)
        {
            if (arr[j-1][0] <= i)
                routes[i][j] = MAX(routes[i][j-1], 
                    arr[j-1][1] + routes[i - arr[j-1][0]][j-1]);
            else
                routes[i][j] = routes[i][j - 1];
                
            max = MAX(max, routes[i][j]);
        }
    }

    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    int **inarr = new int*[n];
    for (int i=0; i < n; i++)
    {
        inarr[i] = new int[2];
        cin >> inarr[i][0] >> inarr[i][1];
    }

    cout << solve(inarr, n, k) << '\n';
}