#include "header.h"
#include <iostream>
using namespace std;

void createListPasien(ListPasien &LP){
    LP.first = NULL;
}
adr_pasien createElmPasien(Pasien C){
    adr_pasien p = new elmPasien;
    p->info = C;
    p->next = NULL;
    return p;
}
void insertLastPasien(ListPasien &LP, adr_pasien P){
    adr_pasien Q;
    if (LP.first == NULL){
        LP.first = P;
    } else {
        Q = LP.first;
        while (Q->next != NULL) {
            Q = Q->next;
        }
        Q->next = P;
    }
}
void deleteFirstPasien(ListPasien &LP, adr_pasien &P){
    if (LP.first == NULL){
        P = NULL;
    } else {
        P = LP.first;
        LP.first = LP.first->next;
        P->next = NULL;
    }

}
adr_pasien FindPasien(ListPasien LP, string NIK, string nama){
    adr_pasien Q;
    bool ketemu = false;
    Q = LP.first;
    while (Q != NULL && !ketemu){
        if (Q->info.NIK == NIK && Q->info.Nama == nama) {
            ketemu = true;
            cout << "Pasien Ditemukan" << endl;
            return Q;
        } else {
            Q = Q->next;
        }
    }
    cout << "Pasien Tidak ditemukan" << endl;
    return NULL;
}
void ShowPasien(ListPasien LP){
    adr_pasien Q;
    Q = LP.first;
    if (LP.first == NULL){
        cout << "List Pasien Kosong" << endl;
    } else {
        cout << "List Pasien: " << endl;
        while (Q != NULL){
            cout << Q->info.Nama << endl;
            cout << Q->info.NIK << endl;
            cout << Q->info.JenisKelamin << endl;
            cout << Q->info.golonganDarah<< endl;
            cout << Q->info.berat << endl;
            cout << Q->info.tinggiBadan << endl;
            cout << Q->info.TTL << endl;
            cout << Q->info.usia << endl;
            cout << Q->info.asuransiKesehatan << endl;
            cout << Q->info.agama << endl;
        }
    }
}
void hitungRelasiPasien(ListDokter LD, ListPasien LP, int &jumRelasi);
int hitungPasienNoRelasi(ListDokter LD, ListPasien LP);
