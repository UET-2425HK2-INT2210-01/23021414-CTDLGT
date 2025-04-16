#include <iostream>
using namespace std;

// Hàm phụ trợ để gọi đệ quy có tham số tạm thời (revNum)
int reverseNumber(int n, int revNum = 0) {
    if (n == 0) return revNum;                        // Khi n = 0 thì trả về kết quả
    return reverseNumber(n / 10, revNum * 10 + n % 10); // Gộp chữ số vào kết quả tạm
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    cout << reverseNumber(n) << endl;
    return 0;
}
