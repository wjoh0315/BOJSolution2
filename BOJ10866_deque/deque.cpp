//https://www.acmicpc.net/problem/10866
#include <iostream>
#include <string>
#define MAXSIZE 10000
using namespace std;

class deque
{
    private:
        int mfront;
        int mrear;
        int mdeque[MAXSIZE];

    public:
        deque()
        {
            mfront = 0;
            mrear = 0;
        }

        bool isfull()
        {
            return (mrear + 1) % MAXSIZE == mfront;
        }

        int size()
        {
            return mfront > mrear ? MAXSIZE - mfront + mrear
                : mrear - mfront;
        }

        bool empty()
        {
            return mfront == mrear;
        }

        void push_front(int x)
        {
            if (isfull())
                return;
            mdeque[mfront] = x;
            mfront = (mfront - 1 + MAXSIZE) % MAXSIZE;
        }

        void push_back(int x)
        {
            if (isfull())
                return;
            mrear = (mrear + 1) % MAXSIZE;
            mdeque[mrear] = x;
        }

        int pop_front()
        {
            if (empty())
                return -1;
            mfront = (mfront + 1) % MAXSIZE;
            return mdeque[mfront];
        }

        int pop_back()
        {
            if (empty())
                return -1;
            int tmp = mdeque[mrear];
            mrear = (mrear - 1 + MAXSIZE) % MAXSIZE;
            return tmp;
        }

        int front()
        {
            if (empty())
                return -1;
            return mdeque[(mfront + 1) % MAXSIZE];
        }

        int back()
        {
            if (empty())
                return -1;
            return mdeque[mrear];
        }
};

void solve()
{
    int n;
    cin >> n;

    deque dq;
    string cmd;
    int tmp;
    for (int i=0; i < n; i++)
    {
        cin >> cmd;
        if (cmd == "push_front")
        {
            cin >> tmp;
            dq.push_front(tmp);
        }
        else if (cmd == "push_back")
        {
            cin >> tmp;
            dq.push_back(tmp);
        }
        else if (cmd == "pop_front")
        {
            cout << dq.pop_front() << '\n';
        }
        else if (cmd == "pop_back")
        {
            cout << dq.pop_back() << '\n';
        }
        else if (cmd == "size")
        {
            cout << dq.size() << '\n';
        }
        else if (cmd == "empty")
        {
            cout << dq.empty() << '\n';
        }
        else if (cmd == "front")
        {
            cout << dq.front() << '\n';
        }
        else if (cmd == "back")
        {
            cout << dq.back() << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    solve();
}