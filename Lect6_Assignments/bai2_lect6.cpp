#include <iostream>
#define MAX 100
using namespace std;

// Hàm điều chỉnh đỉnh i để duy trì tính chất Min-Heap
void minHeapify(int heap[], int size, int index) {
    int smallest = index;               // Giả sử node hiện tại là nhỏ nhất
    int leftChild = 2 * index + 1;      // Vị trí con trái
    int rightChild = 2 * index + 2;     // Vị trí con phải

    // So sánh với con trái
    if (leftChild < size && heap[leftChild] < heap[smallest])
        smallest = leftChild;

    // So sánh với con phải
    if (rightChild < size && heap[rightChild] < heap[smallest])
        smallest = rightChild;

    // Nếu nhỏ nhất không phải là node hiện tại, hoán đổi và đệ quy
    if (smallest != index) {
        swap(heap[index], heap[smallest]);
        minHeapify(heap, size, smallest);
    }
}

// Hàm xây dựng Min-Heap từ mảng ban đầu
void buildMinHeap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        minHeapify(heap, size, i);
    }
}

// Hàm in Min-Heap
void printHeap(int heap[], int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Hàm thêm phần tử mới vào Min-Heap
void insert(int heap[], int value, int &size) {
    heap[size] = value;        // Gán phần tử mới vào cuối heap
    size++;                    // Tăng kích thước heap
    buildMinHeap(heap, size); // Gọi lại build heap để duy trì tính chất
}

// Hàm xóa phần tử có giá trị val khỏi Min-Heap
void deleteMinHeap(int heap[], int &size, int value) {
    for (int i = 0; i < size; i++) {
        if (heap[i] == value) {
            heap[i] = heap[--size];     // Gán phần tử cuối lên vị trí cần xóa
            minHeapify(heap, size, i);  // Điều chỉnh lại heap
            break;
        }
    }
}

int main() {
    // Mảng ban đầu
    int heapArray[] = {2, 1, 10, 6, 3, 8, 7, 13, 20};
    int heapSize = sizeof(heapArray) / sizeof(heapArray[0]);

    // Xây dựng Min-Heap ban đầu
    buildMinHeap(heapArray, heapSize);
    cout << "Min-Heap ban đầu: ";
    printHeap(heapArray, heapSize);
    cout << endl;

    // Thêm phần tử mới
    cout << "Min-Heap sau khi thêm 14, 0, 35: ";
    insert(heapArray, 14, heapSize);
    insert(heapArray, 0, heapSize);
    insert(heapArray, 35, heapSize);
    printHeap(heapArray, heapSize);
    cout << endl;

    // Xóa phần tử khỏi heap
    cout << "Min-Heap sau khi xóa 6, 13, 35: ";
    deleteMinHeap(heapArray, heapSize, 6);
    deleteMinHeap(heapArray, heapSize, 13);
    deleteMinHeap(heapArray, heapSize, 35);
    printHeap(heapArray, heapSize);
    cout << endl;
}
