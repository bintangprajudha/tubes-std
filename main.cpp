#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListDokter LD;
    ListPasien LP;

    int select;

    createListDokter(LD);
    createListPasien(LP);

    select = menu();
    while (select != 0) {
        switch(select) {
            case 1:
                // Show List Dokter
                cout << "~~~~~~~~~~~~~~ Menampilkan List Dokter ~~~~~~~~~~~~~~" << endl;
                showDokter(LD);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            case 2:
                // Show List Pasien
                cout << "~~~~~~~~~~~~~~ Menampilkan List Pasien ~~~~~~~~~~~~~~" << endl;
                ShowPasien(LP);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            case 3: {
                // tambahkan Dokter baru
                cout << "~~~~~~~~~~~~~~~~~~ Tambahkan Dokter ~~~~~~~~~~~~~~~~~" << endl;
                tambahDokterBaru(LD);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 4: {
                // tambah pasien baru
                cout << "~~~~~~~~~~~~~~~~~~ Tambahkan Pasien ~~~~~~~~~~~~~~~~~" << endl;
                tambahPasienBaru(LP);
                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 5: {
                // tambahkan relasi dokter dan pasien sesuai spesialisasi
                cout << "~~~~~~~~~~~ Registrasi pasien dengan dokter ~~~~~~~~~" << endl;
                regitrasiPasien(LD, LP);

                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                break;
            }
            case 6: {
                //hapus elemen
                select = case6();
                while (select != 0) {
                    switch(select) {
                        case 1: {
                            //hapus dokter
                            cout << "~~~~~~~~~~~~~~~~~~~~ Hapus Dokter ~~~~~~~~~~~~~~~~~~~" << endl;
                            adr_dokter d;
                            DeleteLastDokter(LD, d);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 2: {
                            // hapus pasien
                            cout << "~~~~~~~~~~~~~~~~~~~~ Hapus Pasien ~~~~~~~~~~~~~~~~~~~" << endl;
                            adr_pasien p;
                            deleteFirstPasien(LP, LD, p);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 3: {
                            //hapus pasien pada dokter
                            cout << "~~~~~~~~~~~~~ Hapus Pasien Dari Dokter ~~~~~~~~~~~~~~" << endl;
                            hapusPasienDariDokter(LD, LP);

                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 4:
                            break;
                        case 0:
                            break;
                    }
                    select = case6();
                }
                break;
            }
            case 7: {
                //show data
                select = case7();
                while (select != 0) {
                    switch(select) {
                        case 1: {
                            //Show data Dokter dan Pasiennya
                            cout << "~~~~~~~~~~~ Tampilkan Dokter dan Pasiennya ~~~~~~~~~~" << endl;
                            showDokterPasienBerelasi(LD);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 2: {
                            //Show data Pasien dan Dokternya
                            cout << "~~~~~~~~~~~ Tampilkan Pasien dan Dokternya ~~~~~~~~~~" << endl;
                            Pasien P;
                            adr_pasien p;

                            cout << "Masukkan nama pasien: ";
                            cin >> P.Nama;
                            cout << "Masukkan NIK pasien: ";
                            cin >> P.NIK;
                            showDokterDariPasien(LD, LP, P.NIK, P.Nama);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 3: {
                            //show semua data pasien dan dokternya
                            cout << "~~~~ Tampilkan Semua Data Pasien dan Dokternnya ~~~~~" << endl;
                            showChildParent(LP, LD);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 4:
                            //tampilkan relasi
                            break;
                        case 5:
                            break;
                        case 0:
                            break;
                    }
                    select = case7();
                }
                break;
            }
            case 8: {
                //cari data
                select = case8();
                while (select != 0) {
                    switch(select) {
                        case 1: {
                            cout << "~~~~~~~~~~~~~~~~~~~~ Cari Dokter ~~~~~~~~~~~~~~~~~~~~" << endl;
                            dokter D;
                            adr_dokter d;

                            cout << "Masukkkan nama dokter yang ingin dicari: ";
                            cin >> D.nama;
                            cout << "Masukkkan ID dokter yang ingin dicari: ";
                            cin >> D.id;
                            d = FindDokterTanpaSpesialisasi(LD, D.id, D.nama);
                            cout << " " << endl;

                            if (d != nullptr) {
                                cout << "ID dokter: " << d->info.id << endl;
                                cout << "Nama dokter: " << d->info.nama << endl;
                                cout << "Jenis Kelamin: " << d->info.jk << endl;
                                cout << "Umur: " << d->info.umur << endl;
                                cout << "NKD: " << d->info.NKD << endl;
                                cout << "Nomor telepon: " << d->info.nomorHP << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            }else {
                                cout << "Dokter dengan nama: " << D.nama << ", " << "dan ID: " << D.id << ", tidak ditemukan." << endl;
                                cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            }
                            break;
                        }
                        case 2: {
                            //cari pasien
                            cout << "~~~~~~~~~~~~~~~~~~~~ Cari Pasien ~~~~~~~~~~~~~~~~~~~~" << endl;
                            Pasien P;
                            adr_pasien p;

                            cout << "Cari Pasien";
                            cout << "Masukkan nama pasien yang ingin dicari: ";
                            cin >> P.Nama;
                            cout << "Masukkan NIK dokter yang ingin dicari: ";
                            cin >> P.NIK;
                            p = FindPasien(LP, P.NIK, P.Nama);

                            cout << p->info.Nama << endl;
                            cout << p->info.NIK << endl;
                            cout << p->info.JenisKelamin << endl;
                            cout << p->info.golonganDarah<< endl;
                            cout << p->info.berat << endl;
                            cout << p->info.tinggiBadan << endl;
                            cout << p->info.TTL << endl;
                            cout << p->info.usia << endl;
                            cout << p->info.asuransiKesehatan << endl;
                            cout << p->info.agama << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 3: {
                            //cari relasi
                            cout << "~~~~~~~~~~~~~~~~~~~~ Cari Relasi ~~~~~~~~~~~~~~~~~~~~" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 4: {
                            //cari pasien dokter
                            cout << "~~~~~~~~~~~~~~ Cari Pasien dari Dokter ~~~~~~~~~~~~~~" << endl;

                            dokter D;
                            adr_dokter d;
                            cout << "Masukkan nama dokter yang ingin dicari: ";
                            cin >> D.nama;
                            cout << "Masukkan ID dokter yang ingin dicari: ";
                            cin >> D.id;

                            showPasienDariDokter(LD, D.id, D.nama);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 5:
                            break;
                        case 0:
                            break;
                    }
                    select = case8();
                }
                break;
            }
            case 9: {
                //menu lainnya
                select = case9();
                while (select != 0) {
                    switch(select) {
                        case 1: {
                            //hitung pasien yang dimiliki dokter
                            cout << "~~~~~~~~~ Hitung Pasien yang dimiliki Dokter ~~~~~~~~" << endl;
                            dokter D;
                            adr_dokter d;
                            cout << "Masukkan nama dokter: ";
                            cin >> D.nama;
                            cout << "Masukkan ID dokter: ";
                            cin >> D.id;
                            hitungPasienDariDokter(LD, D.id, D.nama);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 2: {
                            //hitung dokter yang dimiliki pasien
                            cout << "~~~~~~~~~ Hitung Dokter yang dimiliki Pasien ~~~~~~~~" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 3: {
                            //hitung pasien yang tidak memiliki dokter
                            cout << "~~~~~~ Hitung Pasien yang Tidak Memiliki Dokter ~~~~~" << endl;
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 4: {
                            //ganti pasien pada dokter tertentu
                            cout << "~~~~~~~~~ Ganti Pasien pada Dokter Tertentu ~~~~~~~~~" << endl;

                            dokter D;
                            Pasien P;
                            Pasien Pnew;

                            cout << "Masukkan ID dokter: ";
                            cin >> D.id;
                            cout << "Masukkan nama dokter: ";
                            cin >> D.nama;

                            cout << "Masukkan nama pasien lama: ";
                            cin >> P.Nama;
                            cout << "Masukkan NIK pasien lama: ";
                            cin >> P.NIK;

                            cout << "Masukkan nama pasien baru: ";
                            cin >> Pnew.Nama;
                            cout << "Masukkan NIK pasien baru: ";
                            cin >> Pnew.NIK;

                            editRelasiGantiPasien(LD, LP, D.id, D.nama, P.NIK, P.Nama, Pnew.NIK, Pnew.Nama);
                            cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
                            break;
                        }
                        case 5:
                            break;
                        case 0:
                            break;
                    }
                    select = case9();
                }
                break;
            }
            default:
                // jika user input tidak sesuai
                break;
        }
        select = menu();
    }
    cout << "keluar dari program";

    return 0;
}
