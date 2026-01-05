#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Struktur data untuk menyimpan kendaraan
struct kendaraan {
    string platNomor;
    string jenis; // mobil/motor
    int jamMasuk;
};

int main() {
    vector<kendaraan> daftarParkir;
    int pilihan;
    const int tarifMotor = 2000;
    const int tarifMobil = 5000;

    do {
        cout << "\n=== Sistem Parkir ===\n";
        cout << "1.Kendaraan Masuk" << endl;
        cout << "2.Kendaraan Keluar (cetak struk)" << endl;
        cout << "3.Lihat Daftar Parkir" << endl;
        cout << "4.Keluar" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1) {
            kendaraan k; // Mendeklarasi objek kendaraan
            cout << "Masukkan plat nomor: ";
            cin >> k.platNomor;
            cout << "Masukkan jenis kendaraan (mobil/motor): ";
            cin >> k.jenis;
            cout << "Masukkan jam masuk (0-23): ";
            cin >> k.jamMasuk;

            daftarParkir.push_back(k);
            cout << "Kendaraan Berhasil Didaftarkan" << endl;

        } else if (pilihan == 2) {
            string platKeluar;
            int jamKeluar;
            bool ditemukan = false;

            cout << "masukan Plat Nomor yang Keluar: ";
            cin >> platKeluar;

            for (int i = 0; i < daftarParkir.size(); i++) {
                if (daftarParkir[i].platNomor == platKeluar) { // Memberbaiki nama variabel 'plat'
                    ditemukan = true;
                    cout << "Masukkan jam keluar (0-23): ";
                    cin >> jamKeluar;

                    int durasi = jamKeluar - daftarParkir[i].jamMasuk;
                    if (durasi <=0) durasi = 1; // Minimal 1 jam

                    // Memperbaiki pengecekan string dan menambahkan titik koma
                    int totalBiaya = (daftarParkir[i].jenis == "mobil" ? tarifMobil : tarifMotor) * durasi;
                    
                    cout << "\n--- Struk Parkir ---" << endl;
                    cout << "Plat Nomor: " << daftarParkir[i].platNomor << endl;
                    cout << "Jenis     : " << daftarParkir[i].jenis << endl;
                    cout << "Durasi    : " << durasi << "jam" << endl;
                    cout << "Total Biaya: Rp " << totalBiaya << endl;
                    cout << "---------------------" << endl;

                    // Menghapus kendaraan dari daftar parkir
                    daftarParkir.erase(daftarParkir.begin() + i);
                    break;
                }
            }
        } else if (pilihan == 3) {
            cout << "\n--- Daftar Kendaraan Parkir ---" << endl;
            if (daftarParkir.empty()) {
                cout << "Parkir kosong." << endl;
            } else {
                cout << "No\tPlat Nomor\tJenis\tJam Masuk" << endl;
                for (int i = 0; i <daftarParkir.size(); i++) {
                    cout << i + 1 << "\t" << daftarParkir[i].platNomor << "\t\t" << daftarParkir[i].jenis << "\t" << daftarParkir[i].jamMasuk << endl;
                }
            }
        } else if (pilihan != 4) {
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 4);

    cout << "Terima kasih telah menggunakan sistem parkir." << endl;
    return 0;

}    