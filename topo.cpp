#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Function to perform DFS
void dfs(vector<vector<int>> &graph, vector<bool> &visited, stack<int> &stk, int node)
{
    visited[node] = true;

    // Visit all the adjacent nodes
    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(graph, visited, stk, neighbor);
        }
    }

    // Push the current node to the stack after visiting all its neighbors
    stk.push(node);
}

// Function to perform topological sort
vector<int> topologicalSort(vector<vector<int>> &graph, int numNodes)
{
    vector<bool> visited(numNodes, false);
    stack<int> stk;

    // Perform DFS on each unvisited node
    for (int i = 0; i < numNodes; i++)
    {
        if (!visited[i])
        {
            dfs(graph, visited, stk, i);
        }
    }

    // Create the resulting topological order from the stack
    vector<int> result;
    while (!stk.empty())
    {
        result.push_back(stk.top());
        stk.pop();
    }

    return result;
}

int main()
{
    int numNodes, numEdges;
    cout << "Enter the number of nodes: ";
    cin >> numNodes;
    cout << "Enter the number of edges: ";
    cin >> numEdges;

    vector<vector<int>> graph(numNodes);

    cout << "Enter the edges (u v):\n";
    for (int i = 0; i < numEdges; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

    vector<int> topoSort = topologicalSort(graph, numNodes);

    cout << "Topological Sort: ";
    for (int node : topoSort)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
