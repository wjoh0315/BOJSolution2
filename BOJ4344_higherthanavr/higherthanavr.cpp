//https://www.acmicpc.net/problem/4344
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int c;
    cin >> c;

    cout << fixed;
    cout.precision(3);

    int n;
    int cur;
    int cnt1 = 0;
    int cnt2 = 0;
    double avr = 0;
    for (int i=0; i < c; i++)
    {
        cin >> n;
        cnt1 = 0;
        cnt2 = 0;
        
        int *score = new int[n];
        for (int j=0; j < n; j++)
        {
            cin >> cur;
            cnt1 += cur;
            score[j] = cur;
        }
        avr = (double)cnt1 / n;

        for (int j=0; j < n; j++)
            cnt2 += score[j] > avr ? 1 : 0;

        cout << (double)cnt2 / n * 100 << '%' << '\n';
    }
}
