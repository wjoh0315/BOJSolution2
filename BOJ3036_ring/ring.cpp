//https://www.acmicpc.net/problem/3036
#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    int max = a>b?a:b;
    int min = a<b?a:b;
    if (max % min == 0)
        return min;
    return gcd(min, max%min);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int firstring;
    cin >> firstring;
    for (int i=0; i < n - 1; i++)
    {
        int ring;
        cin >> ring;
        
        int div = gcd(firstring, ring);
        cout << firstring / div << '/' << ring / div << '\n';
    }
}