#include <iostream>
using namespace std;

class queue {
private:
	int array[10000];
	int n = 0;
public:
//thêm 1 phần tử vào hàng đợi
	void push()
	{
		int x;
		cin >> x;
		array[n] = x;
		n++;
    }
//xóa 1 phần tử khỏi hàng đợi
	void pop()
	{
		if(check()) return;
		for (int i = 0; i < n; i++)
		{
			array[i] = array[i + 1];
		}
		n--;
    }
//check xem hàng đợi có rỗng không
	bool check()
	{
		if (n = 0) return true;
		else return false;
	}
//check xem hàng đợi có bao nhiêu phần tủ
	int count()
	{
		return n;
	}
//lấy ra phần tử đầu hàng đợi
	int value()
	{
		return array[0];
	}
//in ra hàng đợi
	void print()
	{
		for (int i = 0; i < n; i++)
		{
			cout << array[i] << ' ';
		}
	}
};


int main()
{
	int n;
	cin >> n;
	queue p;
	for (int i = 0; i < n; i++)
	{
		p.push(); // vd nhập 1 2 3 4 5; 1 sẽ là đầu hàng đợi
	}

	cout << p.count(); //5
	cout << p.value(); //1
	p.pop();
	p.pop();

	p.print(); // 3 4 5

	return 0;
}

//giả code:
//đầu tiên ta tạo 1 class queue với private là 1 mảng có 1000 phần tử và n = 0
//n đánh dấu số phần tử có trong hàng đợi
//thêm 1 phần tử vào hàng đợi ta chỉ cần cho array[0] = x và tăng n lên 1 đơn vị O(1)
//hàm kiểm tra xem hàng đợi có rỗng không nếu n = 0 thì return true
// ngược lại return else; O(1)
//hàm đếm số phần tử có trong hàng đợi return n; O(1)
D:\assignments4\main.cpp//hàm xóa 1 phần tử khỏi hàng đợi kiểm tra nếu hàng đợi rỗng thì return;
//nếu không ta sẽ dùng vòng for để lặp từ 0 đến n - 1 sau đó cho
//array[i] = array[i + 1]; O(n)
