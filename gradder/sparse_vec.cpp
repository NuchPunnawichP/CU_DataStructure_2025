#include <iostream>
#include <vector>
#include <map>
using namespace std;
void insert_into_sv(map<int,int> &v, int pos, int value) {
//your code here
    vector<pair<int,int>> temp;
    auto it = v.lower_bound(pos);
    
    while(it != v.end())
    {
        temp.push_back({it->first + 1, it->second});
        it = v.erase(it);
    }
    v.insert({pos, value});
    
    for(auto &p : temp)
    {
        v.insert(p);
    }
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