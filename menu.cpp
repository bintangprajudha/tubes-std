#include "header.h"

int menu(){
    int select;

    cout << "               _______________________               " << endl;
    cout << "~~~~~~~~~~~~~~|                       |~~~~~~~~~~~~~~" << endl;
    cout << "|             |  Rumah Sakit Budiman  |             |" << endl;
    cout << "|             |       Pilih Menu      |             |" << endl;
    cout << "|~~~~~~~~~~~~~|_______________________|~~~~~~~~~~~~~|" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. Show List Dokter                               |" << endl;
    cout << "| 2. Show List Pasien                               |" << endl;
    cout << "| 3. Tambahkan Dokter                               |" << endl;
    cout << "| 4. Tambahkan Pasien                               |" << endl;
    cout << "| 5. Registrasi Pasien dengan Dokter                |" << endl; //bintang (done)
    cout << "| 6. Hapus Elemen                                   |" << endl;
    cout << "| 7. Show Data                                      |" << endl;
    cout << "| 8. Cari Data                                      |" << endl;
    cout << "| 9. Menu Lainnya                                   |" << endl;
    cout << "| 0. Exit                                           |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

int case6() {
    int select;

    cout << "~~~~~~~~~~~~~~~~~~~ Hapus Elemen ~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. Hapus Dokter                                   |" << endl;
    cout << "| 2. Hapus Pasien                                   |" << endl;
    cout << "| 3. Hapus Pasien dari Dokter                       |" << endl; //bintang (done)
    cout << "| 0. Kembali                                        |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

int case7() {
    int select;

    cout << "~~~~~~~~~~~~~~~~~~~ Tampilkan Data ~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. Tampilkan Semua Data Dokter dan Pasiennya      |" << endl; //bintang (done)
    cout << "| 2. Tampilkan Data Dokter dari Pasien Tertentu     |" << endl;
    cout << "| 3. Tampilkan Semua Data Pasien dan Dokternya      |" << endl; //bintang (done)
    cout << "| 0. Kembali                                        |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

int case8() {
    int select;

    cout << "~~~~~~~~~~~~~~~~~~~~~ Cari Data ~~~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. Cari Dokter                                    |" << endl;
    cout << "| 2. Cari Pasien                                    |" << endl;
    cout << "| 3. Cari Relasi                                    |" << endl; //bintang(done)
    cout << "| 4. Cari Pasien dari Dokter                        |" << endl;
    cout << "| 0. Kembali                                        |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

int case9() {
    int select;

    cout << "~~~~~~~~~~~~~~~~~~~~ Menu Lainnya ~~~~~~~~~~~~~~~~~~~" << endl;
    cout << "|                                                   |" << endl;
    cout << "| 1. Hitung Pasien yang Dimiliki Dokter             |" << endl;
    cout << "| 2. Hitung Dokter yang Dimiliki Pasien             |" << endl;
    cout << "| 3. Hitung Pasien yang Tidak memiliki dokter       |" << endl;
    cout << "| 4. Ganti Pasien pada Dokter Tertentu              |" << endl; //bintang (done)
    cout << "| 0. Kembali                                        |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

void inputDataDokter(dokter &D) {
    cout << "ID Dokter     : ";
    cin >> D.id;
    cin.ignore();

    cout << "Nama Dokter   : ";
    getline(cin, D.nama);

    cout << "Spesialisasi  : ";
    getline(cin, D.spesialisasi);

    cout << "Jenis Kelamin : ";
    getline(cin, D.jk);

    cout << "Umur          : ";
    cin >> D.umur;
    cin.ignore();

    cout << "NKD Dokter    : ";
    cin >> D.NKD;
    cin.ignore();

    cout << "Nomor Telepon : ";
    cin >> D.nomorHP;
    cin.ignore();
}

void inputDataPasien(Pasien &P) {
    string askes, temp;

    cout << "Nama Pasien          : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);
    cout << "NIK Pasien           : ";
    cin >> P.NIK;
    cout << "Jenis Kelamin Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.JenisKelamin);
    cout << "Jenis Golongan Darah : ";
    cin >> P.golonganDarah;
    cout << "Berat Badan(kg)      : ";
    cin >> P.berat;
    cout << "Tinggi Badan(cm)     : ";
    cin >> P.tinggiBadan;
    cout << "Tempat, Tanggal Lahir: ";
    std::getline(std::cin, temp);
    getline(cin, P.TTL);
    cout << "Usia Pasien          : ";
    cin >> P.usia;
    cout << "Agama Pasien         : ";
    cin >> P.agama;
    cout << "Memiliki Asuransi Kesehatan(Ya/Tidak)? ";
    cin >> askes;
    P.asuransiKesehatan = (askes == "Ya") ? true : false;
}

void tambahDokterBaru(ListDokter &LD){
    dokter D;
    adr_dokter d;
    string tambah;

    inputDataDokter(D);
    d = createElmDokter(D);
    insertLastDokter(LD, d);
    cout << endl;
    cout << "Tambah Dokter Baru Lagi(Ya/Tidak)? ";
    cin >> tambah;
    cout << endl;
    if (tambah == "Ya") {
        tambahDokterBaru(LD);
    }
}

void tambahPasienBaru(ListPasien &LP){
    Pasien P;
    adr_pasien p;
    string tambah;

    inputDataPasien(P);
    p = createElmPasien(P);
    insertLastPasien(LP, p);
    cout << endl;

    cout << "Tambah Pasien Baru Lagi(Ya/Tidak)? ";
    cin >> tambah;
    cout << endl;
    if (tambah == "Ya") {
        tambahPasienBaru(LP);
    }
}

void regitrasiPasien(ListDokter &LD, ListPasien &LP){
    dokter D;
    adr_dokter d;
    Pasien P;
    adr_pasien p;
    adr_relasi r;
    string pilih, temp, spesialisasi;
    bool found;
    string lagi = "Ya";


        cout << "Masukkan nama pasien: ";
        std::getline(std::cin, temp);
        getline(cin, P.Nama);
        cout << "Masukkan NIK pasien : ";
        cin >> P.NIK;
        cout << endl;
        p = FindPasien(LP, P.NIK, P.Nama);
        cout << endl;

        if (p == nullptr) {
            cout << "Tambah data pasien baru? (Ya/Tidak)" << endl;
            cout << "-> ";
            cin >> pilih;
            if(pilih == "Ya") {
                inputDataPasien(P);
                p = createElmPasien(P);
                insertLastPasien(LP, p);
                cout << endl;

                r = createElmRelasi(p);

                cout << "Masukkan spesialisasi dokter yang diinginkan: ";
                std::getline(std::cin, temp);
                getline(cin, D.spesialisasi);
                cout << endl;

                found = showDokterSpesialisasi(LD, D.spesialisasi);

                if(found){
                    cout << "Masukkan nama dokter: ";
                    getline(cin, D.nama);

                    cout << "Masukkan ID dokter  : ";
                    cin >> D.id;
                    cout << endl;
                    d = FindDokter(LD, D.id, D.nama, D.spesialisasi);

                    //baru
                    adr_relasi relasi = d->firstRelasi;
                    while(relasi != nullptr){
                        if(relasi->firstPasien == r->firstPasien){
                            d = nullptr;
                        }
                        relasi = relasi->nextRelasi;
                    }
                    //baru

                    if(d != nullptr) {
                        insertLastRelasi(d, r);
                        cout << "Registrasi berhasil." << endl << endl;
                    } else {
                        cout << "Registrasi gagal." << endl << endl;
                    }
                }
            }
        } else {
            r = createElmRelasi(p);

            cout << "Masukkan spesialisasi dokter yang diinginkan: ";
            std::getline(std::cin, temp);
            getline(cin, D.spesialisasi);
            cout << endl;

            found = showDokterSpesialisasi(LD, D.spesialisasi);

            if(found){
                cout << "Masukkan nama dokter: ";
                getline(cin, D.nama);

                cout << "Masukkan ID dokter  : ";
                cin >> D.id;
                d = FindDokter(LD, D.id, D.nama, D.spesialisasi);

                //baru
                adr_relasi relasi = d->firstRelasi;
                while(relasi != nullptr){
                    if(relasi->firstPasien == r->firstPasien){
                        d = nullptr;
                    }
                    relasi = relasi->nextRelasi;
                }
                //baru

                if(d != nullptr) {
                    insertLastRelasi(d, r);
                    cout << "Registrasi berhasil." << endl << endl;
                } else {
                cout << "Registrasi gagal." << endl << endl;
                }
            }
        }

        cout << "Registrasi lagi? (Ya/Tidak)" << endl;
        cout << "-> ";
        cin >> lagi;
        cout << endl;
        if(lagi == "Ya"){
            regitrasiPasien(LD, LP);
        }

}

void hapusPasienDariDokter(ListDokter &LD, ListPasien &LP){
    dokter D;
    adr_dokter d;
    string temp;

    cout << "Masukkan Nama Dokter: ";
    std::getline(std::cin, temp);
    getline(cin, D.nama);

    cout << "Masukkan ID Dokter  : ";
    cin >> D.id;
    cout << endl;

    d = FindDokterTanpaSpesialisasi(LD, D.id, D.nama);

    Pasien P;
    adr_pasien p;

    cout << "Masukkan Nama Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);

    cout << "Masukkan NIK Pasien  : ";
    cin >> P.NIK;
    cout << endl;

    p = FindPasien(LP, P.NIK, P.Nama);

    if (d == nullptr || p == nullptr){
        cout << "Hapus pasien gagal." << endl;
        cout << "Dokter atau pasien tidak ditemukan." << endl << endl;
    } else {
        adr_relasi r;
        r = deleteAfterRelasi(d, p);
        cout << "Hapus pasien Berhasil." << endl << endl;
    }

    string lagi;
    cout << "Hapus Lagi? (Ya/Tidak)" << endl;
    cout << "-> ";
    cin >> lagi;
    cout << endl;
    if(lagi == "Ya"){
        hapusPasienDariDokter(LD, LP);
    }
}

void gantiPasienDariDokter(ListDokter &LD, ListPasien &LP){
    dokter D;
    Pasien P;
    Pasien Pnew;
    string temp;

    cout << "Masukkan Nama Dokter      : ";
    std::getline(std::cin, temp);
    getline(cin, D.nama);

    cout << "Masukkan ID Dokter        : ";
    cin >> D.id;
    cout << endl;

    cout << "Masukkan Nama Pasien Lama : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);

    cout << "Masukkan NIK Pasien Lama  : ";
    cin >> P.NIK;
    cout << endl;

    cout << "Masukkan Nama Pasien Baru : ";
    std::getline(std::cin, temp);
    getline(cin, Pnew.Nama);

    cout << "Masukkan NIK Pasien Baru  : ";
    cin >> Pnew.NIK;
    cout << endl;

    adr_dokter dokter = FindDokterTanpaSpesialisasi(LD, D.id, D.nama);
    adr_pasien pasienLama = FindPasien(LP, P.NIK, P.Nama);
    adr_pasien pasienBaru = FindPasien(LP, Pnew.NIK, Pnew.Nama);

    cout << endl;

    if(dokter != nullptr && pasienBaru != nullptr && pasienLama != nullptr){
        editRelasiGantiPasien(LD, LP, dokter, pasienLama, pasienBaru);
        cout << "Ganti pasien Berhasil." << endl << endl;
    } else {
        cout << "Ganti pasien Gagal." << endl << endl;
    }

    string lagi;
    cout << "Ganti Pasien Lagi? (Ya/Tidak)" << endl;
    cout << "-> ";
    cin >> lagi;
    cout << endl;
    if(lagi == "Ya"){
        gantiPasienDariDokter(LD, LP);
    }
}

void HapusPasien(ListPasien &LP, ListDokter &LD){
    Pasien P;
    adr_pasien p;
    string temp;

    cout << "Masukkan Nama Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);

    cout << "Masukkan NIK Pasien  : ";
    cin >> P.NIK;
    cout << endl;

    p = FindPasien(LP, P.NIK, P.Nama);
    deletePasien(LP, LD, p);

    if(p == nullptr){
        cout << "Pasien tidak ada dalam list." << endl;
    } else {
        deletePasien(LP, LD, p);
        cout << "Pasien Telah Dihapus dari List." << endl;
    }

}

void CariPasien(ListPasien LP){
    Pasien P;
    adr_pasien p;
    string temp;

    cout << "Masukkan Nama Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);

    cout << "Masukkan NIK Pasien : ";
    cin >> P.NIK;
    cout << endl;

    p = FindPasien(LP, P.NIK, P.Nama);
    if (p != NULL){
        cout << "Pasien Ditemukan" << endl;
        cout << "Nama Pasien            : " << p->info.Nama << endl;
        cout << "NIK Pasien             : " << p->info.NIK << endl;
        cout << "Jenis Kelamin          : " <<  p->info.JenisKelamin << endl;
        cout << "Golongan Darah         : " <<  p->info.golonganDarah<< endl;
        cout << "Berat Badan            : " <<  p->info.berat << endl;
        cout << "Tinggi Badan           : " <<  p->info.tinggiBadan << endl;
        cout << "Tempat, Tanggal Lahir  : " <<  p->info.TTL << endl;
        cout << "Usia                   : " <<  p->info.usia << endl;
        cout << "Asuransi Kesehatan     : " <<  p->info.asuransiKesehatan << endl;
        cout << "Agama                  : " <<  p->info.agama << endl;
    } else {
        cout << "Pasien Tidak ditemukan" << endl;
    }
}

void HitungPasientanpaDokter(ListDokter LD, ListPasien LP){
    int hasil;
    hasil = hitungPasienNoRelasi(LD, LP);
    cout << "Jumlah Pasien yang Tidak Memiliki Dokter adalah " << hasil << " Orang" << endl;
}

void HitungDokterdariPasien(ListDokter LD, ListPasien LP){
    int hasil;
    hitungRelasiPasien(LD, LP, hasil);
    cout << "Jumlah Dokter yang Dimiliki oleh Pasien tersebut adalah " << hasil << endl;
}

void cariRelasi(ListDokter &LD){
    dokter D;
    Pasien P;
    Pasien Pnew;
    string temp;

    cout << "Masukkan Nama Dokter : ";
    std::getline(std::cin, temp);
    getline(cin, D.nama);

    cout << "Masukkan ID Dokter   : ";
    cin >> D.id;
    cout << endl;

    cout << "Masukkan Nama Pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);

    cout << "Masukkan NIK Pasien  : ";
    cin >> P.NIK;
    cout << endl;

    adr_relasi r = findRelasi(LD, D.id, P.NIK);

    if(r == nullptr){
        cout << "Dokter dan pasien tersebut tidak berelasi." << endl << endl;
    } else {
        cout << "Dokter dan pasien tersebut berelasi." << endl << endl;
    }

    string lagi;
    cout << "Cari lagi? (Ya/Tidak)" << endl;
    cout << "-> ";
    cin >> lagi;
    cout << endl;
    if(lagi == "Ya"){
        cariRelasi(LD);
    }
}

/*
    1. show list dokter
    2. show list pasien
    3. tambahkan dokter
    4. tambahkan pasien
    5. registrasi pasien dengan dokter
    6. hapus elemen
        1. hapus dokter
        2. hapus pasien
        3. hapus pasien pada dokter
    7. show data
        1. Show data Dokter dan Pasiennya
        2. Show data Pasien dan Dokternya
        3. show semua data pasien dan dokternya
        4. tampilkan relasi
    8. cari elemen
        1. cari dokter
        2. cari pasien
        3. cari relasi
        4. cari pasien dokter
    9. menu lainnya
        1. hitung pasien yang dimiliki dokter
        2. hitung dokter yang dimiliki pasien
        3. hitung pasien yang tidak memiliki dokter
        4. ganti pasien pada dokter tertentu
        5. show list relasi
    0. exit
*/
