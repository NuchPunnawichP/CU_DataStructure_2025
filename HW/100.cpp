#include <iostream>
#include <map>

using namespace std;

map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;

    int odd_group = 0, all = 0;
    while(q--)
    {
        int d;
        cin >> d;

        if(mp[d] == 0)
            all++;

        mp[d]++;

        if(mp[d] %2 != 0)
        {
            odd_group++;
        }
        else
            odd_group--;

        cout << (all - odd_group) << " " << odd_group << "\n";
    }
    return 0;
}
