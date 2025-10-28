#include <bits/stdc++.h>
using namespace std;

map<int, bool> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<int> vec;
    for(int i=0 ; i<n ; i++)
        vec.push_back(i);

    mp[m] = true;
    int ans = 1;

    for(int i=m+1 ; i<n ; i++)
    {
        if( mp[(i - 1) / 2])
        {
            mp[i] = true;
            ans++;
        }
    }

    cout << n - ans << "\n";
    
    for(int i=0 ; i<n ; i++)
    {
        if(!mp[i])
            cout << i << " ";
    }
    return 0;
}