//https://www.acmicpc.net/problem/9012
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    string ps;
    int count = 0;
    for (int i=0; i < t; i++)
    {
        cin >> ps;
        count = 0;
        for (int j=0; j < ps.length(); j++)
        {
            if (ps[j] == '(')
                count++;
            else if (ps[j] == ')')
            {
                if (count <= 0)
                {
                    count = -1;
                    break;
                }
                else 
                    count--;
            }
        }
        cout << (count == 0 ? "YES" : "NO") << '\n';
    }
}