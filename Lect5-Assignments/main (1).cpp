#include <iostream>

using namespace std;

// Định nghĩa cấu trúc nút cây nhị phân
struct TreeNode {
    int val; // Giá trị của nút
    TreeNode* left; // Con trái
    TreeNode* right; // Con phải
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // Constructor khởi tạo
};

// Hàm xây dựng cây từ danh sách cha-con
TreeNode* buildTree(int parent[], int N) {
    TreeNode* nodes[N + 1] = {NULL}; // Mảng lưu các nút của cây
    bool isChild[N + 1] = {false}; // Đánh dấu các nút con

    // Khởi tạo các nút
    for (int i = 1; i <= N; i++) {
        nodes[i] = new TreeNode(i);
    }

    // Gán quan hệ cha-con giữa các nút
    for (int i = 1; i <= N; i++) {
        if (parent[i] != -1) { // Nếu nút i có cha
            if (!nodes[parent[i]]->left) // Nếu cha chưa có con trái, gán vào con trái
                nodes[parent[i]]->left = nodes[i];
            else // Nếu đã có con trái, gán vào con phải
                nodes[parent[i]]->right = nodes[i];
            isChild[i] = true; // Đánh dấu nút này là con
        }
    }

    // Tìm gốc cây (nút không phải con của bất kỳ nút nào)
    for (int i = 1; i <= N; i++) {
        if (!isChild[i]) return nodes[i]; // Trả về nút gốc
    }
    return NULL; // Trả về NULL nếu không tìm thấy gốc
}

// Duyệt cây theo thứ tự trước (Preorder)
void preorder(TreeNode* root) {
    if (!root) return;
    cout << root->val << " "; // In giá trị nút
    preorder(root->left); // Duyệt cây con trái
    preorder(root->right); // Duyệt cây con phải
}

// Duyệt cây theo thứ tự sau (Postorder)
void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left); // Duyệt cây con trái
    postorder(root->right); // Duyệt cây con phải
    cout << root->val << " "; // In giá trị nút
}

// Duyệt cây theo thứ tự giữa (Inorder)
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left); // Duyệt cây con trái
    cout << root->val << " "; // In giá trị nút
    inorder(root->right); // Duyệt cây con phải
}

// Tính chiều cao của cây
int treeHeight(TreeNode* root) {
    if (!root) return 0; // Nếu là nút rỗng, chiều cao là 0
    return max(treeHeight(root->left), treeHeight(root->right)) + 1; // Tính chiều cao dựa vào con trái và con phải
}

// Kiểm tra cây có phải là cây nhị phân hợp lệ không
bool isBinaryTree(TreeNode* root) {
    if (!root) return true;
    int childCount = 0;
    if (root->left) childCount++;
    if (root->right) childCount++;
    if (childCount > 2) return false; // Nếu một nút có nhiều hơn 2 con, không phải cây nhị phân
    return isBinaryTree(root->left) && isBinaryTree(root->right);
}

int main() {
    int N, M;
    cin >> N >> M; // Nhập số lượng nút và số lượng cạnh
    int parent[N + 1]; // Mảng lưu cha của từng nút
    for (int i = 1; i <= N; i++) parent[i] = -1; // Khởi tạo tất cả là -1 (chưa có cha)
    
    // Nhập danh sách các cạnh
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        parent[v] = u; // Nút v có cha là u
    }
    
    // Xây dựng cây và tìm gốc
    TreeNode* root = buildTree(parent, N);
    
    // In ra chiều cao của cây
    cout << treeHeight(root) - 1 << endl;
    
    // In kết quả duyệt cây theo các phương pháp khác nhau
    preorder(root); cout << endl;
    postorder(root); cout << endl;
    
    // Kiểm tra xem có phải cây nhị phân hợp lệ không
    if (isBinaryTree(root)) {
        inorder(root);
    } else {
        cout << "NOT BINARY TREE";
    }
    cout << endl;
    
    return 0;
}
