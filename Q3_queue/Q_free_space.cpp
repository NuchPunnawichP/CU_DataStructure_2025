#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int q;
    cin >> q;

    long long mSize = 0;
    long long mCap = 1;

    while(q--)
    {
        int pu, po;
        int cm;
        long long m;
        cin >> cm >> m;

        if(cm == 0) // push
        {
            mSize += m;
            if(mSize > mCap)
            {
                while (mCap < mSize)
                {
                    mCap *= 2;
                }
            }
        }
        else if(cm == 1) // pop
        {
            mSize -= m;
        }
    }
    cout << mCap - mSize;
    return 0;
}