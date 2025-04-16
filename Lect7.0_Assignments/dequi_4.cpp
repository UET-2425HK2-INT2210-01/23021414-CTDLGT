#include <iostream>
using namespace std;

// Hàm đệ quy tính x^n
int power(int x, int n) {
    if (n == 0) return 1;         // Trường hợp cơ sở: x^0 = 1
    return x * power(x, n - 1);   // Nhân x với kết quả x^(n-1)
}

int main() {
    int x, n;
    cout << "x = ";
    cin >> x;
    cout << "n = ";
    cin >> n;

    cout << power(x, n) << endl;
    return 0;
}
