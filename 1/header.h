#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>
using namespace std;

// --- DEFINISI STRUKTUR DATA ---
struct infotypeAnak {
    string namaProvinsi, ibuKotaProvinsi, gubernur;
    int populasiProvinsi, luasWilayah;
};

struct infotypeInduk {
    string namaNegara, kodeNegara, benua, mataUang, presiden;
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

// Alokasi
addressInduk alokasiNegara(infotypeInduk x);
addressAnak alokasiProvinsi(infotypeAnak x);

// Insert Induk (Negara)
void insertLastNegara(ListInduk &l, addressInduk p);
// Insert Anak (Provinsi) -> Butuh tahu mau dimasukkan ke Negara mana (string namaNegara)
void insertLastProvinsi(ListInduk &LI, string namaNegara, addressAnak p);

// Searching
addressInduk searchNegara(ListInduk l, string namaNegara); // Search by nama lebih umum
addressAnak searchProvinsi(ListInduk l, string namaNegara, string namaProvinsi);

// Delete Induk (Negara)
void deleteFirstNegara(ListInduk &l, addressInduk &p); // Pakai &p agar pointer di main jadi NULL
void deleteLastNegara(ListInduk &l, addressInduk &p);
void deleteAfterNegara(ListInduk &l, addressInduk prec, addressInduk &p);
void hapusNegara(ListInduk &l, string namaNegara); // Wrapper function

// Delete Anak (Provinsi)
void deleteFirstProvinsi(ListInduk &LI, string namaNegara, addressAnak &p);
void deleteLastProvinsi(ListInduk &LI, string namaNegara, addressAnak &p);
void deleteAfterProvinsi(ListInduk &LI, addressAnak prec, addressAnak &p); // Tipe data diperbaiki jadi addressAnak
void hapusProvinsi(ListAnak &LI, ListInduk &LA, string namaNegara);

//MinMax
addressInduk maxNegara(ListInduk l);
addressInduk minNegara(ListInduk l);
addressAnak minProvinsi(ListInduk LI, string x);
addressAnak maxProvinsi(ListInduk LI, string x);
void MaxMinNegara(ListInduk l);
void MaxMinProvinsi(ListInduk l);

void printAll(ListInduk l);


#endif // HEADER_H_INCLUDED
