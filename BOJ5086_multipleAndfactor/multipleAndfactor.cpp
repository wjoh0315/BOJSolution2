//https://www.acmicpc.net/problem/5086
#include <iostream>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b;
    while (true)
    {
        cin >> a >> b;
        if (a == 0 && b == 0)
            break;
        
        // 1. 첫번째 숫자가 두번째 숫자의 약수이다.
        if (b % a == 0)
            cout << "factor" << '\n';
        // 2. 첫번째 숫자가 두번째 숫자의 배수이다.
        else if (a % b == 0)
            cout << "multiple" << '\n';
        // 3. 첫번째 숫자가 두번째 숫자의 약수와 배수 모두 아니다.
        else 
            cout << "neither" << '\n';
    }
}