//https://www.acmicpc.net/problem/2565

/*

동적 계획법을 이용한 풀이 (LIS 응용)


없애야하는 전깃줄의 최대 개수를 구하기 위해서는 
전체 전깃줄 갯수에서 서로 교차하지 않고 놓일 수 있는 
경우의 수 중 최대 개수를 빼면 됨

계산상 편의를 위해 전깃줄을 왼쪽 기준으로 정렬하고 시작

각 루트를 비교하기 위해 전깃줄 개수만큼의 루트 배열 routes를 선언
루트 배열의 각 인덱스는 해당 전깃줄까지 존재한다고 가정했을 때
서로 교차하지 않고 놓일 수 있는 최적 루트

따라서 루트 배열의 점화식은 다음과 같음
(교차하지 않는 전깃줄을 구하는 함수를 NOCROSS(시작 인덱스, 끝 인덱스),
최적 루트 (가장 개수가 많은 루트)을 구하는 함수를 MAX라고 정의)
routes[i] = MAX(NOCROSS(0, i - 1)) + 1 -> 최적 루트에 현재 전깃줄을 포함시킨 것으로, 1을 더함
result = length - MAX(0, length - 1) -> 최적 루트를 찾아 전깃줄 개수에서 최적 루트값을 뺀 것을 결과값으로 산출

e.g.

input:
8
1 8
3 9
2 2
4 1
6 4
10 10
9 7
7 6

routes:
1 1 2 1 2 3 4 5

output:
3

*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solve(vector<pair<int, int>> cables, int length)
{
    int *routes = new int[length];
    int max = 0;
    for (int i=0; i < length; i++)
    {
        int maxroute = 0;
        for (int j=i-1; j >= 0; j--)
        {
            if (cables[j].first < cables[i].first
            && cables[j].second < cables[i].second
            && routes[j] > maxroute)
                maxroute = routes[j];
        }
        routes[i] = maxroute + 1;
        max = routes[i] > max ? routes[i] : max;
    }

    /*for (int i=0; i < length; i++)
        cout << routes[i] << ' ';
    cout << '\n';*/

    return length - max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<int, int>> v;
    for (int i=0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    sort(v.begin(), v.end());
    cout << solve(v, n) << '\n';
}