//https://www.acmicpc.net/problem/9012
#include <iostream>
using namespace std;

int stack[50];
int top = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    string ps;
    for (int i=0; i < t; i++)
    {
        top = -1;
        cin >> ps;

        for (int j=0; j < ps.length(); j++)
        {
            if (ps[j] == '(')
            {
                top++;
                stack[top] = 1;
            }
            else if (ps[j] == ')')
            {
                top--;
                if (top < -1)
                    break;
            }
        }

        cout << (top == -1 ? "YES" : "NO") << '\n';
    }
}