#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* newNode = new Node{data, top};
    top = newNode;
}

char pop(Node*& top) {
    if (top == nullptr) return '\0';
    Node* temp = top;
    char poppedValue = temp->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

string reverseString(string s) {
    Node* stackTop = nullptr;  // Inisialisasi pointer top stack, awalnya kosong
    string reversed = "";       // String untuk menampung hasil pembalikan

    // Loop untuk memasukkan semua karakter string ke dalam stack
    // Karakter pertama akan masuk paling bawah, karakter terakhir paling atas
    for (int i = 0; i < s.length(); i++) {
        push(stackTop, s[i]);
    }

    // Loop untuk mengeluarkan karakter dari stack
    // Karena LIFO, karakter terakhir keluar duluan, sehingga string otomatis terbalik
    while (stackTop != nullptr) {
        reversed += pop(stackTop);
    }

    return reversed;
}

int main() {
    string text = "Struktur Data";
    cout << "Teks asli: " << text << endl;
    cout << "Teks terbalik: " << reverseString(text) << endl;
    return 0;
}