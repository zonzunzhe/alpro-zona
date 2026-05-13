#include <iostream>
using namespace std;


void pause();
void errorAngka();
void judul(string teks);
void awalan();
void bannersatu(string satu);
void header(char a='#', char b='#'); 

void menu1(string nama[], int stok[], int harga[], int &total);
void input_barang(string nama[], int stok[], int harga[], int &total);
void hapus_barang(string nama[], int stok[], int harga[], int &total);
void lihat_barang(string nama[], int stok[], int harga[], int total);
void menu_edit(string nama[], int stok[], int harga[], int total); 
 
void kalkulator_menu();
void banner_kalkulator();
void operasiDasar(float a, float b, char op);
long long faktorial(int n);

void pause() {
    cout << "Press any key to continue . . . ";
    cin.get();
}
void errorAngka() {
    cout << "[Gagal] Input harus berupa angka!\n";
    cin.clear(); 
    cin.ignore(1000, '\n');
    pause();
}
void judul(string teks) {
    system("cls");
    bannersatu("TIVAIZ STORE");
    cout << "-----------------------------------------\n";
    cout << "               " << teks << "              \n";
    cout << "-----------------------------------------\n";
}
void awalan() {
    cout << "|===============================================|\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "[\t\tFUNCTION - MODUL 4\t\t]\n";
    cout << "|\t\t\t\t\t\t|\n";
    cout << "|===============================================|\n";
    cout << "1. TIVAIZ Store\n2. Kalkulator TIVAIZ\n0. Keluar\n";
    cout << "=================================================\nPilih Menu: "; 
}
void bannersatu(string satu) {
    cout << "#=======================================#\n";
    cout << "|\t\t" << satu << "\t\t|\n";
    cout << "#=======================================#\n";
}
void header(char a, char b) {
    cout << a << "=======================================================" << b << endl;
}
void menu1(string nama[], int stok[], int harga[], int &total) {
    int pilihan;
    cout << "1. Input Barang\n";
	cout << "2. Hapus Barang\n";
	cout << "3. Edit Barang\n";
	cout << "4. Lihat Barang\n";
	cout << "0. Keluar\n";
    cout << "=================================================\n";
	cout << "Pilih Menu: ";
    cin >> pilihan;
    
    if (cin.fail()) {
        cin.clear(); cin.ignore(1000, '\n'); return; 
    }
    switch(pilihan) {
        case 1: input_barang(nama, stok, harga, total);
        break;
        case 2: hapus_barang(nama, stok, harga, total); 
        break;
        case 3: menu_edit(nama, stok, harga, total); 
        break;
        case 4: lihat_barang(nama, stok, harga, total); 
        break;
        case 0: return;
    }
}
void input_barang(string nama[], int stok[], int harga[], int &total) {
    judul("INPUT BARANG");
    cout << "Nama Barang : ";
    cin.ignore(); 
    getline(cin, nama[total]);
    cout << "-----------------------------------------\n";

    cout << "Stok (unit) : ";
    cin >> stok[total];
    if (cin.fail()) { errorAngka(); return; }
    cout << "-----------------------------------------\n";

    cout << "Harga (Rp)  : ";
    cin >> harga[total];
    if (cin.fail()){
        errorAngka(); return; 
    }
    cout << "\n[Berhasil] " << nama[total] << " ditambahkan! (Total barang: " << total + 1 << ")\n";
    total++; 
    cin.ignore(1000, '\n'); pause();
}
void hapus_barang(string nama[], int stok[], int harga[], int &total) {
    judul("HAPUS BARANG");
    if (total == 0) {
        cout << "Belum ada data barang.\n";
        cin.ignore(1000, '\n'); pause();
        return;
    }
    for (int i = 0; i < total; i++) {
        cout << "No          : " << i + 1 << "\n";
          cout <<"Nama Barang : " << nama[i] << "\n";
		  cout <<"Stok Barang : " << stok[i] << "\n";
		  cout <<"Harga/Stok  : Rp " << harga[i] << "\n";
		  cout <<"-----------------------------------------\n";
    }
    int hapus;
    cout << "Pilih nomor barang yang dihapus (1-" << total << "): ";
    cin >> hapus;

    if (cin.fail() || hapus < 1 || hapus > total) {
        if (cin.fail()) errorAngka();
        else {
            cout << "[Gagal] Nomor " << hapus << " tidak valid! Pilih antara 1 sampai " << total << ".\n";
            cin.clear(); cin.ignore(1000, '\n'); 
			pause();
        }
        return;
    }

    string nama_dihapus = nama[hapus - 1];
    for (int i = hapus - 1; i < total - 1; i++) {
        nama[i] = nama[i + 1]; stok[i] = stok[i + 1]; harga[i] = harga[i + 1];
    }
    total--;

    cout << "\n[Berhasil] " << nama_dihapus << " dihapus! (Total barang: " << total << ")\n";
    cin.ignore(1000, '\n'); pause();
}
void lihat_barang(string nama[], int stok[], int harga[], int total) {
    judul("LIHAT BARANG");
    if (total == 0) {
        cout << "Belum ada data barang.\n";
		cout<< "-----------------------------------------\n";
        cin.ignore(1000, '\n'); pause(); return;
    }

    for (int i = 0; i < total; i++) {
        long long totalHarga = (long long)stok[i] * harga[i]; 
        cout << "No          : " << i + 1 << "\n";
		cout << "Nama Barang : " << nama[i] << "\n";
		cout << "Stok Barang : " << stok[i] << "\n";
        cout << "Harga/Stok  : Rp " << harga[i] << "\n";
		cout << "Total Harga : Rp " << totalHarga << "\n";
		cout << "-----------------------------------------\n";
    }
    cout << "Total barang : " << total << " jenis\n";
	cout << "-----------------------------------------\n";
    cin.ignore(1000, '\n'); pause();
}

void menu_edit(string nama[], int stok[], int harga[], int total) {
    judul("EDIT BARANG");
    if (total == 0) {
        cout << "Belum ada data barang.\n";
        cin.ignore(1000, '\n'); pause(); return;
    }
    lihat_barang(nama,stok,harga,total);
    
    
    
    
    
}
void bannerdua(string dua){
    cout << "#=======================================#\n";
    cout << "|\t\t" << dua << "\t\t|\n";
    cout << "#=======================================#\n";
}

void operasiDasar(float a, float b, char op) {
    if (op == '/' && b == 0) {
        cout << "[Gagal] Tidak bisa dibagi nol!\n";
    } else if (op == '+') {
        cout << a << " + " << b << " = " << a + b << "\n";
    } else if (op == '-') {
        cout << a << " - " << b << " = " << a - b << "\n";
    } else if (op == '*') {
        cout << a << " * " << b << " = " << a * b << "\n";
    } else if (op == '/') {
        cout << a << " / " << b << " = " << a / b << "\n";
    } else {
        cout << "[Gagal] Operator tidak dikenal!\n";
    }
}

long long faktorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * faktorial(n - 1);
}

void kalkulator_menu() {
    int pilihan_menu;
    while (true) {
        system("cls");
        bannerdua("KALKULATOR");
        cout << "1. Operasi Dasar (+, -, *, /)\n";
        cout << "2. Faktorial\n";
        cout << "0. Kembali\n";
        cout << "-----------------------------------------\n";
        cout << "Pilih menu: ";
        cin >> pilihan_menu;

        if (cin.fail()) {
            errorAngka(); 
            continue;
        }

        if (pilihan_menu == 1) {
            char op; 
            float a, b;
            
            cout << "-----------------------------------------\n";
            cout << "Operator (+, -, *, /) : ";
            cin >> op;
            cout << "-----------------------------------------\n";
            
            cout << "Angka pertama : ";
            cin >> a;
            if (cin.fail()) { errorAngka(); continue; }
            cout << "-----------------------------------------\n";
            
            cout << "Angka kedua   : ";
            cin >> b;
            if (cin.fail()) { errorAngka(); continue; }
            cout << "-----------------------------------------\n";
            
            operasiDasar(a, b, op);
            cin.ignore(1000, '\n'); pause();

        } else if (pilihan_menu == 2) {
            system("cls");
            bannerdua("KALKULATOR");
            int n;
            
            cout << "-----------------------------------------\n";
            cout << "N : ";
            cin >> n;
            cout << "-----------------------------------------\n";
            
            if (cin.fail()) { errorAngka(); continue; }

            if (n < 0) {
                cout << "[Gagal] Faktorial tidak bisa untuk angka negatif!\n";
            } else {
                cout << n << "! = " << faktorial(n) << "\n";
            }
            cin.ignore(1000, '\n'); pause();

        } else if (pilihan_menu == 0) {
            break; 
        } else {
            cout << "[Gagal] Menu tidak valid! Pilih antara 0 sampai 2.\n";
            cin.ignore(1000, '\n'); pause();
        }
    }
}

int main() {
    string namaBarang[100];
    int stokBarang[100];
    int hargaBarang[100];
    int totalBarang = 0; 

    int pilihan;
    bool ulang = true;
    
    do {
        system("cls");
        awalan();
        cin >> pilihan;
        
        if (cin.fail()) {
            cin.clear(); cin.ignore(1000, '\n'); 
        } else if (pilihan == 1) {
            system("cls");
            bannersatu("TIVAIZ STORE");
            menu1(namaBarang, stokBarang, hargaBarang, totalBarang);
        } else if (pilihan == 2) {
//        	system("cls");
//        	bannerdua("KALKULATOR");
            kalkulator_menu();
        } else if (pilihan == 0) {
            ulang = false; 
        }
    } while (ulang == true);
    
    system("cls");
    header();
    cout << "  Terima kasih telah menggunakan program TIVAIZ  \n";
    header();
    
    return 0;
}