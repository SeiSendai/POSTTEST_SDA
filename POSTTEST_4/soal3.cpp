#include <iostream>
#include <string>
using namespace std;

struct Node {
    string document;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string document) {
    Node* newNode = new Node{document, nullptr};  // Buat node baru untuk dokumen

    // Kalau queue masih kosong (belum ada antrian)
    // front dan rear sama-sama menunjuk ke node pertama
    if (front == nullptr) {
        front = rear = newNode;
    } 
    // Kalau sudah ada antrian, tambahkan node baru di belakang (rear)
    else {
        rear->next = newNode;  // Sambungkan node terakhir ke node baru
        rear = newNode;         // Update rear ke node baru
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == nullptr) return "";  // Queue kosong, tidak ada yang diproses

    // Simpan pointer ke node yang akan dihapus dan ambil datanya
    Node* temp = front;
    string document = temp->document;

    // Geser front ke node berikutnya (proses antrian berikutnya)
    front = front->next;

    // Kalau setelah digeser front jadi NULL, berarti queue sudah kosong
    // Maka rear juga harus di-reset ke NULL
    if (front == nullptr) {
        rear = nullptr;
    }

    // Hapus node yang sudah diproses dari memori
    delete temp;
    return document;
}

void processAllDocuments(Node*& front, Node*& rear) {
    // Proses semua dokumen sampai queue kosong
    // FIFO: dokumen yang masuk duluan, keluar/diproses duluan
    while (front != nullptr) {
        string doc = dequeue(front, rear);  // Ambil dokumen dari depan antrian
        cout << "Memproses: " << doc << endl;
    }
}

int main() {
    Node* front = nullptr;
    Node* rear = nullptr;

    enqueue(front, rear, "Document1.pdf");
    enqueue(front, rear, "Report.docx");
    enqueue(front, rear, "Presentation.pptx");

    cout << "Memulai pemrosesan antrian printer:" << endl;
    processAllDocuments(front, rear);

    return 0;
}