//https://www.acmicpc.net/problem/1912

/*

동적 계획법을 이용한 풀이


수열의 최대 연속합을 구하기 위해서는
유망성을 판단해 연속합이 최대가 되는 루트를 선택하면 된다.

따라서 현재 수열항, 현재 수열항까지의 연속합을 비교하여
더 큰 값이 유망성있는 루트로, 이와 같은 과정을 반복하여 최댓값을 구한다.
(현재 수열항까지의 연속항보다 현재 수열항이 더 큰 경우 
연속합을 계속 구해봤자 손해이기 때문)

수열 A에서 루트 배열 R의 점화식은 다음과 같다. (i > 0)
R[0] = A[0]
R[i] = MAX(R[i - 1] + A[i], A[i])

e.g.

input:
10 -4 3 1 5 6 -35 12 21 -1

routes:
10 6 9 10 15 21 -14 12 33 32

output:
33

*/

#include <iostream>
using namespace std;

int solve(int *arr, int length)
{
    int max;
    int *routes = new int[length];
    routes[0] = arr[0];
    max = routes[0];
    for (int i=1; i < length; i++)
    {
        routes[i] = routes[i - 1] + arr[i] > arr[i]
            ? routes[i - 1] + arr[i] : arr[i];
        max = routes[i] > max ? routes[i] : max;
    }
    return max;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    int *inarr = new int[n];
    for (int i=0; i < n; i++)
        cin >> inarr[i];

    cout << solve(inarr, n) << '\n';
}