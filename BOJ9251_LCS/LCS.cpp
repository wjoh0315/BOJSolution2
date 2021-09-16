//https://www.acmicpc.net/problem/9251
#include <iostream>
#include <string>
using namespace std;

int LCS(string a, string b)
{
    int LCSlength = 0;
    int tmp = 0;
    int **routes = new int*[a.length() + 1] { 0, };
    routes[0] = new int[b.length() + 1] { 0, };
    for (int i=1; i < a.length() + 1; i++)
    {
        int max = 0;
        routes[i] = new int[b.length() + 1] { 0, };
        for (int j=1; j < b.length() + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
                routes[i][j] = routes[i - 1][j - 1] + 1;
            else
                routes[i][j] = routes[i - 1][j] > routes[i][j - 1] 
                    ? routes[i - 1][j] : routes[i][j - 1];
            
            if (routes[i][j] > routes[i][j - 1])
                max = routes[i][j];
        }

        if (max > tmp)
            LCSlength++;
        tmp = max;
    }

    return LCSlength;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string ina, inb;
    cin >> ina >> inb;

    cout << LCS(ina, inb) << '\n';
}