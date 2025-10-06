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

bool areBracketsBalanced(string expr) {
    Node* stackTop = nullptr;  // Stack untuk menyimpan kurung buka

    // Periksa setiap karakter dalam string
    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        // Jika ketemu kurung buka, simpan dulu ke stack
        // Kita akan cocokkan nanti saat ketemu kurung tutupnya
        if (c == '(' || c == '{' || c == '[') {
            push(stackTop, c);
        }
        // Jika ketemu kurung tutup, harus ada pasangan kurung buka
        else if (c == ')' || c == '}' || c == ']') {
            // Kalau stack kosong artinya kurung tutup tanpa pasangan, langsung false
            if (stackTop == nullptr) {
                return false;
            }

            // Ambil kurung buka terakhir dari stack
            char topChar = pop(stackTop);
            
            // Cek apakah kurung tutup cocok dengan kurung buka
            // Misal: ')' harus cocok dengan '(', '}' dengan '{', dst
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return false;  // Tidak cocok, berarti tidak seimbang
            }
        }
    }

    // Di akhir, kalau stack kosong berarti semua kurung buka punya pasangan
    // Kalau masih ada isi, berarti ada kurung buka yang tidak berpasangan
    return (stackTop == nullptr);
}

int main() {
    string expr1 = "{[()]}";
    cout << expr1 << " -> " << (areBracketsBalanced(expr1) ? "Seimbang" : "Tidak Seimbang") << endl;
    
    string expr2 = "{[(])}";
    cout << expr2 << " -> " << (areBracketsBalanced(expr2) ? "Seimbang" : "Tidak Seimbang") << endl;

    return 0;
}