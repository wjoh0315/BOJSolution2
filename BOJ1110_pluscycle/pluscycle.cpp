//https://www.acmicpc.net/problem/1110
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int tmp = n;
    int count = 0;
    while (true)
    {
        tmp = tmp % 10 * 10 + (tmp / 10 + tmp % 10) % 10;
        count++;
        if (tmp == n)
            break;
    }
    cout << count << '\n';
}
