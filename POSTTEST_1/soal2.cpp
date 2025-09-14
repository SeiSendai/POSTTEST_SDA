#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int matriks[3][3];
    int jumlah_diagonal_utama = 0;
    int jumlah_diagonal_sekunder = 0;
    
    cout << "Program Matriks 3x3" << endl;
    cout << "===================" << endl;
    
    // Input matriks
    cout << "Masukkan elemen matriks 3x3:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << "Matriks[" << i << "][" << j << "]: ";
            cin >> matriks[i][j];
        }
    }
    
    // Tampilkan matriks
    cout << "\nMatriks yang dimasukkan:" << endl;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << setw(4) << matriks[i][j] << " ";
        }
        cout << endl;
    }
    
    // Hitung diagonal utama dan diagonal sekunder
    for(int i = 0; i < 3; i++) {
        // Diagonal utama: i == j
        jumlah_diagonal_utama += matriks[i][i];
        
        // Diagonal sekunder: i + j == 2
        jumlah_diagonal_sekunder += matriks[i][2-i];
    }
    
    // Tampilkan hasil
    cout << "\nDiagonal Utama:" << endl;
    cout << matriks[0][0] << " + " << matriks[1][1] << " + " << matriks[2][2];
    cout << " = " << jumlah_diagonal_utama << endl;
    
    cout << "\nDiagonal Sekunder:" << endl;
    cout << matriks[0][2] << " + " << matriks[1][1] << " + " << matriks[2][0];
    cout << " = " << jumlah_diagonal_sekunder << endl;
    
    cout << "\nJumlah total: " << jumlah_diagonal_utama + jumlah_diagonal_sekunder << endl;
    
    return 0;
}