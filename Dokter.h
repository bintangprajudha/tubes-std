#ifndef DOKTER_H_INCLUDED
#define DOKTER_H_INCLUDED
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
typedef struct elmChild *adr_pasien;

struct elmDokter
{
    dokter info;
    adr_dokter prev;
    adr_dokter next;
    adr_relasi nextRelasi;
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
    adr_pasien firstChild;
};

// procedure parent

void createListDokter(ListDokter &LD);
adr_dokter createElmDokter(dokter D);
void insertLastDokter(ListDokter &LD, adr_dokter P);
void DeleteLastDokter(ListDokter &LD, adr_dokter &P);
void showDokter(ListDokter LD);
adr_dokter FindDokter(ListDokter LD, string id, string nama, string spesialisasi);

// procedure relasi
void createListRelasi(elmRelasi &R);
void insertLastRelasi(ListDokter &LD, adr_relasi R);
void DeleteFirstRelasi(ListDokter &LD, adr_relasi &R);


#endif // DOKTER_H_INCLUDED
