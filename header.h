#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>
using namespace std;

// adt list parent

struct dokter
{
    string id;
    string nama;
    string spesialisasi;
    string jk;
    int umur;
    int NKD;
    int nomorHP;
};

typedef struct elmDokter *adr_dokter;
typedef struct elmRelasi *adr_relasi;
typedef struct elmPasien *adr_pasien;

struct elmDokter
{
    dokter info;
    adr_dokter prev;
    adr_dokter next;
    adr_relasi firstRelasi;
};

struct ListDokter
{
    adr_dokter first;
    adr_dokter last;
};
// ADT list pasien

struct Pasien{
    string Nama;
    string NIK;
    string JenisKelamin;
    string golonganDarah;
    string berat;
    string tinggiBadan;
    string TTL;
    int usia;
    bool asuransiKesehatan;
    string agama;
};

struct elmPasien{
    Pasien info;
    adr_pasien next;
};

struct ListPasien{
    adr_pasien first;
};
// ADT list relasi

struct elmRelasi
{
    adr_relasi nextRelasi;
    adr_pasien firstPasien;
};

// procedure parent

void createListDokter(ListDokter &LD);
adr_dokter createElmDokter(dokter D);
void insertLastDokter(ListDokter &LD, adr_dokter P);
void DeleteLastDokter(ListDokter &LD, adr_dokter &P);
void showDokter(ListDokter LD);
adr_dokter FindDokter(ListDokter LD, string id, string nama);

// procedure Child

void createListPasien(ListPasien &LP);
adr_pasien createElmPasien(Pasien C);
void insertLastPasien(ListPasien &LP, adr_pasien P);
void deleteFirstPasien(ListPasien &LP, adr_pasien &P);
adr_pasien FindPasien(ListPasien LP, string NIK);
void ShowPasien(ListPasien LP);
void hitungRelasiPasien(ListDokter LD, ListPasien LP, int &jumRelasi);
int hitungPasienNoRelasi(ListDokter LD, ListPasien LP);

// procedure relasi
void createListRelasi(adr_pasien P);
void insertLastRelasi(adr_dokter &D, adr_relasi R);
adr_relasi DeleteFirstRelasi(adr_dokter &D, adr_relasi &R);
adr_relasi findRelasi(ListDokter &LD, string id_dokter, string nik_pasien);
void showDokterPasienBerelasi(ListDokter LD);
void showChildParent(ListPasien LP, ListDokter LD);
adr_relasi deleteAfterRelasi(adr_dokter &dokter, adr_pasien pasienLama);
void editRelasiGantiPasien(ListDokter &LD, ListPasien &LP, string id_dokter, string nama_dokter, string nik_pasien, string new_nik_pasien);

int menu();

#endif // HEADER_H_INCLUDED
