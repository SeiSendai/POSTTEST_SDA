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

int findMaxValue(Node* root) {
    
    // Cek apakah tree kosong
    // Jika kosong, kembalikan -1 sebagai penanda tidak ada nilai
    if (root == nullptr) {
        return -1;
    }
    
    // Di BST, nilai terbesar selalu berada di paling kanan
    // Jadi kita terus menelusuri ke kanan sampai tidak ada lagi node kanan
    while (root->right != nullptr) {
        root = root->right;  // Pindah ke node kanan
    }
    
    // Setelah loop selesai, root sekarang menunjuk ke node paling kanan
    // Node ini memiliki nilai terbesar
    return root->data;

    // -----------------------------
}

int main() {
    Node* root = nullptr;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 80);

    cout << "Nilai terbesar dalam tree adalah: " << findMaxValue(root) << endl; // Harusnya output: 80
    return 0;
}