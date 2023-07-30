#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool visited[1001];
stack<int> ans;
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
}

void dfs(int u)
{
    visited[u] = true;
    for (int x : adj[u])
    {
        if (!visited[x])
        {
            dfs(x);
        }
    }
    ans.push(u);
}

int main()
{
    input();
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i);
        }
    }

    if (ans.size() == n)
    {
        for (int i = 0; i < n; i++)
        {
            int v = ans.top();
            ans.pop();
            cout << v << " ";
        }
    }
    else
    {
        cout << "false";
    }

    return 0;
}

// 4 4 0 1 0 2 3 1 1 2