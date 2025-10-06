#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void sortedInsert(Node *&head_ref, int data) {
    Node* newNode = new Node{data, nullptr, nullptr};  // Buat node baru

    // KASUS 1: List masih kosong
    // Node baru jadi satu-satunya node, next dan prev menunjuk ke diri sendiri
    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    // KASUS 2: Data baru lebih kecil dari head (harus jadi head baru)
    // Sisipkan di awal dan update head_ref
    if (data < head_ref->data) {
        Node* tail = head_ref->prev;  // Ambil tail (node terakhir)
        
        // Hubungkan newNode antara tail dan head
        newNode->next = head_ref;
        newNode->prev = tail;
        head_ref->prev = newNode;
        tail->next = newNode;
        
        // Update head_ref karena ada node baru yang lebih kecil
        head_ref = newNode;
        return;
    }

    // KASUS 3: Data baru ada di tengah atau akhir
    // Cari posisi yang tepat dengan traversal
    Node* current = head_ref;
    
    // Loop sampai ketemu posisi: next node lebih besar atau sudah kembali ke head
    // Berhenti sebelum node yang lebih besar
    while (current->next != head_ref && current->next->data < data) {
        current = current->next;
    }
    
    // Sisipkan newNode setelah current
    Node* nextNode = current->next;
    
    // Update pointer: current <-> newNode <-> nextNode
    newNode->next = nextNode;
    newNode->prev = current;
    current->next = newNode;
    nextNode->prev = newNode;
}

void printList(Node *head_ref) {
    if (head_ref == nullptr) {
        cout << "List kosong" << endl;
        return;
    }

    Node *current = head_ref;
    do {
        cout << current->data << " ";
        current = current->next;
    } while (current != head_ref);
    cout << endl;
}

int main() {
    Node *head = nullptr;

    // Test sorted insert
    sortedInsert(head, 30);
    sortedInsert(head, 10);
    sortedInsert(head, 40);
    sortedInsert(head, 20);

    cout << "Circular Doubly Linked List (sorted): ";
    printList(head);

    return 0;
}