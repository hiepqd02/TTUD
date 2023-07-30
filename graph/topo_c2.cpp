#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
int in[1001];
queue<int> q;
vector<int> ans;
void input()
    {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        in[y]++;
        }
    }

void kahn()
    {
    for (int i = 1; i <= n; i++)
        {
        if (in[i] == 0)
            {
            q.push(i);
            }
        }

    while (!q.empty())
        {
        int v = q.front();
        ans.push_back(v);
        q.pop();
        for (int x : adj[v])
            {
            in[x]--;
            if (in[x] == 0)
                {
                q.push(x);
                }
            }
        }

    for (int i : ans)
        {
        cout << i << ' ';
        }
    }

int main()
    {
    input();
    kahn();
    }