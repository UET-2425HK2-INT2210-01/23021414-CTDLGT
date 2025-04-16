#include <iostream>
using namespace std;

// Hàm đệ quy đếm số chữ số
int countDigits(int n) {
    if (n < 10) return 1;               // Nếu chỉ còn 1 chữ số thì dừng
    return 1 + countDigits(n / 10);     // Mỗi lần chia cho 10 là bỏ đi 1 chữ số
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    cout << countDigits(n) << endl;
    return 0;
}
