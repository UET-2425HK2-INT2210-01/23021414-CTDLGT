#include <iostream>
using namespace std;

// Mảng lưu danh sách kề (tối đa 1000 công việc và 10000 cạnh)
int adj[1001][1001]; // lưu các đỉnh kề
bool visited[1001];
int result[1001], result_size = 0;
int n;

// Hàm DFS để tìm thứ tự tô pô
void dfs(int u) {
    // Đánh dấu đỉnh u là đã thăm
    visited[u] = true;
    
    // Duyệt qua các đỉnh kề của u
    for (int i = 1; i <= adj[u][0]; i++) {
        int v = adj[u][i];
        if (!visited[v]) {
            dfs(v);
        }
    }
    
    // Thêm u vào kết quả (theo thứ tự ngược)
    result[++result_size] = u;
}

int main() {
    // Chuyển hướng input/output tới file
    freopen("jobs.txt", "r", stdin);
    freopen("jobs.out", "w", stdout);
    
    int m;
    cin >> n >> m;
    
    // Khởi tạo mảng visited và danh sách kề
    for (int i = 1; i <= n; i++) {
        visited[i] = false;
        adj[i][0] = 0; // Số đỉnh kề ban đầu là 0
    }
    
    // Đọc danh sách cạnh
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u][++adj[u][0]] = v; // Thêm v vào danh sách kề của u
    }
    
    // Thực hiện DFS từ mỗi đỉnh chưa thăm
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    
    // Ghi kết quả (đảo ngược thứ tự)
    for (int i = result_size; i >= 1; i--) {
        cout << result[i];
        if (i > 1) cout << " ";
    }
    cout << endl;
    
    return 0;
}