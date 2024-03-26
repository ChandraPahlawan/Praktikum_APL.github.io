#include <iostream>
#include <string>
#include <vector>
#include <limits> 

using namespace std;


struct DataPeserta {
    string nama;
    string jenis_kelamin;
    int umur;
    string nomor_peserta;
};

void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Fungsi menu
void displayMenu() {
    clearScreen();
    cout << "Menu:\n";
    cout << "1. Tambah Data Peserta\n";
    cout << "2. Lihat Data Peserta\n";
    cout << "3. Edit Data Peserta\n";
    cout << "4. Hapus Data Peserta\n";
    cout << "5. Keluar\n";
}

// Fungsi login
bool login() {
    string username, password;
    cout << "Login\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    return (username == "chandra" && password == "11");
}

// Fungsi menambah data peserta ke dalam array
void tambahData(vector<DataPeserta>& dataPeserta) {
    DataPeserta peserta;
    cout << "Masukkan Nama Peserta: ";
    getline(cin, peserta.nama);
    cout << "Masukkan Jenis Kelamin (Laki-laki / Perempuan): ";
    getline(cin, peserta.jenis_kelamin);
    cout << "Masukkan Umur Peserta: ";
    while (!(cin >> peserta.umur)) {
        cout << "Input umur tidak valid. Masukkan umur kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan
    cout << "Masukkan Nomor Peserta: ";
    getline(cin, peserta.nomor_peserta);
    dataPeserta.push_back(peserta);
    cout << "\nData peserta berhasil ditambahkan.\n";
}

// Fungsi menampilkan data peserta 
void lihatData(const vector<DataPeserta>& dataPeserta) {
    clearScreen();
    if (dataPeserta.empty()) {
        cout << "Tidak ada data peserta.\n";
        return;
    }
    cout << "Data Peserta:\n";
    for (size_t i = 0; i < dataPeserta.size(); ++i) {
        cout << "Peserta ke-" << i + 1 << ":\n";
        cout << "  Nama: " << dataPeserta[i].nama << endl;
        cout << "  Jenis Kelamin: " << dataPeserta[i].jenis_kelamin << endl;
        cout << "  Umur: " << dataPeserta[i].umur << endl;
        cout << "  Nomor Peserta: " << dataPeserta[i].nomor_peserta << endl;
    }
}

// Fungsi mengedit data peserta 
void editData(vector<DataPeserta>& dataPeserta) {
    lihatData(dataPeserta);
    if (dataPeserta.empty()) {
        cout << "Tidak ada data peserta untuk diedit.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data peserta yang ingin diedit: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataPeserta.size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan 

    DataPeserta& peserta = dataPeserta[index - 1];
    cout << "Masukkan Nama Peserta yang baru: ";
    getline(cin, peserta.nama);
    cout << "Masukkan Jenis Kelamin yang baru (Laki-laki / Perempuan): ";
    getline(cin, peserta.jenis_kelamin);
    cout << "Masukkan Umur Peserta yang baru: ";
    while (!(cin >> peserta.umur)) {
        cout << "Input umur tidak valid. Masukkan umur kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan 
    cout << "Masukkan Nomor Peserta yang baru: ";
    getline(cin, peserta.nomor_peserta);
    cout << "\nData peserta berhasil diubah.\n";
}

// Fungsi menghapus data peserta dari array
void hapusData(vector<DataPeserta>& dataPeserta) {
    lihatData(dataPeserta);
    if (dataPeserta.empty()) {
        cout << "Tidak ada data peserta untuk dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data peserta yang ingin dihapus: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataPeserta.size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); // Membersihkan buffer 
    dataPeserta.erase(dataPeserta.begin() + index - 1);
    cout << "Data peserta berhasil dihapus.\n";
}

int main() {
    int loginAttempts = 0;
    bool loggedIn = false;

    // Maksimum 3 kali percobaan login
    while (!loggedIn && loginAttempts < 3) {
        if (login()) {
            loggedIn = true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            loginAttempts++;
        }
    }

    // Jika login gagal 3 kali, program berhenti
    if (!loggedIn) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0;
    }


    vector<DataPeserta> dataPeserta;
    char opsi;

    do {
        displayMenu();
        cout << "\nMasukkan pilihan: ";
        cin >> opsi;
        clearBuffer(); // Membersihkan buffer

        switch (opsi) {
            case '1':
                tambahData(dataPeserta);
                break;
            case '2':
                lihatData(dataPeserta);
                break;
            case '3': 
                editData(dataPeserta);
                break;
            case '4':
                hapusData(dataPeserta);
                break;
            case '5':
                cout << "Program berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get(); // Menunggu sampai pengguna menekan Enter
    } while (opsi != '5');

    return 0;
}

//bg saya ganti konsep wkwkw yang sblmnya mlah pusing sendiri saya