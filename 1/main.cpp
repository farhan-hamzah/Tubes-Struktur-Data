#include <iostream>
#include "header.h"
#include <string>

using namespace std;

int main()
{
    // 1. Setup List
    ListInduk LI;
    createList(LI);

    int pilihan = -1;
    string s1, s2;
    infotypeInduk dataNegara;
    infotypeAnak dataProvinsi;
    addressInduk pNegara;
    addressAnak pProvinsi;

    // 2. Loop Menu
    while (pilihan != 0)
    {
        showDashboard(LI);
        cin >> pilihan;

        cout << "\n----------------------------------------" << endl;

        if (pilihan == 1)
        {
            // --- TAMBAH NEGARA ---
            cout << "--- INPUT DATA NEGARA ---" << endl;
            cout << "Nama Negara (Tanpa Spasi) : ";
            cin >> s1;

            if (searchNegara(LI, s1) != nullptr)
            {
                cout << "[!] Gagal: Negara '" << s1 << "' sudah terdaftar!" << endl;
            }
            else
            {
                dataNegara.namaNegara = s1;
                cout << "Kode Negara    : "; cin >> dataNegara.kodeNegara;
                cout << "Benua          : "; cin >> dataNegara.benua;
                cout << "Ibu Kota       : "; cin >> dataNegara.ibuKotaNegara;
                cout << "Presiden       : "; cin >> dataNegara.presiden;
                cout << "Mata Uang      : "; cin >> dataNegara.mataUang;

                // Populasi dihitung otomatis dari provinsi (set awal 0)
                dataNegara.totalPopulasi = 0;

                pNegara = alokasiNegara(dataNegara);
                insertLastNegara(LI, pNegara);

                cout << "\n[BERHASIL] Negara berhasil ditambahkan." << endl;
            }
        }
        else if (pilihan == 2)
        {
            // --- TAMBAH PROVINSI ---
            cout << "--- INPUT DATA PROVINSI ---" << endl;
            cout << "Nama Negara Tujuan: ";
            cin >> s1;

            pNegara = searchNegara(LI, s1);
            if (pNegara == nullptr)
            {
                cout << "[!] Error: Negara tidak ditemukan." << endl;
            }
            else
            {
                cout << "Nama Provinsi (Tanpa Spasi) : ";
                cin >> s2;

                if (searchProvinsi(LI, s1, s2) != nullptr)
                {
                    cout << "[!] Gagal: Provinsi '" << s2 << "' sudah ada!" << endl;
                }
                else
                {
                    dataProvinsi.namaProvinsi = s2;
                    cout << "Ibu Kota Prov  : "; cin >> dataProvinsi.ibuKotaProvinsi;
                    cout << "Gubernur       : "; cin >> dataProvinsi.gubernur;
                    cout << "Luas Wilayah   : "; cin >> dataProvinsi.luasWilayah;
                    // SUDAH DITAMBAHKAN (JT) DI SINI
                    cout << "Populasi (JT)  : "; cin >> dataProvinsi.populasiProvinsi;

                    pProvinsi = alokasiProvinsi(dataProvinsi);
                    insertLastProvinsi(LI, s1, pProvinsi);
                    updatePopulasiOtomatis(LI);

                    cout << "\n[BERHASIL] Provinsi ditambahkan ke " << s1 << endl;
                }
            }
        }
        else if (pilihan == 3)
        {
            cout << "Nama Negara yang dihapus: ";
            cin >> s1;
            hapusNegara(LI, s1);
        }
        else if (pilihan == 4)
        {
            cout << "Dari Negara mana: "; cin >> s1;
            cout << "Nama Provinsi dihapus: "; cin >> s2;
            hapusProvinsi(LI, s1, s2);
            updatePopulasiOtomatis(LI);
        }
        else if (pilihan == 5)
        {
            cout << "Cari Nama Negara: ";
            cin >> s1;
            pNegara = searchNegara(LI, s1);
            printDetailNegara(pNegara);
        }
        else if (pilihan == 6)
        {
            cout << "Cari di Negara: "; cin >> s1;
            cout << "Nama Provinsi : "; cin >> s2;
            pProvinsi = searchProvinsi(LI, s1, s2);
            printDetailProvinsi(pProvinsi);
        }
        else if (pilihan == 7)
        {
            printAll(LI);
        }
        else if (pilihan == 8)
        {
            MaxMinNegara(LI);
        }
        else if (pilihan == 9)
        {
            cout << "Masukkan Nama Negara: ";
            cin >> s1;
            MaxMinProvinsi(LI, s1);
        }
        else if (pilihan == 10)
        {
            sortingNegaraAscending(LI);
            cout << "[INFO] Negara telah diurutkan (Ascending)." << endl;
            printAll(LI);
        }
        else if (pilihan == 11)
        {
            cout << "Masukkan Negara target sorting: ";
            cin >> s1;
            pNegara = searchNegara(LI, s1);
            if (pNegara != nullptr) {
                sortingProvinsiDescending(pNegara);
            } else {
                cout << "[!] Negara tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 12)
        {
            printTotalData(LI);
        }
        else if (pilihan == 13)
        {
            cout << "Nama Negara yang ingin diubah: ";
            cin >> s1;
            updateDataNegara(LI, s1);
        }
        else if (pilihan == 14)
        {
            cout << "Nama Negara: "; cin >> s1;
            cout << "Nama Provinsi yang ingin diubah: "; cin >> s2;
            updateDataProvinsi(LI, s1, s2);
        }
        else if (pilihan == 15)
        {
            cout << "Masukkan Nama Negara: ";
            cin >> s1;
            pNegara = searchNegara(LI, s1);

            if (pNegara != nullptr) {
                int jumlahProv = countProvinsi(pNegara);
                cout << "\n----------------------------------------" << endl;
                cout << "  INFO STATISTIK: " << pNegara->info.namaNegara << endl;
                cout << "----------------------------------------" << endl;
                cout << "  Jumlah Provinsi : " << jumlahProv << " Provinsi" << endl;

                if (jumlahProv == 0) {
                    cout << "  (Negara ini belum memiliki data provinsi)" << endl;
                }
            } else {
                cout << "[!] Negara tidak ditemukan." << endl;
            }
        }
        else if (pilihan == 16)
        {
            int total = countNegara(LI);
            cout << "  TOTAL NEGARA TERDAFTAR" << endl;
            cout << "----------------------------------------" << endl;
            cout << "  Jumlah : " << total << " Negara" << endl;
            cout << "\nTekan Enter untuk kembali...";
            cin.ignore();
            cin.get();
        }
        else if (pilihan == 0)
        {
            cout << "Terima kasih." << endl;
        }
        else
        {
            cout << "Pilihan tidak valid!" << endl;
        }

        cout << "\n"; // Pemisah antar menu
    }

    return 0;
}
