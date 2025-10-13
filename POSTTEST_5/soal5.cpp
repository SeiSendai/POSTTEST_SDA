#include <iostream>
using namespace std;

// Struktur Node untuk Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// Fungsi insert untuk membangun tree
Node* insert(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else if (val > root->data) {
        root->right = insert(root->right, val);
    }
    return root;
}

void preOrderTraversal(Node* root) {
    
    // Base case: Jika node kosong (nullptr), tidak ada yang perlu dikunjungi
    // Langsung return untuk menghentikan rekursi
    if (root == nullptr) {
        return;
    }
    
    // Pre-order: Root -> Kiri -> Kanan
    
    // 1. Cetak data dari node saat ini (root) terlebih dahulu
    // Ini yang membedakan pre-order dengan traversal lainnya
    cout << root->data << " ";
    
    // 2. Setelah root dicetak, kunjungi dan proses semua node di subtree kiri
    preOrderTraversal(root->left);
    
    // 3. Terakhir, kunjungi dan proses semua node di subtree kanan
    preOrderTraversal(root->right);

    // -----------------------------
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    cout << "Pre-order traversal dari tree adalah: ";
    preOrderTraversal(root); // Harusnya output: 50 30 20 40 70 60 80
    cout << endl;
    return 0;
}