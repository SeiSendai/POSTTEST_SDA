#include <iostream>
using namespace std;

int main() {
    // Membuat array untuk 7 data integer
    int data[7];
    int *ptr = data;  // Pointer menunjuk ke array
    
    cout << "Program Array + Pointer" << endl;
    cout << "======================" << endl;
    
    // Mengisi array dengan kelipatan 3 menggunakan pointer
    for(int i = 0; i < 7; i++) {
        *(ptr + i) = (i + 1) * 3;
    }
    
    // Menampilkan isi array
    cout << "Array berisi kelipatan 3:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << "data[" << i << "] = " << *(ptr + i) << endl;
    }
    
    cout << "\nMenggunakan pointer arithmetic:" << endl;
    for(int i = 0; i < 7; i++) {
        cout << "Alamat: " << (ptr + i) << " -> Nilai: " << *(ptr + i) << endl;
    }
    
    return 0;
}