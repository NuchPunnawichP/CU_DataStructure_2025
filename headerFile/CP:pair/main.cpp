#include <iostream>
#include "pair.h"

using namespace std;
using namespace CP;

void fastC();

void solve()
{
    // solve here
    CP::pair<int, int> x, y;
    
    cin >> x.first >> x.second >> y.first >> y.second;

    cout << (x != y) << "\n";
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
    cin.tie(NULL);
}