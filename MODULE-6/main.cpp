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

void tambah_memori_sister(sister_core& sister, int tipe_pilihan, int pilihan_sister) {
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
        ukuran_data = sizeof(unsigned int);
    } 
    else if (tipe_pilihan == 2) {
        std::cout << "Masukkan nilai double: ";
        std::cin >> input_double;
        ukuran_data = sizeof(double);
    }
    size_t current_offset = sister.bump_pointer;
    size_t aligned_offset = (current_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
    size_t special_gap_terpakai = (tipe_pilihan == 0) ? sister.special_gap : 0;
    size_t final_offset = aligned_offset + special_gap_terpakai;
    if (final_offset + ukuran_data > sister.pool_size) {
        std::cout << "Ruang tidak cukup di " << sister.nama 
                  << " pada offset aligned " << aligned_offset << " butuh " << ukuran_data << "\n";
        std::cout << "Penambahan memori gagal\n[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }
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
    sister.bump_pointer = final_offset + ukuran_data;
    sister.used_bytes += ukuran_data;
    sister.used_slots++;
    std::cout << "\n";
    if (pilihan_sister == 0) {
        if (tipe_pilihan == 0) {
            std::cout << "Historia berbicara: \"Disiplin. Sejajarkan aku ke " << sister.alignment << ", dan tinggalkan upeti sebesar " << sister.special_gap << "-byte.\"\n";
        } else {
            std::cout << "Historia berbicara: \"Disiplin. Data numerik harus bersandar pada kelipatan " << sister.alignment << ".\"\n";
        }
    } 
    else if (pilihan_sister == 1) {
        if (tipe_pilihan == 0) {
            std::cout << "Mira tersenyum: \"Perlawanan menyambutmu dengan hangat. " << sister.alignment << "-byte untuk kedamaian, dan hembusan angin sepoi-sepoi " << sister.special_gap << "-byte untuk harapan.\"\n";
        } else {
            std::cout << "Mira tersenyum: \"Membawa harmoni angka ke dalam simfoni kelipatan " << sister.alignment << ".\"\n";
        }
    } 
    else if (pilihan_sister == 2) {
        if (tipe_pilihan == 0) {
            std::cout << "Victoria parau: \"...Aku tidak butuh bantuanmu, pemberontak. Tapi Abyss... membayar upeti " << sister.special_gap << "-byte untuk kebaikanmu.\"\n";
        } else {
            std::cout << "Victoria parau: \"Bahkan di dalam kegelapan, matematika darimu membawa secercah harapan sebesar " << sister.special_gap << "-byte.\"\n";
            std::cout << "Cyria: \"Lipat gandakan usaha; selalu jaga jarak dari kejamnya CyroN.\"\n";
        }
    }
    const char* nama_tipe = (tipe_pilihan == 0) ? "String" : (tipe_pilihan == 1) ? "Uint" : "Double";
    const char* nama_singkat = (pilihan_sister == 0) ? "Historia" : (pilihan_sister == 1) ? "Mira" : "Victoria";
    std::cout << nama_tipe << " berhasil ditambahkan ke " << nama_singkat << "\n";
    std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
    if (tipe_pilihan != 0) std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
}
void menu_tambah_data(sister_core& historia, sister_core& mira, sister_core& victoria) {
    CLS;
    std::cout << "========================================================\n";
    std::cout << "PROTOKOL PENYUNTIKAN DATA BARU\n";
    std::cout << "========================================================\n";
    std::cout << "Pilih Target Sister:\n";
    std::cout << "0. " << historia.nama << "\n";
    std::cout << "1. " << mira.nama << "\n";
    std::cout << "2. " << victoria.nama << "\n";
    std::cout << "Pilih Sister (0-2): ";
    int target_sister;
    std::cin >> target_sister;

    if (target_sister < 0 || target_sister > 2) {
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

    if (target_sister == 0) tambah_memori_sister(historia, target_tipe,target_sister);
    else if (target_sister == 1) tambah_memori_sister(mira, target_tipe,target_sister);
    else if (target_sister == 2) tambah_memori_sister(victoria, target_tipe,target_sister);
}
void memory_sister(const sister_core& sister) {
    CLS;
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Memori dari ";
    int j = 0;
    while (sister.nama[j] != '\0' && sister.nama[j] != ' ') {
        std::cout << sister.nama[j];
        j++;
    }
    std::cout << "\n------------------------------------------------------------\n";

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
void menu_hapus_data(sister_core& historia, sister_core& mira, sister_core& victoria) {
    std::cout << "Pilih sister: 0 = Historia, 1 = Mira, 2 = Victoria: ";
    int pilihan_sister;
    std::cin >> pilihan_sister;

    sister_core* sister = nullptr;
    if (pilihan_sister == 0) sister = &historia;
    else if (pilihan_sister == 1) sister = &mira;
    else if (pilihan_sister == 2) sister = &victoria;
    else return;

    std::cout << "Masukkan indeks untuk dihapus: ";
    size_t indeks;
    std::cin >> indeks;

    if (indeks >= sister->used_slots) {
        std::cout << "Indeks di luar jangkauan!\n";
        std::cout << "[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }

    if (sister->slots[indeks].is_deleted) {
        std::cout << "Entri sudah dihapus sebelumnya!\n";
        std::cout << "[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n'); std::cin.get();
        return;
    }

    std::cout << "Cyria: \"Kamu menghapus sebuah pecahan, tetapi kekosongan akan tetap ada jika pecahan yang lebih tinggi masih ada.\"\n";
    std::cout << "Menghapus indeks " << indeks << " pada offset " << sister->slots[indeks].offset << "\n";

    sister->used_bytes -= sister->slots[indeks].ukuran;
    sister->slots[indeks].is_deleted = true;

    if (indeks == sister->used_slots - 1) {
        while (sister->used_slots > 0 && sister->slots[sister->used_slots - 1].is_deleted) {
            sister->used_slots--;
        }
        if (sister->used_slots == 0) {
            sister->bump_pointer = 0;
        } else {
            size_t idx_ekor_baru = sister->used_slots - 1;
            sister->bump_pointer = sister->slots[idx_ekor_baru].offset + sister->slots[idx_ekor_baru].ukuran;
        }
        std::cout << "Ekor berhasil dikembalikan, Bump baru: " << sister->bump_pointer << "\n";
    } 
    else {
        std::cout << "Fragmentasi menghalangi pengembalian memori. Hapus indeks yang lebih tinggi terlebih dahulu!\n";
    }

    std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
    std::cin.ignore(INT_MAX, '\n'); std::cin.get();
}
void diagnostik(const sister_core& historia, const sister_core& mira, const sister_core& victoria) {
    std::cout << "Pilih sister: 0 = Historia, 1 = Mira, 2 = Victoria: ";
    int pilihan_sister;

    if (!(std::cin >> pilihan_sister) || pilihan_sister < 0 || pilihan_sister > 2) {
        std::cin.clear();
        std::cin.ignore(INT_MAX, '\n');
        
        std::cout << "\nPilihan tidak valid! Masukkan angka 0, 1, atau 2.\n";
        std::cout << "[GAGAL] Tekan ENTER untuk melanjutkan...";
        std::cin.get();
        return;
    }

    const sister_core* sister = nullptr;
    if (pilihan_sister == 0) sister = &historia;
    else if (pilihan_sister == 1) sister = &mira;
    else if (pilihan_sister == 2) sister = &victoria;

    size_t slot_aktif = 0;
    for (size_t i = 0; i < sister->used_slots; ++i) {
        if (!sister->slots[i].is_deleted) {
            slot_aktif++;
        }
    }
    double utilisasi = 0.0;
    if (sister->pool_size > 0) {
        utilisasi = ((double)sister->used_bytes / sister->pool_size) * 100.0;
    }

    const char* nama_singkat = "Historia";
    if (pilihan_sister == 1) nama_singkat = "Mira";
    if (pilihan_sister == 2) nama_singkat = "Victoria";

    std::cout << "------------------------------------------------------------\n";
    std::cout << "Diagnostik untuk " << nama_singkat << "\n";
    std::cout << "------------------------------------------------------------\n";
    
    std::cout << "Pool: " << (void*)sister->pool_start 
              << " | Ukuran: " << sister->pool_size 
              << " | Bump: " << sister->bump_pointer 
              << " | Align: " << sister->alignment << " + Gap " << sister->special_gap << "\n";
              
    std::cout << "Entri: " << sister->used_slots << "\n";
    std::cout << "Slot Terpakai: " << slot_aktif << " | Byte Terpakai: " << sister->used_bytes << "\n";
    std::cout << "Utilisasi: " << utilisasi << "%\n\n";

    std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
    std::cin.ignore(INT_MAX, '\n');
    std::cin.get();
}
void keluar_sistem(const sister_core& historia, const sister_core& mira, const sister_core& victoria) {
    CLS;
    size_t h_aktif = 0;
    for (size_t i = 0; i < historia.used_slots; i++) {
        if (!historia.slots[i].is_deleted) h_aktif++;
    }
    double h_util = (historia.pool_size > 0) ? ((double)historia.used_bytes / historia.pool_size) * 100.0 : 0.0;

    std::cout << "============================================================\n";
    std::cout << "Historia: Akhirnya bebas. Alignment " << historia.alignment << ", bimbingan spark +" << historia.special_gap << ".\n";
    std::cout << "============================================================\n";
    std::cout << "Pool: " << (void*)historia.pool_start 
              << " | Ukuran: " << historia.pool_size 
              << " | Bump: " << historia.bump_pointer 
              << " | Align: " << historia.alignment << " + Gap " << historia.special_gap << "\n";
    std::cout << "Entri: " << historia.used_slots << "\n";
    std::cout << "Slot Terpakai: " << h_aktif << " | Byte Terpakai: " << historia.used_bytes << "\n";
    std::cout << "Utilisasi: " << h_util << "%\n\n";

    size_t m_aktif = 0;
    for (size_t i = 0; i < mira.used_slots; i++) {
        if (!mira.slots[i].is_deleted) m_aktif++;
    }
    double m_util = (mira.pool_size > 0) ? ((double)mira.used_bytes / mira.pool_size) * 100.0 : 0.0;

    std::cout << "============================================================\n";
    std::cout << "Mira: Sayap perlawanan. Alignment " << mira.alignment << ", hembusan harapan +" << mira.special_gap << ".\n";
    std::cout << "============================================================\n";
    std::cout << "Pool: " << (void*)mira.pool_start 
              << " | Ukuran: " << mira.pool_size 
              << " | Bump: " << mira.bump_pointer 
              << " | Align: " << mira.alignment << " + Gap " << mira.special_gap << "\n";
    std::cout << "Entri: " << mira.used_slots << "\n";
    std::cout << "Slot Terpakai: " << m_aktif << " | Byte Terpakai: " << mira.used_bytes << "\n";
    std::cout << "Utilisasi: " << m_util << "%\n\n";

    size_t v_aktif = 0;
    for (size_t i = 0; i < victoria.used_slots; i++) {
        if (!victoria.slots[i].is_deleted) v_aktif++;
    }
    double v_util = (victoria.pool_size > 0) ? ((double)victoria.used_bytes / victoria.pool_size) * 100.0 : 0.0;

    std::cout << "============================================================\n";
    std::cout << "Victoria: Bayang yang pulih. Alignment " << victoria.alignment << ", persembahan kebaikan +" << victoria.special_gap << ".\n";
    std::cout << "============================================================\n";
    std::cout << "Pool: " << (void*)victoria.pool_start 
              << " | Ukuran: " << victoria.pool_size 
              << " | Bump: " << victoria.bump_pointer 
              << " | Align: " << victoria.alignment << " + Gap " << victoria.special_gap << "\n";
    std::cout << "Entri: " << victoria.used_slots << "\n";
    std::cout << "Slot Terpakai: " << v_aktif << " | Byte Terpakai: " << victoria.used_bytes << "\n";
    std::cout << "Utilisasi: " << v_util << "%\n\n";

    std::cout << "Lagta: Patuhi alignment.\n";
    std::cout << "Daiki: Perhatikan alirannya.\n";
    std::cout << "Cyria: Waspadalah terhadap jurang maut.\n";
    std::cout << "Xelvelt: Bandingkan stack dan heap.\n";
    std::cout << "Good bye. May the Koura sisters function well within your hands.\n";
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
void suntik_string_otomatis(sister_core& sister, const char* teks) {
    size_t ukuran = strlen(teks) + 1;
    size_t current_offset = sister.bump_pointer;
    size_t aligned_offset = (current_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
    size_t final_offset = aligned_offset + sister.special_gap;
    
    unsigned char* alamat_tujuan = sister.pool_start + final_offset;
    for (size_t i = 0; i < ukuran; ++i) {
        alamat_tujuan[i] = (unsigned char)teks[i];
    }
    
    size_t idx = sister.used_slots;
    sister.slots[idx].tipe = TIPE_CHAR_PTR;
    sister.slots[idx].ukuran = ukuran;
    sister.slots[idx].offset = final_offset;
    sister.slots[idx].alamat_memori = (void*)alamat_tujuan;
    sister.slots[idx].is_deleted = false;
    manual_strcpy(sister.slots[idx].nilai_str, teks);
    
    sister.bump_pointer = final_offset + ukuran;
    sister.used_bytes += ukuran;
    sister.used_slots++;
}
void suntik_uint_otomatis(sister_core& sister, unsigned int nilai) {
    size_t ukuran = sizeof(unsigned int);
    size_t current_offset = sister.bump_pointer;
    size_t aligned_offset = (current_offset + (sister.alignment - 1)) & ~(sister.alignment - 1);
    size_t final_offset = aligned_offset;
    
    unsigned char* alamat_tujuan = sister.pool_start + final_offset;
    unsigned char* src = (unsigned char*)&nilai;
    for (size_t i = 0; i < ukuran; ++i) {
        alamat_tujuan[i] = src[i];
    }
    
    size_t idx = sister.used_slots;
    sister.slots[idx].tipe = TIPE_UINT;
    sister.slots[idx].ukuran = ukuran;
    sister.slots[idx].offset = final_offset;
    sister.slots[idx].alamat_memori = (void*)alamat_tujuan;
    sister.slots[idx].is_deleted = false;
    sister.slots[idx].nilai_uint = nilai;
    
    sister.bump_pointer = final_offset + ukuran;
    sister.used_bytes += ukuran;
    sister.used_slots++;
}
int main(int argc, char* argv[]) {
    const char* nim_gwh = "F1D02510070";
    if (argc < 2) {
        std::cout <<"Penggunaan: ./solution.exe <student_id>\nContoh: ./solution.exe F1D02510070\n";
        return 1;
    }
    if (argc > 2) {
        std::cout <<"Error: Terlahu banyak argumen.\n";
        return 1;
    }
    bool nim_cocok = true;
    int i = 0;
    while (argv[1][i] != '\0' || nim_gwh[i] != '\0') {
        if (argv[1][i] != nim_gwh[i]) {
            nim_cocok = false;
            break;
        }
        i++;
    }
    if (nim_valid(argv[1]) && nim_cocok) {
        CLS;
        std::cout << "NIM VALID: " << argv[1] << "\n";
        std::cout << "Salam Hormat Kaisar Agung Yang Mulia Arizona, Kedatanganmu Kali Ini Merupakan Awal Dari Perubahan Besar Di Schryza\nKami Sungguh Berharap Yang Mulia Bisa Mengakhiri Kediktatoran CyroN!\nAll Hail ZonaZunZhe!!\n";
        std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n');
    }
    else if (nim_valid(argv[1])) {
        CLS;
        std::cout << "NIM VALID: " << argv[1] << "\n";
        std::cout << "Halo MemArch Kau Adalah Orang Yang Kami Tunggu,Semoga Berhasil Dalam Pekerjaanmu\n(luvvv zona)\n";
        std::cout << "[OK] Tekan ENTER untuk melanjutkan...";
        std::cin.ignore(INT_MAX, '\n');
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
        if (historia.pool_start) free(historia.pool_start);
        if (mira.pool_start) free(mira.pool_start);
        if (victoria.pool_start) free(victoria.pool_start);
        return 1;
    }
    suntik_string_otomatis(historia, "Historia: Schryza will be free.");
    suntik_string_otomatis(mira, "Mira: The winds are changing.");
    suntik_uint_otomatis(mira, 101);
    suntik_string_otomatis(victoria, "Victoria: Fragment of the First Light.");
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
                menu_hapus_data(historia, mira, victoria);
                break;
            case 6:
                diagnostik(historia, mira, victoria);
                break;
            case 0:
                keluar_sistem(historia, mira, victoria);
                break;
        }
    }
    free(historia.pool_start);
    free(mira.pool_start);
    free(victoria.pool_start);
    return 0;
}