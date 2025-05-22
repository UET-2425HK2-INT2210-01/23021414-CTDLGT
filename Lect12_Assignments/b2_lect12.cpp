#include <iostream>
using namespace std;

// Cấu trúc cạnh
struct Edge {
    int u, v, w;
} edges[10001];

int parent[1001];
int find(int x) {
    if (parent[x] != x) parent[x] = find(parent[x]);
    return parent[x];
}
void unite(int x, int y) {
    parent[find(x)] = find(y);
}

// Sắp xếp nhanh (QuickSort) cho danh sách cạnh
void quickSort(int l, int r) {
    if (l >= r) return;
    int pivot = edges[(l + r) / 2].w;
    int i = l, j = r;
    while (i <= j) {
        while (edges[i].w < pivot) i++;
        while (edges[j].w > pivot) j--;
        if (i <= j) {
            swap(edges[i], edges[j]);
            i++; j--;
        }
    }
    quickSort(l, j); quickSort(i, r);
}

int main() {
    freopen("connection.txt", "r", stdin);
    freopen("connection.out", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    
    // Đọc danh sách cạnh
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    // Khởi tạo Union-Find
    for (int i = 1; i <= n; i++) parent[i] = i;
    
    // Sắp xếp cạnh theo trọng số
    quickSort(0, m - 1);
    
    // Chọn cạnh cho MST
    int total = 0, selected[10001], cnt = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (find(u) != find(v)) {
            unite(u, v);
            total += w;
            selected[cnt++] = i;
        }
    }
    
    cout << total << endl;
    for (int i = 0; i < cnt; i++) {
        int idx = selected[i];
        cout << edges[idx].u << " " << edges[idx].v << " " << edges[idx].w << endl;
    }
    
    return 0;
}