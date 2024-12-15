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
    adr_pasien Q, ada;
    ada = FindPasien(LP, P->info.NIK, P->info.Nama);
    if (ada != NULL){
        cout << "Pasien Sudah Ada, Tidak dapat Menambahkan Pasien." << endl;
    } else {
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
}
void deletePasien(ListPasien &LP, ListDokter &LD, adr_pasien P){
    adr_dokter d;
    adr_relasi prevR, nextR;
    adr_pasien prevPasien = LP.first;

    if (LP.first == NULL) {
        cout << "List Pasien Kosong" << endl;
    } else {
        d = LD.first;
        while (d != NULL) {
            deleteAfterRelasi(d, P);
            d = d->next;
        }
        while (prevPasien->next != P) {
            prevPasien = prevPasien->next;
        }
        prevPasien->next = P->next;
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
            return Q;
        } else {
            Q = Q->next;
        }
    }
    return NULL;
}
void ShowPasien(ListPasien LP){
    adr_pasien Q;
    Q = LP.first;
    if (LP.first == NULL){
        cout << "List Pasien Kosong." << endl;
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
void hitungRelasiPasien(ListDokter LD, ListPasien LP, int &jumRelasi){
    jumRelasi = 0;
    adr_pasien p;
    adr_dokter d = LD.first;
    adr_relasi r;
    string temp, nama, NIK;

    cout << "Masukkan Nama Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, nama);

    cout << "Masukkan NIK Pasien : ";
    cin >> NIK;
    cout << endl;

    p = FindPasien(LP, NIK, nama);

    if (p != NULL) {
        while (d != NULL) {
            r = d->firstRelasi;
            while (r != NULL) {
                if (r->firstPasien->info.NIK == NIK && r->firstPasien->info.Nama == nama) {
                    jumRelasi++;
                    cout << " ID Dokter         : " << d->info.id << endl;
                    cout << " Nama Dokter       : " << d->info.nama << endl;
                    cout << " Spesialisasi      : " << d->info.spesialisasi << endl;
                    cout << " Jenis Kelamin     : " << d->info.jk << endl;
                    cout << endl;
                }
                r = r->nextRelasi;
                }
                d = d->next;
        }
        p = p->next;
    } else {
        cout << "Pasien Tidak ditemukan, mohon masukkan data dengan benar:)" << endl;
    }
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
            cout << "Nama Pasien            : " << p->info.Nama << endl;
            cout << "NIK Pasien             : " << p->info.NIK << endl;
            cout << "Jenis Kelamin          : " << p->info.JenisKelamin << endl;
            cout << "Tempat, Tanggal Lahir  : " << p->info.TTL << endl;
            cout << "Asuransi Kesehatan     : " << p->info.asuransiKesehatan << endl;
            cout << endl;
        }
        p = p->next;
    }
    return jumNoRelasi;
}
