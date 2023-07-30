#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
bool visited[1001];
int height[1001];
void input()
    {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        }
    memset(visited, false, sizeof(visited));
    }

void bfs(int u)
    {
    height[u] = 0;
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
        {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
            if (!visited[x])
                {
                q.push(x);
                visited[x] = true;
                }
        height[u]++;
        }
    cout << height[u] << "jehje";
    }

int main()
    {
    input();
    bfs(1);
    return 0;
    }