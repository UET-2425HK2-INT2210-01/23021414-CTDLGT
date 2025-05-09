#include <iostream>
using namespace std;

const int MAXN = 1005;
int adj[MAXN][MAXN];   // Ma trận kề: lưu cạnh có hướng từ x -> y
bool visited[MAXN];    // Mảng đánh dấu đã thăm đỉnh nào chưa
int dist[MAXN];        // dist[i] là số cạnh ngắn nhất từ X đến i

int queue[MAXN];       // Hàng đợi để duyệt BFS (giả lập queue)
int front = 0, back = 0;

int main() {
    int n, m, X, Y;
    cin >> n >> m >> X >> Y;

    // Nhập cạnh có hướng vào ma trận kề
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1;
    }

    // Khởi tạo BFS
    visited[X] = true;
    dist[X] = 0;
    queue[back++] = X;  // Thêm X vào hàng đợi

    // BFS bắt đầu
    while (front < back) {
        int u = queue[front++];  // Lấy phần tử đầu hàng đợi

        // Duyệt các đỉnh kề u
        for (int v = 1; v <= n; ++v) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = true;
                dist[v] = dist[u] + 1;  // Cập nhật khoảng cách
                queue[back++] = v;     // Thêm v vào hàng đợi
            }
        }
    }

    if (visited[Y]) {
        cout << dist[Y] << endl;
    } else {
        cout << -1 << endl;  // Không có đường đi từ X đến Y
    }

    return 0;
}
