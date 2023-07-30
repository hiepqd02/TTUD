#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MaxN = 1 + 1e2;
const ll INF = 1e18;

int n, m, s;
bool mark[MaxN];
ll dist[MaxN];
vector<pair<int, int>> adj[MaxN];

void Dijkstra(int s) {
    fill(dist + 1, dist + n + 1, INF);
    dist[s] = 0;

    for (int i = 1; i <= n; ++i) {
        int v = -1;
        for (int j = 1; j <= n; ++j) {
            if (!mark[j] && (v == -1 || dist[j] < dist[v])) v = j;
            }
        if (v == -1) break;
        mark[v] = 1;
        for (auto u : adj[v]) {
            if (mark[u.first]) continue;
            dist[u.first] = min(dist[u.first], dist[v] + u.second);
            }
        }
    }

int main() {
    // freopen("CTDL.inp", "r", stdin);
    // freopen("CTDL.out", "w", stdout);
    cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({ v, w });
        }
    Dijkstra(s);
    for (int i = 1; i <= n; ++i) {
        if (dist[i] == INF) cout << -1 << endl;
        else cout << dist[i] << endl;
        }

    return 0;
    }
