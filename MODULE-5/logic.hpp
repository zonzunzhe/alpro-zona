#ifndef LOGIC_HPP
#define LOGIC_HPP
#include <iostream>
#include <climits>
#include <windows.h>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
#define CLS     std::cout<<"\033[2J\033[H";

void enableANSI() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}
int input_angka(const char prompt[]) {
    int input_user;
    while (true) {
        std::cout << prompt;
        std::cin >> input_user;

        // Jika input salah tipe data (misal user input huruf/simbol)
        if (std::cin.fail()) {
            std::cin.clear(); // Reset status error cin
            std::cin.ignore(1000, '\n'); // Hapus huruf/karakter sampah di buffer
            std::cout << RED << "\t[!] Input harus berupa angka!" << RESET << std::endl;
            std::cin.get(); // Tahan layar sebentar
            continue; // Ulangi minta input
        }

        std::cin.ignore(1000, '\n'); // Bersihkan sisa enter di buffer
        return input_user; // Kembalikan angka yang benar
    }
}
void tampilkanHeader() {
    std::cout <<BLUE;
    std::cout << "      ____  ___  ____  _  _    ____  ___  ___ " << std::endl;
    std::cout << "     / __)/ _ \\(  _ \\( \\( )  (  _ \\/ _ \\/ __)" << std::endl;
    std::cout << "    ( (__(  (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << "     \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)" << std::endl;
    std::cout <<RED;
    std::cout << "              >> Corn Dog Simulator <<         " << std::endl;
    std::cout <<YELLOW;
    std::cout << "===================================================" << std::endl;
    std::cout <<RESET;
}
void corndogSenang() {
    std::cout<<RED;
    std::cout << "                      .----." << std::endl;
    std::cout << "                     ( o  o )   <- pelanggan senang!" << std::endl;
    std::cout << "                      \\  ~ /" << std::endl;
    std::cout<<GREEN;
    std::cout << "                 _____/____\\_____" << std::endl;
    std::cout << "                |  CORN DOG SHOP  |" << std::endl;
    std::cout << "                |_________________|" << std::endl;
    std::cout << "                      ||    ||" << std::endl;
    std::cout<<YELLOW;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout<<BLUE;
    std::cout << "      ____  ___  ____  _  _    ____  ___  ___ " << std::endl;
    std::cout << "     / __)/ _ \\(  _ \\( \\( )  (  _ \\/ _ \\/ __)" << std::endl;
    std::cout << "    ( (__(  (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << "     \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout<<YELLOW;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout<<RED;
    std::cout << "     >> Simulator Jualan Corn Dog Terbaik! <<" << std::endl;
    std::cout<<RESET;
}
void corndogSedih() {
    std::cout<<RED;
    std::cout << "                      .----." << std::endl;
    std::cout << "                     ( > < )   <- pelanggan tidak senang!" << std::endl;
    std::cout << "                      \\  _ /" << std::endl;
    std::cout<<GREEN;
    std::cout << "                 _____/____\\_____" << std::endl;
    std::cout << "                |  CORN DOG SHOP  |" << std::endl;
    std::cout << "                |_________________|" << std::endl;
    std::cout << "                     ||    ||" << std::endl;
    std::cout<<YELLOW;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout<<BLUE;
    std::cout << "      ____  ___  ____  _  _    ____  ___  ___ " << std::endl;
    std::cout << "     / __)/ _ \\(  _ \\( \\( )  (  _ \\/ _ \\/ __)" << std::endl;
    std::cout << "    ( (__(  (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << "     \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout<<YELLOW;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout<<RED;
    std::cout << "     >> Simulator Jualan Corn Dog Terbaik! <<" << std::endl;
    std::cout<<RESET;
}
void banner1(const char nama[100]){
    int total_width = 28;
    int text_length = 0;
    for(int i = 0; nama[i] != '\0'; i++) {
        text_length++;
    }
    int left_padding = (total_width - text_length) / 2;
    int right_padding = total_width - text_length - left_padding;

    std::cout << "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "         |";
    for(int i = 0; i < left_padding; i++) {
        std::cout << " ";
    }
    std::cout << nama;
    for(int i = 0; i < right_padding; i++) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void footer(){
    int total_width = 51;
    for(int i = 0; i < total_width; i++) {
        std::cout << "=";
    }
    std::cout <<std::endl;
}
void footer2(){
    int total_width = 51;
    for(int i = 0; i < total_width; i++) {
        std::cout << "-";
    }
    std::cout <<std::endl;
}
struct Pesanan_Pelanggan{
    char patty_name[100];
    char sauce[100];
    char topping[100];
    int cash_awal;
    int cash;
    
    Pesanan_Pelanggan(int init_cash){
        cash_awal=init_cash;
        cash=init_cash;
    }
    void header0(char text[100]){
        int total_width = 51;
        int text_length = 0;
        for(int i = 0; text[i] != '\0'; i++) {
            text_length++;
        }
        int left_padding = (total_width - text_length) / 2;
        int right_padding = total_width - text_length - left_padding;
        tampilkanHeader();
        footer();
        for(int i = 0; i < left_padding; i++) {
            std::cout << " ";
        }
        std::cout << text;
        for(int i = 0; i < right_padding; i++) {
            std::cout << " ";
        }
        std::cout << std::endl;
        footer();
        std::cout << std::endl;
    }
    void header1(char text[100]){
        int total_width = 51;
        int text_length = 0;
        for(int i = 0; text[i] != '\0'; i++) {
            text_length++;
        }
        int left_padding = (total_width - text_length) / 2;
        int right_padding = total_width - text_length - left_padding;
        int uang=cash;
        tampilkanHeader();
        std::cout<<"Uang: Rp. "<<uang<<std::endl;
        footer();
        for(int i = 0; i < left_padding; i++) {
            std::cout << " ";
        }
        std::cout << text;
        for(int i = 0; i < right_padding; i++) {
            std::cout << " ";
        }
        std::cout << std::endl;
    }
};
struct KomponenBahan {
	char nama[100];
	int harga;
	int stok;
	void ambil_nama(char dest[]) {
		int i = 0;
		for (i = 0; nama[i] != '\0'; i++) {
			dest[i] = nama[i];
		}
		dest[i] = '\0';
	}
	int ambil_harga() {
		return harga;
	}
};
struct InventarisToko {
	KomponenBahan daftar_patty[3] = {
		{"Sosis Sapi", 10000, 2},
		{"Mozarela", 13000, 2},
		{"Sosis Ayam", 7000, 2}
	};
	KomponenBahan daftar_sauce[6] = {
		{"Manis Pedas", 1000, 2},
		{"Pedas Mayonaise", 1000, 2},
		{"Mayonais", 1000, 2},
		{"Manis", 1000, 2},
		{"Pedas", 1000, 2},
		{"All Sauce", 1000, 2}
	};
	KomponenBahan daftar_topping[6] = {
		{"Tepung Roti", 1000, 2},
		{"Kentang", 3000, 2},
		{"Macha", 1000, 2},
		{"Tiramisu", 2000, 2},
		{"Choco Crunchy", 1000, 2},
		{"Coklat", 2000, 2}
	};
    int roti=2;
	int hitung_total_item() {
		return 3 + 6 + 6;
	}
};
struct HistoryPesanan {
    char patty[100];
    char sauce[100];
    char topping[100];
    bool sukses;
    int dana;
    void set_detail(const char pat[], const char saus[], const char top[], bool status, int uang) {
        int i = 0;
        for (i = 0; pat[i] != '\0'; i++) patty[i] = pat[i];
        patty[i] = '\0';
        for (i = 0; saus[i] != '\0'; i++) sauce[i] = saus[i];
        sauce[i] = '\0';
        for (i = 0; top[i] != '\0'; i++) topping[i] = top[i];
        topping[i] = '\0';
        sukses = status;
        dana = uang;
    }
};
struct RiwayatToko {
    HistoryPesanan list_h[100];
    int total_h = 0;
    void tambah_riwayat(const char pat[], const char saus[], const char top[], bool status, int uang) {
        if (total_h < 100) {
            list_h[total_h].set_detail(pat, saus, top, status, uang);
            total_h++;
        }
    }
    void ambil_data_karakter(int indeks, char pat_dest[], char saus_dest[], char top_dest[]) {
        int i = 0;
        for (i = 0; list_h[indeks].patty[i] != '\0'; i++) pat_dest[i] = list_h[indeks].patty[i];
        pat_dest[i] = '\0';

        for (i = 0; list_h[indeks].sauce[i] != '\0'; i++) saus_dest[i] = list_h[indeks].sauce[i];
        saus_dest[i] = '\0';

        for (i = 0; list_h[indeks].topping[i] != '\0'; i++) top_dest[i] = list_h[indeks].topping[i];
        top_dest[i] = '\0';
    }
};

void randomize_pesanan(Pesanan_Pelanggan &pesanan, InventarisToko &toko,int &jumlah_pelanggan,int &pendapatan,RiwayatToko &riwayat) {
    char patty_options[3][100];
	int patty_prices[3];
	int patty_stock[3];
	for (int i = 0; i < 3; i++) {
		toko.daftar_patty[i].ambil_nama(patty_options[i]);
		patty_prices[i] = toko.daftar_patty[i].ambil_harga();
		patty_stock[i] = toko.daftar_patty[i].stok;
	}
	char sauce_options[6][100];
	int sauce_prices[6];
	int sauce_stock[6];
	for (int i = 0; i < 6; i++) {
		toko.daftar_sauce[i].ambil_nama(sauce_options[i]);
		sauce_prices[i] = toko.daftar_sauce[i].ambil_harga();
		sauce_stock[i] = toko.daftar_sauce[i].stok;
	}

	char topping_options[6][100];
	int topping_prices[6];
	int topping_stock[6];
	for (int i = 0; i < 6; i++) {
		toko.daftar_topping[i].ambil_nama(topping_options[i]);
		topping_prices[i] = toko.daftar_topping[i].ambil_harga();
		topping_stock[i] = toko.daftar_topping[i].stok;
	}
    while (true){
        if (toko.roti <= 0) {
            CLS;
            std::cout << RED << "\t[!] Stok Roti Habis! [Minimal 2 Roti]" << RESET << std::endl;
            std::cout << "Press Any Key to Return to Menu Utama" << std::endl;
            std::cin.ignore(1000, '\n');
            std::cin.get();
            return; // Keluar kembali ke menu utama
        }
        int patty_count = 3;
        int sauce_count = 6;
        int topping_count = 6;
        int patty_index = rand() % patty_count;
        int sauce_index = rand() % sauce_count;
        int topping_index = rand() % topping_count;
        
        int end_array = 0;
        for(end_array = 0; patty_options[patty_index][end_array] != '\0'; end_array++) {
            pesanan.patty_name[end_array] = patty_options[patty_index][end_array];
        }
        pesanan.patty_name[end_array] = '\0';
        
        for(end_array = 0; sauce_options[sauce_index][end_array] != '\0'; end_array++) {
            pesanan.sauce[end_array] = sauce_options[sauce_index][end_array];
        }
        pesanan.sauce[end_array] = '\0';
        
        for(end_array = 0; topping_options[topping_index][end_array] != '\0'; end_array++) {
            pesanan.topping[end_array] = topping_options[topping_index][end_array];
        }
        pesanan.topping[end_array] = '\0';
    
        bool patty=true;
        bool sauce=true;
        bool topping=true;
        int harga_patty = 0;
        int harga_sauce = 0;
        int harga_topping = 0;
        int pilihan1;
        int pilihan2;
        int pilihan3;
        char text[100]="PESANAN PELANGGAN";
        while(true){
            pesanan.header1(text);
            std::cout<<"\n  Patty\t   : "<<pesanan.patty_name << std::endl;
            std::cout<<"  Saus\t   : "<<pesanan.sauce << std::endl;
            std::cout<<"  Tambahan : "<<pesanan.topping << std::endl;
            footer();
            std::cout<<"  TUGAS [1/3] Pilih Patty"<< std::endl;
            for (int i = 0;i<3;i++){
                std::cout<<"  "<<i+1<<". "<<patty_options[i]<<" (Stok: "<<patty_stock[i]<<")"<<std::endl;
            }
            std::cout<<"  0. Batalkan & Kembali Ke Menu Utama"<<std::endl;
            footer();
            pilihan1 = input_angka("Pilihan Anda: ");
            if (pilihan1 >=0 && pilihan1 < 4){
                if(pilihan1 == 0) return;
                if(patty_stock[pilihan1-1] <= 0){
                    CLS;
                    std::cout<<RED<<"\t[!] Stok "<<patty_options[pilihan1-1]<<" Tidak Cukup"<<RESET<<std::endl<<"\tSilahkan Beli Di Toko Sembako"<<std::endl;
                    std::cout<<"Press Any Key to Proceed"<<std::endl;
                    std::cin.ignore(1000,'\n');
                    std::cin.get();
                    return;
                }
                harga_patty = patty_prices[pilihan1 - 1];
                patty_stock[pilihan1-1]--;
                if ((pilihan1-1) != patty_index){
                    patty=false;
                }
                break;
            }
            else{
                std::cout<<"Input Tidak Valid [0-3]"<<std::endl;
                std::cin.ignore(1000,'\n');
            }
        }
        while(true){
            CLS
            pesanan.header1(text);
            std::cout<<"\n  Patty\t   : "<<pesanan.patty_name << std::endl;
            std::cout<<"  Saus\t   : "<<pesanan.sauce << std::endl;
            std::cout<<"  Tambahan : "<<pesanan.topping << std::endl;
            footer();
            std::cout<<"  TUGAS [2/3] Pilih Saus"<< std::endl;
            for (int i = 0;i<6;i++){
                std::cout<<"  "<<i+1<<". "<<sauce_options[i]<<" (Stok: "<<sauce_stock[i]<<")"<<std::endl;
            }
            std::cout<<"  0. Batalkan & Kembali Ke Menu Utama"<<std::endl;
            footer();
            pilihan2 = input_angka("Pilihan Anda: ");
            if (pilihan2 >= 0 && pilihan2 < 7 ){
                if(pilihan2 == 0) return;
                if(sauce_stock[pilihan2-1] <= 0){
                    CLS;
                    std::cout<<RED<<"\t[!] Stok "<<sauce_options[pilihan2-1]<<" Tidak Cukup"<<RESET<<std::endl<<"\tSilahkan Beli Di Toko Sembako"<<std::endl;
                    std::cout<<"Press Any Key to Proceed"<<std::endl;
                    std::cin.ignore(1000,'\n');
                    std::cin.get();
                    return;
                }                
                harga_sauce = sauce_prices[pilihan2 - 1];
                sauce_stock[pilihan2-1]--;
                if ((pilihan2-1) != sauce_index){
                    sauce=false;
                }
                CLS;
                break;
            }
            else{
                std::cout<<"Input Tidak Valid [0-6]"<<std::endl;
                std::cin.ignore(1000,'\n');
            }
        }
        while(true){
            CLS;
            pesanan.header1(text);
            std::cout<<"\n  Patty\t   : "<<pesanan.patty_name << std::endl;
            std::cout<<"  Saus\t   : "<<pesanan.sauce << std::endl;
            std::cout<<"  Tambahan : "<<pesanan.topping << std::endl;
            footer();
            std::cout<<"  TUGAS [3/3] Pilih Tambahan"<< std::endl;
            for (int i = 0;i<6;i++){
                std::cout<<"  "<<i+1<<". "<<topping_options[i]<<" (Stok: "<<topping_stock[i]<<")"<<std::endl;
            }
            std::cout<<"  0. Batalkan & Kembali Ke Menu Utama"<<std::endl;
            footer();
            pilihan3 = input_angka("Pilihan Anda: ");
            if (pilihan3 >=0 && pilihan3 < 7 ){
                if(pilihan3 == 0) return;
                if(topping_stock[pilihan3-1] <= 0){
                    CLS;
                    std::cout<<RED<<"\t[!] Stok "<<topping_options[pilihan3-1]<<" Tidak Cukup"<<RESET<<std::endl<<"\tSilahkan Beli Di Toko Sembako"<<std::endl;
                    std::cout<<"Press Any Key to Proceed"<<std::endl;
                    std::cin.ignore(1000,'\n');
                    std::cin.get();
                    return;
                }
                harga_topping = topping_prices[pilihan3 - 1];
                topping_stock[pilihan3-1]--;
                if ((pilihan3-1) != topping_index){
                    topping=false;
                }
                CLS;
                break;
            }
            else{
                std::cout<<"Input Tidak Valid [0-6]"<<std::endl;
                std::cin.ignore(1000,'\n');
            }
        }
        int perolehan_sekarang = 0;

        const int profit_patty=2000,profit_st=200,base_pay=2000;
        if (patty || sauce ||topping){
            corndogSenang();
        }
        else{
            corndogSedih();
        }
        jumlah_pelanggan ++;
        if(patty){
            perolehan_sekarang += harga_patty + profit_patty;
            std::cout <<"   Patty \t["<<patty_options[pilihan1-1]<<"] -> BENAR + Rp. "<<harga_patty + profit_patty<< std::endl;
        }
        else {
            std::cout <<"   Patty \t["<<patty_options[pilihan1-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        if(sauce){
            perolehan_sekarang += harga_sauce + profit_st;
            std::cout <<"   Sauce \t["<<sauce_options[pilihan2-1]<<"] -> BENAR + Rp. "<<harga_sauce + profit_st<< std::endl;
        }
        else {
            std::cout <<"   Sauce \t["<<sauce_options[pilihan2-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        if(topping){
            perolehan_sekarang += harga_topping + profit_st;
            std::cout <<"   Tambahan \t["<<topping_options[pilihan3-1]<<"] -> BENAR + Rp. "<<harga_topping + profit_st<< std::endl;
        }
        else {
            std::cout <<"   Tambahan ["<<topping_options[pilihan3-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        footer();
        perolehan_sekarang += base_pay;
        pendapatan += perolehan_sekarang;
        pesanan.cash += pendapatan;
        std::cout << "   Base Pembayaran\t: Rp. " << base_pay << std::endl;
        std::cout << "   Total Perolehan\t: Rp. " << pendapatan << std::endl;
        std::cout << "   Uang Sekarang\t : Rp. " << pesanan.cash << std::endl;
        toko.daftar_patty[pilihan1-1].stok = patty_stock[pilihan1-1];
        toko.daftar_sauce[pilihan2-1].stok = sauce_stock[pilihan2-1];
        toko.daftar_topping[pilihan3-1].stok = topping_stock[pilihan3-1];
        toko.roti -= 2;
        bool status_sukses = (patty || sauce || topping);
        int total_dana = pendapatan + base_pay;
        riwayat.tambah_riwayat(patty_options[pilihan1 - 1], sauce_options[pilihan2 - 1], topping_options[pilihan3 - 1], status_sukses, perolehan_sekarang);
        std::cin.ignore(1000,'\n');
        std::cout<<"\nPress Enter to Proceed ";
        std::cin.get();
        CLS;
    }
}
void restock_bahan(Pesanan_Pelanggan& pesanan, InventarisToko& toko,int &pengeluaran) {
    while (true) {
        CLS;
        char text[100] = "STOK BAHAN";
        pesanan.header1(text);
        std::cout << "\t\t-- Bahan Wajib --" << std::endl;
        for (int i = 0; i < 3; i++) {
            std::cout << " ~ " << toko.daftar_patty[i].nama 
                      << " (Stok: " << toko.daftar_patty[i].stok 
                      << ") | Rp." << toko.daftar_patty[i].harga << std::endl;
        }
        std::cout << " ~ Roti (Stok: " << toko.roti << ") | Rp.1000" << std::endl;
        std::cout << std::endl;

        std::cout << "\t\t  -- Saus --" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << " ~ " << toko.daftar_sauce[i].nama 
                      << " (Stok: " << toko.daftar_sauce[i].stok 
                      << ") | Rp." << toko.daftar_sauce[i].harga << std::endl;
        }
        std::cout << std::endl;

        std::cout << "\t\t-- Bahan Tambahan --" << std::endl;
        for (int i = 0; i < 6; i++) {
            std::cout << " ~ " << toko.daftar_topping[i].nama 
                      << " (Stok: " << toko.daftar_topping[i].stok 
                      << ") | Rp." << toko.daftar_topping[i].harga << std::endl;
        }

        footer();
        std::cout << "  1. Membeli Bahan" << std::endl;
        std::cout << "  0. Kembali ke Menu Utama" << std::endl;
        footer();

        int pilihan;
        pilihan = input_angka("Pilihan Anda: ");

        if (pilihan == 0) {
            return;
        } 
        else if (pilihan == 1) {
            while (true) {
                CLS;
                char menu_beli_text[100] = "PILIH KATEGORI BAHAN";
                pesanan.header1(menu_beli_text);
                
                std::cout << "  1. Bahan Wajib (Patty)" << std::endl;
                std::cout << "  2. Saus" << std::endl;
                std::cout << "  3. Bahan Tambahan" << std::endl;
                std::cout << "  0. Kembali" << std::endl;
                footer();
                
                int kat_pilihan;
                kat_pilihan = input_angka("Pilihan Anda: ");
                
                if (kat_pilihan == 0) break; // Kembali ke display stok utama
                
                int kuantitas = 0;
                int total_biaya = 0;
                if (kat_pilihan == 1) {
                    CLS;
                    char beli_patty_text[100] = "BELI BAHAN WAJIB (PATTY)";
                    pesanan.header1(beli_patty_text);
                    
                    for (int i = 0; i < 3; i++) {
                        std::cout << "  " << i + 1 << ". " << toko.daftar_patty[i].nama 
                                  << " (Stok: " << toko.daftar_patty[i].stok 
                                  << " | Harga: Rp." << toko.daftar_patty[i].harga << "/pcs)" << std::endl;
                    }
                    std::cout << "  4. Roti (Stok: " << toko.roti << " | Harga: Rp.1000/pcs)" << std::endl;
                    std::cout << "  0. Kembali" << std::endl;
                    footer();
                    int item_pilihan;
                    item_pilihan = input_angka("Pilihan Anda: ");
                    if (item_pilihan == 0) continue;
                    if (item_pilihan >= 1 && item_pilihan <= 4) {
                        // Ganti std::cin >> kuantitas; dengan ini:
                        kuantitas = input_angka("Masukkan Kuantitas Barang Yang Ingin Dibeli: ");
                        if (kuantitas <= 0) {
                            std::cout << RED << "\t[!] Kuantitas tidak valid!" << RESET << std::endl;
                            std::cin.ignore(1000, '\n'); std::cin.get();
                            continue;
                        }
                        if (item_pilihan == 4) {
                            total_biaya = 1000 * kuantitas;
                        } else {
                            total_biaya = toko.daftar_patty[item_pilihan - 1].harga * kuantitas;
                        }
                        if (pesanan.cash >= total_biaya) {
                            pesanan.cash -= total_biaya;
                            if (item_pilihan == 4) {
                                toko.roti += kuantitas;
                                std::cout << GREEN << "\n\t[+] Berhasil membeli " << kuantitas << " Roti!" << RESET << std::endl;
                            } else {
                                toko.daftar_patty[item_pilihan - 1].stok += kuantitas;
                                std::cout << GREEN << "\n\t[+] Berhasil membeli " << kuantitas << " " << toko.daftar_patty[item_pilihan - 1].nama << "!" << RESET << std::endl;
                            }

                            pengeluaran+=total_biaya;
                        } else {
                            std::cout << RED << "\n\t[!] Uang Tidak Cukup! Total Biaya: Rp." << total_biaya << RESET << std::endl;
                        }
                        std::cin.ignore(1000, '\n'); std::cin.get();
                    }
                } 
                else if (kat_pilihan == 2) {
                    CLS;
                    char beli_sauce_text[100] = "BELI SAUS";
                    pesanan.header1(beli_sauce_text);
                    for (int i = 0; i < 6; i++) {
                        std::cout << "  " << i + 1 << ". " << toko.daftar_sauce[i].nama 
                        << " (Stok: " << toko.daftar_sauce[i].stok 
                        << " | Harga: Rp." << toko.daftar_sauce[i].harga << "/pcs)" << std::endl;
                    }
                    std::cout << "  0. Kembali" << std::endl;
                    footer();
                    
                    int item_pilihan;
                    item_pilihan = input_angka("Pilihan Anda: ");
                    if (item_pilihan == 0) continue;
                    if (item_pilihan >= 1 && item_pilihan <= 6) {
                        kuantitas = input_angka("Masukkan Kuantitas Barang Yang Ingin Dibeli: ");
                        if (kuantitas <= 0) {
                            std::cout << RED << "\t[!] Kuantitas tidak valid!" << RESET << std::endl;
                            std::cin.ignore(1000, '\n'); std::cin.get();
                            continue;
                        }
                        total_biaya = toko.daftar_sauce[item_pilihan - 1].harga * kuantitas;
                        if (pesanan.cash >= total_biaya) {
                            pesanan.cash -= total_biaya;
                            toko.daftar_sauce[item_pilihan - 1].stok += kuantitas;
                            std::cout << GREEN << "\n\t[+] Berhasil membeli " << kuantitas << " " << toko.daftar_sauce[item_pilihan - 1].nama << "!" << RESET << std::endl;
                            pengeluaran+=total_biaya;
                        } else {
                            std::cout << RED << "\n\t[!] Uang Tidak Cukup! Total Biaya: Rp." << total_biaya << RESET << std::endl;
                        }
                        std::cin.ignore(1000, '\n'); std::cin.get();
                    }
                } 
                else if (kat_pilihan == 3) {
                    CLS;
                    char beli_topping_text[100] = "BELI BAHAN TAMBAHAN";
                    pesanan.header1(beli_topping_text);
                    for (int i = 0; i < 6; i++) {
                        std::cout << "  " << i + 1 << ". " << toko.daftar_topping[i].nama 
                        << " (Stok: " << toko.daftar_topping[i].stok 
                        << " | Harga: Rp." << toko.daftar_topping[i].harga << "/pcs)" << std::endl;
                    }
                    std::cout << "  0. Kembali" << std::endl;
                    footer();
                    int item_pilihan;
                    item_pilihan = input_angka("Pilihan Anda: ");
                    if (item_pilihan == 0) continue;
                    if (item_pilihan >= 1 && item_pilihan <= 6) {
                        kuantitas = input_angka("Masukkan Kuantitas Barang Yang Ingin Dibeli: ");
                        if (kuantitas <= 0) {
                            std::cout << RED << "\t[!] Kuantitas tidak valid!" << RESET << std::endl;
                            std::cin.ignore(1000, '\n'); std::cin.get();
                            continue;
                        }

                        total_biaya = toko.daftar_topping[item_pilihan - 1].harga * kuantitas;
                        
                        if (pesanan.cash >= total_biaya) {
                            pesanan.cash -= total_biaya;
                            toko.daftar_topping[item_pilihan - 1].stok += kuantitas;
                            std::cout << GREEN << "\n\t[+] Berhasil membeli " << kuantitas << " " << toko.daftar_topping[item_pilihan - 1].nama << "!" << RESET << std::endl;
                            pengeluaran+=total_biaya;
                        } else {
                            std::cout << RED << "\n\t[!] Uang Tidak Cukup! Total Biaya: Rp." << total_biaya << RESET << std::endl;
                        }
                        std::cin.ignore(1000, '\n'); std::cin.get();
                    }
                } 
                else {
                    std::cout << "Kategori Tidak Valid!" << std::endl;
                    std::cin.ignore(1000, '\n');
                }
            }
        } 
        else {
            std::cout << "Input Tidak Valid!" << std::endl;
            std::cin.ignore(1000, '\n');
            continue;
        }
    }
}
void mulai_berjualan(Pesanan_Pelanggan& pesanan, InventarisToko& toko, int &jumlah_pelanggan, int &pendapatan, RiwayatToko &riwayat) {
    CLS;
    randomize_pesanan(pesanan, toko, jumlah_pelanggan, pendapatan, riwayat);
}
void total_penjualan(Pesanan_Pelanggan& pesanan, InventarisToko& toko,int &pengeluaran,int &jumlah_pelanggan,int &pendapatan){
    CLS;
    char text[100] = "LAPORAN KEUANGAN & PENJUALAN";
    pesanan.header0(text);
    std::cout<<"  Modal Awal\t\t: Rp."<<pesanan.cash_awal<<std::endl;
    std::cout<<"  Total Pengeluaran\t: Rp."<<pengeluaran<<std::endl;
    std::cout<<"  Total Pendapatan\t: Rp."<<pendapatan<<std::endl;
    footer2();
    std::cout<<"  Uang Saat Ini\t\t: Rp."<<pesanan.cash<<std::endl;
    std::cout<<"  Untung Bersih\t\t: Rp."<<pendapatan-pengeluaran<<std::endl;
    std::cout<<"  Pelanggan Dilayani\t: "<<jumlah_pelanggan<<std::endl;
    std::cin.ignore(1000,'\n');
    std::cout<<"Press Enter to Proceed ";
    std::cin.get();
}
void history(Pesanan_Pelanggan& pesanan, InventarisToko& tokochar, RiwayatToko& riwayat, char recordp[100], char records[100], char recordt[100]){
    CLS;
    char text[100] = "HISTORY PENJUALAN";
    pesanan.header0(text);
    
    if (riwayat.total_h == 0) {
        std::cout << "\n  [!] Belum ada riwayat penjualan saat ini.\n" << std::endl;
        footer2();
    } else {
        for (int i = 0; i < riwayat.total_h; i++) {
            riwayat.ambil_data_karakter(i, recordp, records, recordt);
            
            std::cout << "  Pembeli #" << i + 1 << std::endl;
            std::cout << "    Patty   : " << recordp << std::endl;
            std::cout << "    Saus    : " << records << std::endl;
            std::cout << "    Topping : " << recordt << std::endl;
            std::cout << "    Hasil   : ";
            
            if (riwayat.list_h[i].sukses) {
                std::cout << "Berhasil";
            } else {
                std::cout << "Gagal   ";
            }
            
            std::cout << "  |  Perolehan: Rp." << riwayat.list_h[i].dana << std::endl;
            footer2();
        }
    }
    
    std::cout << "Press Enter to Proceed ";
    std::cin.ignore(1000, '\n');
    std::cin.get();
}
void menu_utama(Pesanan_Pelanggan& pesanan){
    srand((unsigned)GetTickCount());
    enableANSI();
    static InventarisToko main_toko;
    static RiwayatToko database_riwayat;
    int pengeluaran=0;
    int jumlah_pelanggan=0;
    int pendapatan=0;
    char recordp[100],records[100],recordt[100];
    while (true){
        CLS;
        tampilkanHeader();
        int pilihan;
        banner1("1. MULAI BERJUALAN");
        banner1("2. STOK BAHAN");
        banner1("3. TOTAL PENJUALAN");
        banner1("4. HISTORI PENJUALAN");
        banner1("0. KELUAR");
        footer();
        pilihan = input_angka("Pilih Menu: ");
        switch(pilihan){
            case 1:
                mulai_berjualan(pesanan, main_toko, jumlah_pelanggan, pendapatan, database_riwayat);
                break;
            case 2:
                restock_bahan(pesanan, main_toko, pengeluaran);
                break;
            case 3:
                total_penjualan(pesanan, main_toko, pengeluaran, jumlah_pelanggan, pendapatan);
                break;
            case 4:
                history(pesanan, main_toko, database_riwayat, recordp, records, recordt);
                break;
            case 0:
                CLS
                std::cout << R"gambar_corndog(+++++*******####%%=#%%%%%+=-+#%%%#%#=******##%%#-==*#%%+------------*%%%%###****++=:::::::::::--::::::::::::::::::::----+=--::::::::::::::::::::::::::::::::::
+++++++++++***#*%%=*##%%%%%%%#===+%#=##****##%%#==+#%%%*------===-+%%%%%#****+==--:::::::::::::::::::::::::::::::::::---=+=--:::::::::::::::::::::::::::::::::
++++++++++++++**#%=*****####%%%%%%#+=+*%%%%##%%*===#%%%*========+%%%%%%##*+=-::::::::::::::::::::::::::::::::::::::::::--=+---::::::::::::::::::::::::::::::::
++++++++++++++++#%=+*******#####%%%#+%%#+=*#%%%#=+=#%%%#=======#%%%%%%*=-::::::::::::-:--::---------:::::::::::::::::::---==--::::::::::::::::::::::::::::::::
++++++++++++++++#%=++++++++**#**#%%#+%%%%%%%*+*++++#%%%#=+=+++%%%%%*-:::::::::::---======---=======--:::::---:::::::::::--==---:::::::::::::::::::::::::::::::
##***+**++++++++#%=++++++++++****%%#=###%%%%%%%*==+#%%%#=+++*%%#+--::::::------:-===++++++++==++====----:-=+-:::::::::::---=---:::::::::::::::::::::::::::::::
--+*%%%%#**+++++%#=+++++++++++***#%#+*#####%%%%#=++#%%%#++*%%-::--------===++++++++*************+--===---=++--::::::::::::-==---::::::::::::::::::::::::::::::
%%%%*+===*%%%%#*%#=++++++++++++++*%#=**#####%%%#+++#%%%#+*%=:--------:-:=#**#####**#######%**%%%+-----:--=++=:::::::::::::-=-----:::::::::::::::::::::::::::::
**##%%%%%%*+==*#%*=***+++++++++++*%#=+****###%%#+++#%%%#+#%----===--::-:=%%%#%%%#####%%%%%%#-**=-:::::-:--==---::::::::::::=+-----::::::::::::::::::::::::::::
******###%%%%%%#*==+*%%%##*******#%#=+*****###%#+++#%%%#+#%:::-++=+--::-%%%=%%%%-=%%**%*=%%*:-:::::::::---==---::::::::::::=+=-----:::::::::::::::::::::::::::
**********#*###%%**%%*+=++##%%####%#=+*****###%#+++#%%%#+*#-::-+%%%*=--+%%%+*%%#-=%%+-%%=-----------:::--=====-::::::::::::=*=------::::::::::::::::::::::::::
*************###%*+###%%%%%#+=+#%%%#+****#*##%%#+++%%%%#++#=:::-%%%%%%%%=##+--=-:--=:-+#-*%%%+--:-=-:-::-=====-::::::::::::=++------::::::::::::::::::::::::::
**************##%*+#######%%%%%%#*==+#%%%%%%%%%#+++#%%%#++*#:-::=%#*%%%%%*%%%%%=-----:-=%%%#*-::::-=--::-=====--:::::::::::====------:::::::::::::::::::::::::
###############%%**#########%%%%%%%#*%#+=*#%%%%#+++%%%%#+++*+-::-%%%%%%%#%%%%%%-::-:==-+%%%#=-:--=#=--::-=====--::::::::::---==---------::::::::::::::::::::::
###############%%**##############%%**%%%%%%%#**++++#%%%#++++*=::-%%%%%%%#%%%%*=-:::-**++%%%%*=+*#%*---::--===----::::::::::---=-------:-::::::::::::::::::::::
#########%#####%%*################%*+####%%%%%%#+++#%%%#+++++*--:=%%%%%%%%%%%%===-=*%+*+=%%%%#*+===------==------::::::::::::-----------::::::::::::::::::::::
%%%%%%%%%%%%%%%%%#################%*+*#####%%%%#+++#%%%#+++++*+:::-#%%%%%%%%%%%*+******+==#%%#*++=-------======-::::::::::::::-=---------:::::::::::::::::::::
--=+*%%%%%%%%%%%%*#%%#######**#**#%*+**#####%%%#+++#%%%*++++++*=:::-%%%%%%%%%%%%##%%##***+=+++++==-----========-:::::::::::::::-----------::::::::::::::::::::
---------==*#%%%%#%%%%%%%%%###***#%*+***####%%%#+*+#%%%*++++++++=:::%%%#%%%%%=------:------=+**####**+++=======--:::::::::::::::-------------:::::::::::::::::
=-----------------*#%%%%%%%%%%%###%*+***####%%%#+**%%%%*+++++++++-::%%%%%%%%*=--:::-:--==---==+*****++++======---::::::::::::::::-=-------------::::::::::::::
:::-=------------------==*%%%%%%%%%**###%%%%%%%#+**%%%%*++++++++++-:-#%%%%%%%%%%%%%%%%%%%#*++==+++++++======----:::::::::::::::::-==------------::::::::::::::
:::::-------------------------==++*+#%%%%%%%%%%#++*%%%%*+++++++++*+-::+%%%%%%%%%%%%%%%%%%#*+==-----------==-----:::::::::::::::::-==---------------:::::::::::
----:::::::::::-----------------=====+*#%%%%%%%#***%%%%#++++++++++++-:=%%%%%%%%%%%%%#####=-+***=----------=------:::::::::::::::::-==-----------------:::::::::
::-----:::::::::::-----------------=========+*#*+**%%%%#++++++++++*%#--+*==*%%%%%*===%%%%=-+#*+=-::----------::::::::::::::::::::-===-----------------::::::::
:::::---::::::::::::----------------========++==+==+**#+++++++++++%%*----:--#%#+==+*#%%%%+=#%%#+-:---------::::::::::::::::::::::-=====-=----------------:::::
:::::-::-::::::::::::-:-------------------==---======++===+++++++%%+---::==*%#+=+*#%%%%%*=-----------::::::::::::::::::::::::::::--==========----------------:
::::::::-::::::::--::----------------------------===========++==#%#=-:::::-======+*##%##*+==-====-----::::::::::::::::::::::::::::-==========-----------------
:::::::==::::::::---==+==----------------------------=========+*%%+--::::-::----====+*****+======-----::::::::::::::::::::::::::::-==========-----------------
::::::-=:::::--+##+------------------------------------======+%%#=-:::::::::::::-----+++++==---==---::::::::::::::::::::::::::::::-========-----------------::
::::::=-:::::-----------------===----------------------=====+%%+==--:::::::::::::::--=------::::::::::::::::::::::::::::::::::::::------------------------::::
:::::--::::::::---:::::::::::--------------------------====+%#+++##*++==-:::::::::::--=----:::::::::::::::::::::::::::::::::::::::--------------------------::
:::--=-::::::::::::::::::::::::::::--------------------====**=*##+=+**=-------::--#%%%%%%%%%#*=::::::::::::::::::::::::::::::::::-----------------------------
:::---:::::::::::::::::::::::::::::::::::---------------===+#**+=+==+-----++--*%%%%%%%##++===--::::::::::::::::::::::::::::::::::----------------------::-----
:::::::::::::::::::::::::::::::::::::::::::::------------===*#+-+-+=------=-%%%%%*%%#+++----::::::::::::::::::::::::::::::::::::::--------------===+#%%%%%%%%%
:::::::::::::::::::::::::::::::::::::::::::::--------------=++-::--::::---:*%%%#%%+-=**--::::::::::::::::::::::::::::::::::::::::::::--=*%%%%%%%%%%%%%%%%%%%%%
:::::::::::::::::::::::::::::::::::::::::::::::-----------=*=::::::::::::-:-#%%%#--+*=:-::::::::::::::::::::::::::::::::::::::::::::=%%%%%%%%%%%%%#####*******
::::::::-++--::::::::::::::::::::::::::::::::::::--------=*-:-:::::::::::::::+%%+-++-:::-::::-::::::::::::::::::::::::::::::::::::::-**+=--==+===========++++=
:::::::::::::::::::::::::::::::::::::::::::::::::--------=+-::::::::::::::::::-%#==--::::::::-:::::::::::::::::::::::::::::::::::::::-----=========-----------
:::::::::::::::::::::::::::::::::::::::::::::::::::------+=:::::::::::::::::::-:----:::::::::-::::::::::::::::::::::::::::::::::::::::------------------------
:::::::::::::::::::::::::::::::::::::::::::::::::---:::-=+-::::::::::::::::::::::::::::::::::-:::::::::::::::::::::::::::::::::::::::-------------------------
::::::::::::::::::::::::::::::::::::::::::::-=*#%%%%%%%%%=-:::::::::::::::::::-::::::::::::::::::::::::::::::::::::::::------------------------
====-----::::::::::::::::::::::::::::::::::-%%%%%%%%%%%%#=-:::::::::--::::::::::::::::::::::---------------------:::::::::::::::::::--------------------------
:::::::::::::::::::::::::::::::::::::::::::+%%%%###*****+-:::::::::-==--:::::::::::::-::::-:---------------------:::::::::::::::::::--------------------------
::::::::::::::::::::::::::::::::::::::::::-#%#******+*++=-:::::::::-===----:::::::::--::-----=-----------=======-::::::::::::::::::---------------------------
::::::::::::::::::::::::::::::::::::::::::+#*+++++++++++=::::::::::====----------------------=---------=========--::::::::::::::::-----=======----------------
:::::::::::::::::::::::::::::::::::::::::-*+++++++++++++-:::::::::-====------------------------------============::::::::::::::::---==============------------
:::::::::::::::::::::::::::::::::::::::::=+==========++=-:::::::::-====-----------------------=---===============-:::::::::::::::--===+++++========-----------
::::::::::::::::::::::::::::::::::::::::-=--==========+=::::::::::-====---------------------=============++++++++--:::::::::::::--==++++++++++======----------
::::::::::::::::::::::::::::::::::::::::-------=======+=*+=--::::-=====---------------------===========+++++++++*+-:--=--::::::---++*******+++++======--------
::::::::::::::::::::::::::::::::::::::::::------=======*%%*---::-======--------------------==========++++++++*****=*%##+=-------==+*********++++++=====-------
:::::::::::::::::::::::::::::::::::::::::::::-----=====*%%+-----=======---------------------=========+++++++*******%%%#+=---=*+==+**######*****++++======-----
::::::::::::::::::::::::::::::::::::::::::::::::---+%%%%%#+-----=------------::::---------------======+++++*******#%%%#*=---***+***########*****++++=====-----)gambar_corndog" << std::endl;
                std::cout<<"Dadah";
                return;
            default:
                std::cout<<"Pilihan Tidak Valid";
                std::cin.ignore(1000,'\n');
                break;
        }
        std::cout<<std::endl;
    }
}
#endif