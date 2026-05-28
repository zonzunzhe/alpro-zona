#include <iostream>
#include <cstdlib>
#include <climits>
#define CLS std::cout << "\033[2J\033[H" << std::flush;

enum tipe_data { TIPE_CHAR_PTR, TIPE_UINT, TIPE_DOUBLE };

struct Entri_Memori {
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
    Entri_Memori slots[128];
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

void manual_strcpy(char* tujuan, const char* sumber) {
    int i = 0;
    while (sumber[i] != '\0') {
        tujuan[i] = sumber[i];
        i++;
    }
    tujuan[i] = '\0';
}

void tambah_memori_sister(sister_core& sister, int tipe_pilihan) {
    CLS;
    if (sister.used_slots >= 128) {
        std::cout << "Kelebihan entri (Overflow)!\n[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }

    size_t ukuran_data = 0;

    char input_str[512] = {0};
    unsigned int input_uint = 0;
    double input_double = 0;

    if (tipe_pilihan == 0) {
        std::cout << "Masukkan string (maks 511): ";
        std::cin.ignore();
        std::cin.getline(input_str, 512);
        
        ukuran_data = strlen(input_str) + 1; 
    } 
    else if (tipe_pilihan == 1) {
        std::cout << "Masukkan nilai uint: ";
        std::cin >> input_uint;
        ukuran_data = 4;
    } 
    else if (tipe_pilihan == 2) {
        std::cout << "Masukkan nilai double: ";
        std::cin >> input_double;
        ukuran_data = 8;
    }

    //ngitung Aligned Offset & Jump (berdasarkan keliptan tertentu)
    size_t current_offset = sister.bump_pointer;
    size_t aligned_offset = (current_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
    size_t jump = aligned_offset - current_offset;

    // ngitung final offset (gap hanya untuk char*)
    size_t special_gap_terpakai = (tipe_pilihan == 0) ? sister.special_gap : 0;
    size_t final_offset = aligned_offset + special_gap_terpakai;
    if (final_offset + ukuran_data > sister.pool_size) {
        std::cout << "Ruang tidak cukup di " << sister.nama 
                  << " pada offset aligned " << aligned_offset << " butuh " << ukuran_data << "\n";
        std::cout << "Penambahan memori gagal\n[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }
    // ngecopy data yang udah di entri ke pool secara manual (byte-by-byte)
    unsigned char* alamat_tujuan = sister.pool_start + final_offset;
    
    if (tipe_pilihan == 0) {
        for (size_t i = 0; i < ukuran_data; ++i) {
            alamat_tujuan[i] = (unsigned char)input_str[i];
        }
    } 
    else if (tipe_pilihan == 1) {
        unsigned char* src = (unsigned char*)&input_uint;
        for (size_t i = 0; i < ukuran_data; ++i) {
            alamat_tujuan[i] = src[i];
        }
    } 
    else if (tipe_pilihan == 2) {
        unsigned char* src = (unsigned char*)&input_double;
        for (size_t i = 0; i < ukuran_data; ++i) {
            alamat_tujuan[i] = src[i];
        }
    }

    size_t slot_aktif = sister.used_slots;
    sister.slots[slot_aktif].tipe = (tipe_data)tipe_pilihan;
    sister.slots[slot_aktif].ukuran = ukuran_data;
    sister.slots[slot_aktif].offset = final_offset;
    sister.slots[slot_aktif].alamat_memori = (void*)alamat_tujuan;
    sister.slots[slot_aktif].is_deleted = false;
    
    if (tipe_pilihan == 0) manual_strcpy(sister.slots[slot_aktif].nilai_str, input_str);
    else if (tipe_pilihan == 1) sister.slots[slot_aktif].nilai_uint = input_uint;
    else if (tipe_pilihan == 2) sister.slots[slot_aktif].nilai_double = input_double;

    //Update state sister core (Buat Checkpoint lah intinya untuk entri selanjutnya)
    sister.bump_pointer = final_offset + ukuran_data;
    sister.used_bytes += ukuran_data;
    sister.used_slots++;

    std::cout << "\nData berhasil ditambahkan ke " << sister.nama << "\n";
    std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
    std::cin.ignore(INT_MAX, '\n'); std::cin.get();
}
void menu_tambah_data(sister_core& historia, sister_core& mira, sister_core& victoria) {
    CLS;
    std::cout << "========================================================\n";
    std::cout << "PROTOKOL PENYUNTIKAN DATA BARU\n";
    std::cout << "========================================================\n";
    std::cout << "Pilih Target Sister:\n";
    std::cout << "1. " << historia.nama << "\n";
    std::cout << "2. " << mira.nama << "\n";
    std::cout << "3. " << victoria.nama << "\n";
    std::cout << "Pilih Sister (1-3): ";
    int target_sister;
    std::cin >> target_sister;

    if (target_sister < 1 || target_sister > 3) {
        std::cout << "\n[ERROR] Sister tidak dikenal!\nTekan ENTER untuk kembali...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }

    std::cout << "\nPilih Tipe Data:\n";
    std::cout << "0 = char*, 1 = uint, 2 = double\nPilih tipe: ";
    int target_tipe;
    std::cin >> target_tipe;

    if (target_tipe < 0 || target_tipe > 2) {
        std::cout << "\n[ERROR] Tipe data ilegal!\nTekan ENTER untuk kembali...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }

    if (target_sister == 1) tambah_memori_sister(historia, target_tipe);
    else if (target_sister == 2) tambah_memori_sister(mira, target_tipe);
    else if (target_sister == 3) tambah_memori_sister(victoria, target_tipe);
}
void memory_sister(const sister_core& sister) {
    CLS;
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Memori dari " << (sister.nama == "Historia Koura" ? "Historia" : 
                                    sister.nama == "Mira Koura" ? "Mira" : "Victoria") << "\n";
    std::cout << "------------------------------------------------------------\n";

    if (sister.used_slots == 0) {
        std::cout << "[INFO] Pool kosong.\n";
    } else {
        for (size_t i = 0; i < sister.used_slots; ++i) {
            if (sister.slots[i].is_deleted) continue;

            std::cout << "[" << i << "] ";
            
            if (sister.slots[i].tipe == TIPE_CHAR_PTR) {
                std::cout << "Tipe: char* | Ukuran: " << sister.slots[i].ukuran 
                          << " | Offset: " << sister.slots[i].offset 
                          << " | Alamat: " << sister.slots[i].alamat_memori 
                          << " | Nilai: \"" << sister.slots[i].nilai_str << "\"\n";
            } 
            else if (sister.slots[i].tipe == TIPE_UINT) {
                size_t prev_offset = (i == 0) ? 0 : sister.slots[i-1].offset + sister.slots[i-1].ukuran;
                size_t aligned_prev = (prev_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
                size_t hitung_jump = aligned_prev - prev_offset;

                std::cout << "Tipe: uint | Ukuran: " << sister.slots[i].ukuran 
                          << " | Alamat: " << sister.slots[i].alamat_memori 
                          << " | Jump: " << hitung_jump 
                          << " | Nilai: " << sister.slots[i].nilai_uint << "\n";
            } 
            else if (sister.slots[i].tipe == TIPE_DOUBLE) {
                size_t prev_offset = (i == 0) ? 0 : sister.slots[i-1].offset + sister.slots[i-1].ukuran;
                size_t aligned_prev = (prev_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
                size_t hitung_jump = aligned_prev - prev_offset;

                std::cout << "Tipe: double | Ukuran: " << sister.slots[i].ukuran 
                          << " | Alamat: " << sister.slots[i].alamat_memori 
                          << " | Jump: " << hitung_jump 
                          << " | Nilai: " << sister.slots[i].nilai_double << "\n";
            }
        }
    }
    std::cout << "Bump: " << sister.bump_pointer 
              << " | Ukuran Pool: " << sister.pool_size 
              << " | Align: " << sister.alignment 
              << " | Special Gap: +" << sister.special_gap << "\n";
              
    std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
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
        std::cout <<"Error: Terlahu banyak argumen.\n";
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
                memory_sister(historia);
                break;
            case 2:
                memory_sister(mira);
                break;
            case 3:
                memory_sister(victoria);
                break;
            case 4:
                menu_tambah_data(historia,mira,victoria);
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