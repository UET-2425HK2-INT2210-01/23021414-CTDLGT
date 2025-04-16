#include <iostream>
using namespace std;

// Hàm đệ quy tính số Fibonacci thứ n
int fibonacci(int n) {
    if (n == 0) return 0;             // Trường hợp cơ sở: F(0) = 0
    if (n == 1) return 1;             // Trường hợp cơ sở: F(1) = 1
    return fibonacci(n - 1) + fibonacci(n - 2); // Gọi lại đệ quy theo công thức
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;                       
    if (n < 0) {
        cout << "n phai >= 0" << endl; 
    } else {
        cout << fibonacci(n) << endl;
    }

    return 0;
}
