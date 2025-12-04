#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int Q;
    cin >> Q;

    vector<int> numbers;
    vector<int> freqs;

    int even_group = 0; // E
    int odd_group = 0;  // O

    while (Q--)
    {
        int x;
        cin >> x;

        bool found = false;
        
        for (size_t i = 0; i < numbers.size(); i++) {
            if (numbers[i] == x)
            {
                if (freqs[i] % 2 != 0)
                {
                    odd_group--;
                    even_group++;
                }
                else
                {
                    even_group--;
                    odd_group++;
                }
                freqs[i]++;
                found = true;
                break;
            }
        }

        if (!found)
        {
            numbers.push_back(x);
            freqs.push_back(1);
            odd_group++;
        }
        cout << even_group << " " << odd_group << "\n";
    }
    return 0;
}