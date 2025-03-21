#include <iostream>
#include <vector>
#define TABLE_SIZE 11
using namespace std;

int hash_function(int key) {
    return (key * 2 + 5) % TABLE_SIZE;
}

void add_key(vector<int> &table, int key) {
    int position = hash_function(key);
    while (table[position] != -1) {
        position = (position + 1) % TABLE_SIZE;
    }
    table[position] = key;
}

void display_table(const vector<int> &table) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << table[i] << " ";
    }
}

int main() {
    vector<int> hash_table(TABLE_SIZE, -1);

    add_key(hash_table, 12);
    add_key(hash_table, 44);
    add_key(hash_table, 13);
    add_key(hash_table, 88);
    add_key(hash_table, 23);
    add_key(hash_table, 94);
    add_key(hash_table, 11);
    add_key(hash_table, 39);
    add_key(hash_table, 20);
    add_key(hash_table, 16);
    add_key(hash_table, 5);

    display_table(hash_table);
    return 0;
}
