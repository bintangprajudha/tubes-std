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
    p->firstRelasi = NULL;
    return p;
}

void insertLastDokter(ListDokter &LD, adr_dokter p) {
    adr_dokter current = LD.first;
    while (current != NULL) {
        if (current->info.id == p->info.id) {
            cout << endl;
            cout << "ID dokter sudah terdaftar." << endl;
            cout << "Silahkan gunakan ID yang lain." << endl;
            return;
        }
        current = current->next;
    }
    if (LD.first == NULL) {
        LD.first = p;
        LD.last = p;
    } else {
        p->prev = LD.last;
        LD.last->next = p;
        LD.last = p;
    }
}

void DeleteLastDokter(ListDokter &LD, adr_dokter &P){
    if (LD.first == nullptr) {
        // List kosong
        cout << "ListDokter kosong, tidak ada data yang bisa dihapus." << endl;
        P = nullptr;
    } else {
        P = LD.last;
        adr_relasi rel = P->firstRelasi;
        while (rel != nullptr) {
            adr_relasi tempRelasi = rel;
            rel = rel->nextRelasi;
            delete tempRelasi;
        }
        P->firstRelasi = nullptr;

        if (LD.first == LD.last) {
            LD.first = nullptr;
            LD.last = nullptr;
        } else {
            LD.last = P->prev;
            LD.last->next = nullptr;
        }
        delete P;
        P = nullptr;
    }
}

void showDokter(ListDokter LD) {
    if (LD.first == nullptr) {
        cout << "List Dokter Kosong." << endl;
    } else {
        cout << "Daftar Dokter:" << endl;
        adr_dokter current = LD.first;
        while (current != nullptr) {
            dokter d = current->info;
            cout << "------------------------------------------" << endl;
            cout << "ID Dokter         : " << d.id << endl;
            cout << "Nama Dokter       : " << d.nama << endl;
            cout << "Spesialisasi      : " << d.spesialisasi << endl;
            cout << "Jenis Kelamin     : " << d.jk << endl;
            cout << "Umur              : " << d.umur << endl;
            cout << "NKD               : " << d.NKD << endl;
            cout << "Nomor HP          : " << d.nomorHP << endl;
            cout << "------------------------------------------" << endl;
            current = current->next;
        }
    }
}


adr_dokter FindDokter(ListDokter LD, string id, string nama, string spesialisasi){
    adr_dokter p = LD.first;
    while (p != NULL) {
        if (p->info.id == id && p->info.spesialisasi == spesialisasi) {
            return p;
        }else {
            p = p->next;
        }
    }
    return NULL;
}

adr_dokter FindDokterTanpaSpesialisasi(ListDokter LD, string id, string nama){
    adr_dokter p = LD.first;
    while (p != NULL) {
        if (p->info.id == id) {
            return p;
        }else {
            p = p->next;
        }
    }
    return NULL;
}

void showPasienDariDokter(ListDokter LD, string id_dokter, string nama_dokter) {
    adr_dokter dokter = FindDokterTanpaSpesialisasi(LD, id_dokter, nama_dokter);
    if (dokter == nullptr) {
        cout << "Dokter Tidak Ditemukan" << endl;
        return;
    }
    cout << " " << endl;
    cout << "Data pasien dari: " << dokter->info.nama << endl;
    cout << "Spesialisasi: " << dokter->info.spesialisasi << endl;
    cout << "=========================================" << endl;

    adr_relasi relasi = dokter->firstRelasi;
    if (relasi == nullptr) {
        cout << "Tidak ada pasien yang terkait dengan dokter ini." << endl;
        return;
    }

    while (relasi != nullptr) {
        adr_pasien pasien = relasi->firstPasien;
        if (pasien != nullptr) {
            cout << "Nama: " << pasien->info.Nama << endl;
            cout << "Jenis Kelamin: " << pasien->info.JenisKelamin << endl;
            cout << "Golongan Darah: " << pasien->info.golonganDarah << endl;
            cout << "TTL: " << pasien->info.TTL << endl;
            cout << "=========================================" << endl;
        }
        relasi = relasi->nextRelasi;
    }
}

void showDokterDariPasien(ListDokter LD, ListPasien LP, string nik_pasien, string nama_pasien) {
    adr_pasien pasien = FindPasien(LP, nik_pasien, nama_pasien);
    if (pasien == nullptr) {
        cout << "Pasien dengan NIK " << nik_pasien << " tidak ditemukan." << endl;
        return;
    }
    cout << " " << endl;
    cout << "Data dokter yang menangani pasien: " << pasien->info.Nama << ", " << "dengan NIK: " << pasien->info.NIK << endl;
    cout << "=================================================================" << endl;

    bool dokterDitemukan = false;
    adr_dokter dokter = LD.first;

    while (dokter != nullptr) {
        adr_relasi relasi = dokter->firstRelasi;

        while (relasi != nullptr) {
            if (relasi->firstPasien == pasien) {
                cout << "ID Dokter: " << dokter->info.id << endl;
                cout << "Nama: " << dokter->info.nama << endl;
                cout << "Spesialisasi: " << dokter->info.spesialisasi << endl;
                cout << "=================================================================" << endl;
                dokterDitemukan = true;
            }
            relasi = relasi->nextRelasi;
        }
        dokter = dokter->next;
    }

    if (!dokterDitemukan) {
        cout << "Tidak ada dokter yang terkait dengan pasien ini." << endl;
    }
}

int hitungPasienDariDokter(ListDokter LD, string id_dokter, string nama_dokter) {
    adr_dokter dokter = nullptr;
    dokter = FindDokterTanpaSpesialisasi(LD, id_dokter, nama_dokter);

    if (dokter == nullptr) {
        cout << "Dokter dengan ID: " << id_dokter << " dan nama: " << nama_dokter << " tidak ditemukan.\n";
        return 0;
    }

    int jumlahPasien = 0;
    adr_relasi currentRelasi = dokter->firstRelasi;

    if (currentRelasi == nullptr) {
        cout << nama_dokter << " belum memiliki pasien.\n";
        return jumlahPasien;
    }
    cout << " " << endl;
    cout << "=================================================================" << endl;
    cout << "Daftar pasien untuk " << nama_dokter << " : " << endl;
    while (currentRelasi != nullptr) {
        adr_pasien pasien = currentRelasi->firstPasien;
        if (pasien != nullptr) {
            cout << "- " << pasien->info.Nama << "\n";
            jumlahPasien++;
        }
        currentRelasi = currentRelasi->nextRelasi;
    }
    cout << " " << endl;
    cout << "Jumlah pasien: " << jumlahPasien << "\n";
    cout << "=================================================================" << endl;
    return jumlahPasien;
}

bool showDokterSpesialisasi(ListDokter LD, string spesialisasi) {
    if (LD.first == nullptr) {
        cout << "List Dokter kosong." << endl << endl;
        return false;
    }
    adr_dokter P = LD.first;
    bool found = false;

    cout << "Dokter dengan Spesialisasi " << spesialisasi << ":" << endl;
    while (P != nullptr) {
        if (P->info.spesialisasi == spesialisasi) {
            cout << "  |Nama\t: " << P->info.nama << endl;
            cout << "  |ID\t: " << P->info.id << endl << endl;
            found = true;
        }
        P = P->next;
    }
    if (!found) {
        cout << "Tidak ada dokter dengan spesialisasi tersebut." << endl << endl;
    }
    return found;
}
