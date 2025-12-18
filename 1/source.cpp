#include "header.h"
// Mengecek apakah List Kosong
bool isEmpty(ListInduk l)
{
    if (l.first == nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Membuat List
void createList(ListInduk &l)
{
    l.first = nullptr;
    l.last = nullptr;
}
void createListAnak(ListAnak &l)
{
    l.first = nullptr;
}

// Alokasi List
addressInduk alokasiNegara(infotypeInduk x)
{
    addressInduk p;
    p = new elmlistInduk;
    p->info = x;
    return p;
}
addressAnak alokasiProvinsi(infotypeAnak x)
{
    addressAnak p;
    p = new elmlistAnak;
    p->info = x;
    return p;
}

// Insert List
void insertLastNegara(ListInduk &l, addressInduk p)
{
    if (searchNegara(l, p->info.namaNegara) != nullptr)
    {
        cout << "[!] Gagal: Negara dengan nama '" << p->info.namaNegara << "' sudah ada dalam daftar." << endl;
        delete p; // Dealokasi p karena tidak jadi dimasukkan
        return;
    }

    if (isEmpty(l))
    {
        l.first = p;
        l.last = p;
        p->next = nullptr;
        p->prev = nullptr;
        p->child = nullptr;
    }
    else
    {
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
        p->next = nullptr;
        p->child = nullptr; // Pastikan child diinisialisasi null
    }
}

void insertLastProvinsi(ListInduk &LI, string x, addressAnak p)
{
    addressInduk q = searchNegara(LI, x);

    if (q != nullptr)
    {
        if (searchProvinsi(LI, x, p->info.namaProvinsi) != nullptr)
        {
            cout << "[!] Gagal: Provinsi '" << p->info.namaProvinsi << "' sudah terdaftar di negara " << x << "." << endl;
            delete p; // Dealokasi p karena tidak jadi dimasukkan
            return;
        }

        if (q->child == nullptr)
        {
            q->child = p;
            p->next = nullptr;
            p->prev = nullptr;
        }
        else
        {
            addressAnak lastAnak = q->child;
            while (lastAnak->next != nullptr)
            {
                lastAnak = lastAnak->next;
            }
            lastAnak->next = p;
            p->prev = lastAnak;
            p->next = nullptr;
        }
    }
    else
    {
        cout << "[!] Gagal: Negara '" << x << "' tidak ditemukan." << endl;
        delete p;
    }
}

// Searching
addressInduk searchNegara(ListInduk l, string negara)
{
    addressInduk p;
    p = l.first;
    if (isEmpty(l))
    {
        return nullptr;
    }
    else
    {
        bool cek = false;
        while (p != nullptr && cek == false)
        {
            if (p->info.namaNegara == negara)
            {
                return p;
                cek = false;
            }
            else
            {
                p = p->next;
            }
        }
    }
    return p;
}
addressAnak searchProvinsi(ListInduk l, string namaNegara, string namaProvinsi)
{
    addressInduk p = searchNegara(l, namaNegara);
    if (p == nullptr)
    {
        return nullptr;
    }
    addressAnak q = p->child;
    while (q != nullptr)
    {
        if (q->info.namaProvinsi == namaProvinsi)
        {
            return q;
        }
        q = q->next;
    }

    return nullptr;
}

// Mencari nilai max dan min
addressInduk maxNegara(ListInduk l)
{
    if (isEmpty(l))
    {
        return nullptr;
    }
    else
    {
        addressInduk p = l.first;
        addressInduk maxNode = l.first;
        int maxVal = p->info.totalPopulasi;

        while (p != nullptr)
        {
            if (p->info.totalPopulasi > maxVal)
            {
                maxVal = p->info.totalPopulasi;
                maxNode = p;
            }
            p = p->next;
        }
        return maxNode;
    }
}
addressInduk minNegara(ListInduk l)
{
    if (isEmpty(l))
    {
        return nullptr;
    }
    else
    {
        addressInduk p = l.first;
        addressInduk minNode = l.first;
        int minVal = p->info.totalPopulasi;

        while (p != nullptr)
        {
            if (p->info.totalPopulasi < minVal)
            {
                minVal = p->info.totalPopulasi;
                minNode = p;
            }
            p = p->next;
        }
        return minNode;
    }
}

addressAnak minProvinsi(ListInduk l, string negara)
{
    addressInduk p = searchNegara(l, negara);
    if (p == nullptr || p->child == nullptr)
    {
        return nullptr;
    }
    else
    {
        addressAnak q = p->child;
        addressAnak minNode = q;
        int minVal = q->info.populasiProvinsi;

        while (q != nullptr)
        {
            if (q->info.populasiProvinsi < minVal)
            {
                minVal = q->info.populasiProvinsi;
                minNode = q;
            }
            q = q->next;
        }
        return minNode;
    }
}

addressAnak maxProvinsi(ListInduk l, string negara)
{
    addressInduk p = searchNegara(l, negara);
    if (p == nullptr || p->child == nullptr)
    {
        return nullptr;
    }
    else
    {
        addressAnak q = p->child;
        addressAnak maxNode = q;
        int maxVal = q->info.populasiProvinsi;

        while (q != nullptr)
        {
            if (q->info.populasiProvinsi > maxVal)
            {
                maxVal = q->info.populasiProvinsi;
                maxNode = q;
            }
            q = q->next;
        }
        return maxNode;
    }
}

void MaxMinNegara(ListInduk l)
{
    addressInduk maxN, minN;
    maxN = maxNegara(l);
    minN = minNegara(l);
    if (!isEmpty(l))
    {
        cout << "Total populasi terbesar adalah negara: " << maxN->info.namaNegara << "Dengan detail negara";
        printDetailNegara(maxN);
        cout << endl;
        cout << "Total populasi terkecil adalah negara: " << minN->info.namaNegara << "Dengan detail negara";
        printDetailNegara(minN);
    }
    else
    {
        cout << "List kosong";
    }
}
void MaxMinProvinsi(string negara, ListInduk l)
{
    addressInduk p;
    p = searchNegara(l, negara);
    if (p != nullptr)
    {
        addressAnak maxP, minP;
        maxP = maxProvinsi(l, negara);
        minP = minProvinsi(l, negara);
        cout << "Populasi paling banyak dari negara: " << negara << "adalah provinsi: " << maxP->info.namaProvinsi << "dengan detail provinsi";
        printDetailProvinsi(maxP);
        cout << "Populasi paling sedikit dari negara: " << negara << "adalah provinsi: " << minP->info.namaProvinsi << "dengan detail provinsi";
        printDetailProvinsi(minP);
    }
    else
    {
        cout << "Negara tidak ditemukan";
    }
}

// Hapus Negara
void deleteFirstNegara(ListInduk &l, addressInduk p)
{
    if (isEmpty(l))
    {
        cout << "List kosong";
    }
    else if (l.first->next == nullptr)
    {
        l.first = nullptr;
    }
    else
    {
        p = l.first;
        l.first = p->next;
        p->next = nullptr;
    }
}
void deleteLastNegara(ListInduk &l, addressInduk p)
{
    if (isEmpty(l))
    {
        cout << "List kosong";
    }
    else
    {
        p = l.last;
        l.last = l.last->prev;
        l.last->next = nullptr;
        p->prev = nullptr;
    }
}
void deleteAfterNegara(ListInduk &l, addressInduk prec, addressInduk &p)
{
    p = prec->next;
    prec->next = p->next;
    if (p->next != nullptr)
    {
        p->next->prev = prec;
    }
    else
    {
        l.last = prec;
    }
    p->next = nullptr;
    p->prev = nullptr;
}

void hapusNegara(ListInduk &l, string namaNegara)
{
    addressInduk p;
    p = searchNegara(l, namaNegara);
    if (p != nullptr)
    {
        if (p == l.first)
        {
            deleteFirstNegara(l, p);
        }
        else if (p == l.last)
        {
            deleteLastNegara(l, p);
        }
        else
        {
            deleteAfterNegara(l, p->prev, p);
        }
    }
    else
    {
        cout << "Negara Tidak Ditemukan";
    }
}

void deleteFirstProvinsi(ListInduk &LI, string namaNegara, addressAnak &p)
{
    addressInduk negara = searchNegara(LI, namaNegara);
    if (negara == nullptr)
    {
        cout << "Negara tidak ditemukan." << endl;
        p = nullptr;
        return;
    }
    if (negara->child == nullptr)
    {
        cout << "Tidak ada provinsi di negara ini." << endl;
        p = nullptr;
    }
    else
    {
        p = negara->child;
        negara->child = p->next;

        if (negara->child != nullptr)
        {
            negara->child->prev = nullptr;
        }

        p->next = nullptr;
        p->prev = nullptr;
    }
}

void deleteLastProvinsi(ListInduk &LI, string namaNegara, addressAnak &p)
{
    addressInduk negara = searchNegara(LI, namaNegara);

    if (negara == nullptr)
    {
        cout << "Negara tidak ditemukan." << endl;
        p = nullptr;
        return;
    }

    if (negara->child == nullptr)
    {
        cout << "Tidak ada provinsi." << endl;
        p = nullptr;
    }
    else
    {
        addressAnak q = negara->child;
        if (q->next == nullptr)
        {
            deleteFirstProvinsi(LI, namaNegara, p);
        }
        else
        {
            while (q->next != nullptr)
            {
                q = q->next;
            }
            p = q;
            q->prev->next = nullptr;
            p->prev = nullptr;
        }
    }
}

void deleteAfterProvinsi(ListInduk &LI, addressAnak prec, addressAnak &p)
{
    if (prec == nullptr || prec->next == nullptr)
    {
        cout << "Gagal hapus after (prec null atau tidak ada elemen setelahnya)." << endl;
        p = nullptr;
    }
    else
    {
        p = prec->next;
        prec->next = p->next;

        if (p->next != nullptr)
        {
            p->next->prev = prec;
        }

        p->next = nullptr;
        p->prev = nullptr;
    }
}

void hapusProvinsi(ListInduk &LI, string namaNegara, string namaProvinsi)
{
    addressInduk negara = searchNegara(LI, namaNegara);

    if (negara != nullptr)
    {
        addressAnak p = searchProvinsi(LI, namaNegara, namaProvinsi);

        if (p != nullptr)
        {
            addressAnak temp;

            if (p == negara->child)
            {
                deleteFirstProvinsi(LI, namaNegara, temp);
            }
            else if (p->next == nullptr)
            {
                deleteLastProvinsi(LI, namaNegara, temp);
            }
            else
            {
                deleteAfterProvinsi(LI, p->prev, temp);
            }
            cout << "Provinsi " << namaProvinsi << " berhasil dihapus." << endl;
        }
        else
        {
            cout << "Provinsi tidak ditemukan." << endl;
        }
    }
    else
    {
        cout << "Negara tidak ditemukan." << endl;
    }
}

// Menghitung ada berapa negara dan provinsi
int countNegara(ListInduk l)
{
    addressInduk p;
    p = l.first;
    int i = 0;
    if (isEmpty(l))
    {
        return 0;
    }
    while (p != nullptr)
    {
        p = p->next;
        i += 1;
    }
    return i;
}
int countProvinsi(addressInduk p)
{
    if (p == nullptr || p->child == nullptr)
    {
        return 0;
    }
    else
    {
        int i = 0;
        addressAnak q = p->child;
        while (q != nullptr)
        {
            i++;
            q = q->next;
        }
        return i;
    }
}

void updatePopulasiOtomatis(ListInduk &l)
{
    addressInduk p = l.first;
    while (p != nullptr)
    {
        int total = 0;
        addressAnak q = p->child;
        while (q != nullptr)
        {
            total += q->info.populasiProvinsi;
            q = q->next;
        }
        p->info.totalPopulasi = total;
        p = p->next;
    }
}

// Sorting
void sortingNegaraAscending(ListInduk &l)
{
    if (isEmpty(l))
    {
        cout << "List kosong, tidak ada yang bisa diurutkan." << endl;
        return;
    }

    addressInduk p = l.first;
    while (p != nullptr)
    {
        addressInduk minNode = p;
        addressInduk q = p->next;

        while (q != nullptr)
        {
            if (q->info.totalPopulasi < minNode->info.totalPopulasi)
            {
                minNode = q;
            }
            q = q->next;
        }

        if (minNode != p)
        {
            infotypeInduk tempInfo = p->info;
            p->info = minNode->info;
            minNode->info = tempInfo;

            addressAnak tempChild = p->child;
            p->child = minNode->child;
            minNode->child = tempChild;
        }
        p = p->next;
    }
    cout << "Sorting Negara selesai (Ascending)." << endl;
}
void sortingProvinsiDescending(addressInduk p)
{
    // 1. Validasi: Cek apakah negara ada atau provinsinya kosong
    if (p == nullptr || p->child == nullptr)
    {
        cout << "Negara tidak ada atau belum memiliki provinsi." << endl;
        return;
    }

    // Cek jika hanya ada 1 provinsi, tidak perlu sorting
    if (p->child->next == nullptr)
    {
        return;
    }

    addressAnak ptr;
    addressAnak temp;
    addressAnak pindah;
    ptr = p->child;

    while (ptr != nullptr)
    {
        temp = ptr;
        pindah = ptr->next;

        while (pindah != nullptr)
        {
            if (pindah->info.populasiProvinsi > temp->info.populasiProvinsi)
            {
                temp = pindah;
            }
            pindah = pindah->next;
        }

        if (temp != ptr)
        {
            infotypeAnak dataSementara = ptr->info;
            ptr->info = temp->info;
            temp->info = dataSementara;
        }

        ptr = ptr->next;
    }

    cout << "Sorting Provinsi di negara " << p->info.namaNegara << " (Descending) selesai." << endl;
}

// Display
void printDetailNegara(addressInduk p)
{
    if (p == nullptr)
    {
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
void printDetailProvinsi(addressAnak p)
{
    if (p == nullptr)
    {
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
void printAll(ListInduk l)
{
    if (isEmpty(l))
    {
        cout << "Data Kosong (Tidak ada negara terdaftar)." << endl;
        return;
    }

    addressInduk p = l.first;
    while (p != nullptr)
    {
        printDetailNegara(p);
        addressAnak q = p->child;
        if (q == nullptr)
        {
            cout << "\t[!] Belum ada data provinsi di negara ini." << endl;
        }
        else
        {
            cout << "\tDAFTAR PROVINSI:" << endl;
            int i = 1;
            while (q != nullptr)
            {
                cout << "\t" << i << ". " << q->info.namaProvinsi
                     << " (Pop: " << q->info.populasiProvinsi << ")" << endl;
                q = q->next;
                i++;
            }
        }
        p = p->next; // Lanjut ke negara berikutnya
    }
    cout << "\n========================================\n"
         << endl;
}

void showDashboard(ListInduk l)
{
    int totalNegara = countNegara(l);

    cout << "================================================================" << endl;
    cout << "           APLIKASI PENCATATAN DATA NEGARA & PROVINSI           " << endl;
    cout << "================================================================" << endl;
    cout << "  [ STATISTIK DATA SAAT INI ]" << endl;
    cout << "  > Jumlah Negara Terdaftar : " << totalNegara << endl;
    cout << "  > Status Database         : " << (isEmpty(l) ? "KOSONG" : "TERISI") << endl;
    cout << "================================================================" << endl;
    cout << "  [ MENU UTAMA ]" << endl;
    cout << "  1.  Tambah Negara Baru" << endl;
    cout << "  2.  Tambah Provinsi ke Negara" << endl;
    cout << "  3.  Hapus Negara" << endl;
    cout << "  4.  Hapus Provinsi" << endl;
    cout << "  5.  Cari Data Negara (Detail)" << endl;
    cout << "  6.  Cari Data Provinsi (Detail)" << endl;
    cout << "  7.  Tampilkan Seluruh Data (View All)" << endl;
    cout << "  8.  Tampilkan Negara Terpadat & Tersepi (Max/Min)" << endl;         // Geser naik
    cout << "  9.  Tampilkan Provinsi Terpadat & Tersepi di suatu Negara" << endl; // Geser naik
    cout << "  10. Sorting Negara (Ascending - Populasi)" << endl;                 // Geser naik
    cout << "  11. Sorting Provinsi (Descending - Populasi)" << endl;              // Geser naik
    cout << "  12. Laporan Total Data Global" << endl;                             // Geser naik
    cout << "----------------------------------------------------------------" << endl;
    cout << "  0.  KELUAR" << endl;
    cout << "================================================================" << endl;
    cout << "  Pilihan Anda [0-12] : ";
}
void printTotalData(ListInduk l)
{
    int jumNegara = countNegara(l);
    int jumProvinsi = 0;

    addressInduk p = l.first;
    while (p != nullptr)
    {
        jumProvinsi += countProvinsi(p);
        p = p->next;
    }

    cout << "\n=== LAPORAN TOTAL DATA ===" << endl;
    cout << "Total Negara   : " << jumNegara << endl;
    cout << "Total Provinsi : " << jumProvinsi << endl;
    cout << "==========================" << endl;
}
