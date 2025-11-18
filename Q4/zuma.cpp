#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;

    Node(int d = 0, Node* p = NULL, Node* n = NULL) 
        : data(d), prev(p), next(n) {}
};

void fastC();

void solve()
{
    // solve
    Node *head = new Node;
    Node *p = head;

    int n, k, v;
    cin >> n >> k >> v;

    // make linklist
    for(int i=0 ; i<n ; i++)
    {
        int x;
        cin >> x;

        if(i == 0)
        {
            p->data = x;
        }
        else
        {
            Node *newNode = new Node(x, p, NULL);
            p->next = newNode;
            p = newNode;
        }
    }

    // play
    Node *tmp = new Node();
}

int main()
{
    fastC();
    solve();
    return 0;
}

void fastC()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
}