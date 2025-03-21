// Key // value
// 12  // 7
// 44  // 5
// 13  // 9
// 88  // 5
// 23  // 7
// 94  // 6
// 11  // 5
// 39  // 6
// 20  // 1
// 16  // 4
// 5   // 4

#include <iostream>
#define TABLE_SIZE 11
using namespace std;

struct Node
{
    int key;
    Node *next;
};

Node *create_node(int value)
{
    Node *new_node = new Node;
    new_node->key = value;
    new_node->next = NULL;
    return new_node;
}

Node *hash_table[TABLE_SIZE];

int hash_function(int key)
{
    return (key * 2 + 5) % TABLE_SIZE;
}

void insert(int key)
{
    int index = hash_function(key);
    Node *new_node = create_node(key);

    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int search(int key)
{
    int index = hash_function(key);
    Node *current = hash_table[index];

    while (current != NULL)
    {
        if (current->key == key)
            return index;
        current = current->next;
    }
    return -1;
}

void print_chain(int key)
{
    int index = hash_function(key);
    Node *current = hash_table[index];

    while (current != NULL)
    {
        cout << current->key << " -> ";
        current = current->next;
    }
    cout << "NULL";
}

int main()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        hash_table[i] = NULL;
    }

    insert(12);
    insert(44);
    insert(13);
    insert(88);
    insert(23);
    insert(94);
    insert(11);
    insert(39);
    insert(20);
    insert(16);
    insert(5);

    cout << search(12) << "|"; print_chain(12); cout << endl;
    cout << search(44) << "|"; print_chain(44); cout << endl;
    cout << search(13) << "|"; print_chain(13); cout << endl;
    cout << search(88) << "|"; print_chain(88); cout << endl;
    cout << search(23) << "|"; print_chain(23); cout << endl;
    cout << search(94) << "|"; print_chain(94); cout << endl;
    cout << search(11) << "|"; print_chain(11); cout << endl;
    cout << search(39) << "|"; print_chain(39); cout << endl;
    cout << search(20) << "|"; print_chain(20); cout << endl;
    cout << search(16) << "|"; print_chain(16); cout << endl;
    cout << search(5)  << "|"; print_chain(5);  cout << endl;

    return 0;
}
