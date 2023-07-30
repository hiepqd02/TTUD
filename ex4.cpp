
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// Định nghĩa cấu trúc của một điểm chứa hàng
struct Point {
    int index; // chỉ số của điểm chứa hàng
    int quantity; // lượng hàng tại điểm chứa hàng
    };
// Định nghĩa cấu trúc của một cạnh trong đồ thị
struct Edge {
    int destination; // đích của cạnh
    int distance; // khoảng cách từ điểm xuất phát đến đích
    };
// Hàm tìm lộ trình ngắn nhất từ điểm 0 đến điểm n
vector<int> findShortestPath(vector<vector<Edge>>& graph, int n) {
    vector<int> distance(n + 1, INT_MAX); // khoảng cách tạm thời từ điểm 0 đến các điểm khác
    vector<int> previous(n + 1, -1); // điểm trước đó trên lộ trình ngắn nhất từ điểm 0 đến các điểm khác
    vector<bool> visited(n + 1, false); // danh sách các điểm đã được xét
    // Đặt khoảng cách từ điểm 0 đến chính nó là 0
    distance[0] = 0;
    // Sử dụng hàng đợi ưu tiên để thực hiện thuật toán Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, 0));
    while (!pq.empty()) {
        int current = pq.top().second;
        pq.pop();
        if (visited[current]) {
            continue;
            }
        visited[current] = true;
        for (const Edge& edge : graph[current]) {
            int destination = edge.destination;
            int newDistance = distance[current] + edge.distance;
            if (newDistance < distance[destination]) {
                distance[destination] = newDistance;
                previous[destination] = current;
                pq.push(make_pair(newDistance, destination));
                }
            }
        }
    // Tạo lộ trình từ điểm n về điểm 0
    vector<int> path;
    int current = n;
    while (current != 0) {
        path.push_back(current);
        current = previous[current];
        }
    // Đảo ngược lộ trình để có thứ tự từ điểm 0 đến điểm n
    reverse(path.begin(), path.end());
    return path;
    }
int main() {
    int n; // số điểm chứa hàng
    int Q; // lượng hàng cần lấy
    cin >> n >> Q;
    vector<Point> points(n + 1); // danh sách các điểm chứa hàng
    vector<vector<Edge>> graph(n + 1); // đồ thị lưu trữ thông tin về khoảng cách giữa các điểm
    // Đọc thông tin về lượng hàng tại từng điểm chứa hàng
    for (int i = 1; i <= n; i++) {
        cin >> points[i].quantity;
        }
    // Đọc thông tin về khoảng cách giữa các điểm
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            int distance;
            cin >> distance;
            if (distance != 0) {
                graph[i].push_back({ j, distance });
                }
            }
        }
    // Tìm lộ trình ngắn nhất
    vector<int> shortestPath = findShortestPath(graph, n);
    // Tính tổng độ dài quãng đường và lượng hàng đã lấy trên lộ trình
    int totalDistance = 0;
    int totalQuantity = 0;
    for (int i = 0; i < shortestPath.size(); i++) {
        int index = shortestPath[i];
        totalDistance += graph[i][index].distance;
        totalQuantity += points[index].quantity;
        }
    // Kiểm tra nếu tổng lượng hàng đã lấy đủ và in ra kết quả
    if (totalQuantity >= Q) {
        cout << "Total distance: " << totalDistance << endl;
        cout << "Shortest path: ";
        for (int i = 0; i < shortestPath.size(); i++) {
            cout << shortestPath[i] << " ";
            }
        cout << endl;
        }
    else {
        cout << "Not enough quantity of goods." << endl;
        }
    return 0;
    }