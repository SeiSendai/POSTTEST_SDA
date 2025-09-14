#include <iostream>
using namespace std;

// Fungsi untuk menukar menggunakan double pointer
void tukar(int **a, int **b) {
    int *temp = *a;  // Simpan alamat yang ditunjuk a
    *a = *b;         // a sekarang menunjuk ke tempat b
    *b = temp;       // b sekarang menunjuk ke tempat a
}

int main() {
    int nilai1, nilai2;
    
    cout << "Program Tukar Variabel dengan Double Pointer" << endl;
    cout << "===========================================" << endl;
    
    // Input nilai
    cout << "Masukkan nilai pertama: ";
    cin >> nilai1;
    cout << "Masukkan nilai kedua: ";
    cin >> nilai2;
    
    // Buat pointer
    int *ptr1 = &nilai1;
    int *ptr2 = &nilai2;
    
    // Tampilkan kondisi sebelum pertukaran
    cout << "\nSEBELUM PERTUKARAN:" << endl;
    cout << "nilai1 = " << nilai1 << " (alamat: " << &nilai1 << ")" << endl;
    cout << "nilai2 = " << nilai2 << " (alamat: " << &nilai2 << ")" << endl;
    cout << "ptr1 menunjuk ke: " << ptr1 << " dengan nilai: " << *ptr1 << endl;
    cout << "ptr2 menunjuk ke: " << ptr2 << " dengan nilai: " << *ptr2 << endl;
    
    // Panggil fungsi tukar
    cout << "\nMemanggil fungsi tukar(&ptr1, &ptr2)..." << endl;
    tukar(&ptr1, &ptr2);
    
    // Tampilkan kondisi setelah pertukaran
    cout << "\nSETELAH PERTUKARAN:" << endl;
    cout << "nilai1 = " << nilai1 << " (alamat: " << &nilai1 << ")" << endl;
    cout << "nilai2 = " << nilai2 << " (alamat: " << &nilai2 << ")" << endl;
    cout << "ptr1 menunjuk ke: " << ptr1 << " dengan nilai: " << *ptr1 << endl;
    cout << "ptr2 menunjuk ke: " << ptr2 << " dengan nilai: " << *ptr2 << endl;
    
    cout << "\nKesimpulan:" << endl;
    cout << "- Nilai asli tidak berubah" << endl;
    cout << "- Yang bertukar adalah alamat yang ditunjuk oleh pointer" << endl;
    cout << "- ptr1 sekarang menunjuk ke nilai2" << endl;
    cout << "- ptr2 sekarang menunjuk ke nilai1" << endl;
    
    return 0;
}