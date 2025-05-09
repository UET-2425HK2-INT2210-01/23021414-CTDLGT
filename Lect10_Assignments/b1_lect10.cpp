#include <iostream>
using namespace std;

const int MAXN = 1005;  // Giới hạn tối đa số đỉnh
int adj[MAXN][MAXN];    // Ma trận kề để lưu các cạnh giữa các đỉnh
bool visited[MAXN];     // Mảng đánh dấu đỉnh đã được thăm hay chưa
int n, m;               //số đỉnh,số cạnh

// Hàm duyệt DFS từ đỉnh u
void dfs(int u) {
    visited[u] = true;  // Đánh dấu đã thăm đỉnh u

    // Duyệt tất cả các đỉnh v từ 1 đến n
    for (int v = 1; v <= n; ++v) {
        // Nếu có cạnh từ u đến v và v chưa được thăm
        if (adj[u][v] && !visited[v]) {
            dfs(v);  // Gọi đệ quy DFS từ đỉnh v
        }
    }
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        adj[x][y] = 1;
        adj[y][x] = 1;  // là đồ thị vô hướng nên gán cả 2 chiều
    }

    int components = 0;  // Biến đếm số thành phần liên thông

    // Duyệt qua tất cả các đỉnh
    for (int i = 1; i <= n; ++i) {
        // Nếu đỉnh i chưa được thăm thì đó là một thành phần mới
        if (!visited[i]) {
            dfs(i);       // Thăm toàn bộ thành phần liên thông chứa đỉnh i
            components++; // Tăng biến đếm thành phần liên thông
        }
    }

    // In ra số thành phần liên thông
    cout << components << endl;

    return 0;
}
