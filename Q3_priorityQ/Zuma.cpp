#include <bits/stdc++.h>
using namespace std;

void bomb(vector<int> &vec, int k, int v);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, v;
    cin >> n >> k >> v;

    vector<int> vec(n);
    for(int i=0 ; i<n ; i++)
        cin >> vec[i];

    vec.insert(vec.begin() + k, v);
    bomb(vec, k, v);

    for(auto x : vec)
    {
        if(x != -1)
            cout << x << " ";
    }
    
    return 0;
}

void bomb(vector<int> &vec, int k, int v)
{
    // f2 f1 k|v b1 b2
    int ll = k, rr = k;

    while(true)
    {
        if(ll - 1 >= 0)
            if(vec[ll - 1] == v)
                ll--;
        
        if(rr + 1 <= vec.size() - 1)
            if(vec[rr + 1] == v)
                rr++;
        
        if(ll - 1 < 0 || rr + 1 == vec.size())
            break;
        
        if(ll - 1 >= 0 && rr + 1 <= vec.size() - 1)
        {
            if(vec[ll - 1] == vec[rr + 1])
                v = vec[ll - 1];
        }

        if(vec[ll] != vec[rr])
            break;
        
        cout << 
    }

    for(int i=ll ; i<=rr ; i++)
    {
        vec[i] = -1;
    }
};