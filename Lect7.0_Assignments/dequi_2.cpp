#include <iostream>
using namespace std;

// Hàm đệ quy tính giai thừa
int factorial(int n) {
    if (n == 0 || n == 1) return 1;    // Trường hợp cơ sở: 0! = 1! = 1
    return n * factorial(n - 1);       // Gọi lại hàm với n-1 và nhân với n
}

int main() {
    int n;
    cout << " n: ";
    cin >> n;                          // Nhập giá trị n từ bàn phím

    if (n < 0) {
        cout << "n phai >= 0" << endl; // Kiểm tra đầu vào
    } else {
        cout << factorial(n) << endl; 
    }

    return 0;
}
