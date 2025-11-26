#include"header.h"
//Mengecek apakah List Kosong
bool isEmpty(ListInduk l){
    if(l.first == nullptr){
        return true;
    }else{
        return false;
    }
}

//Membuat List
void createList(ListInduk &l){
    l.first = nullptr;
    l.last = nullptr;
}
void createListAnak(ListAnak &l){
    l.first = nullptr;
}

//Alokasi List
addressInduk alokasiNegara(infotypeInduk x){
    addressInduk p;
    p = new elmlistInduk;
    p->info = x;
    return p;
}
addressAnak alokasiProvinsi(infotypeAnak x){
    addressAnak p;
    p = new elmlistAnak;
    p->info = x;
    return p;
}

//Insert List
void insertLastNegara(ListInduk &l, addressInduk p){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
        p->next = nullptr;
        p->prev = nullptr;
        p->child = nullptr;
    }else{
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
        p->next = nullptr;
    }
}
void insertLastProvinsi(ListInduk &LI, string x, addressAnak p) {
    addressInduk q = LI.first;
    bool ketemu = false;
    while (q != nullptr && ketemu == false) {
        if (q->info.namaNegara == x) {
            ketemu = true;
        }else{
            q = q->next;
        }
    }
    if (ketemu) {
        if (q->child == nullptr) {
            q->child = p;
        } else {
            addressAnak lastAnak = q->child;
            while (lastAnak->next != nullptr) {
                lastAnak = lastAnak->next;
            }
            lastAnak->next = p;
            p->prev = lastAnak;
        }
    } else {
        cout << "Negara tidak ditemukan" << endl;
    }
}

//Mencari nilai max dan min
addressInduk maxNegara(ListInduk l) {
    if (isEmpty(l)) {
        return nullptr;
    } else {
        addressInduk p = l.first;
        addressInduk maxNode = l.first;
        int maxVal = p->info.totalPopulasi;

        while (p != nullptr) {
            if (p->info.totalPopulasi > maxVal) {
                maxVal = p->info.totalPopulasi;
                maxNode = p;
            }
            p = p->next;
        }
        return maxNode;
    }
}
addressInduk minNegara(ListInduk l) {
    if (isEmpty(l)) {
        return nullptr;
    } else {
        addressInduk p = l.first;
        addressInduk minNode = l.first;
        int minVal = p->info.totalPopulasi;

        while (p != nullptr) {
            if (p->info.totalPopulasi < minVal) {
                minVal = p->info.totalPopulasi;
                minNode = p;
            }
            p = p->next;
        }
        return minNode;
    }
}
addressAnak minProvinsi(ListInduk LI, string x) {
    addressInduk q = LI.first;
    bool cek = false;
    while (q != nullptr && cek == false) {
        if (q->info.namaNegara == x) {
            cek = true;
        }else{
            q = q->next;
        }
    }
    if (q == nullptr || q->child == nullptr) {
        return nullptr;
    }
    addressAnak p = q->child;
    addressAnak minNode = p;
    int minVal = p->info.populasiProvinsi;

    while (p != nullptr) {
        if (p->info.populasiProvinsi < minVal) {
            minVal = p->info.populasiProvinsi;
            minNode = p;
        }
        p = p->next;
    }
    return minNode;
}
addressAnak maxProvinsi(ListInduk LI, string x) {
    addressInduk q = LI.first;
    bool cek = false;
    while (q != nullptr && cek == false) {
        if (q->info.namaNegara == x) {
            cek = true;
        }else{
            q = q->next;
        }
    }
    if (q == nullptr || q->child == nullptr) {
        return nullptr;
    }
    addressAnak p = q->child;
    addressAnak minNode = p;
    int maxVal = p->info.populasiProvinsi;

    while (p != nullptr) {
        if (p->info.populasiProvinsi > maxVal) {
            maxVal = p->info.populasiProvinsi;
            maxNode = p;
        }
        p = p->next;
    }
    return maxNode;
}
void MaxMinNegara(ListInduk l){
    addressInduk maxN, minN;
    maxN = maxNegara(l);
    minN = minNegara(l);
    if(!isEmpty(l)){
        cout << "Total populasi terbesar adalah negara: "<<maxN->info.namaNegara << "Dengan detail negara";
        printDetailNegara(maxN);
        cout << endl;
        cout << "Total populasi terkecil adalah negara: "<<minN->info.namaNegara << "Dengan detail negara";
        printDetailNegara(minN);
    }else{
        cout << "List kosong";
    }
}
void MaxMinProvinsi(ListInduk l, string negara){
    if(!isEmpty(l)){
        addressAnak maxP, minP;
        maxP = maxProvinsi(l, negara);
        minP = minProvinsi(l, negara);
        cout << "Populasi paling banyak dari negara: " << negara << "adalah provinsi: " << maxP->info.namaProvinsi << "dengan detail provinsi";
        printDetailProvinsi(maxP);
        cout << "Populasi paling sedikit dari negara: " << negara << "adalah provinsi: " << minP->info.namaProvinsi << "dengan detail provinsi";
        printDetailProvinsi(minP);
    }
}


//Display
void printDetailNegara(addressInduk p) {
    if (p == nullptr) {
        cout << "\n[!] Data negara tidak ditemukan." << endl;
        return;
    }

    cout << "\n";
    cout << "========================================" << endl;
    cout << "          INFO NEGARA           " << endl;
    cout << "========================================" << endl;
    cout << "  Nama       : " << p->info.namaNegara << " (" << p->info.kodeNegara << ")" << endl;
    cout << "  Benua      : " << p->info.benua << endl;
    cout << "  Ibu Kota   : " << p->info.ibuKotaNegara << endl;
    cout << "  Mata Uang  : " << p->info.mataUang << endl;
    cout << "  Presiden   : " << p->info.presiden << endl;
    cout << "----------------------------------------" << endl;
    cout << "  Populasi   : " << p->info.totalPopulasi << " Jiwa" << endl;
    cout << "========================================" << endl;
}
void printDetailProvinsi(addressAnak p) {
    if (p == nullptr) {
        cout << "\n[!] Data provinsi tidak ditemukan atau kosong." << endl;
        return;
    }

    cout << "\n";
    cout << "========================================" << endl;
    cout << "          DETAIL PROVINSI               " << endl;
    cout << "========================================" << endl;
    cout << "  Nama Provinsi : " << p->info.namaProvinsi << endl;
    cout << "  Ibu Kota      : " << p->info.ibuKotaProvinsi << endl;
    cout << "  Gubernur      : " << p->info.gubernur << endl;
    cout << "----------------------------------------" << endl;
    cout << "  Populasi      : " << p->info.populasiProvinsi << " Jiwa" << endl;
    cout << "  Luas Wilayah  : " << p->info.luasWilayah << " km2" << endl;
    cout << "========================================" << endl;
}
