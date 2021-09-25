//https://www.acmicpc.net/problem/2981
#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int gcd(int a, int b)
{
    int max = a>b?a:b;
    int min = a<b?a:b;
    if (max % min == 0)
        return min;
    return gcd(min, max%min);
}

void solve(int *nums, int n)
{
    /*
        p는 공약수,
        q는 ([i] - r)/p 
        ([i]에서 p가 포함된 갯수로, p에 종속),
        나머지 r이 일정할 때

        [0] = pq_0 + r
        [1] = pq_1 + r
        [i] = pq_i + r

        인접항 간의 차이는 
        pq_(i-1) - pq_i = p(q_(i-1) - q_i)

        따라서 나머지 r을 몰라도 공약수 p가
        항상 포함되므로 인접항의 차이끼리 공약수를 구하면
        나머지가 모두 같은 M을 구할 수 있음.
    */

    int *de = new int[n - 1];
    for (int i=1; i < n; i++)
        de[i - 1] = abs(nums[i] - nums[i - 1]);

    int result = de[0];
    for (int i=1; i < n - 1; i++)
        result = gcd(result, de[i]);

    vector<int> factor;
    factor.push_back(result);
    for (int i=2; i < floor(sqrt(result) + 1); i++)
    {
        if (result % i == 0)
        {
            factor.push_back(i);
            if (i * i != result)
                factor.push_back(result / i);
        }
    }

    sort(factor.begin(), factor.end(), [](int a, int b){return a > b;});
    for (int i=factor.size() - 1; i >= 0; i--)
        cout << factor[i] << ' ';
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *nums = new int[n];
    for (int i=0; i < n; i++)
        cin >> nums[i];

    solve(nums, n);
    cout << '\n';
}