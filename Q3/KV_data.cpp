#include <bits/stdc++.h>
using namespace std;

//  pos             ver, val
map<int, vector<pair<int, int>>> kv_map;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q, id_ver = 0;
    cin >> q;

    while (q--)
    {
        char s;
        cin >> s;

        // pos, val
        if(s == 'U')
        {
            int pos, val;
            cin >> pos >> val;

            kv_map[pos].push_back({++id_ver, val});
        }

        // pos, ver
        if(s == 'A')
        {
            int pos, ver;
            cin >> pos >> ver;

            if(kv_map.find(pos) == kv_map.end())
            {
                cout << "-1\n";
                continue;
            }

            int it = upper_bound(kv_map[pos].begin(), kv_map[pos].end(), make_pair(ver, (int)2e9)) - kv_map[pos].begin();

            if(it == 0)
            {
                cout << "-1\n";
            }
            else
            {
                cout << kv_map[pos][it - 1].second << "\n";
            }
        }
    }

    return 0;
}