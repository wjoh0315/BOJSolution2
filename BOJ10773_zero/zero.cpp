//https://www.acmicpc.net/problem/10773
#include <iostream>
using namespace std;

int *stack;
int stacksize;
int top = -1;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int k;
    cin >> k;
    stacksize = k;
    stack = new int[stacksize];

    int n;
    int result = 0;
    for (int i=0; i < k; i++)
    {
        cin >> n;
        if (n == 0)
        {
            result -= top < 0 ? 0 : stack[top];
            top -= top < 0 ? 0 : 1;
        }
        else 
        {
            top++;
            stack[top] = n;
            result += n;
        }
    }

    cout << result << '\n';
}