#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    // 1. Setup List
    ListInduk LI;
    createList(LI);

    int pilihan = -1; // Inisialisasi awal bukan 0 agar loop jalan
    string s1, s2;
    infotypeInduk dataNegara;
    infotypeAnak dataProvinsi;
    addressInduk pNegara;
    addressAnak pProvinsi;

    // 2. Loop Menggunakan While (Tanpa break/get di akhir)
    while (pilihan != 0) {

        showDashboard(LI);
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer enter

        cout << "\n----------------------------------------" << endl;

        // MENGGUNAKAN IF-ELSE (Pengganti Switch-Case agar tidak pakai break)

        if (pilihan == 1) {
            // Tambah Negara
            cout << "--- INPUT DATA NEGARA ---" << endl;
            cout << "Nama Negara    : "; getline(cin, dataNegara.namaNegara);
            cout << "Kode Negara    : "; getline(cin, dataNegara.kodeNegara);
            cout << "Benua          : "; getline(cin, dataNegara.benua);
            cout << "Ibu Kota       : "; getline(cin, dataNegara.ibuKotaNegara);
            cout << "Presiden       : "; getline(cin, dataNegara.presiden);
            cout << "Mata Uang      : "; getline(cin, dataNegara.mataUang);
            cout << "Total Populasi : "; cin >> dataNegara.totalPopulasi;

            pNegara = alokasiNegara(dataNegara);
            insertLastNegara(LI, pNegara);
            cout << "[+] Negara berhasil ditambahkan!" << endl;

        } else if (pilihan == 2) {
            // Tambah Provinsi
            cout << "--- INPUT DATA PROVINSI ---" << endl;
            cout << "Masukkan Nama Negara Tujuan: "; getline(cin, s1);

            pNegara = searchNegara(LI, s1);
            if (pNegara == nullptr) {
                cout << "[!] Negara tidak ditemukan." << endl;
            } else {
                cout << "Nama Provinsi  : "; getline(cin, dataProvinsi.namaProvinsi);
                cout << "Ibu Kota Prov  : "; getline(cin, dataProvinsi.ibuKotaProvinsi);
                cout << "Gubernur       : "; getline(cin, dataProvinsi.gubernur);
                cout << "Luas Wilayah   : "; cin >> dataProvinsi.luasWilayah;
                cout << "Populasi       : "; cin >> dataProvinsi.populasiProvinsi;

                pProvinsi = alokasiProvinsi(dataProvinsi);
                insertLastProvinsi(LI, s1, pProvinsi);
                cout << "[+] Provinsi berhasil ditambahkan!" << endl;
            }

        } else if (pilihan == 3) {
            // Hapus Negara
            cout << "Nama Negara yang dihapus: "; getline(cin, s1);
            hapusNegara(LI, s1);

        } else if (pilihan == 4) {
            // Hapus Provinsi
            cout << "Dari Negara mana: "; getline(cin, s1);
            cout << "Nama Provinsi dihapus: "; getline(cin, s2);
            hapusProvinsi(LI, s1, s2);

        } else if (pilihan == 5) {
            // Cari Negara
            cout << "Cari Nama Negara: "; getline(cin, s1);
            pNegara = searchNegara(LI, s1);
            printDetailNegara(pNegara);

        } else if (pilihan == 6) {
            // Cari Provinsi
            cout << "Cari di Negara: "; getline(cin, s1);
            cout << "Nama Provinsi : "; getline(cin, s2);
            pProvinsi = searchProvinsi(LI, s1, s2);
            printDetailProvinsi(pProvinsi);

        } else if (pilihan == 7) {
            // View All
            printAll(LI);

        } else if (pilihan == 8) {
            // Update Populasi (Hitung ulang)
            updatePopulasiOtomatis(LI);

        } else if (pilihan == 9) {
            // Analisis Negara
            MaxMinNegara(LI);

        } else if (pilihan == 10) {
            // Analisis Provinsi
            cout << "Masukkan Nama Negara: "; getline(cin, s1);
            MaxMinProvinsi(s1, LI); // Pastikan header sesuai (LI, s1) atau (s1, LI)

        } else if (pilihan == 11) {
            // Sort Negara
            sortingNegaraAscending(LI);
            cout << "[Info] Sorting Negara selesai." << endl;
            printAll(LI);

        } else if (pilihan == 12) {
            // Sort Provinsi
            cout << "Masukkan Negara target sorting: "; getline(cin, s1);
            pNegara = searchNegara(LI, s1);
            sortingProvinsiDescending(pNegara);

        } else if (pilihan == 13) {
            // Total Data Global
            printTotalData(LI);

        } else if (pilihan == 0) {
            cout << "Terima kasih." << endl;
        } else {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\n"; // Hanya enter kosong sebagai pemisah, tidak ada pause
    }

    return 0;
}
