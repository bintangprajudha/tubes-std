#include <iostream>
#include "header.h"

using namespace std;

int main()
{
    ListDokter LD;
    ListPasien LP;
    int select;


    createListDokter(LD);

    select = menu();

    while (select != 0) {
        switch(select) {
            case 1:
                showDokter(LD);
                break;
            case 2:
                ShowPasien(LP)
                break;
            case 3:
                // code block
                break;
            case 4:
                dokter d;
                cout << "Masukkan nama dokter: ";
                cin << d.id;
                cin << d.nama;
                cin << d.spesialisasi;
                cin << d.jk;
                cin << d.umur;
                cin << d.NKD;
                cin << d.nomorHP;

                adr_dokter createElmDokter(dokter D)
                insertLastDokter(LD, p)
                break;
            case 5:
                // code block
                break;
            case 6:
                // code block
                break;
            case 7:
                // code block
                break;
            case 8:
                // code block
                break;
            case 9:
                // code block
                break;
            case 10:
                // code block
                break;
            case 11:
                // code block
                break;
            case 12:
                // code block
                break;
            case 13:
                // code block
                break;
            case 14:
                // code block
                break;
            case 15:
                // code block
                break;
            case 16:
                // code block
                break;
            case 17:
                // code block
                break;
            case 18:
                // code block
                break;
            case 19:
                // code block
                break;
            case 0:
                // code block
                break;
            default:
                break;
        // code block
        }
        select = menu();
    }

    return 0;
}
