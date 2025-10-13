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

int findMinValue(Node* root) {
    
    // Cek apakah tree kosong
    // Jika kosong, kembalikan -1 sebagai penanda tidak ada nilai
    if (root == nullptr) {
        return -1;
    }
    
    // Di BST, nilai terkecil selalu berada di paling kiri
    // Jadi kita terus menelusuri ke kiri sampai tidak ada lagi node kiri
    while (root->left != nullptr) {
        root = root->left;  // Pindah ke node kiri
    }
    
    // Setelah loop selesai, root sekarang menunjuk ke node paling kiri
    // Node ini memiliki nilai terkecil
    return root->data;

    // -----------------------------
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);

    cout << "Nilai terkecil dalam tree adalah: " << findMinValue(root) << endl; // Harusnya output: 20
    return 0;
}