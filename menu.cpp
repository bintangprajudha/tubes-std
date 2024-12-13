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
    cout << "| 3. Tambahkan dokter                               |" << endl;
    cout << "| 4. Tambahkan pasien                               |" << endl;
    cout << "| 5. Registrasi pasien dengan dokter                |" << endl; //bintang
    cout << "| 6. Hapus elemen                                   |" << endl;
    cout << "| 7. Show data                                      |" << endl;
    cout << "| 8. Cari data                                      |" << endl;
    cout << "| 9. Menu lainnya                                   |" << endl;
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
    cout << "| 1. Hapus dokter                                   |" << endl;
    cout << "| 2. Hapus pasien                                   |" << endl;
    cout << "| 3. Hapus pasien dari dokter                       |" << endl; //bintang
    cout << "| 4. Kembali                                        |" << endl;
    cout << "| 0. Exit                                           |" << endl;
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
    cout << "| 1. Tampilkan semua data dokter dan pasiennya      |" << endl; //bintang
    cout << "| 2. Tampilkan data dokter dari pasien tertentu     |" << endl;
    cout << "| 3. Tampilkan semua data pasien dan dokternya      |" << endl; //bintang
    cout << "| 4. Tampilkan relasi                               |" << endl; //bintang
    cout << "| 5. Kembali                                        |" << endl;
    cout << "| 0. Exit                                           |" << endl;
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
    cout << "| 1. Cari dokter                                    |" << endl;
    cout << "| 2. Cari pasien                                    |" << endl;
    cout << "| 3. Cari relasi                                    |" << endl; //bintang
    cout << "| 4. Cari pasien dari dokter                        |" << endl;
    cout << "| 5. Kembali                                        |" << endl;
    cout << "| 0. Exit                                           |" << endl;
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
    cout << "| 1. Hitung pasien yang dimiliki dokter             |" << endl;
    cout << "| 2. Hitung dokter yang dimiliki pasien             |" << endl;
    cout << "| 3. Hitung pasien yang tidak memiliki dokter       |" << endl;
    cout << "| 4. Ganti pasien pada dokter tertentu              |" << endl; //bintang
    cout << "| 5. Kembali                                        |" << endl;
    cout << "| 0. Exit                                           |" << endl;
    cout << "|                                                   |" << endl;
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;

    cout << "-> ";
    cin >> select;
    return select;
}

void inputDataDokter(dokter &D) {
    cout << "ID dokter     : ";
    cin >> D.id;
    cin.ignore();

    cout << "Nama dokter   : ";
    getline(cin, D.nama);

    cout << "Spesialisasi  : ";
    getline(cin, D.spesialisasi);

    cout << "Jenis kelamin : ";
    getline(cin, D.jk);

    cout << "Umur          : ";
    cin >> D.umur;
    cin.ignore();

    cout << "NKD dokter    : ";
    cin >> D.NKD;
    cin.ignore();

    cout << "nomor telepon : ";
    cin >> D.nomorHP;
    cin.ignore();
}

void inputDataPasien(Pasien &P) {
    string askes, temp;

    cout << "Nama pasien          : ";
    std::getline(std::cin, temp);
    getline(cin, P.Nama);
    cout << "NIK pasien           : ";
    cin >> P.NIK;
    cout << "Jenis kelamin pasien : ";
    std::getline(std::cin, temp);
    getline(cin, P.JenisKelamin);
    cout << "Jenis golongan darah : ";
    cin >> P.golonganDarah;
    cout << "Berat badan(kg)      : ";
    cin >> P.berat;
    cout << "Tinggi badan(cm)     : ";
    cin >> P.tinggiBadan;
    cout << "Tempat, tanggal lahir: ";
    std::getline(std::cin, temp);
    getline(cin, P.TTL);
    cout << "Usia pasien          : ";
    cin >> P.usia;
    cout << "Agama pasien         : ";
    cin >> P.agama;
    cout << "Memiliki asuransi kesehatan(Ya/Tidak)? ";
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
        cout << "Masukkan NIK pasien: ";
        cin >> P.NIK;
        cout << endl;
        p = FindPasien(LP, P.NIK, P.Nama);
        cout << endl;

        if (p == nullptr) {
            cout << "Tambah data pasien baru? (Ya/Tidak)" << endl;
            cout << "-> ";
            cin >> pilih;
            if(pilih == "Ya") {
                tambahPasienBaru(LP);

                r = createElmRelasi(p);

                cout << "Masukkan spesialisasi dokter yang diinginkan: ";
                std::getline(std::cin, temp);
                getline(cin, D.spesialisasi);
                cout << endl;

                found = showDokterSpesialisasi(LD, D.spesialisasi);

                if(found){
                    cout << "Masukkan nama dokter: ";
                    getline(cin, D.nama);

                    cout << "Masukkan ID dokter: ";
                    cin >> D.id;
                    d = FindDokter(LD, D.id, D.nama, D.spesialisasi);
                    if(d != nullptr) {
                        insertLastRelasi(d, r);
                        cout << "Registrasi berhasil." << endl << endl;
                    } else {
                        cout << "Dokter tidak ditemukan." << endl << endl;
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

                cout << "Masukkan ID dokter: ";
                cin >> D.id;
                d = FindDokter(LD, D.id, D.nama, D.spesialisasi);
                if(d != nullptr) {
                    insertLastRelasi(d, r);
                    cout << "Registrasi berhasil." << endl << endl;
                } else {
                cout << "Dokter tidak ditemukan." << endl << endl;
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

    cout << "Masukkan nama dokter: ";
    std::getline(std::cin, temp);
    getline(cin, D.nama);

    cout << "Masukkan ID dokter  : ";
    cin >> D.id;

    cout << "Masukkan spesialisasi dokter: ";
    std::getline(std::cin, temp);
    getline(cin, D.spesialisasi);

    d = FindDokter(LD, D.id, D.nama, D.spesialisasi);

    Pasien P;
    adr_pasien p;

    cout << "Masukkan nama pasien : ";
    getline(cin, P.Nama);

    cout << "Masukkan NIK pasien  : ";
    cin >> P.NIK;
    cout << endl;

    p = FindPasien(LP, P.NIK, P.Nama);

    adr_relasi r;
    r = deleteAfterRelasi(d, p);

    string lagi;
    cout << "Registrasi lagi? (Ya/Tidak)" << endl;
    cout << "-> ";
    cin >> lagi;
    cout << endl;
    if(lagi == "Ya"){
        regitrasiPasien(LD, LP);
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
