#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

// Struct untuk data item
struct Item {
    string namaItem;
    int jumlah;
    string tipe;
    Item* next;
};

class InventoryGame {
private:
    Item* head;
    const int NIM_SUFFIX = 75; // Dua digit terakhir NIM: 2409106075
    const int POSISI_SISIP = 6; // Digit terakhir (5) + 1 = 6

public:
    InventoryGame() {
        head = nullptr;
    }

    ~InventoryGame() {
        while (head != nullptr) {
            Item* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void tampilkanMenu() {
        cout << "\n";
        cout << "╔══════════════════════════════════════════════════════════════╗\n";
        cout << "║                GAME INVENTORY MANAGEMENT                     ║\n";
        cout << "║          [ Muhammad Fathir Rahman - 2409106075 ]             ║\n";
        cout << "╠══════════════════════════════════════════════════════════════╣\n";
        cout << "║  1. Tambah Item Baru                                         ║\n";
        cout << "║  2. Sisipkan Item                                            ║\n";
        cout << "║  3. Hapus Item Terakhir                                      ║\n";
        cout << "║  4. Gunakan Item                                             ║\n";
        cout << "║  5. Tampilkan Inventory                                      ║\n";
        cout << "║  0. Keluar                                                   ║\n";
        cout << "╚══════════════════════════════════════════════════════════════╝\n";
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

        if (head == nullptr) {
            head = newItem;
        } else {
            Item* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newItem;
        }

        cout << "Item '" << newItem->namaItem << "' berhasil ditambahkan dengan jumlah " << NIM_SUFFIX << "!\n";
    }

    void sisipkanItem() {
        if (hitungItem() < POSISI_SISIP - 1) {
            cout << "\nInventory tidak memiliki cukup item untuk menyisipkan di posisi " << POSISI_SISIP << "!\n";
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

        if (POSISI_SISIP == 1) {
            newItem->next = head;
            head = newItem;
        } else {
            Item* temp = head;
            for (int i = 1; i < POSISI_SISIP - 1; i++) {
                temp = temp->next;
            }
            newItem->next = temp->next;
            temp->next = newItem;
        }

        cout << "Item '" << newItem->namaItem << "' berhasil disisipkan di posisi " << POSISI_SISIP << "!\n";
    }

    void hapusItemTerakhir() {
        if (head == nullptr) {
            cout << "\nInventory kosong! Tidak ada item yang dapat dihapus.\n";
            return;
        }

        if (head->next == nullptr) {
            cout << "\nItem '" << head->namaItem << "' berhasil dihapus dari inventory!\n";
            delete head;
            head = nullptr;
            return;
        }

        Item* temp = head;
        while (temp->next->next != nullptr) {
            temp = temp->next;
        }

        cout << "\nItem '" << temp->next->namaItem << "' berhasil dihapus dari inventory!\n";
        delete temp->next;
        temp->next = nullptr;
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

        // Cari item di linked list
        Item* current = head;
        Item* prev = nullptr;
        bool found = false;

        while (current != nullptr) {
            if (current->namaItem == namaItem) {
                found = true;
                break;
            }
            prev = current;
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
            
            if (prev == nullptr) {
                // Hapus head
                head = current->next;
            } else {
                // Hapus node di tengah/akhir
                prev->next = current->next;
            }
            delete current;
        }
    }

    void tampilkanInventory() {
        if (head == nullptr) {
            cout << "\n=== INVENTORY KOSONG ===\n";
            return;
        }

        cout << "\n=== INVENTORY GAME ===\n";
        cout << "╔════╦═══════════════════════╦════════╦═══════════════╗\n";
        cout << "║ No ║       Nama Item       ║ Jumlah ║     Tipe      ║\n";
        cout << "╠════╬═══════════════════════╬════════╬═══════════════╣\n";

        Item* temp = head;
        int nomor = 1;
        while (temp != nullptr) {
            cout << "║ " << setw(2) << nomor << " ║ " 
                 << setw(22) << left << temp->namaItem << "║ " 
                 << setw(6) << right << temp->jumlah << " ║ " 
                 << setw(14) << left << temp->tipe << "║\n";
            temp = temp->next;
            nomor++;
        }
        cout << "╚════╩═══════════════════════╩════════╩═══════════════╝\n";
    }

    int hitungItem() {
        int count = 0;
        Item* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    InventoryGame game;
    int pilihan;

    cout << "Selamat datang di Game Inventory Management System!\n";
    
    do {
        game.tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                game.tambahItemBaru();
                break;
            case 2:
                game.sisipkanItem();
                break;
            case 3:
                game.hapusItemTerakhir();
                break;
            case 4:
                game.gunakanItem();
                break;
            case 5:
                game.tampilkanInventory();
                break;
            case 0:
                cout << "\nTerima kasih telah menggunakan Game Inventory Management!\n";
                cout << "Program berakhir.\n";
                break;
            default:
                cout << "\nPilihan tidak valid! Silakan pilih menu 0-5.\n";
        }

        if (pilihan != 0) {
            cout << "\nTekan Enter untuk melanjutkan...";
            cin.ignore();
            cin.get();
        }

    } while (pilihan != 0);

    return 0;
}