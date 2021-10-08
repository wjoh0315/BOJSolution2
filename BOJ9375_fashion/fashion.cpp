//https://www.acmicpc.net/problem/9375
#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int i=0; i < t; i++)
    {
        int n;
        cin >> n;

        string *arr = new string[n];
        map<string, int> clothes;
        for (int j=0; j < n; j++)
        {
            cin >> arr[j] >> arr[j];
            if (clothes.find(arr[j]) == clothes.end())
                clothes.insert({arr[j], 1});
            else
                clothes[arr[j]]++;
        }

        int result = 1;
        for (map<string, int>::iterator j=clothes.begin(); j != clothes.end(); j++)
            result *= (*j).second + 1;
        cout << result - 1 << '\n';
    }
}