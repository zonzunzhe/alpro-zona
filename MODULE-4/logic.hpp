#ifndef LOGIC_HPP
#define LOGIC_HPP
#include <iostream>
#define cin std::cin
#define cout std::cout
#define endl std::endl
void banner_awal() {
    cout << "|=======================================================|" << endl;
    cout << "|                                                       |" << endl;
    cout << "[                 MODULE 4 FUNCTION                     ]" << endl;
    cout << "|                                                       |" << endl;
    cout << "|=======================================================|" << endl;
}
void header(char chara_a = '#', char chara_b = '#') {
    cout << chara_a
	 << "=======================================================" << chara_b
	 << endl;
}
void header2() {
    cout << "---------------------------------------------------------" << endl;
}
void input_barang(char daftar_barang[100][50], int stok_barang[100],
		  int harga_barang[100], int& jumlah_sekarang) {
    system("cls");
    header();
    cout << "|                    TIVAIZ STORE                       |" << endl;
    header();
    header2();
    cout << "                     INPUT BARANG                          "
	 << endl;
    header2();
    if (jumlah_sekarang >= 100) {
	cout << "Penyimpanan Penuh!" << endl;
	return;
    }
    cin.ignore();
    header2();
    cout << "Nama Barang \t:";
    cin.getline(daftar_barang[jumlah_sekarang], 50);
    header2();
    if (daftar_barang[jumlah_sekarang][0] == '\0') {
	cout << "Error: Nama barang tidak boleh kosong!" << endl;
	return;
    }
    while (true) {
	cout << "Harga Barang \t:";
	cin >> harga_barang[jumlah_sekarang];
	header2();

	if (cin.fail() || harga_barang[jumlah_sekarang] < 0) {
	    cout << "[!] Error: Input harus berupa angka positif!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }
    while (true) {
	cout << "Stok Barang \t:";
	cin >> stok_barang[jumlah_sekarang];
	header2();

	if (cin.fail() || stok_barang[jumlah_sekarang] < 0) {
	    cout << "[!] Error: Stok harus berupa angka positif!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }
    jumlah_sekarang++;
    cout << "Barang berhasil ditambahkan!" << endl;
    header2();
}

void lihat_barang(char daftar_barang[100][50], int stok_barang[100],
		  int harga_barang[100], int jumlah_sekarang) {
    if (jumlah_sekarang == 0) {
	cout << "Kosong loh yaaa" << endl;
	return;
    }
    for (int i = 0; i < jumlah_sekarang; i++) {
	header2();
	cout << "No\t\t: " << i + 1 << endl;
	header2();
	cout << "Nama Barang\t: " << daftar_barang[i] << endl;
	header2();
	cout << "Harga\t\t: Rp." << harga_barang[i] << endl;
	header2();
	cout << "Stok\t\t: " << stok_barang[i] << endl;
	header2();
    }
}
void hapus_barang(char daftar_barang[100][50], int stok_barang[100],
		  int harga_barang[100], int& jumlah_sekarang) {
    system("cls");
    header();
    cout << "|                    TIVAIZ STORE                       |" << endl;
    header();
    header2();
    cout << "                     HAPUS BARANG                          "
	 << endl;
    header2();
    lihat_barang(daftar_barang, stok_barang, harga_barang, jumlah_sekarang);
    if (jumlah_sekarang == 0)
	return;

    int indeks;
    while (true) {
	cout << "Pilih nomor barang yang dihapus" << "(1-" << jumlah_sekarang
	     << "):";
	cin >> indeks;
	if (cin.fail() || indeks < 0) {
	    cout << "[!] Error: Input harus berupa angka positif!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }
    indeks--;
    if (indeks >= 0 && indeks < jumlah_sekarang) {
	for (int i = indeks; i < jumlah_sekarang - 1; i++) {
	    for (int j = 0; j < 50; j++) {
		daftar_barang[i][j] = daftar_barang[i + 1][j];
	    }
	    harga_barang[i] = harga_barang[i + 1];
	    stok_barang[i] = stok_barang[i + 1];
	}
	jumlah_sekarang--;
	cout << "Barang berhasil dihapus!" << endl;
    } else {
	cout << "Nomor tidak valid!" << endl;
	return;
    }
}
void edit_barang(char daftar_barang[100][50], int stok_barang[100],
		 int harga_barang[100], int& jumlah_sekarang) {
    system("cls");
    header();
    cout << "|                    TIVAIZ STORE                       |" << endl;
    header();
    header2();
    cout << "                     EDIT BARANG                          "
	 << endl;
    header2();
    lihat_barang(daftar_barang, stok_barang, harga_barang, jumlah_sekarang);

    if (jumlah_sekarang == 0) {
	return;
    }

    int indeks, option;
    while (true) {
	cout << "Pilih nomor barang yang diedit" << "(1-" << jumlah_sekarang
	     << "):";
	cin >> indeks;
	if (cin.fail() || indeks <= 0 || indeks > jumlah_sekarang) {
	    cout << "[!] Error: Nomor tidak valid!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }

    indeks--;  // Penyesuaian ke indeks array
    int shift;

    if (indeks >= 0 && indeks < jumlah_sekarang) {
	while (true) {
	    while (true) {
		system("pause");
		system("cls");
		header();
		cout << "|                    TIVAIZ STORE                     "
			"  |"
		     << endl;
		header();
		header2();
		cout << "                     EDIT BARANG                      "
			"    "
		     << endl;
		header2();
		cout << "Barang: " << daftar_barang[indeks] << endl;
		cout << "Harga Saat Ini: Rp." << harga_barang[indeks] << endl;
		cout << "Stok Saat Ini : " << stok_barang[indeks] << endl;
		header2();
		cout << "1. Edit Harga" << endl;
		cout << "2. Tambah Stok" << endl;
		cout << "3. Kurangi Stok" << endl;
		cout << "0. Kembali" << endl;
		header2();
		cout << "Pilih Opsi: ";
		cin >> option;

		if (cin.fail()) {
		    cout << "[!] Error: Input harus berupa angka" << endl;
		    cin.clear();
		    while (cin.get() != '\n');
		} else {
		    break;
		}
	    }

	    if (option == 1) {
		int harga_lama = harga_barang[indeks];
		while (true) {
		    cout << "Harga Baru (Rp.): ";
		    cin >> harga_barang[indeks];
		    if (cin.fail() || harga_barang[indeks] < 0) {
			cout << "[!] Error: Input harus berupa angka positif"
			     << endl;
			cin.clear();
			while (cin.get() != '\n');
		    } else {
			break;
		    }
		}
		cout << "Harga " << daftar_barang[indeks] << " : Rp."
		     << harga_lama << " --> Rp." << harga_barang[indeks]
		     << endl;
	    } else if (option == 2) {
		while (true) {
		    cout << "Jumlah Tambah: ";
		    cin >> shift;
		    if (cin.fail() || shift < 0) {
			cout << "[!] Error: Input harus berupa angka positif"
			     << endl;
			cin.clear();
			while (cin.get() != '\n');
		    } else {
			break;
		    }
		}
		int stok_sebelumnya = stok_barang[indeks];
		stok_barang[indeks] += shift;
		cout << "Stok " << daftar_barang[indeks] << " : "
		     << stok_sebelumnya << " --> " << stok_barang[indeks]
		     << endl;
	    } else if (option == 3) {
		while (true) {
		    cout << "Jumlah Kurang: ";
		    cin >> shift;
		    if (cin.fail() || shift < 0) {
			cout << "[!] Error: Input harus berupa angka positif"
			     << endl;
			cin.clear();
			while (cin.get() != '\n');
		    } else {
			break;
		    }
		}
		if (shift > stok_barang[indeks]) {
		    cout << "[!] Error: Stok tidak mencukupi! (Stok saat ini: "
			 << stok_barang[indeks] << ")" << endl;
		} else {
		    int stok_sebelumnya = stok_barang[indeks];
		    stok_barang[indeks] -= shift;
		    cout << "Stok " << daftar_barang[indeks] << " : "
			 << stok_sebelumnya << " --> " << stok_barang[indeks]
			 << endl;
		}
	    } else if (option == 0) {
		return;
	    } else {
		cout << "Input Tidak Valid" << endl;
	    }
	}
    }
}
void store_menu(char daftar_barang[100][50], int stok_barang[100],
		int harga_barang[100], int& jumlah_sekarang, bool aseli) {
    int menu_pilihan;
    do {
	while (true) {
	    header();
	    cout << "|                    TIVAIZ STORE                       |"
		 << endl;
	    header();
	    cout << "1. Input Barang" << endl;
	    cout << "2. Hapus Barang" << endl;
	    cout << "3. Edit Barang" << endl;
	    cout << "4. Lihat Barang" << endl;
	    cout << "0. Kembali" << endl;
	    header();
	    cout << "Pilih Menu: ";
	    cin >> menu_pilihan;
	    if (cin.fail()) {
		cout << "[!] Error: Input harus berupa angka" << endl;
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	    } else {
		break;
	    }
	}
	switch (menu_pilihan) {
	    case 1:
		input_barang(daftar_barang, stok_barang, harga_barang,
			     jumlah_sekarang);
		system("pause");
		system("cls");
		break;
	    case 2:
		hapus_barang(daftar_barang, stok_barang, harga_barang,
			     jumlah_sekarang);
		system("pause");
		system("cls");
		break;
	    case 3:
		edit_barang(daftar_barang, stok_barang, harga_barang,
			    jumlah_sekarang);
		system("pause");
		system("cls");
		break;
	    case 4:
		system("cls");
		header();
		cout << "|                    TIVAIZ STORE                     "
			"  |"
		     << endl;
		header();
		header2();
		cout << "                     LIHAT BARANG                     "
			"     "
		     << endl;
		header2();
		lihat_barang(daftar_barang, stok_barang, harga_barang,
			     jumlah_sekarang);
		system("pause");
		system("cls");
		break;
	    case 0:
		system("pause");
		system("cls");
		return;
	    default:
		cout << "Pilihan Tidak Valid" << endl;
		system("pause");
		system("cls");
	}
    } while (aseli);
}
void kalkulator_dasar() {
    double angka_a, angka_b;
    char operasi;
    while (true) {
	header2();
	cout << "Masukan Angka Pertama: ";
	cin >> angka_a;
	header2();
	if (cin.fail()) {
	    cout << "[!] Error: Input harus berupa angka!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }
    while (true) {
	cout << "Masukan Angka Kedua: ";
	cin >> angka_b;
	header2();
	if (cin.fail()) {
	    cout << "[!] Error: Input harus berupa angka!" << endl;
	    cin.clear();
	    while (cin.get() != '\n');
	} else {
	    break;
	}
    }
    while (true) {
	cout << "Masukan Operasi(+ , - , * , /): ";
	cin >> operasi;
	header2();
	if (operasi == '+') {
	    double hasil = angka_a + angka_b;
	    cout << "Hasil Operasi " << angka_a << " " << operasi << " "
		 << angka_b << " = " << hasil << endl;
	    break;
	} else if (operasi == '-') {
	    double hasil = angka_a - angka_b;
	    cout << "Hasil Operasi " << angka_a << " " << operasi << " "
		 << angka_b << " = " << hasil << endl;
	    break;
	} else if (operasi == '*') {
	    double hasil = angka_a * angka_b;
	    cout << "Hasil Operasi " << angka_a << " " << operasi << " "
		 << angka_b << " = " << hasil << endl;
	    break;
	} else if (operasi == '/') {
	    if (angka_b != 0) {
		double hasil = angka_a / angka_b;
		cout << "Hasil Operasi " << angka_a << " " << operasi << " "
		     << angka_b << " = " << hasil << endl;
	    } else {
		cout << "Error: Pembagian dengan nol gk boleh!" << endl;
	    }
	    break;
	} else {
	    cout << "Operasi Tidak Valid" << endl;
	    cin.ignore(1000, '\n');
	    cin.clear();
	}
    }
}
long long faktorial(int angka_faktorial) {
    if (angka_faktorial <= 1) {
	return 1;
    }
    return angka_faktorial * faktorial(angka_faktorial - 1);
}
void kalkulator_menu() {
    int pilihan_menu, angka_faktorial;
    bool cihuy = 1;
    do {
	header('+', '-');
	cout << "|                    K4LKUL4T0R                         |"
	     << endl;
	header('x', '/');
	cout << "1. Operasi Dasar" << endl;
	cout << "2. Faktorial" << endl;
	cout << "0. Kembali" << endl;
	header();
	cout << "Pilih Menu: ";
	cin >> pilihan_menu;
	switch (pilihan_menu) {
	    case 1:
		system("cls");
		header('+', '-');
		cout << "|                    K4LKUL4T0R                       "
			"  |"
		     << endl;
		header('x', '/');
		kalkulator_dasar();
		system("pause");
		system("cls");
		break;
	    case 2:
		while (true) {
		    system("cls");
		    header('+', '-');
		    cout << "|                    K4LKUL4T0R                   "
			    "      |"
			 << endl;
		    header('x', '/');
		    cout << "Masukan Angka: ";
		    cin >> angka_faktorial;
		    if (cin.fail() || angka_faktorial < 0) {
			cout << "[!] Error: Input harus berupa angka positif!"
			     << endl;
			cin.clear();
			system("pause");
			while (cin.get() != '\n');
		    } else {
			break;
		    }
		}
		cout << "Hasil Dari " << angka_faktorial
		     << "! adalah: " << faktorial(angka_faktorial) << endl;
		system("pause");
		system("cls");
		break;
	    case 0:
		cihuy = 0;
		system("pause");
		system("cls");
		break;
	    default:
		cout << "Input Tidak Valid!" << endl;
		system("pause");
		system("cls");
		break;
	}
    } while (cihuy != 0);
}
void aselole() {
    int menu;
    char daftar_barang[100][50];
    int stok_barang[100];
    int harga_barang[100];
    int jumlah_sekarang = 0;
    bool aseli = 1;
    while (true) {
	while (true) {
	    banner_awal();
	    cout << "1. Tivaiz Store" << endl;
	    cout << "2. Kalkulator" << endl;
	    cout << "0. Exit" << endl;
	    header();
	    cout << "Pilih Menu: ";
	    cin >> menu;
	    if (cin.fail()) {
			cout << "[!] Error: Input harus berupa angka!" << endl;
			cin.clear();
			system("pause");
			while (cin.get() != '\n');
			system("cls");
	    } 
		else {
			break;
	    }
	}
	system("cls");
	switch (menu) {
	    case 1:
		store_menu(daftar_barang, stok_barang, harga_barang,
			   jumlah_sekarang, aseli);
		break;
	    case 2:
		kalkulator_menu();
		break;
	    case 0:
		cout << "Goodbye,再见,Auf Wiedersehen,Adiós,Au revoir!Terima "
			"Kasih Sudah Menggunakan TIVAIZ STORE"
		     << endl;
		system("pause");
		system("cls");
		return;
	    default:
		cout << "Input Yang Benar Tolong" << endl;
		system("pause");
		system("cls");
	}
    }
}
#endif
