#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
using namespace std;

struct Data {
    char nama[100];
    char kelamin[100];
    char umur[100];
    char nomor_peserta[10000];
};

Data batas[100];
int a = 0;

void inputData() {
    system("color 90");
    cout << "Nomor Peserta\t: ";
    cin >> batas[a].nomor_peserta;
    cout << "Nama Panggilan\t: ";
    cin >> batas[a].nama;
    cout << "Jenis Kelamin (Laki-laki / Perempuan)\t: ";
    cin >> batas[a].kelamin;
    cout << "Umur\t\t: ";
    cin >> batas[a].umur;
    a++;
    cout << "\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();
    system("cls");
}

void lihatData(int i = 0) {
    system("color 90");
    if (i == 0) {
        cout << "\n==================================== Menampilkan Data ====================================\n\n";
        cout << "==========================================================================================\n";
        cout << "||\tNO\t||\tNo Peserta\t||\tNama Panggilan\t\t||\tJenis Kelamin\t||\tUmur\t||";
        cout << "\n==========================================================================================";
    }

    if (i < a) {
        cout << "\n";
        cout << "||\t" << (i + 1) << "\t||";
        cout << "\t" << batas[i].nomor_peserta << "\t\t||";
        cout << "\t\t" << batas[i].nama << "\t\t||";
        cout << "\t" << batas[i].kelamin << "\t||";
        cout << "\t" << batas[i].umur << "\t||";
        cout << "\n==========================================================================================";
        lihatData(i + 1);
    } else {
        getch();
        system("cls");
    }
}

void editData() {
    system("color 90");
    char Nama[100];
    int ditemukan = 0;
    cout << "Masukan nama yang ingin diedit : ";
    cin >> Nama;

    for (int b = 0; b < a; b++) {
        if (strcmp(batas[b].nama, Nama) == 0) {
            ditemukan++;
            cout << "Nama Panggilan\t: ";
            cin >> batas[b].nama;
            cout << "Jenis Kelamin (Laki-laki / Perempuan)\t: ";
            cin >> batas[b].kelamin;
            cout << "Umur\t: ";
            cin >> batas[b].umur;
            break;
        }
    }

    if (ditemukan == 0) {
        cout << "Nama tidak ditemukan\n";
    }

    cout << "\n================================== Data Berhasil Diedit ==================================\n";
    lihatData();
}

void hapusData() {
    system("color 90");
    char Nama[100];
    int ditemukan = 0;
    cout << "Masukan nama yang ingin dihapus : ";
    cin >> Nama;

    for (int c = 0; c < a; c++) {
        if (strcmp(batas[c].nama, Nama) == 0) {
            ditemukan++;
            for (int i = c; i < a - 1; i++) {
                batas[i] = batas[i + 1];
            }
            a--;
            break;
        }
    }

    if (ditemukan == 0) {
        cout << "Nama tidak ditemukan\n";
    }

    cout << "\n================================== Data Berhasil Dihapus ==================================\n";
    lihatData();
}

void programUtama() {
    system("cls");
    system("color 90");
    int pilih;
    cout << "\n============================= PROGRAM CRUD DATA PESERTA =============================";
    cout << "\n=================================== PILIHAN MENU ====================================\n";
    cout << "\n1. Masukkan data";
    cout << "\n2. Lihat Data";
    cout << "\n3. Edit Data";
    cout << "\n4. Hapus Data";
    cout << "\n5. Keluar";
    cout << "\n\nMasukkan Pilihan : ";
    cin >> pilih;

    switch (pilih) {
        case 1:
            inputData();
            break;
        case 2:
            lihatData();
            break;
        case 3:
            editData();
            break;
        case 4:
            hapusData();
            break;
        case 5:
            char tanya;
            cout << "Apakah anda ingin keluar dari program ? (Y / T) : ";
            cin >> tanya;
            if (tanya == 'y' || tanya == 'Y') {
                cout << "\n=======================================================================";
                cout << "\nTerimakasih telah menggunakan program ini :) Semoga harimu menyenangkan";
                cout << "\n=======================================================================\n";
                exit(0);
            }
            break;
        default:
            cout << "Pilihan yang anda masukkan salah, Mohon pilih kembali";
    }
    programUtama(); // Rekursi untuk menjalankan programUtama() secara berulang
}

void login() {
    string input_nama, input_nim;
    cout << "Silahkan login menggunakan nama dan nim anda\n\n";
    string nama = "chandra";
    string nim = "11";
    int coba = 1;

    while (coba <= 3) {
        cout << "Silahkan masukkan username : ";
        cin.sync();
        getline(cin, input_nama);
        cout << "Silahkan masukkan password : ";
        cin.sync();
        cin >> input_nim;
        if (input_nama == nama && input_nim == nim) {
            cout << "Login berhasil\n\n";
            programUtama();
            break;
        } else if (coba == 3) {
            cout << endl;
            cout << "Kesempatan login habis. Silakan coba lagi nanti.";
            break;
        } else {
            system("cls");
            cout << "Username atau password yang Anda masukkan salah. Percobaan ke-" << coba << "\n\n";
            coba += 1;
        }
    }
}

int main() {
    login(); // Memanggil fungsi login()
    return 0;
}
