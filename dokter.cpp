#include "header.h"
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

adr_dokter FindDokter(ListDokter LD, string id, string nama){
    adr_dokter p = LD.first;
    while (p != NULL) {
        if (p->info.id == id && p->info.nama == nama) {
            cout << "Dokter Ditemukan" << endl;
            return p;
        }else {
            p = p->next;
        }
    }
    cout << "Dokter tidak ditemukan" << endl;
    return NULL;
}

int menu(){
    int select;

    cout << "-------------Rumah Sakit Budiman-------------" << endl;
    cout << "--Pilih Menu--" << endl;
    cout << "1. Show List Dokter" << endl;
    cout << "2. Show List Pasien" << endl;
    cout << "3. Show List Relasi" << endl;
    cout << "4. Tambahkan Dokter Baru" << endl;
    cout << "5. Tambahkan Pasien Baru" << endl;
    cout << "6. Tambahkan relasi Dokter dan Pasien" << endl;
    cout << "7. Hapus Dokter" << endl;
    cout << "8. Hapus pasien" << endl;
    cout << "9. Hapus relasi" << endl;
    cout << "10. Mencari Dokter" << endl;
    cout << "11. Mencari Pasien" << endl;
    cout << "12. Mencari Relasi" << endl;
    cout << "13. Mencari Pasien Dokter" << endl;
    cout << "14. Show data Dokter dan Pasiennya" << endl;
    cout << "15. Show data Pasien dan Dokternya" << endl;
    cout << "16. Hitung Relasi Dokter" << endl;
    cout << "17. Hitung Relasi Pasien tertentu" << endl;
    cout << "18. Hitung pasien yang tidak memiliki dokter" << endl;
    cout << "19. Edit Relasi" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------------------" << endl;

    cin >> select;
    return select;
}


