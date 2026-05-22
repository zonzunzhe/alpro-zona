#include <iostream>
using namespace std; 
void register(char daftar_barang[100][50], int stok_barang[100],
		  int harga_barang[100], int& jumlah_sekarang) {
    cout << "|                    TIVAIZ STORE                       |" << endl;
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
    cout << "Sign In Berhasil" << endl;
    header2();
}
int main(){
    aselole();
}