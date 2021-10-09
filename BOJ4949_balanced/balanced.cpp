//https://www.acmicpc.net/problem/4949
#include <iostream>
#include <string>
using namespace std;

int stack[100];
int top = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (true)
    {
        top = -1;
        string in;
        getline(cin, in, '.');

        if (in.length() <= 1)
            break;
        
        for (int i=0; i < in.length(); i++)
        {
            if (in[i] == '(')
            {
                top++;
                stack[top] = 0;
            }
            else if (in[i] == ')')
            {
                if (--top < -1)
                    break;
                if (stack[++top] != 0)
                    break;
                top--;
            }
            else if (in[i] == '[')
            {
                top++;
                stack[top] = 1;
            }
            else if (in[i] == ']')
            {
                if (--top < -1)
                    break;
                if (stack[++top] != 1)
                    break;
                top--;
            }
        }

        cout << (top == -1 ? "yes" : "no") << '\n';
    }
}