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
void deleteFirstPasien(ListPasien &LP, ListDokter &LD, adr_pasien &P){
    adr_dokter d;
    adr_relasi prevR, nextR;
    adr_pasien p;

    if (LP.first == NULL) {
        cout << "List Pasien Kosong" << endl;
    } else {
        p = LP.first;
        d = LD.first;
        while (d != NULL) {
            prevR = d->firstRelasi;
            nextR = d->firstRelasi->nextRelasi;
            if (d->firstRelasi->firstPasien->info.NIK == p->info.NIK){
                d->firstRelasi = d->firstRelasi->nextRelasi;
                prevR->nextRelasi = NULL;
            }
            while (nextR != NULL){
                if (nextR->firstPasien->info.NIK == p->info.NIK) {
                    prevR->nextRelasi = nextR->nextRelasi;
                    nextR->nextRelasi = NULL;
                } else {
                    prevR = nextR;
                    nextR = nextR->nextRelasi;
                }
            }
            d = d->next;
        }
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
            cout << "------------------------------------------------" << endl;
            cout << "Nama Pasien                        : "<< Q->info.Nama << endl;
            cout << "NIK Pasien                         : "<< Q->info.NIK << endl;
            cout << "Jenis Kelamin Pasien               : "<< Q->info.JenisKelamin << endl;
            cout << "Golongan Darah Pasien              : "<< Q->info.golonganDarah<< endl;
            cout << "Berat Badan Pasien                 : "<< Q->info.berat << endl;
            cout << "Tinggi Badan Pasien                : "<< Q->info.tinggiBadan << endl;
            cout << "Tempat dan Tanggal Lahir Pasien    : "<< Q->info.TTL << endl;
            cout << "Usia Pasien                        : "<< Q->info.usia << endl;
            cout << "Kepemilikan Asuransi Pasien        : "<< Q->info.asuransiKesehatan << endl;
            cout << "Agama Pasien                       : "<< Q->info.agama << endl;
            cout << "------------------------------------------------" << endl;
            Q = Q->next;
        }
    }
}
int hitungRelasiPasien(ListDokter LD, ListPasien LP, string NIK, string nama){
    int jumRelasi = 0;
    adr_pasien p;
    adr_dokter d = LD.first;
    adr_relasi r;
    p = FindPasien(LP, NIK, nama);
    if (p != NULL) {
        while (d != NULL) {
            r = d->firstRelasi;
            while (r != NULL) {
                if (r->firstPasien->info.NIK == NIK && r->firstPasien->info.Nama == nama) {
                    jumRelasi++;
                } else {
                    r = r->nextRelasi;
                }
            }
            d = d->next;
        }
    } else {
        cout << "Pasien Tidak ditemukan, mohon masukkan data dengan benar:)" << endl;
    }
    return jumRelasi;
}
int hitungPasienNoRelasi(ListDokter LD, ListPasien LP){
    int jumNoRelasi = 0;
    adr_dokter d = LD.first;
    adr_pasien p = LP.first;
    adr_relasi r;
    bool ketemu;
    while (p != NULL) {
        ketemu = false;
        while (d != NULL && !ketemu) {
            r = d->firstRelasi;
            while (r != NULL && !ketemu) {
                if (r->firstPasien->info.NIK == p->info.NIK) {
                    ketemu = true;
                } else {
                    r = r->nextRelasi;
                }
            }
            d = d->next;
        }
        if (!ketemu) {
            jumNoRelasi++;
        }
        p = p->next;
    }
    return jumNoRelasi;
}
