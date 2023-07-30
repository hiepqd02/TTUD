#include <bits/stdc++.h>
using namespace std;

const int maxn = 100001;
int n, m;
vector<int> adj[maxn], r_adj[maxn];
bool visited[maxn];
stack<int> st;

// Nhap input
void inp()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        r_adj[y].push_back(x);
    }
}

void dfs1(int u)
{
    visited[u] = true;
    for (int v : adj[u])
    {
        if (!visited[v])
        {
            dfs1(v);
        }
    }
    // da duyet xong dinh u
    st.push(u);
}

void dfs2(int u)
{
    cout << u << " ";
    visited[u] = true;
    for (int v : r_adj[u])
    {
        if (!visited[v])
        {
            dfs2(v);
        }
    }
}

void SCC()
{
    memset(visited, false, sizeof(visited));
    // B1 : Goi thuat toan dfs tren do thi ban dau
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            dfs1(i);
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    while (!st.empty())
    {
        int u = st.top();
        st.pop();
        if (!visited[u])
        {
            dfs2(u);
            cout << endl;
            cnt++;
        }
    }

    cout << cnt;
}

int main()
{
    inp();
    SCC();
}