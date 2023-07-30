#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool visited[1001];

// example input
// 9 9
// 1 2
// 1 3
// 1 5
// 2 4
// 3 6
// 3 7
// 3 9
// 5 8
// 8 9
void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    memset(visited, false, sizeof(visited));
}

bool dfs(int u, int dir_par)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            // return dfs(x, u); toac
            if (dfs(v, u))
                return true;
        }
        else if (v != dir_par)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    input();
    if (dfs(1, 0))
        cout << "yes";
    else
    {
        cout << "no";
    }

    return 0;
}

// 7 6
// 1 2
// 2 3
// 2 4
// 3 6
// 6 7
// 7 3