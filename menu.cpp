#include "header.h"

int menu(){
    int select;

    cout << "-------------Rumah Sakit Budiman-------------" << endl;
    cout << "--Pilih Menu--" << endl;
    cout << "1. Show List Dokter" << endl;
    cout << "2. Show List Pasien" << endl;
    cout << "3. Show List Relasi" << endl;
    cout << "4. Tambahkan Dokter Baru" << endl;
    cout << "5. Tambahkan Pasien Baru" << endl;
    cout << "6. Tambahkan relasi Dokter dan Pasien" << endl;
    cout << "7. Hapus Dokter" << endl;
    cout << "8. Hapus pasien" << endl;
    cout << "9. Hapus pasien pada dokter tertentu" << endl;
    cout << "10. Mencari Dokter" << endl;
    cout << "11. Mencari Pasien" << endl;
    cout << "12. Mencari Relasi" << endl;
    cout << "13. Mencari Pasien Dokter" << endl;
    cout << "14. Show data Dokter dan Pasiennya" << endl;
    cout << "15. Show data Pasien dan Dokternya" << endl;
    cout << "16. Show semua data Pasien dan Dokternya" << endl;
    cout << "17. Hitung Relasi Dokter" << endl;
    cout << "18. Hitung Relasi Pasien tertentu" << endl;
    cout << "19. Hitung pasien yang tidak memiliki dokter" << endl;
    cout << "20. Edit Relasi" << endl;
    cout << "0. Exit" << endl;
    cout << "-----------------------------------------------" << endl;

    cin >> select;
    return select;
}
