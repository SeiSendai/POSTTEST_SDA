#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void exchangeHeadAndTail(Node *&head_ref) {
    // Cek apakah list kosong atau cuma 1 node
    // Kalau iya, tidak perlu tukar karena tidak ada yang bisa ditukar
    if (head_ref == nullptr || head_ref->next == head_ref) {
        return;
    }

    Node* head = head_ref;          // Simpan pointer ke head
    Node* tail = head_ref->prev;    // Tail ada di prev dari head (karena circular)

    // KASUS KHUSUS: Hanya ada 2 node
    // Cukup tukar posisi head dan tail saja, keduanya tetanggan
    if (head->next == tail) {
        tail->next = head;
        tail->prev = head;
        head->next = tail;
        head->prev = tail;
        head_ref = tail;  // Update head_ref ke tail
        return;
    }

    // KASUS UMUM: Lebih dari 2 node
    // Simpan tetangga head dan tail sebelum kita ubah koneksinya
    Node* head_next = head->next;   // Node setelah head (akan jadi tetangga tail)
    Node* tail_prev = tail->prev;   // Node sebelum tail (akan jadi tetangga head)

    // Pindahkan TAIL ke posisi HEAD
    // tail sekarang harus terhubung dengan head_next
    tail->next = head_next;
    tail->prev = head;         // prev-nya tail sekarang adalah head
    head_next->prev = tail;    // head_next sekarang prev-nya adalah tail

    // Pindahkan HEAD ke posisi TAIL
    // head sekarang harus terhubung dengan tail_prev
    head->next = tail;         // next-nya head sekarang adalah tail
    head->prev = tail_prev;
    tail_prev->next = head;    // tail_prev sekarang next-nya adalah head

    // Update head_ref karena sekarang tail yang jadi head
    head_ref = tail;
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

void insertEnd(Node *&head_ref, int data) {
    Node *newNode = new Node{data, nullptr, nullptr};

    if (head_ref == nullptr) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head_ref = newNode;
        return;
    }

    Node *tail = head_ref->prev;
    newNode->next = head_ref;
    newNode->prev = tail;
    head_ref->prev = newNode;
    tail->next = newNode;
}

int main() {
    Node *head = nullptr;

    // Buat list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    insertEnd(head, 1);
    insertEnd(head, 2);
    insertEnd(head, 3);
    insertEnd(head, 4);
    insertEnd(head, 5);

    cout << "List sebelum exchange: ";
    printList(head);

    exchangeHeadAndTail(head);

    cout << "List setelah exchange head dan tail: ";
    printList(head);

    return 0;
}