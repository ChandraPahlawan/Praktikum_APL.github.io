#include <iostream>
#include <string>
#include <vector>
#include <limits> 
#include <algorithm> // untuk std::sort

using namespace std;

// Definisi struktur untuk menyimpan data peserta
struct DataPeserta {
    string nama;
    string jenis_kelamin;
    int umur;
    string nomor_peserta;
};

// Fungsi untuk membersihkan buffer input
void clearBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk membersihkan layar konsol
void clearScreen() {
    cout << "\033[2J\033[1;1H";
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    clearScreen();
    cout << "Menu:\n";
    cout << "1. Tambah Data Peserta\n";
    cout << "2. Lihat Data Peserta\n";
    cout << "3. Edit Data Peserta\n";
    cout << "4. Hapus Data Peserta\n";
    cout << "5. Urutkan Nama Peserta Secara Ascending\n";
    cout << "6. Urutkan Nama Peserta Secara Descending\n";
    cout << "7. Urutkan Umur Peserta (Insertion sort)\n";
    cout << "8. Cari Data Peserta berdasarkan Umur (Interpolation Search)\n";
    cout << "9. Keluar\n";
}

// Fungsi untuk melakukan login
bool login() {
    string username, password;
    cout << "Login\n";
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    return (username == "chandra" && password == "11");
}

// Fungsi untuk menambahkan data peserta baru
void tambahData(vector<DataPeserta>* dataPeserta) {
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
    clearBuffer(); 
    cout << "Masukkan Nomor Peserta: ";
    getline(cin, peserta.nomor_peserta);
    dataPeserta->push_back(peserta);
    cout << "\nData peserta berhasil ditambahkan.\n";
}

// Fungsi untuk melihat data peserta
void lihatData(const vector<DataPeserta>* dataPeserta) {
    clearScreen();
    if (dataPeserta->empty()) {
        cout << "Tidak ada data peserta.\n";
        return;
    }
    cout << "Data Peserta:\n";
    for (size_t i = 0; i < dataPeserta->size(); ++i) {
        cout << "Peserta ke-" << i + 1 << ":\n";
        cout << "  Nama: " << (*dataPeserta)[i].nama << endl;
        cout << "  Jenis Kelamin: " << (*dataPeserta)[i].jenis_kelamin << endl;
        cout << "  Umur: " << (*dataPeserta)[i].umur << endl;
        cout << "  Nomor Peserta: " << (*dataPeserta)[i].nomor_peserta << endl;
    }
}

void editData(vector<DataPeserta>* dataPeserta) {
    lihatData(dataPeserta);
    if (dataPeserta->empty()) {
        cout << "Tidak ada data peserta untuk diedit.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data peserta yang ingin diedit: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataPeserta->size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer();

    DataPeserta& peserta = (*dataPeserta)[index - 1];
    cout << "Masukkan Nama Peserta yang baru: ";
    getline(cin, peserta.nama);
    cout << "Masukkan Jenis Kelamin yang baru (Laki-laki / Perempuan): ";
    getline(cin, peserta.jenis_kelamin);
    cout << "Masukkan Umur Peserta yang baru: ";
    while (!(cin >> peserta.umur)) {
        cout << "Input umur tidak valid. Masukkan umur kembali: ";
        clearBuffer();
    }
    clearBuffer(); 
    cout << "Masukkan Nomor Peserta yang baru: ";
    getline(cin, peserta.nomor_peserta);
    cout << "\nData peserta berhasil diubah.\n";
}

void hapusData(vector<DataPeserta>* dataPeserta) {
    lihatData(dataPeserta);
    if (dataPeserta->empty()) {
        cout << "Tidak ada data peserta untuk dihapus.\n";
        return;
    }
    int index;
    cout << "Masukkan nomor data peserta yang ingin dihapus: ";
    while (!(cin >> index) || index <= 0 || index > static_cast<int>(dataPeserta->size())) {
        cout << "Nomor tidak valid. Masukkan nomor kembali: ";
        clearBuffer();
    }
    clearBuffer(); 
    dataPeserta->erase(dataPeserta->begin() + index - 1);
    cout << "Data peserta berhasil dihapus.\n";
}

// Fungsi untuk sorting nama peserta secara ascending
void sortNamaAscending(vector<DataPeserta>* dataPeserta) {
    sort(dataPeserta->begin(), dataPeserta->end(), [](const DataPeserta& a, const DataPeserta& b) {
        return a.nama < b.nama;
    });
    cout << "\nData peserta berhasil diurutkan secara ascending berdasarkan nama. Silahkan cek kembali data peserta\n";
}

// Fungsi untuk sorting nama peserta secara descending
void sortNamaDescending(vector<DataPeserta>* dataPeserta) {
    sort(dataPeserta->begin(), dataPeserta->end(), [](const DataPeserta& a, const DataPeserta& b) {
        return a.nama > b.nama;
    });
    cout << "\nData peserta berhasil diurutkan secara descending berdasarkan nama. Silahkan cek kembali data peserta\n";
}

void sortUmurAscending(vector<DataPeserta>* dataPeserta) {
    int n = dataPeserta->size();
    for (int i = 1; i < n; ++i) {
        DataPeserta key = (*dataPeserta)[i];
        int j = i - 1;
        while (j >= 0 && (*dataPeserta)[j].umur > key.umur) {
            (*dataPeserta)[j + 1] = (*dataPeserta)[j];
            j = j - 1;
        }
        (*dataPeserta)[j + 1] = key;
    }
    cout << "\nData peserta berhasil diurutkan secara ascending berdasarkan umur. Silahkan cek kembali data peserta\n";
}

int interpolationSearchUmur(const vector<DataPeserta>& dataPeserta, int umur) {
    int low = 0;
    int high = dataPeserta.size() - 1;
    
    while (low <= high && umur >= dataPeserta[low].umur && umur <= dataPeserta[high].umur) {
        if (low == high) {
            if (dataPeserta[low].umur == umur)
                return low;
            return -1;
        }

        // Proses interpolasi untuk mencari posisi
        int pos = low + (((double)(high - low) / (dataPeserta[high].umur - dataPeserta[low].umur)) * (umur - dataPeserta[low].umur));

        // Jika ditemukan
        if (dataPeserta[pos].umur == umur)
            return pos;
        // Jika elemen berada di sebelah kiri
        else if (dataPeserta[pos].umur > umur)
            high = pos - 1;
        // Jika elemen berada di sebelah kanan
        else
            low = pos + 1;
    }
    return -1; // Data tidak ditemukan
}


// Fungsi utama
int main() {
    // Inisialisasi vector untuk menyimpan data peserta
    vector<DataPeserta> dataPeserta;

    // Percobaan login
    int loginAttempts = 0;
    bool loggedIn = false;

    while (!loggedIn && loginAttempts < 3) {
        if (login()) {
            loggedIn = true;
        } else {
            cout << "Login gagal. Silakan coba lagi.\n";
            loginAttempts++;
        }
    }

    if (!loggedIn) {
        cout << "Anda telah melebihi batas percobaan login. Program berhenti.\n";
        return 0;
    }

    char opsi;

    // Loop menu
    do {
        // Menampilkan menu
        displayMenu();
        cout << "\nMasukkan pilihan: ";
        cin >> opsi;
        clearBuffer();

        // Memproses pilihan pengguna
        switch (opsi) {
            case '1':
                tambahData(&dataPeserta);
                break;
            case '2':
                lihatData(&dataPeserta);
                break;
            case '3': 
                editData(&dataPeserta);
                break;
            case '4':
                hapusData(&dataPeserta);
                break;
            case '5':
                sortNamaAscending(&dataPeserta);
                break;
            case '6':
                sortNamaDescending(&dataPeserta);
                break;
            case '7':
                sortUmurAscending(&dataPeserta);
                break;
            case '8':{
                int umur;
                cout << "Masukkan umur yang ingin dicari: ";
                cin >> umur;
                int hasilPencarian = interpolationSearchUmur(dataPeserta, umur);
                if (hasilPencarian != -1) {
                    cout << "Data peserta dengan umur " << umur << " ditemukan pada indeks " << hasilPencarian + 1 << ".\n";
                    cout << "Detail data:\n";
                    cout << "  Nama: " << dataPeserta[hasilPencarian].nama << endl;
                    cout << "  Jenis Kelamin: " << dataPeserta[hasilPencarian].jenis_kelamin << endl;
                    cout << "  Umur: " << dataPeserta[hasilPencarian].umur << endl;
                    cout << "  Nomor Peserta: " << dataPeserta[hasilPencarian].nomor_peserta << endl;
                } else {
                    cout << "Data peserta dengan umur " << umur << " tidak ditemukan.\n";
                }
                break;
            }
            case '9':
                cout << "Program berhenti.\n";
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
        cout << "\nTekan Enter untuk melanjutkan...";
        cin.get(); 
    } while (opsi != '9');

    return 0;
}
