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
    std::cout << "                      .----." << std::endl;
    std::cout << "                     ( o  o )   <- pelanggan senang!" << std::endl;
    std::cout << "                      \\  ~ /" << std::endl;
    std::cout << "                 _____/____\\_____" << std::endl;
    std::cout << "                |  CORN DOG SHOP  |" << std::endl;
    std::cout << "                |_________________|" << std::endl;
    std::cout << "                      ||    ||" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "      ____  ___  ____  _  _    ____  ___  ___ " << std::endl;
    std::cout << "     / __)/ _ \\(  _ \\( \\( )  (  _ \\/ _ \\/ __)" << std::endl;
    std::cout << "    ( (__(  (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << "     \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "     >> Simulator Jualan Corn Dog Terbaik! <<" << std::endl;
}
void corndogSedih() {
    std::cout << "                      .----." << std::endl;
    std::cout << "                     ( > < )   <- pelanggan tidak senang!" << std::endl;
    std::cout << "                      \\  _ /" << std::endl;
    std::cout << "                 _____/____\\_____" << std::endl;
    std::cout << "                |  CORN DOG SHOP  |" << std::endl;
    std::cout << "                |_________________|" << std::endl;
    std::cout << "                     ||    ||" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "      ____  ___  ____  _  _    ____  ___  ___ " << std::endl;
    std::cout << "     / __)/ _ \\(  _ \\( \\( )  (  _ \\/ _ \\/ __)" << std::endl;
    std::cout << "    ( (__(  (_) ))   / )  (    )(_) )(_) ) (_ " << std::endl;
    std::cout << "     \\___)\\___ /(_)\\_)(_)\\_)  (____/ \\___/\\___)  " << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "     >> Simulator Jualan Corn Dog Terbaik! <<" << std::endl;
}
void banner1(const char nama[100]){
    int total_width = 28;
    int text_length = 0;
    for(int i = 0; nama[i] != '\0'; i++) {
        text_length++;
    }
    int left_padding = (total_width - text_length) / 2;
    int right_padding = total_width - text_length - left_padding;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "|";
    for(int i = 0; i < left_padding; i++) {
        std::cout << " ";
    }
    std::cout << nama;
    for(int i = 0; i < right_padding; i++) {
        std::cout << " ";
    }
    std::cout << "|" << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
}

void footer(){
    int total_width = 51;
    for(int i = 0; i < total_width; i++) {
        std::cout << "=";
    }
    std::cout <<std::endl;
}
struct Pesanan_Pelanggan{
    char patty_name[100];
    char sauce[100];
    char topping[100];
    int cash;
    
    Pesanan_Pelanggan(int init_cash){
        cash=init_cash;
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
	int hitung_total_item() {
		return 3 + 6 + 6;
	}
};
void randomize_pesanan(Pesanan_Pelanggan& pesanan, InventarisToko& toko) {
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
            std::cout<<"Pilihan Anda: ";
            std::cin>>pilihan1;
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
                CLS
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
            std::cout<<"Pilihan Anda: ";
            std::cin>>pilihan2;
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
            std::cout<<"Pilihan Anda: ";
            std::cin>>pilihan3;
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
        int pendapatan=0;
        const int profit_patty=2000,profit_st=200,base_pay=2000;
        if (patty || sauce ||topping){
            corndogSenang();
        }
        else{
            corndogSedih();
        }
        if(patty){
            pendapatan += harga_patty + profit_patty;
            std::cout <<"   Patty \t["<<patty_options[pilihan1-1]<<"] -> BENAR + Rp. "<<harga_patty + profit_patty<< std::endl;
        }
        else {
            std::cout <<"   Patty \t["<<patty_options[pilihan1-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        if(sauce){
            pendapatan += harga_sauce + profit_st;
            std::cout <<"   Sauce \t["<<sauce_options[pilihan2-1]<<"] -> BENAR + Rp. "<<harga_sauce + profit_st<< std::endl;
        }
        else {
            std::cout <<"   Sauce \t["<<sauce_options[pilihan2-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        if(topping){
            pendapatan += harga_topping + profit_st;
            std::cout <<"   Tambahan \t["<<topping_options[pilihan3-1]<<"] -> BENAR + Rp. "<<harga_topping + profit_st<< std::endl;
        }
        else {
            std::cout <<"   Tambahan ["<<topping_options[pilihan3-1]<<"] -> SALAH + Rp. 0 (bahan hangus)"<< std::endl;
        }
        footer();
        pesanan.cash += pendapatan+base_pay;
        std::cout << "   Base Pembayaran\t: Rp. " << base_pay << std::endl;
        std::cout << "   Total Perolehan\t: Rp. " << pendapatan << std::endl;
        std::cout << "   Uang Sekarang\t : Rp. " << pesanan.cash << std::endl;
        toko.daftar_patty[pilihan1-1].stok = patty_stock[pilihan1-1];
		toko.daftar_sauce[pilihan2-1].stok = sauce_stock[pilihan2-1];
		toko.daftar_topping[pilihan3-1].stok = topping_stock[pilihan3-1];
        std::cin.ignore(1000,'\n');
        std::cout<<"   Press Enter to Proceed ";
        std::cin.get();
        CLS;
    }
}


void mulai_berjualan(Pesanan_Pelanggan& pesanan, InventarisToko& toko) {
    CLS;
    static InventarisToko main_toko; 
    randomize_pesanan(pesanan, main_toko);
}
void restock_bahan(Pesanan_Pelanggan& pesanan, InventarisToko& toko) {
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
        std::cout << " ~ Roti (Stok: 92) | Rp.1000" << std::endl;
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
        std::cout << "Pilihan Anda: ";
        std::cin >> pilihan;

        if (pilihan == 0) {
            return;
        } 
        else if (pilihan == 1) {
            CLS;
            char menu_beli_text[100] = "MEMBELI BAHAN";
            pesanan.header1(menu_beli_text);
            std::cout << "\n\t[ Fitur Pembelian Bahan ]" << std::endl;
            std::cout << "\t Deadline Btw" << std::endl;
            std::cout << "\n  Press Enter to Continue... ";
            std::cin.ignore(1000, '\n');
            std::cin.get();
        } 
        else {
            std::cout << "Input Tidak Valid!" << std::endl;
            std::cin.ignore(1000, '\n');
            std::cin.get();
        }
    }
}
void menu_utama(Pesanan_Pelanggan& pesanan){
    static InventarisToko main_toko;
    while (true){
        CLS;
        tampilkanHeader();
        int pilihan;
        banner1("1. MULAI BERJUALAN");
        banner1("2. STOK BAHAN");
        banner1("3. TOTAL PENJUALAN");
        banner1("4. HISTORY PENJUALAN");
        banner1("0. KELUAR");
        footer();
        std::cout<<"Pilih Menu: ";
        std::cin>>pilihan;
        switch(pilihan){
            case 1:
                mulai_berjualan(pesanan,main_toko);
                break;
            case 2:
                restock_bahan(pesanan,main_toko);
                break;
            case 3:
                std::cout<<"Under Construct";
            break;
            case 0:
                std::cout<<"Under Contrusct";
                return;
            default:
                std::cout<<"Pilihan Tidak Valid";
            break;
        }
        std::cout<<std::endl;
    }
}
int main(){
    srand((unsigned)GetTickCount());
    enableANSI();
    Pesanan_Pelanggan pesanan(200000);
    menu_utama(pesanan);
}