#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
#include <iomanip> // Tambahkan ini untuk setw() di print
using namespace std;

// --- DEFINISI STRUKTUR DATA ---
struct infotypeAnak {
    string namaProvinsi, ibuKotaProvinsi, gubernur;
    int populasiProvinsi, luasWilayah;
};

struct infotypeInduk {
    string namaNegara, kodeNegara, benua, mataUang, presiden, ibuKotaNegara;
    int totalPopulasi;
};

typedef struct elmlistInduk *addressInduk;
typedef struct elmlistAnak *addressAnak;

struct elmlistAnak {
    infotypeAnak info;
    addressAnak next;
    addressAnak prev;
};

struct elmlistInduk {
    infotypeInduk info;
    addressAnak child;
    addressInduk next;
    addressInduk prev;
};

struct ListInduk {
    addressInduk first;
    addressInduk last;
};

struct ListAnak {
    addressAnak first;
    addressAnak last;
};

// Umum
bool isEmpty(ListInduk l);
void createList(ListInduk &l);
void createListAnak(ListAnak &l); // Opsional, tapi dibiarkan jika diminta

// Alokasi
addressInduk alokasiNegara(infotypeInduk x);
addressAnak alokasiProvinsi(infotypeAnak x);

// Insert Induk (Negara)
void insertLastNegara(ListInduk &l, addressInduk p);
// Insert Anak (Provinsi)
void insertLastProvinsi(ListInduk &LI, string namaNegara, addressAnak p);

// Searching
addressInduk searchNegara(ListInduk l, string namaNegara);
addressAnak searchProvinsi(ListInduk l, string namaNegara, string namaProvinsi);

// Delete Induk (Negara)
void deleteFirstNegara(ListInduk &l, addressInduk p);
void deleteLastNegara(ListInduk &l, addressInduk p);
void deleteAfterNegara(ListInduk &l, addressInduk prec, addressInduk &p);
void hapusNegara(ListInduk &l, string namaNegara);

// Delete Anak (Provinsi)
void deleteFirstProvinsi(ListInduk &LI, string namaNegara, addressAnak &p);
void deleteLastProvinsi(ListInduk &LI, string namaNegara, addressAnak &p);
void deleteAfterProvinsi(ListInduk &LI, addressAnak prec, addressAnak &p);
void hapusProvinsi(ListInduk &LI, string namaNegara, string namaProvinsi);

// MinMax & Analisis
addressInduk maxNegara(ListInduk l);
addressInduk minNegara(ListInduk l);
addressAnak minProvinsi(ListInduk l, string negara); // Tambah parameter ListInduk
addressAnak maxProvinsi(ListInduk l, string negara); // Tambah parameter ListInduk
void MaxMinNegara(ListInduk l);
void MaxMinProvinsi(string negara, ListInduk l); // Tambah parameter ListInduk

//Hitung banyak negara & Provinsi
int countNegara(ListInduk l);
int countProvinsi(addressInduk p);


//Update
void updatePopulasiOtomatis(ListInduk &l);

//Sort
void sortingNegaraAscending(ListInduk &l);
void sortingProvinsiDescending(addressInduk p);

// Display
void printDetailNegara(addressInduk p);
void printDetailProvinsi(addressAnak p);
void printAll(ListInduk l);


// FITUR BARU (UPDATE MANUAL & TOTAL)
void updateDataNegara(ListInduk &l, string namaNegara);
void updateDataProvinsi(ListInduk &l, string namaNegara, string namaProvinsi);
void printTotalData(ListInduk l); // Untuk fitur Total Album/Lagu versi kamu

// HITUNG PROVINSI DI SUATU NEGARA
void hitungProvinsiTertentu(ListInduk l);


void showDashboard(ListInduk l);
#endif // HEADER_H_INCLUDED

