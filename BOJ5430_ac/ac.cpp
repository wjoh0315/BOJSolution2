//https://www.acmicpc.net/problem/5430
#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

void solve()
{
    int t;
    cin >> t;

    for (int i=0; i < t; i++)
    {
        int n;
        deque<int> rdq;
        deque<int> sdq;
        deque<int> *dq = &sdq;
        string cmd;
        string tmp;
        
        cin >> cmd >> n;

        cin.ignore();
        for (int j=0; j < n; j++)
        {
            if (j < n - 1)
                getline(cin, tmp, ',');
            else
                cin >> tmp;

            if (j == 0)
                tmp[0] = ' ';
            else if (j == n - 1)
                tmp[tmp.length() - 1] = ' ';
            sdq.push_back(stoi(tmp));
        }
        if (n == 0)
            cin >> tmp;

        bool r = false;
        bool error = false;
        for (int j=0; j < cmd.length(); j++)
        {
            if (cmd[j] == 'R')
            {
                if (rdq.empty())
                {
                    for (deque<int>::iterator k=sdq.begin(); k != sdq.end(); k++)
                        rdq.push_front(*k);
                }
                
                r = !r;
                dq = r ? &rdq : &sdq;
            }
            else if (cmd[j] == 'D')
            {
                error = (*dq).empty();
                if (error)
                {
                    cout << "error" << '\n';
                    break;
                }
                if (r)
                {
                    sdq.pop_back();
                    rdq.pop_front();
                }
                else
                {
                    sdq.pop_front();
                    if (!rdq.empty())
                        rdq.pop_back();
                }
            }
        }

        if (error)
            continue;

        cout << '[';
        while ((*dq).size() > 1)
        {
            cout << (*dq).front() << ',';
            (*dq).pop_front();
        }
        if (!(*dq).empty())
            cout << (*dq).front();
        cout << ']' << '\n';
        cin.ignore();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}