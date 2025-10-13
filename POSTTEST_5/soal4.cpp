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

void postOrderTraversal(Node* root) {
    
    // Base case: Jika node kosong (nullptr), tidak ada yang perlu dikunjungi
    // Langsung return untuk menghentikan rekursi
    if (root == nullptr) {
        return;
    }
    
    // Post-order: Kiri -> Kanan -> Root
    
    // 1. Kunjungi dan proses semua node di subtree kiri terlebih dahulu
    postOrderTraversal(root->left);
    
    // 2. Setelah subtree kiri selesai, kunjungi dan proses subtree kanan
    postOrderTraversal(root->right);
    
    // 3. Terakhir, cetak data dari node saat ini (root)
    // Ini dilakukan setelah semua anak-anaknya selesai dikunjungi
    cout << root->data << " ";

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

    cout << "Post-order traversal dari tree adalah: ";
    postOrderTraversal(root); // Harusnya output: 20 40 30 60 80 70 50
    cout << endl;
    return 0;
}