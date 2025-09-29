#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk data item dengan Double Linked List
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
    Item* prev;  // Tambahan pointer untuk Double Linked List
};

// Global variables
Item* head = nullptr;
Item* tail = nullptr;  // Pointer untuk elemen terakhir
const int NIM_SUFFIX = 75; // Dua digit terakhir NIM: 2409106075
const int POSISI_SISIP = 6; // Digit terakhir (5) + 1 = 6

// Function prototypes
void tampilkanMenu();
void tambahItemBaru();
void sisipkanItem();
void hapusItemTerakhir();
void gunakanItem();
void tampilkanInventory();
void tampilkanInventoryTerbalik();
void tampilkanDetailItem();
int hitungItem();
void cleanupMemory();

void tampilkanMenu() {
    cout << "\n";
    cout << "================================================================\n";
    cout << "                GAME INVENTORY MANAGEMENT                       \n";
    cout << "          [ Muhammad Fathir Rahman - 2409106075 ]               \n";
    cout << "                  DOUBLE LINKED LIST VERSION                    \n";
    cout << "================================================================\n";
    cout << "  1. Tambah Item Baru                                           \n";
    cout << "  2. Sisipkan Item di Posisi " << POSISI_SISIP << "                                \n";
    cout << "  3. Hapus Item Terakhir                                        \n";
    cout << "  4. Gunakan Item                                               \n";
    cout << "  5. Tampilkan Inventory (Depan ke Belakang)                    \n";
    cout << "  6. Tampilkan Inventory (Belakang ke Depan)                    \n";
    cout << "  7. Tampilkan Detail Item                                      \n";
    cout << "  0. Keluar                                                     \n";
    cout << "================================================================\n";
    cout << "Pilih menu: ";
}

void tambahItemBaru() {
    Item* newItem = new Item;
    
    cout << "\n=== TAMBAH ITEM BARU ===\n";
    cout << "Nama Item: ";
    cin.ignore();
    getline(cin, newItem->namaItem);
    
    cout << "Tipe Item (Sword/Potion/Armor/dll): ";
    getline(cin, newItem->tipe);
    
    // Jumlah otomatis berdasarkan dua digit terakhir NIM
    newItem->jumlah = NIM_SUFFIX;
    newItem->next = nullptr;
    newItem->prev = nullptr;

    if (head == nullptr) {
        // List kosong
        head = newItem;
        tail = newItem;
    } else {
        // Tambah di akhir
        tail->next = newItem;
        newItem->prev = tail;
        tail = newItem;
    }

    cout << "Item '" << newItem->namaItem << "' berhasil ditambahkan dengan jumlah " << NIM_SUFFIX << "!\n";
}

void sisipkanItem() {
    int totalItem = hitungItem();
    if (totalItem < POSISI_SISIP - 1) {
        cout << "\nInventory tidak memiliki cukup item untuk menyisipkan di posisi " << POSISI_SISIP << "!\n";
        cout << "Jumlah item saat ini: " << totalItem << "\n";
        return;
    }

    Item* newItem = new Item;
    
    cout << "\n=== SISIPKAN ITEM DI POSISI " << POSISI_SISIP << " ===\n";
    cout << "Nama Item: ";
    cin.ignore();
    getline(cin, newItem->namaItem);
    
    cout << "Tipe Item (Sword/Potion/Armor/dll): ";
    getline(cin, newItem->tipe);
    
    newItem->jumlah = NIM_SUFFIX;
    newItem->next = nullptr;
    newItem->prev = nullptr;

    if (POSISI_SISIP == 1) {
        // Sisipkan di awal
        newItem->next = head;
        if (head != nullptr) {
            head->prev = newItem;
        }
        head = newItem;
        if (tail == nullptr) {
            tail = newItem;
        }
    } else {
        // Sisipkan di posisi tertentu
        Item* current = head;
        for (int i = 1; i < POSISI_SISIP; i++) {
            current = current->next;
        }
        
        newItem->next = current;
        newItem->prev = current->prev;
        
        if (current->prev != nullptr) {
            current->prev->next = newItem;
        }
        current->prev = newItem;
    }

    cout << "Item '" << newItem->namaItem << "' berhasil disisipkan di posisi " << POSISI_SISIP << "!\n";
}

void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "\nInventory kosong! Tidak ada item yang dapat dihapus.\n";
        return;
    }

    if (head == tail) {
        // Hanya ada satu item
        cout << "\nItem '" << head->namaItem << "' berhasil dihapus dari inventory!\n";
        delete head;
        head = nullptr;
        tail = nullptr;
        return;
    }

    // Hapus item terakhir
    Item* temp = tail;
    cout << "\nItem '" << temp->namaItem << "' berhasil dihapus dari inventory!\n";
    
    tail = tail->prev;
    tail->next = nullptr;
    delete temp;
}

void gunakanItem() {
    if (head == nullptr) {
        cout << "\nInventory kosong! Tidak ada item yang dapat digunakan.\n";
        return;
    }

    string namaItem;
    cout << "\n=== GUNAKAN ITEM ===\n";
    cout << "Masukkan nama item yang ingin digunakan: ";
    cin.ignore();
    getline(cin, namaItem);

    // Cari item di double linked list
    Item* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->namaItem == namaItem) {
            found = true;
            break;
        }
        current = current->next;
    }

    if (!found) {
        cout << "Item '" << namaItem << "' tidak ditemukan dalam inventory!\n";
        return;
    }

    // Kurangi jumlah item
    current->jumlah--;
    cout << "Menggunakan 1 " << namaItem << ". Sisa: " << current->jumlah << "\n";

    // Jika jumlah menjadi 0, hapus node
    if (current->jumlah == 0) {
        cout << "Item '" << namaItem << "' telah habis dan dihapus dari inventory!\n";
        
        // Update pointer prev dan next
        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            // Hapus head
            head = current->next;
        }
        
        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            // Hapus tail
            tail = current->prev;
        }
        
        delete current;
    }
}

void tampilkanInventory() {
    if (head == nullptr) {
        cout << "\n=== INVENTORY KOSONG ===\n";
        cout << "Tidak ada item dalam inventory.\n";
        return;
    }

    cout << "\n=== INVENTORY GAME (DEPAN KE BELAKANG) ===\n";
    cout << "+----+-----------------------+--------+---------------+\n";
    cout << "| No |       Nama Item       | Jumlah |     Tipe      |\n";
    cout << "+----+-----------------------+--------+---------------+\n";

    Item* current = head;
    int nomor = 1;
    while (current != nullptr) {
        cout << "| " << setw(2) << nomor << " | " 
             << setw(22) << left << current->namaItem << "| " 
             << setw(6) << right << current->jumlah << " | " 
             << setw(14) << left << current->tipe << "|\n";
        current = current->next;
        nomor++;
    }
    cout << "+----+-----------------------+--------+---------------+\n";
    cout << "Total item: " << hitungItem() << " jenis\n";
}

void tampilkanInventoryTerbalik() {
    if (head == nullptr) {
        cout << "\n=== INVENTORY KOSONG ===\n";
        cout << "Tidak ada item dalam inventory.\n";
        return;
    }

    cout << "\n=== INVENTORY GAME (BELAKANG KE DEPAN) ===\n";
    cout << "+----+-----------------------+--------+---------------+\n";
    cout << "| No |       Nama Item       | Jumlah |     Tipe      |\n";
    cout << "+----+-----------------------+--------+---------------+\n";

    Item* current = tail;
    int nomor = 1;
    while (current != nullptr) {
        cout << "| " << setw(2) << nomor << " | " 
             << setw(22) << left << current->namaItem << "| " 
             << setw(6) << right << current->jumlah << " | " 
             << setw(14) << left << current->tipe << "|\n";
        current = current->prev;
        nomor++;
    }
    cout << "+----+-----------------------+--------+---------------+\n";
    cout << "Total item: " << hitungItem() << " jenis\n";
}

void tampilkanDetailItem() {
    if (head == nullptr) {
        cout << "\nInventory kosong! Tidak ada item untuk ditampilkan.\n";
        return;
    }

    string namaItem;
    cout << "\n=== DETAIL ITEM ===\n";
    cout << "Masukkan nama item yang ingin dilihat detailnya: ";
    cin.ignore();
    getline(cin, namaItem);

    // Cari item berdasarkan nama
    Item* current = head;
    int posisi = 1;
    bool found = false;

    while (current != nullptr) {
        if (current->namaItem == namaItem) {
            found = true;
            break;
        }
        current = current->next;
        posisi++;
    }

    if (!found) {
        cout << "Item '" << namaItem << "' tidak ditemukan dalam inventory!\n";
        return;
    }

    // Tampilkan detail item
    cout << "\n================================================================\n";
    cout << "                        DETAIL ITEM                             \n";
    cout << "================================================================\n";
    cout << " Nama Item    : " << current->namaItem << "\n";
    cout << " Tipe         : " << current->tipe << "\n";
    cout << " Jumlah       : " << current->jumlah << "\n";
    cout << " Posisi       : " << posisi << "\n";
    cout << " Status       : " << (current->jumlah > 0 ? "Tersedia" : "Habis") << "\n";
    
    // Informasi navigasi
    cout << "----------------------------------------------------------------\n";
    cout << " Item Sebelum : " << (current->prev ? current->prev->namaItem : "Tidak ada") << "\n";
    cout << " Item Sesudah : " << (current->next ? current->next->namaItem : "Tidak ada") << "\n";
    cout << "================================================================\n";
}

int hitungItem() {
    int count = 0;
    Item* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void cleanupMemory() {
    while (head != nullptr) {
        Item* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

int main() {
    int pilihan;

    cout << "Selamat datang di Game Inventory Management System!\n";
    cout << "Double Linked List Version - Muhammad Fathir Rahman\n";
    
    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahItemBaru();
                break;
            case 2:
                sisipkanItem();
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                gunakanItem();
                break;
            case 5:
                tampilkanInventory();
                break;
            case 6:
                tampilkanInventoryTerbalik();
                break;
            case 7:
                tampilkanDetailItem();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan Game Inventory Management!\n";
                cout << "Program berakhir.\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 0-7.\n";
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 0);

    // Cleanup memory sebelum program berakhir
    cleanupMemory();
    
    return 0;
}