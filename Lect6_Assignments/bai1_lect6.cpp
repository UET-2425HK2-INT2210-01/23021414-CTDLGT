#include <iostream>
#include <vector>
#include <limits>
using namespace std;

// Định nghĩa cấu trúc một node trong cây nhị phân
struct TreeNode {
    int value;                // Giá trị của node
    TreeNode *leftChild;      // Con trái
    TreeNode *rightChild;     // Con phải

    // Constructor mặc định
    TreeNode() : value(0), leftChild(NULL), rightChild(NULL) {};

    // Constructor có giá trị
    TreeNode(int x) : value(x), leftChild(NULL), rightChild(NULL) {};

    // Constructor đầy đủ
    TreeNode(int x, TreeNode *left, TreeNode *right) : value(x), leftChild(left), rightChild(right) {};

    // Destructor để xóa các node con khi node hiện tại bị xóa
    ~TreeNode() {
        delete leftChild;
        delete rightChild;
        leftChild = rightChild = NULL;
    }
};

class Solution {
public:
    // Hàm thêm node mới vào cây nhị phân tìm kiếm
    TreeNode *insertNode(TreeNode *root, int val) {
        if (root == NULL)  // Nếu cây rỗng thì tạo node mới làm gốc
            return new TreeNode(val);

        // Nếu giá trị nhỏ hơn node hiện tại, thêm vào cây con trái
        if (val < root->value)
            root->leftChild = insertNode(root->leftChild, val);
        else // Nếu giá trị lớn hơn hoặc bằng, thêm vào cây con phải
            root->rightChild = insertNode(root->rightChild, val);

        return root; // Trả về cây đã cập nhật
    }

    // Hàm tìm node nhỏ nhất trong cây (dùng trong xóa node có 2 con)
    TreeNode *findMin(TreeNode *root) {
        while (root->leftChild)  // Duyệt về bên trái đến khi không còn con trái
            root = root->leftChild;
        return root;
    }

    // Hàm xóa một node khỏi cây nhị phân tìm kiếm
    TreeNode* deleteNode(TreeNode* root, int val) {
        if (root == nullptr) // Nếu cây rỗng, trả về nullptr
            return nullptr;

        if (val < root->value) {
            // Nếu giá trị nhỏ hơn node hiện tại, tìm trong cây con trái
            root->leftChild = deleteNode(root->leftChild, val);
        } else if (val > root->value) {
            // Nếu giá trị lớn hơn node hiện tại, tìm trong cây con phải
            root->rightChild = deleteNode(root->rightChild, val);
        } else {
            // Đã tìm thấy node cần xóa

            // Trường hợp chỉ có 1 con phải hoặc không có con
            if (root->leftChild == nullptr) {
                TreeNode* temp = root->rightChild;
                delete root;  // Giải phóng bộ nhớ
                return temp;
            }
            // Trường hợp chỉ có 1 con trái
            else if (root->rightChild == nullptr) {
                TreeNode* temp = root->leftChild;
                delete root;
                return temp;
            }

            // Trường hợp có 2 con: tìm node nhỏ nhất bên cây phải
            TreeNode* temp = findMin(root->rightChild);
            root->value = temp->value; // Gán giá trị nhỏ nhất cho node hiện tại
            root->rightChild = deleteNode(root->rightChild, temp->value); // Xóa node nhỏ nhất đã gán
        }

        return root; // Trả lại cây sau khi xóa
    }

    // Hàm duyệt cây theo thứ tự giữa (Inorder Traversal)
    void printInorder(TreeNode *root) {
        if (root) {
            printInorder(root->leftChild);    // Duyệt cây con trái
            cout << root->value << " ";       // In giá trị node hiện tại
            printInorder(root->rightChild);   // Duyệt cây con phải
        }
    }
};

int main() {
    Solution treeSolver;
    TreeNode *root = NULL;

    // Mảng chứa các giá trị ban đầu để xây dựng cây
    int initialValues[9] = {2, 1, 10, 6, 3, 8, 7, 13, 20};

    // Thêm từng giá trị vào cây
    for (int i = 0; i < 9; i++) {
        root = treeSolver.insertNode(root, initialValues[i]);
    }

    // Thêm các giá trị mới vào cây
    int newInsertions[3] = {14, 0, 35};
    for (int i = 0; i < 3; i++) {
        root = treeSolver.insertNode(root, newInsertions[i]);
    }

    // In cây sau khi chèn thêm
    cout << "Sau khi chen 14, 0, 35: ";
    treeSolver.printInorder(root);
    cout << endl;

    // Xóa node có giá trị 6 khỏi cây
    root = treeSolver.deleteNode(root, 6);

    // In cây sau khi xóa
    cout << "Sau khi xoa 6: ";
    treeSolver.printInorder(root);
    cout << endl;
}
