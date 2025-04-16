#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng từ 1 đến n
int sum(int n) {
    if (n == 1) return 1;          // Trường hợp cơ sở: nếu n = 1 thì trả về 1
    return n + sum(n - 1);         // Gọi lại hàm với n-1 và cộng thêm n
}

int main() {
    int n;
    cout << " n = ";
    cin >> n;                      // Nhập giá trị n từ bàn phím

    if (n < 1) {
        cout << "n phai >= 1" << endl;   // Kiểm tra điều kiện đầu vào
    } else {
        cout << sum(n) << endl; 

    return 0;
}
