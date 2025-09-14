#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    double ipk;
};

int main() {
    const int JUMLAH = 5;
    Mahasiswa mhs[JUMLAH];
    
    cout << "Program Data Mahasiswa" << endl;
    cout << "=====================" << endl;
    
    // Data mahasiswa sudah diisi otomatis
    mhs[0] = {"Ahmad Rizki", "2023001", 3.75};
    mhs[1] = {"Siti Nurhaliza", "2023002", 3.92};
    mhs[2] = {"Budi Santoso", "2023003", 3.45};
    mhs[3] = {"Maya Sari", "2023004", 3.88};
    mhs[4] = {"Doni Pratama", "2023005", 3.67};
    
    cout << "Data mahasiswa telah diisi otomatis." << endl;
    
    // Tampilkan semua data
    cout << "\n" << string(60, '=') << endl;
    cout << "DATA SEMUA MAHASISWA" << endl;
    cout << string(60, '=') << endl;
    cout << left << setw(20) << "Nama" << setw(15) << "NIM" << setw(10) << "IPK" << endl;
    cout << string(60, '-') << endl;
    
    for(int i = 0; i < JUMLAH; i++) {
        cout << left << setw(20) << mhs[i].nama 
             << setw(15) << mhs[i].nim 
             << fixed << setprecision(2) << mhs[i].ipk << endl;
    }
    
    // Cari mahasiswa dengan IPK tertinggi
    int index_tertinggi = 0;
    for(int i = 1; i < JUMLAH; i++) {
        if(mhs[i].ipk > mhs[index_tertinggi].ipk) {
            index_tertinggi = i;
        }
    }
    
    // Tampilkan hasil
    cout << "\n" << string(60, '=') << endl;
    cout << "MAHASISWA DENGAN IPK TERTINGGI" << endl;
    cout << string(60, '=') << endl;
    cout << "Nama : " << mhs[index_tertinggi].nama << endl;
    cout << "NIM  : " << mhs[index_tertinggi].nim << endl;
    cout << "IPK  : " << fixed << setprecision(2) << mhs[index_tertinggi].ipk << endl;
    
    return 0;
}