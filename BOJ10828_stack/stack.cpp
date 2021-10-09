//https://www.acmicpc.net/problem/10828
#include <iostream>
#include <string>
using namespace std;

int *stack;
int stacksize;
int topidx = -1;

int push(int x)
{
    if (topidx > stacksize - 1)
        return -1;
    topidx++;
    stack[topidx] = x;
    return x;
}

int pop()
{
    if (topidx < 0)
        return -1;
    topidx--;
    return stack[topidx + 1];
}

int size()
{
    if (topidx < 0)
        return 0;
    return topidx + 1;
}

int empty()
{
    return topidx < 0;
}

int top()
{
    if (topidx < 0)
        return -1;
    return stack[topidx];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string cmd;
    int tmp;
    stacksize = n;
    stack = new int[stacksize] { 0, };
    for (int i=0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> tmp;
            push(tmp);
        }
        else if (cmd == "pop")
            cout << pop() << '\n';
        else if (cmd == "size")
            cout << size() << '\n';
        else if (cmd == "empty")
            cout << empty() << '\n';
        else if (cmd == "top")
            cout << top() << '\n';
    }
}