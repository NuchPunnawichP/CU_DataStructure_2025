#include <bits/stdc++.h>
using namespace std;
int n, m;
int tables[2010]; // -1 = empty, -2 = deleted, >= 0 = data

int hashing(int x, int y)
{
    return (x % n + y*y) % n;
}

void insert_hash(int x)
{
    for(int i=0; i<n; i++)
    {
        int pos = hashing(x, i);
        if(tables[pos] < 0)
        {
            tables[pos] = x;
            return;
        }
    }
}

void delete_hash(int x)
{
    for(int i=0; i<n; i++)
    {
        int pos = hashing(x, i);
        if(tables[pos] == x)
        {
            tables[pos] = -2;
            return;
        }
        if(tables[pos] == -1)
            return;
    }
}

int findMx_insert(int x)
{
    int probes = 0;
    for (int j = 0; j < n; j++)
    {
        int pos = hashing(x, j);
        probes++;
        if (tables[pos] < 0)
        {
            return probes;
        }
    }
    return probes;
}

int findMx_find(int x)
{
    int probes = 0;
    for (int j = 0; j < n; j++)
    {
        int pos = hashing(x, j);
        probes++;

        if (tables[pos] == -1)
        {
            return probes;
        }
    }
    return probes;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++)
        tables[i] = -1;
    
    for(int i=0; i<m; i++)
    {
        int a, b;
        cin >> a >> b;

        if(a == 1) // insert
        {
            insert_hash(b);
        }
        else // delete
        {
            delete_hash(b);
        }
    }
    
    int max_insert = 0;
    for (int x = 0; x < n; x++)
    {
        int probes = findMx_insert(x);
        max_insert = max(max_insert, probes);
    }
    
    int max_find = 0;
    for (int x = 0; x < n; x++)
    {
        int probes = findMx_find(x);
        max_find = max(max_find, probes);
    }
    
    cout << max_insert << " " << max_find << "\n";
    return 0;
}