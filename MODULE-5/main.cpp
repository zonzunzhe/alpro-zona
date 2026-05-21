#include <iostream>
#include <climits>
#include <windows.h>
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"
struct Pesanan_Pelanggan{
    char patty_name[100];
    char sauce[100];
    char topping[100];
};
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
    int total_width = 39;
    for(int i = 0; i < total_width; i++) {
        std::cout << "=";
    }
}
void randomize_pesanan(Pesanan_Pelanggan& pesanan) {
    const char patty_options[][50] = {
        "Sosis Sapi", 
        "Mozarela", 
        "Sosis Ayam"
    };
    const char sauce_options[][50] = { 
        "Manis Pedas",
        "Pedas Mayonaise",
        "Mayonaise",
        "Manis"
    };
    const char topping_options[][50] = { 
        "Coklat",
        "Tiramisu",
        "Choco Chrunchy",
        "Coklat"
    };
    
    int patty_count = 0;
    int sauce_count = 0;
    int topping_count = 0;
    int patty_index = rand() % patty_count;
    int sauce_index = rand() % sauce_count;
    int topping_index = rand() % topping_count;
    
    for(int i = 0; patty_options[patty_index][i] != '\0'; i++) {
        pesanan.patty_name[i] = patty_options[patty_index][i];
    }
    for(int i = 0; sauce_options[sauce_index][i] != '\0'; i++) {
        pesanan.sauce[i] = sauce_options[sauce_index][i];
    }
    for(int i = 0; topping_options[topping_index][i] != '\0'; i++) {
        pesanan.topping[i] = topping_options[topping_index][i];
    }
}
void mulai_berjualan(Pesanan_Pelanggan& pesanan){
    randomize_pesanan(pesanan);
}
int main(){
    srand((unsigned)GetTickCount());
    enableANSI();
    tampilkanHeader();
    banner1("1. MULAI BERJUALAN");
    banner1("2. STOK BAHAN");
    banner1("3. TOTAL PENJUALAN");
    banner1("4. HISTORY PENJUALAN");
    banner1("0. KELUAR");
    footer();
    std::cout<<std::endl;
}