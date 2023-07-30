#include <bits/stdc++.h>
using namespace std;


int m, n;
vector<pair<int, int>> adj[1001];
bool used[1001];

struct edge {
    int x, y;
    int w;
    };
void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({ y, w });
        adj[y].push_back({ x, w });
        }
    memset(used, false, sizeof(used));
    }


void prim(int u) {
    vector<edge> MST;
    int d = 0;
    used[u] = true;
    while (MST.size() < n - 1) {
        int min_w = INT_MAX;
        int X, Y;
        for (int i = 1; i <= n; i++)
            {
            if (used[i])
                for (pair<int, int> it : adj[i]) {
                    int j = it.first;int weight = it.second;
                    if (!used[j] && weight < min_w) {
                        min_w = weight;
                        X = j; Y = i;
                        }
                    }
            }

        MST.push_back({ X,Y,min_w });
        d += min_w;
        used[X] = true;
        }

    cout << d << endl;
    for (auto e : MST) {
        cout << e.x << " " << e.y << " " << e.w << endl;
        }
    }



int main() {
    input();
    prim(1);
    return 0;
    }
// 


// 6 9
// 1 2 9
// 1 3 4
// 2 3 1
// 2 4 6
// 2 5 3
// 3 5 2
// 4 5 3
// 4 6 10
// 5 6 8 