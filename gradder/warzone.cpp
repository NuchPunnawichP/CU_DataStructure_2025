#include <bits/stdc++.h>
using namespace std;

void fastC();

void solved()
{
    // Solve the problem here
    int n, q;
    cin >> n >> q;
    int ans = n;

    set<pair<int, int>> st;
    while(q--)
    {
        //int op;
        //cin >> op;

        //if(op == 1)
        //{
            int x, y;
            cin >> x >> y;

            st.insert({x, 0});
            st.insert({y, 1});

            // position for checking
            // ... itx2 itx1 it1 .... it2 ity1 ity2 ....
            auto it1 = st.find({x, 0});
            auto it2 = st.find({y, 1});

            // adjusting iterator of x positioning
            auto itx1 = it1;
            auto itx2 = it1;
            if(it1 != st.begin())
            {
                itx1--;
                if(itx1 != st.begin())
                {
                    itx2 = itx1;
                    itx2--;
                }
            }

            // adjusting iterator of y positioning
            auto ity1 = it2;
            auto ity2 = it2;
            ++ity1;
            if(ity1 != st.end())
            {
                ity2 = ity1;
                ++ity2;
                if(ity2 == st.end())
                    ity2 = ity1;
            }
            else
            {
                ity1--;
                ity2 = ity1;
            }

            // ... itx2 itx1 it1 .... it2 ity1 ity2 ....
            if(it1 != itx1)
            {
                if(itx1 != itx2)
                {
                    if(itx1->second == 0)
                    {
                        it1 = itx1;
                        x = itx1->first;
                    }
                    else if(itx1->second == 1 && it1->first - itx1->first <= 1)
                    {
                        it1 = itx2;
                        x = itx2->first;
                    }
                }
                else
                {
                    it1 = itx1;
                    x = itx1->first;
                }
            }

            // ... itx2 itx1 it1 .... it2 ity1 ity2 ....
            if(it2 != ity1)
            {
                if(ity1 != ity2)
                {
                    if(ity1->second == 1)
                    {
                        it2 = ity1;
                        y = ity1->first;
                    }
                    else if(ity1->second == 0 && ity1->first - it2->first <= 1)
                    {
                        it2 = ity2;
                        y = ity2->first;
                    }
                }
                else
                {
                    it2 = ity1;
                    y = ity1->first;
                }
            }

            ++it2;
            for(auto itl = it1; ; ) {
                auto itr = itl;
                itr++;
                ans += itr->first - itl->first + 1;
                if(++itr == it2) {
                    break;
                }
                cout << itl->first <<" " << itr->first << " " << it1->first << " " << it2->first << "\n";
                itl++, itl++;
            }
            ans -= it2->first - it1->first + 1;
            st.erase(it1, it2);

            st.insert({x, 0});
            st.insert({y, 1});
        //}
        //else
        //{
            cout << st.size() / 2 << "\n";
        //}
    }
}

main(){
    //fastC();
    solved();
    return 0;
}

void fastC()
{
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
}

/*

*/
