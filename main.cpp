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
                showDokter(LD);
                break;
            case 2:
                // Show List Pasien
                ShowPasien(LP);
                break;
            case 3:
                // Show List relasi
                break;
            case 4: {
                // tambahkan Dokter baru
                dokter D;
                adr_dokter d;
                cout << "Menambahkan dokter baru" << endl;
                cout << "Masukkan ID dokter: ";
                cin >> D.id;
                cout << "Masukkan nama dokter: ";
                cin >> D.nama;
                cout << "Masukkan spesialisasi dokter: ";
                cin >> D.spesialisasi;
                cout << "Masukkan jenis kelamin dokter: ";
                cin >> D.jk;
                cout << "Masukkan umur dokter: ";
                cin >> D.umur;
                cout << "Masukkan NKD dokter: ";
                cin >> D.NKD;
                cout << "Masukkan nomor telepon dokter: ";
                cin >> D.nomorHP;

                d = createElmDokter(D);
                insertLastDokter(LD, d);
                break;
            }
            case 5: {
                // tambah pasien baru
                Pasien P;
                adr_pasien p;
                cout << "Menambahkan pasien baru" << endl ;
                cout << "Masukkan nama pasien: ";
                cin >> P.Nama;
                cout << "Masukkan NIK pasien: ";
                cin >> P.NIK;
                cout << "Masukkan jenis kelamin pasien: ";
                cin >> P.JenisKelamin;
                cout << "Masukkan jenis golongan darah pasien: ";
                cin >> P.golonganDarah;
                cout << "Masukkan berat pasien: ";
                cin >> P.berat;
                cout << "Masukkan tinggi pasien: ";
                cin >> P.NIK;
                cout << "Apakah pasien memiliki asuransi kesehatan? ";
                cin >> P.asuransiKesehatan;
                cout << "Masukkan agama pasien";
                cin >> P.agama;

                p = createElmPasien(P);
                insertLastPasien(LP, p);
                break;
            }
            case 6: {
                // tambahkan relasi dokter dan pasien
                dokter D;
                adr_dokter d;
                Pasien P;
                adr_pasien p;
                adr_relasi r;

                cout << "Masukkan nama pasien";
                cin >> P.Nama;
                cout << "Masukkan NIK pasien";
                cin >> P.NIK;
                p = FindPasien(LP, P.NIK, P.Nama);
                r = createElmRelasi(p);

                cout << "Masukkan nama dokter";
                cin >> D.nama;
                cout << "Masukkan ID dokter";
                cin >> D.id;
                d = FindDokter(LD, D.id, D.nama);

                insertLastRelasi(d, r);
                break;
            }
            case 7: {
                // hapus dokter
                adr_dokter d;
                DeleteLastDokter(LD, d);
                break;
            }
            case 8: {
                // hapus pasien
                adr_pasien p;
                deleteFirstPasien(LP, p);
                break;
            }
            case 9:{
                // hapus pasien pada dokter tertentu
                dokter D;
                adr_dokter d;
                cout << "Cari dokter" << endl;
                cout << "Masukkan nama dokter yang ingin dicari: ";
                cin >> D.nama;
                cout << "Masukkan ID dokter yang ingin dicari: ";
                cin >> D.id;
                d = FindDokter(LD, D.id, D.nama);

                Pasien P;
                adr_pasien p;

                cout << "Cari Pasien" << endl;
                cout << "Masukkan nama pasien yang ingin dihapus: ";
                cin >> P.Nama;
                cout << "Masukkan NIK dokter yang ingin dihapus: ";
                cin >> P.NIK;
                p = FindPasien(LP, P.NIK, P.Nama);

                adr_relasi r;
                r = deleteAfterRelasi(d, p);

                break;
            }
            case 10: {
                // mencari dokter
                dokter D;
                adr_dokter d;
                cout << "Cari dokter";
                cout << "Masukkan nama dokter yang ingin dicari: ";
                cin >> D.nama;
                cout << "Masukkan ID dokter yang ingin dicari: ";
                cin >> D.id;
                d = FindDokter(LD, D.id, D.nama);

                cout << d->info.id << endl;
                cout << d->info.nama << endl;
                cout << d->info.spesialisasi << endl;
                cout << d->info.jk << endl;
                cout << d->info.umur << endl;
                cout << d->info.NKD << endl;
                cout << d->info.nomorHP << endl;
                break;
            }
            case 11: {
                // mencari pasien
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
                break;
            }
            case 12: {
                    // Mencari Relasi
                break;
            }
            case 13: {
                // Mencari Pasien Dokter
                dokter D;
                adr_dokter d;
                cout << "Cari dokter";
                cout << "Masukkan nama dokter yang ingin dicari: ";
                cin >> D.nama;
                cout << "Masukkan ID dokter yang ingin dicari: ";
                cin >> D.id;

                showPasienDariDokter(LD, D.id, D.nama);
                break;
            }

            case 14: {
                // Show data Dokter dan Pasiennya
                showDokterPasienBerelasi(LD);
                break;
            }
            case 15: {
                // Show data Pasien dan Dokternya
                Pasien P;
                adr_pasien p;

                cout << "Cari Pasien";
                cout << "Masukkan nama pasien yang ingin dicari: ";
                cin >> P.Nama;
                cout << "Masukkan NIK dokter yang ingin dicari: ";
                cin >> P.NIK;
                showDokterDariPasien(LD, LP, P.NIK, P.Nama);
                break;
            }
            case 16: {
                // show semua child dan parent
                showChildParent(LP, LD);
                break;
            }
            case 17: {
                // hitung relasi dokter
                dokter D;
                adr_dokter d;
                cout << "Cari dokter";
                cout << "Masukkan nama dokter yang ingin dicari: ";
                cin >> D.nama;
                cout << "Masukkan ID dokter yang ingin dicari: ";
                cin >> D.id;
                hitungPasienDariDokter(LD, D.id, D.nama);
                break;
            }
            case 18: {
                // hitung relasi pasien
                break;
            }
            case 19: {
                // Hitung pasien yang tidak memiliki dokter
                break;
            }
            case 20: {
                // Edit Relasi
                dokter D;
                Pasien P;
                Pasien Pnew;

                cout << "Ganti Pasien";

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
                break;
            }
            case 0:
                // exit
                break;
            default:
                // jika user input tidak sesuai
                break;
        }
        select = menu();
    }

    return 0;
}
