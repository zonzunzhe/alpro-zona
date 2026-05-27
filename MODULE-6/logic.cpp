#include <iostream>
#include <cstdlib>
#include <climits>
#define CLS std::cout << "\033[2J\033[H" << std::flush;

enum tipe_data { TIPE_CHAR_PTR, TIPE_UINT, TIPE_DOUBLE };

struct entri_memori {
    tipe_data tipe;
    size_t ukuran;
    size_t offset;
    void* alamat_memori;
    bool is_deleted;
    char nilai_str[512];
    unsigned int nilai_uint;
    double nilai_double;
};

struct sister_core {
    const char* nama;
    size_t pool_size;
    size_t alignment;
    int special_gap;
    unsigned char* pool_start;
    size_t bump_pointer;
    entri_memori slots[128];
    size_t used_slots;
    size_t used_bytes;
};

int strlen(const char* str) {
    int len = 0;
    while (str[len] != '\0') len++;
    return len;
}

int isdigit(char c) {
    return (c >= '0' && c <= '9') ? 1 : 0;
}

bool nim_valid(const char* nim) {
    if (strlen(nim) != 11) return false;
    
    if (nim[0] != 'F' && nim[0] != 'f') return false;
    if (nim[1] != '1') return false;
    if (nim[2] != 'D' && nim[2] != 'd') return false;
    if (nim[3] != '0') return false;
    if (nim[4] != '2') return false;

    for (int i = 5; i < 11; i++) {
        if (!isdigit(nim[i])) return false;
    }
    return true;
}
int startup_menu() {
    CLS;
    std::cout << "========================================================\n";
    std::cout << "RESISTANSI SCHRYZA - PROTOKOL PEMULIHAN [TERMINAL: PHOENIX]\n";
    std::cout << "========================================================\n";
    std::cout << "Kamu adalah Memory Architect Schryza.\n";
    std::cout << "Patuhi para dewa dan sembuhkan sister.\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Menu\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "1 - Tampilkan memori Historia\n";
    std::cout << "2 - Tampilkan memori Mira\n";
    std::cout << "3 - Tampilkan memori Victoria\n";
    std::cout << "4 - Tambah memori ke sister\n";
    std::cout << "5 - Hapus memori berdasarkan indeks dari sister\n";
    std::cout << "6 - Cetak diagnostik pool sister\n";
    std::cout << "0 - Keluar\n";
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Pilih: ";
    int pilihan;
    if (!(std::cin >> pilihan)) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        return -1;
    }
    return pilihan;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout <<"Penggunaan: ./solution.exe <student_id>\nContoh: ./solution.exe F1D02410053\n";
        return 1;
    }
    if (argc > 2) {
        std::cout <<"Error: Terlalu banyak argumen.\n";
        return 1;
    }
    if (nim_valid(argv[1])) {
        std::cout << "NIM VALID: " << argv[1] << "\n";
    }
    else if (strlen(argv[1]) != 11){
        std::cout <<"Error:NIM harus tepat 11 karakter..\n";
        return 1;
    }
    else {
        std::cout << "Error: NIM harus diawali dengan F1D02 lalu diikuti angka setelahnya.\n";
        return 1;
    }
    int dig1 = argv[1][8] - '0';
    int dig2 = argv[1][9] - '0';
    int dig3 = argv[1][10] - '0';
    int nim_tiga_digit = (dig1 * 100) + (dig2 * 10) + dig3;
    int gap_historia = (dig3 % 2 != 0) ? 1 : 0;
    int gap_mira = (nim_tiga_digit * 7 % 23) + 12;
    int gap_victoria = (nim_tiga_digit * 11 % 53) + 14;

    sister_core historia;
    historia.nama = "Historia Koura";
    historia.pool_size = 1024;
    historia.alignment = 16;
    historia.special_gap = gap_historia;
    historia.bump_pointer = 0;
    historia.used_slots = 0;
    historia.used_bytes = 0;
    historia.pool_start = (unsigned char*)malloc(historia.pool_size);

    sister_core mira;
    mira.nama = "Mira Koura";
    mira.pool_size = 2048;
    mira.alignment = 8;
    mira.special_gap = gap_mira;
    mira.bump_pointer = 0;
    mira.used_slots = 0;
    mira.used_bytes = 0;
    mira.pool_start = (unsigned char*)malloc(mira.pool_size);

    sister_core victoria;
    victoria.nama = "Victoria Koura";
    victoria.pool_size = 4096;
    victoria.alignment = 4;
    victoria.special_gap = gap_victoria;
    victoria.bump_pointer = 0;
    victoria.used_slots = 0;
    victoria.used_bytes = 0;
    victoria.pool_start = (unsigned char*)malloc(victoria.pool_size);

    if (!historia.pool_start || !mira.pool_start || !victoria.pool_start) {
        std::cout << "Gagal mengalokasikan memori pool!\n";
        return 1;
    }
    startup_menu();
    int pilihan = -1;
    while (pilihan != 0) {
        pilihan = startup_menu();
        if (pilihan == -1 || pilihan > 6) {
            std::cout << "\nInput tidak valid! Tekan ENTER untuk mencoba lagi...";
            std::cin.get();
            std::cin.get();
            continue;
        }
        switch(pilihan) {
            case 1:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                break;
                //memori Historia
            case 2:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                break;
                //memori Mira
            case 3:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                break;
                //memori Victoria
            case 4:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                // Tambah data
                break;
            case 5:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                // Hapus data
                break;
            case 6:
                std::cout<<"Under Construct";
                std::cin.get();
                std::cin.get();
                // Diagnostik
                break;
            case 0:
                std::cout << "\nKeluar dari sistem Terminal Phoenix. Membebaskan memori...\n";
                break;
        }
    }

free(historia.pool_start);
free(mira.pool_start);
free(victoria.pool_start);
    return 0;
}