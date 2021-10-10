//https://www.acmicpc.net/problem/18258
#include <iostream>
#include <list>
using namespace std;

class queue
{
    private:
        list<int> mqueue;
    
    public:
        void push(int x) { mqueue.push_back(x); }
        int pop() 
        { if (mqueue.empty()) return -1;
          int tmp = mqueue.front(); mqueue.pop_front(); return tmp; }
        int size() { return mqueue.size(); }
        int empty() { return mqueue.empty(); }
        int front() { return mqueue.empty() ? -1 : mqueue.front(); }
        int back() { return mqueue.empty() ? -1 : mqueue.back(); }
};

void solve()
{
    int n;
    cin >> n;

    int tmp;
    string cmd;
    queue q;
    for (int i=0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push")
        {
            cin >> tmp;
            q.push(tmp);
        }
        else if (cmd == "pop")
            cout << q.pop() << '\n';
        else if (cmd == "size")
            cout << q.size() << '\n';
        else if (cmd == "empty")
            cout << q.empty() << '\n';
        else if (cmd == "front")
            cout << q.front() << '\n';
        else if (cmd == "back")
            cout << q.back() << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}