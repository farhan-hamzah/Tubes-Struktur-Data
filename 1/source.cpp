#include"header.h"
bool isEmpty(ListInduk l){
    if(l.first == nullptr){
        return true;
    }else{
        return false;
    }
}
void createList(ListInduk &l){
    l.first = nullptr;
}
void createListAnak(ListAnak &l){
    l.first = nullptr;
}
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
void insertLastNegara(ListInduk &l, addressInduk p){
    if(isEmpty(l)){
        l.first = p;
        l.last = p;
        p->next = nullptr;
        p->prev = nullptr;
    }else{
        p->prev = l.last;
        l.last->next = p;
        l.last = p;
        p->next = nullptr;
    }
}
void insertLastProvinsi(ListAnak &LA, ListInduk &LI, string x, addressAnak p){
    if(isEmpty(LI)){
        cout << "Negara tidak ditemukan" <<;
    }else{
        bool cek;
        cek = false;
        addressInduk q;
        q = LI.first;
        while(q != nullptr){
            if(q->next->info.namaNegara == x){
                cek = true;
            }
            q = q->next;
        }
        if(cek == true){
            if(isEmpty(LA)){
                LA->first = p;
                LA->last = p;
                p->next = nullptr;
                p->prev = nullptr;
            }else{
                LA.last->next = p;
                p->prev = LA.last;
                p = LA.last;
                p->next = nullptr;
            }
        }
    }
}
addressInduk max(ListInduk l){
    if(isEmpty(l)){
        return nullptr;
    }else{
        addressInduk p,q;
        p = l.first;
        int cek;
        cek = p->info.totalPopulasi;
        while(p!= nullptr){
            if(p->info.totalPopulasi > cek){
                cek = p->info.totalPopulasi;
                q = p;
            }
        }
    }
    return q;
}
addressInduk min(ListInduk l){
    if(isEmpty(l)){
        return nullptr;
    }else{
        addressInduk p,q;
        p = l.first;
        int cek;
        cek = p->info.totalPopulasi;
        while(p!= nullptr){
            if(p->info.totalPopulasi < cek){
                cek = p->info.totalPopulasi;
                q = p;
            }
        }
    }
    return q;
}
addressAnak min(ListInduk LI, ListAnak LA, string x){
    if(isEmpty(LI)){
        return nullptr;
    }else{
        addressInduk p;
        p = LI.first;
        bool cek = false;
        while(p != nullptr){
            if(p->info.namaNegara == x){
                cek = true;
            }
            p = p->next;
        }
        if(cek == false){
            return nullptr;
        }else{

        }
    }
}
