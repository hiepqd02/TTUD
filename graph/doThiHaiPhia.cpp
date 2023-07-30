// #include <iostream>
// #include <queue>
// #include <vector>

// using namespace std;

// bool isBipartite(vector<vector<int>> &graph, int start)
// {
//     int n = graph.size();
//     vector<int> colors(n, -1); // -1: Chưa được tô màu, 0: Màu 1, 1: Màu 2

//     queue<int> q;
//     q.push(start);
//     colors[start] = 0;

//     while (!q.empty())
//     {
//         int node = q.front();
//         q.pop();

//         for (int neighbor : graph[node])
//         {
//             if (colors[neighbor] == -1)
//             {
//                 // Gán màu khác cho đỉnh láng giềng
//                 colors[neighbor] = 1 - colors[node];
//                 q.push(neighbor);
//             }
//             else if (colors[neighbor] == colors[node])
//             {
//                 // Đồ thị không phải là đồ thị hai phía
//                 return false;
//             }
//         }
//     }

//     return true;
// }

// int main()
// {
//     int n, m;
//     cout << "Nhập số đỉnh và số cạnh của đồ thị: ";
//     cin >> n >> m;

//     vector<vector<int>> graph(n);

//     cout << "Nhập các cạnh của đồ thị:\n";
//     for (int i = 0; i < m; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         graph[u].push_back(v);
//         graph[v].push_back(u);
//     }

//     bool isTwoColorable = true;
//     for (int i = 0; i < n; i++)
//     {
//         if (isBipartite(graph, i) == false)
//         {
//             isTwoColorable = false;
//             break;
//         }
//     }

//     if (isTwoColorable)
//     {
//         cout << "Đồ thị là đồ thị hai phía.\n";
//     }
//     else
//     {
//         cout << "Đồ thị không phải là đồ thị hai phía.\n";
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> adj[1001];
int color[1001];

// 0 : 1

// example input
// 10 11
// 1 2
// 1 3
// 1 5
// 1 10
// 2 4
// 3 6
// 3 7
// 3 9
// 6 7
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
    memset(color, -1, sizeof(color));
}

bool bfs(int u)
{
    queue<int> q;
    q.push(u);
    color[u] = 1;

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int x : adj[v])
        {
            if (color[x] == -1)
            {
                color[x] = 1 - color[v];
                q.push(x);
            }
            else if (color[x] == color[v])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    input();
    if (bfs(1))
    {
        cout << "okela";
    }
    else
        cout << "Toe";
    return 0;
}