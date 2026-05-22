#include <iostream>
using namespace std;
void regis(char nama[100][100], char password[100][100], int& jumlah_sekarang) {
    system("cls");
    cout << "=== REGISTER ===" << endl;
    cout << "Masukan Username \t:";
    cin.getline(nama[jumlah_sekarang], 100);
    if (nama[jumlah_sekarang][0] == '\0') {
	cout << "Error: Nama tidak boleh kosong!" << endl;
	return;
    }
    cout << "Masukan Password \t:";
    cin.getline(password[jumlah_sekarang], 100);
    if (password[jumlah_sekarang][0] == '\0') {
	cout << "Error: Password tidak boleh kosong!" << endl;
	return;
    }
    jumlah_sekarang++;
    cout << "Sign In Berhasil" << endl;
}

void login(char log_name[1][100], char log_password[1][100],
	   char nama[100][100], char password[100][100], int& jumlah_sekarang) {
    int indeks_user = -1;
    system("cls");
    do {
	system("cls");
	cout << "=== LOGIN ===" << endl;
	cout << "Masukan Nama \t:";
	cin.getline(log_name[0], 100);
	if (log_name[0][0] == '\0') {
	    cout << "Error: Nama tidak boleh kosong!" << endl;
	    system("pause");
	    continue;
	}

	bool valid_username = false;
	for (int i = 0; i < jumlah_sekarang; i++) {
	    bool sama = true;
	    int j = 0;
	    while (log_name[0][j] != '\0' || nama[i][j] != '\0') {
		if (log_name[0][j] != nama[i][j]) {
		    sama = false;
		    break;
		}
		j++;
	    }
	    if (sama) {
		valid_username = true;
		indeks_user = i;
		break;
	    }
	}

	if (valid_username) {
	    break;
	} else {
	    cout << "Username Tidak Terdaftar" << endl;
	    system("pause");
	}
    } while (true);

    do {
	cout << "Masukan Password :";
	cin.getline(log_password[0], 100);
	if (log_password[0][0] == '\0') {
	    cout << "Error: Password tidak boleh kosong!" << endl;
	    continue;
	}
	bool valid_password = false;
	bool sama = true;
	int j = 0;
	while (log_password[0][j] != '\0' || password[indeks_user][j] != '\0') {
	    if (log_password[0][j] != password[indeks_user][j]) {
		sama = false;
		break;
	    }
	    j++;
	}
	if (sama) {
	    valid_password = true;
	} else {
	    cout << "Password Salah" << endl;
	    cin.clear();
	}

	if (valid_password) {
	    cout << "Berhasil Login" << endl;
	    system("pause");
	    break;
	}
    } while (true);
}

int main() {
    char nama[100][100], password[100][100], username[1][100],
	password_login[1][100];
    int jumlah = 0, main_menu;
    bool cihuy = true;
    while (cihuy) {
	while (true) {
	    system("cls");
	    cout << "1. REGISTER" << endl;
	    cout << "2. Login" << endl;
	    cout << "0. Keluar" << endl;
	    cout << "Pilih: ";
	    cin >> main_menu;
	    if (cin.fail()) {
		cout << "[!] Error: Input harus berupa angka!" << endl;
		cin.clear();
		system("pause");
		while (cin.get() != '\n');
		system("cls");
	    } else {
		break;
	    }
	}
	switch (main_menu) {
	    case 1:
		cin.ignore();
		cin.clear();
		regis(nama, password, jumlah);
		break;
	    case 2:
		cin.ignore();
		cin.clear();
		if (jumlah > 0) {
		    login(username, password_login, nama, password, jumlah);
		} else {
		    cout << "Kosong Jir" << endl;
		    system("pause");
		    system("cls");
		}
		break;
	    case 0:
		cout << "Bye" << endl;
		return 0;
	    default:
		cout << "Input Tidak Valid" << endl;
		system("pause");
		break;
	}
    }
}
