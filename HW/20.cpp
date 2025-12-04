#include <iostream>

using namespace std;

int counts[1000005]; 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
        cin >> Q;

    int even_group = 0; // E
    int odd_group = 0;  // O

    while (Q--)
    {
        int x;
        cin >> x;

        if (counts[x] == 0)
        {
            odd_group++;
        } 
        else
        {
            if (counts[x] % 2 != 0)
            {
                odd_group--;
                even_group++;
            }
            else
            {
                even_group--;
                odd_group++;
            }
        }
        counts[x]++;

        cout << even_group << " " << odd_group << "\n";
    }
    return 0;
}