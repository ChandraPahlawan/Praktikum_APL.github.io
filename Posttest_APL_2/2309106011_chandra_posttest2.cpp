#include <iostream> // Untuk penggunaan fungsi cout, cin, dan endl
#include<conio.h>   // Untuk penggunaan fungsi getch
#include <stdlib.h> // Untuk bisa menggunakan fungsi clear pada terminal
using namespace std; // Agar tidak perlu menuliskan "std::"

struct data // Terdapat sebuah struct untuk mendeklarasi array dari nama, jenis kelamin dan umur
{
    char nama[100];
    char kelamin[100];
    char umur[100];
    char nomor_peserta[10000]; // Menambahkan nomor peserta sebagai bagian dari struktur data
};

struct data batas[100]; // Untuk mendeklarasikan sebuah array batas yang bertipe struct data
int a, b, c, i, j, ditemukan, pilih; // Untuk keperluan pertambahan indeks array, nomor, pilihan dan perulangan
char tanya; // Untuk tanya saat ingin keluar dari program
string Nama, nomor_peserta; // Untuk variabel saat mencari nama


void inputdata() // Prosedur untuk input data
{
    system("color 90");
    cout<<"Nomor Peserta\t: ";cin>>batas[a].nomor_peserta; // Menambahkan nomor peserta sebagai bagian dari struktur data
    cout<<"Nama Panggilan\t: ";cin>>batas[a].nama; 
    cout<<"Jenis Kelamin (Laki-laki / Perempuan)\t: ";cin>>batas[a].kelamin;
    cout<<"Umur\t\t: ";cin>>batas[a].umur;
    a++; // Untuk penambahan indeks array
    cout<<"\n=========================== Data Berhasil Ditambahkan ===========================";
    getch();system("cls");
}


void lihatdata() // Prosedur untuk lihat data
{
    system("color 90");
    cout<<"\n==================================== Menampilkan Data ====================================\n\n";
    cout<<"==========================================================================================\n";
    cout<<"||\tNO\t||\tNo Peserta\t||\tNama Panggilan\t\t||\tJenis Kelamin\t||\tUmur\t||";
    cout<<"\n==========================================================================================";

    j = 0; // Untuk penomoran dalam tabel
    for(i=0;i<a;i++)
    {
        j=j+1;
        cout<<"\n";
        cout<<"||\t"<<j<<"\t||";
        cout<<"\t"<<batas[i].nomor_peserta<<"\t\t||";
        cout<<"\t\t"<<batas[i].nama<<"\t\t||";
        cout<<"\t"<<batas[i].kelamin<<"\t||";
        cout<<"\t"<<batas[i].umur<<"\t||";
        cout<<"\n==========================================================================================";
    }
    getch();system("cls");
}

void editdata() // Prosedur untuk edit data
{
    apa: // goto yang berfungsi untuk melompat ke baris label
    ditemukan = 0;
    system("color 90");
    cout<<"Masukan nama yang ingin diedit : ";cin>>Nama;

    for( b = 0; b < 100 - 1; b++)
    {
            if (batas[b].nama == Nama){ditemukan++;break;}
            else
            {
                cout<<"Nama tidak ditemukan";
                cout<<"\nApakah anda ingin mengedit kembali ? (Y / T) : "<< endl;cin>>tanya; // Untuk menanyakan user apakah ingin keluar dari program

                if(tanya == 'y'|| tanya == 'Y')
                {
                    system("cls");goto apa;
                }
                if(tanya =='n'|| tanya =='N')
                    {
                        break;break;
                    }
                else // Untuk kesalahan dalam memilih
                {
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto apa;
                }

            }
    }
    
    cout<<"Nama Panggilan\t: ";cin>>batas[b].nama;
    cout<<"Jenis Kelamin (Laki-laki / Perempuan)\t: ";cin>>batas[b].kelamin;
    cout<<"Umur\t: ";cin>>batas[b].umur;
    cout<<"\n================================== Data Berhasil Diedit ==================================\n";
    lihatdata();
}

void hapusdata() // Prosedur untuk hapus data
{
    iya: // goto yang berfungsi untuk melompat ke baris label
    system("color 90");
    cout<<"Masukan nama yang ingin dihapus : ";cin>>Nama;

    for( c = 0; c < 100 - 1; c++)
    {
            if (batas[c].nama == Nama){ditemukan++;break;}
            else
            {
                cout<<"Nama tidak ditemukan";
                cout<<"\nApakah anda ingin menghapus kembali ? (Y / N) : "<< endl;cin>>tanya; // Untuk menanyakan user apakah ingin keluar dari program

                if(tanya == 'y'|| tanya == 'Y')
                {
                    system("cls");goto iya;
                }
                if(tanya =='n'|| tanya =='N')
                    {
                        break;break;
                    }
                else // Untuk kesalahan dalam memilih
                {
                    cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto iya;
                }
            }
    }
    a--; // Untuk indeks di input data
    for(int i=c;i<a;i++)
    {
        batas[i]=batas[i+1];
    }

    system("cls");
    cout<<"\n================================== Data Berhasil Dihapus ==================================\n";
    lihatdata();
}


int menu() // Fungsi utama
{
    awal: // Terdapat label awal sebagai tempat untuk kembali ke menu utama setelah melakukan eksekusi data
    system("cls");
    system("color 90");
    cout<<"\n============================= PROGRAM CRUD DATA PESERTA =============================";
    cout<<"\n=================================== PILIHAN MENU ====================================\n";
    cout<<"\n1. Masukkan data";
    cout<<"\n2. Lihat Data";
    cout<<"\n3. Edit Data";
    cout<<"\n4. Hapus Data";
    cout<<"\n5. Keluar";
    cout<<"\n\nMasukkan Pilihan : ";
    cin>>pilih;
    if(pilih==1)
    {system("cls");inputdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
    if(pilih==2)
    {system("cls");lihatdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
    if(pilih==3)
    {system("cls");editdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
    if(pilih==4)
    {system("cls");hapusdata();goto awal;} // goto yang berfungsi untuk melompat ke baris label
    if(pilih==5)
    {   
        system("cls");
        Tanya: // goto yang berfungsi untuk melompat ke baris label
        cout<<"\nApakah anda ingin keluar dari program ? (Y / T) : "<< endl;cin>>tanya; // Untuk menanyakan user apakah ingin keluar dari program

        if(tanya == 'y'|| tanya == 'Y')
        {
            system("cls");
            cout<<"=======================================================================" << endl;
            cout << "Terimakasih telah menggunakan program ini :) Semoga harimu menyenangkan" << endl;
            cout<<"======================================================================="; exit(0);
        }
        if(tanya =='n'|| tanya =='N')
            {
                system("cls");goto awal;
            }
        else // Untuk kesalahan dalam memilih
        {
            cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto Tanya;
        }
    }
    else // Untuk kesalahan dalam memilih
    {
        cout<<"Pilihan yang anda masukkan salah, Mohon pilih kembali";getch();goto awal;
    }
}
int main() {
    string input_nama, input_nim;

    cout << "Silahkan login menggunakan nama dan nim anda\n\n";
    string nama = "Chandra";
    string nim = "11";
    int coba = 1;

    while (coba <= 3) {
        cout << "Silahkan masukkan username : ";
        cin.sync();
        getline (cin, input_nama);
        cout << "silahkan masukkan password : ";
        cin.sync();
        cin >> input_nim;
        if (input_nama == nama && input_nim == nim){
            cout << "login berhasil\n\n";
            coba = 4;
            menu();
        }else if (coba == 3){
            cout << endl;
            cout << "kalo nd tau username sm pwnya nd ush";
            break;
        }
        else {
            system("cls");
            cout << "username yang anda masukkan salah, percobaan ke " << coba <<"x\n\n";
            coba += 1;
        }
    }
    return 0;
}