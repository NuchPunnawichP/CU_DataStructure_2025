#include <bits/stdc++.h>

using namespace std;

void fastC();

void solve()
{
    // solve problem here
    int n;
    cin >> n;

    int ch = 1;

    while(ch < n)
    {
        ch *= 2;
    }

    cout << ch - n;
}

int main()
{
    fastC();
    solve();
    return 0;
}

void fastC()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}