#include "pasien.h"
#include <iostream>
using namespace std;

void createListDokter(ListDokter &LD){
    LD.first = NULL;
    LD.last = NULL;
}

adr_dokter createElmDokter(dokter D){
    adr_dokter p = new elmDokter;
    p->info = D;
    p->next = NULL;
    p->prev = NULL;
    return p;
}

void insertLastDokter(ListDokter &LD, adr_dokter p){
    if (LD.first == NULL){
        LD.first = p;
        LD.last = p;
    }else {
        p->prev = LD.last;
        LD.last->next = p;
        LD.last = p;
    }
}

void DeleteLastDokter(ListDokter &LD, adr_dokter &p){
    p = LD.last;
    if (LD.first == NULL){
        LD.first = NULL;
        LD.last = NULL;
    }else {
        LD.last = LD.last->prev;
        p->prev = NULL;
        LD.last->next = NULL;
    }
}

void showDokter(ListDokter LD){
    adr_dokter p = LD.first;
    if (LD.first == NULL){
        cout << "list kosong" << endl;
    }else {
        cout << "List Dokter: " << endl;
        while (p != NULL){
            cout << p->info.id << endl;
            cout << p->info.nama << endl;
            cout << p->info.spesialisasi << endl;
            cout << p->info.jk << endl;
            cout << p->info.umur << endl;
            cout << p->info.NKD << endl;
            cout << p->info.nomorHP << endl;
        }
    }
}

adr_dokter FindDokter(ListDokter LD, string id, string nama, string spesialisasi){
    adr_dokter p = LD.first;
    while (p != NULL) {
        if (p->info.id == id && p->info.nama == nama && p->info.spesialisasi == spesialisasi) {
            cout << "Dokter Ditemukan" << endl;
            return p;
        }else {
            p = p->next;
        }
    }
    cout << "Dokter tidak ditemukan" << endl;
    return NULL;
}
