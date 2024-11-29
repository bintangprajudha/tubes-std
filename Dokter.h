#ifndef PASIEN_H_INCLUDED
#define PASIEN_H_INCLUDED
#include <iostream>
using namespace std;
struct dokter {
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
struct elmDokter {
    dokter info;
    adr_dokter prev;
    adr_dokter next;
    adr_relasi nextRelasi;
};
struct ListDokter {
    adr_dokter first;
    adr_dokter last;
};
void createListDokter(ListDokter &LD);
adr_dokter createElmDokter(dokter D);
void insertLastDokter(ListDokter &LD, adr_dokter P);
void DeleteLastDokter(ListDokter &LD, adr_dokter &P);
void showDokter(ListDokter LD);
adr_dokter FindDokter(ListDokter LD, string id, string nama, string spesialisasi);
#endif // PASIEN_H_INCLUDED
