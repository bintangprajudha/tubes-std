#include "header.h"

adr_relasi createElmRelasi(adr_pasien P){
    adr_relasi R = new elmRelasi;
    R->nextRelasi = NULL;
    R->firstPasien = P;
    return R;
}

void insertLastRelasi(adr_dokter &D, adr_relasi R){
    if (D->firstRelasi == NULL){
        D->firstRelasi = R;
    } else {
        adr_relasi P = D->firstRelasi;
        while (P->nextRelasi != NULL) {
            P = P->nextRelasi;
        }
        P->nextRelasi = R;
    }
}

adr_relasi deleteFirstRelasi(adr_dokter &D, adr_relasi &R){
    R = D->firstRelasi;
    if (D->firstRelasi == NULL){
        D->firstRelasi = NULL;
    } else {
        D->firstRelasi = D->firstRelasi->nextRelasi;
        R->nextRelasi = NULL;
    }
}
adr_relasi findRelasi(ListDokter &LD, string id_dokter, string nik_pasien){
    adr_dokter dokter = LD.first;

    while (dokter != nullptr) {
        if (dokter->info.id == id_dokter) {
            adr_relasi relasi = dokter->firstRelasi;

            while (relasi != nullptr) {
                if (relasi->firstPasien != nullptr && relasi->firstPasien->info.NIK == nik_pasien) {
                    return relasi; // Relasi ditemukan
                }
                relasi = relasi->nextRelasi;
            }
        }
        dokter = dokter->next;
    }

    return nullptr; // Relasi tidak ditemukan
}

void showDokterPasienBerelasi(ListDokter LD){
    adr_dokter currentDokter = LD.first;

    while (currentDokter != nullptr) {
        cout << " ID Dokter         : " << currentDokter->info.id << endl;
        cout << " Nama Dokter       : " << currentDokter->info.nama << endl;
        cout << " Spesialisasi      : " << currentDokter->info.spesialisasi << endl;
        cout << " NKD               : " << currentDokter->info.NKD << endl;
        cout << " Jenis Kelamin     : " << currentDokter->info.jk << endl;
        cout << " Umur              : " << currentDokter->info.umur << endl;
        cout << " Nomor Telepon     : " << currentDokter->info.nomorHP << endl;

        adr_relasi currentRelasi = currentDokter->firstRelasi;

        if (currentRelasi == nullptr) {
            cout << "    Dokter ini tidak memiliki pasien yang terkait.\n";
        } else {
            cout << " Pasien terkait    :\n";
            while (currentRelasi != nullptr) {
                adr_pasien relatedPasien = currentRelasi->firstPasien;
                if (relatedPasien != nullptr) {
                    cout << "    Nama Pasien          : " << relatedPasien->info.Nama << endl;
                    cout << "    NIK                  : " << relatedPasien->info.NIK << endl;
                    cout << "    Jenis Kelamin        : " << relatedPasien->info.JenisKelamin << endl;
                    cout << "    Golongan Darah       : " << relatedPasien->info.golonganDarah << endl;
                    cout << "    Berat                : " << relatedPasien->info.berat << endl;
                    cout << "    Tinggi               : " << relatedPasien->info.tinggiBadan << endl;
                    cout << "    Tempat, Tanggal Lahir: " << relatedPasien->info.TTL << endl;
                    cout << "    Usia                 : " << relatedPasien->info.usia << endl;
                    cout << "    Asuransi Kesehatan   : " << relatedPasien->info.asuransiKesehatan << endl;
                    cout << "    Agama                : " << relatedPasien->info.agama << endl << endl;

                }
                currentRelasi = currentRelasi->nextRelasi;
            }
        }
        currentDokter = currentDokter->next;
        cout << endl;
    }
};

void showChildParent(ListPasien LP, ListDokter LD){
    adr_pasien currentPasien = LP.first;

    // Iterasi melalui daftar pasien
    while (currentPasien != nullptr) {
        cout << " Nama Pasien    : " << currentPasien->info.Nama << endl;
        cout << " NIK            : " << currentPasien->info.NIK << endl;
        cout << " Jenis Kelamin  : " << currentPasien->info.JenisKelamin << endl;
        cout << " Golongan Darah : " << currentPasien->info.golonganDarah << endl;
        cout << " Tinggi Badan   : " << currentPasien->info.tinggiBadan << " cm" << endl;
        cout << " Berat Badan    : " << currentPasien->info.berat << " kg" << endl;
        cout << " Usia           : " << currentPasien->info.usia << endl;
        cout << " Agama          : " << currentPasien->info.agama << endl;

        // Temukan dokter melalui daftar relasi di ListDokter
        adr_dokter currentDokter = LD.first;
        bool found = false;

        while (currentDokter != nullptr && !found) {
            adr_relasi currentRelasi = currentDokter->firstRelasi;

            // perulangan melalui daftar relasi dokter
            while (currentRelasi != nullptr) {
                if (currentRelasi->firstPasien == currentPasien) {
                    cout << " Dokter Terkait:\n";
                    cout << "    ID Dokter     : " << currentDokter->info.id << endl;
                    cout << "    Nama Dokter   : " << currentDokter->info.nama << endl;
                    cout << "    Spesialisasi  : " << currentDokter->info.spesialisasi << endl;
                    cout << "    Jenis Kelamin : " << currentDokter->info.jk << endl;
                    cout << "    Umur          : " << currentDokter->info.umur << endl << endl;
                    found = true;
                    break;
                }
                currentRelasi = currentRelasi->nextRelasi;
            }
            currentDokter = currentDokter->next;
        }

        if (!found) {
            cout << "    Tidak ada dokter yang terhubung dengan pasien ini." << endl;
        }

        currentPasien = currentPasien->next;
    }
};

adr_relasi deleteAfterRelasi(adr_dokter &dokter, adr_pasien pasienLama){
    adr_relasi currentRelasi = dokter->firstRelasi;
    adr_relasi prevRelasi = nullptr;
    while (currentRelasi != nullptr && currentRelasi->firstPasien != pasienLama) {
        prevRelasi = currentRelasi;
        currentRelasi = currentRelasi->nextRelasi;
    }

    if (currentRelasi != nullptr) {
        if (prevRelasi == nullptr) {
            dokter->firstRelasi = currentRelasi->nextRelasi;
        } else {
            prevRelasi->nextRelasi = currentRelasi->nextRelasi;
        }
        currentRelasi->nextRelasi = NULL;
    }
    return currentRelasi;
};

void editRelasiGantiPasien(ListDokter &LD, ListPasien &LP, string id_dokter, string nama_dokter, string nik_pasien, string nama_pasien_lama, string new_nik_pasien, string nama_pasien_baru){
    adr_dokter dokter = FindDokter(LD, id_dokter, nama_dokter, "");
    adr_pasien pasienLama = FindPasien(LP, nik_pasien, nama_pasien_lama);
    adr_pasien pasienBaru = FindPasien(LP, new_nik_pasien, nama_pasien_baru);

    deleteAfterRelasi(dokter, pasienLama);

    adr_relasi relasiPasienBaru = createElmRelasi(pasienBaru);
    insertLastRelasi(dokter, relasiPasienBaru);
};
