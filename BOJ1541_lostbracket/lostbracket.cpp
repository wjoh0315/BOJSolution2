//https://www.acmicpc.net/problem/1541
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solve(string formula)
{
    vector<int> num;
    vector<char> op;
    string temp = "";
    for (int i=0; i < formula.length(); i++)
    {
        if (formula[i] == '+'
            || formula[i] == '-')
        {
            num.push_back(stoi(temp));
            op.push_back(formula[i]);
            temp = "";
        }
        else
            temp += formula[i];
    }
    num.push_back(stoi(temp));

    int result = num.front();
    bool minus = false;
    for (int i=1; i < num.size(); i++)
    {
        if (op[i - 1] == '-')
            minus = true;
        if (minus)
            result -= num[i];
        else
            result += num[i];
    }
    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string in;
    cin >> in;

    cout << solve(in) << '\n';
}