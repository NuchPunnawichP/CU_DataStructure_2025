#include <bits/stdc++.h>

using namespace std;

void fastCin();

void solve()
{
    // solve the problem here

    // use in every 1 question
    int from = 1, to = 5;
    
    /*
    // 1.1
    stack<vector<int>> a, tmp;
    a.push({1, 2, 3});
    
    while(!a.empty())
    {
        vector<int> tmp_vec(a.top().size());
        for(int i=0 ; i<a.top().size() ; i++)
        {
            if(a.top()[i] == from)
                tmp_vec[i] - to;
            else
                tmp_vec[i] = a.top()[i];
        }
        tmp.push(tmp_vec);
        a.pop();
    }
    
    while(!tmp.empty())
    {
        a.push(tmp.top());
        tmp.pop();
    }
    */
    /*
    // 1.2
    priority_queue<pair<int, char>> a;
    stack<pair<int, char>> tmp;
    while(!a.empty())
    {
        pair<int, char> tmp_p;
        if(a.top().first == from)
            tmp_p = make_pair(to, a.top().second);
        else
            tmp_p = make_pair(a.top().first, a.top().second);
        a.pop();
        tmp.push(tmp_p);
    }

    while(!tmp.empty())
    {
        a.push(tmp.top());
        tmp.pop();
    }
    */

    /*
    // 1.3
    map<int, vector<pair<char, int>>> a;
    //a[0].push_back(make_pair('a', 2));
    for(auto x : a) // loop key for access vector
    {
        //cout << x.second[0].first;
        for(auto y : x.second)
        {
            if(y.second == from)
                y.second = to;
        }
    }
    */
    /*
    // 2.1
    map<string, vector<int>> data;
    for(auto it = data.begin() ; it != data.end() ; )
    {
        if(it->second.size() < 5)
            it = data.erase(it);
        else
            ++it;
    }
    */
   /**/
   // 2.2
   
};

int main()
{
    fastCin();
    solve();
    return 0;
}

void fastCin()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}