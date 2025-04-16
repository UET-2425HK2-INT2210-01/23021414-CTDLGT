#include <iostream>
using namespace std;

// Hàm đệ quy tính tổng các chữ số
int sumDigits(int n) {
    if (n == 0) return 0;               // Nếu n = 0 thì dừng
    return (n % 10) + sumDigits(n / 10); // Lấy chữ số cuối + gọi đệ quy phần còn lại
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    cout << sumDigits(n) << endl;
    return 0;
}
