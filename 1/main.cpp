#include <iostream>
#include "header.h"
#include <string>

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
    while (pilihan != 0)
    {

        showDashboard(LI);
        cin >> pilihan;
        cin.ignore(); // Membersihkan buffer enter

        cout << "\n----------------------------------------" << endl;

        // MENGGUNAKAN IF-ELSE (Pengganti Switch-Case agar tidak pakai break)

        if (pilihan == 1)
        {
            cout << "--- INPUT DATA NEGARA ---" << endl;
            cout << "Nama Negara    : ";
            getline(cin, s1);

            if (searchNegara(LI, s1) != nullptr)
            {
                cout << "[!] Gagal: Negara dengan nama '" << s1 << "' sudah terdaftar!" << endl;
            }
            else
            {
                dataNegara.namaNegara = s1;
                cout << "Kode Negara    : ";
                getline(cin, dataNegara.kodeNegara);
                cout << "Benua          : ";
                getline(cin, dataNegara.benua);
                cout << "Ibu Kota       : ";
                getline(cin, dataNegara.ibuKotaNegara);
                cout << "Presiden       : ";
                getline(cin, dataNegara.presiden);
                cout << "Mata Uang      : ";
                getline(cin, dataNegara.mataUang);
                cout << "Total Populasi : ";
                cin >> dataNegara.totalPopulasi;

                dataNegara.totalPopulasi = 0; // Set awal 0
                pNegara = alokasiNegara(dataNegara);
                insertLastNegara(LI, pNegara);

                // KONFIRMASI MANUAL TANPA PROSEDUR
                cout << "\n[BERHASIL] Negara berhasil ditambahkan:" << endl;
                printDetailNegara(pNegara);
                cout << "\nTekan ENTER untuk lanjut...";
                cin.ignore(); // Membersihkan buffer
                getline(cin, s1);
            }
        }
        else if (pilihan == 2)
        {
            // Tambah Provinsi
            cout << "--- INPUT DATA PROVINSI ---" << endl;
            cout << "Masukkan Nama Negara Tujuan: ";
            getline(cin, s1);

            pNegara = searchNegara(LI, s1);
            if (pNegara == nullptr)
            {
                cout << "[!] Negara tidak ditemukan." << endl;
            }
            else
            {
                cout << "Nama Provinsi  : ";
                getline(cin, s2);

                if (searchProvinsi(LI, s1, s2) != nullptr)
                {
                    cout << "[!] Gagal: Provinsi '" << s2 << "' sudah ada di negara " << s1 << "!" << endl;
                }
                else
                {
                    dataProvinsi.namaProvinsi = s2;
                    cout << "Ibu Kota Prov  : ";
                    getline(cin, dataProvinsi.ibuKotaProvinsi);
                    cout << "Gubernur       : ";
                    getline(cin, dataProvinsi.gubernur);
                    cout << "Luas Wilayah   : ";
                    cin >> dataProvinsi.luasWilayah;
                    cout << "Populasi       : ";
                    cin >> dataProvinsi.populasiProvinsi;

                    pProvinsi = alokasiProvinsi(dataProvinsi);
                    insertLastProvinsi(LI, s1, pProvinsi);
                    updatePopulasiOtomatis(LI);
                    cout << "\n[UPDATE] Data Negara setelah provinsi ditambah:" << endl;
                    pNegara = searchNegara(LI, s1);
                    printDetailNegara(pNegara);
                    cout << "\nTekan ENTER untuk lanjut...";
                    cin.ignore();
                    getline(cin, s1);
                }
            }
        }
        else if (pilihan == 3)
        {
            // Hapus Negara
            cout << "Nama Negara yang dihapus: ";
            getline(cin, s1);
            hapusNegara(LI, s1);
        }
        else if (pilihan == 4)
        {
            cout << "Dari Negara mana: ";
            getline(cin, s1);
            cout << "Nama Provinsi dihapus: ";
            getline(cin, s2);
            hapusProvinsi(LI, s1, s2);
            updatePopulasiOtomatis(LI);
            cout << "\n[UPDATE] Data Negara setelah provinsi dihapus:" << endl;
            pNegara = searchNegara(LI, s1);
            if (pNegara != nullptr)
            {
                printDetailNegara(pNegara);
            }
            cout << "\nTekan ENTER untuk lanjut...";
            getline(cin, s1);
        }
        else if (pilihan == 5)
        {
            // Cari Negara
            cout << "Cari Nama Negara: ";
            getline(cin, s1);
            pNegara = searchNegara(LI, s1);
            printDetailNegara(pNegara);
        }
        else if (pilihan == 6)
        {
            // Cari Provinsi
            cout << "Cari di Negara: ";
            getline(cin, s1);
            cout << "Nama Provinsi : ";
            getline(cin, s2);
            pProvinsi = searchProvinsi(LI, s1, s2);
            printDetailProvinsi(pProvinsi);
        }
        else if (pilihan == 7)
        {
            // View All
            printAll(LI);
        }
        else if (pilihan == 8)
        {
            // Analisis Negara
            MaxMinNegara(LI);
        }
        else if (pilihan == 9)
        {
            // Analisis Provinsi
            cout << "Masukkan Nama Negara: ";
            getline(cin, s1);
            MaxMinProvinsi(s1, LI); // Pastikan header sesuai (LI, s1) atau (s1, LI)
        }
        else if (pilihan == 10)
        {
            // Sort Negara
            sortingNegaraAscending(LI);
            cout << "\n[INFO] Data setelah diurutkan:" << endl;
            printAll(LI);
            cout << "\nTekan ENTER untuk lanjut...";
            getline(cin, s1);
        }
        else if (pilihan == 11)
        {
            // Sort Provinsi
            cout << "Masukkan Negara target sorting: ";
            getline(cin, s1);
            pNegara = searchNegara(LI, s1);
            sortingProvinsiDescending(pNegara);
        }
        else if (pilihan == 12)
        {
            // Total Data Global
            printTotalData(LI);
        }
        else if (pilihan == 0)
        {
            cout << "Terima kasih." << endl;
        }
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\n"; // Hanya enter kosong sebagai pemisah, tidak ada pause
    }

    return 0;
}
