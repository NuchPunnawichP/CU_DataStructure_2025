#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
//your code here
    v[-1] = -1;

    if(v.count(pos))
    {
        auto it1 = v.end();
        --it1;

        auto it2 = v.find(pos);
        --it2;

        for(it1 ; it1 != it2 ; it1--)
        {
            int p = it1->first;
            int val = it1->second;

            v.erase(it1);
            v[p + 1] = val;
        }

        v[pos] = value;
    }
    else
    {
        v[pos] = value;
    }
    v.erase(v.begin());
}
int main() {
ios_base::sync_with_stdio(false);cin.tie(0);
int n;
map<int,int> v;
cin >> n;
for (int i = 0;i < n;i++) {
int a,b;
cin >> a >> b;
insert_into_sv(v,a,b);
}
cout << v.size() << "\n";
for (auto &x : v) {
cout << x.first << ": " << x.second << "\n";
}
}

/*
6
2 10
5 30
10 7
11 8
20 9
5 999
*/