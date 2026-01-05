#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    vector<string> pemilih;        // Menyimpan ID yang sudah voting
    int hasil[4] = {0, 0, 0, 0};    // Hasil voting

    int menu;
    string id;

    do {
        cout << "\n=== SISTEM VOTING MANAJEMEN PARKIR ===\n";
        cout << "1. Voting\n";
        cout << "2. Lihat Hasil Voting\n";
        cout << "3. Keluar\n";
        cout << "Pilih menu: ";
        cin >> menu;

        if (menu == 1) {
            cout << "\nMasukkan NIM / ID: ";
            cin >> id;

            // Cek apakah sudah voting
            bool sudahVoting = false;
            for (string p : pemilih) {
                if (p == id) {
                    sudahVoting = true;
                    break;
                }
            }

            if (sudahVoting) {
                cout << "❌ Anda sudah melakukan voting!\n";
            } else {
                int pilihan;
                cout << "\nPilih Sistem Pembayaran Parkir:\n";
                cout << "1. Tunai\n";
                cout << "2. E-Wallet\n";
                cout << "3. Kartu Parkir\n";
                cout << "4. QRIS\n";
                cout << "Masukkan pilihan (1-4): ";
                cin >> pilihan;

                if (pilihan >= 1 && pilihan <= 4) {
                    hasil[pilihan - 1]++;
                    pemilih.push_back(id);
                    cout << "✅ Voting berhasil!\n";
                } else {
                    cout << "❌ Pilihan tidak valid!\n";
                }
            }
        }
        else if (menu == 2) {
            cout << "\n=== HASIL VOTING ===\n";
            cout << "Tunai       : " << hasil[0] << " suara\n";
            cout << "E-Wallet    : " << hasil[1] << " suara\n";
            cout << "Kartu Parkir: " << hasil[2] << " suara\n";
            cout << "QRIS        : " << hasil[3] << " suara\n";
        }
        else if (menu == 3) {
            cout << "\nTerima kasih telah menggunakan sistem voting parkir 🚗\n";
        }
        else {
            cout << "❌ Menu tidak valid!\n";
        }

    } while (menu != 3);

    return 0;
}
