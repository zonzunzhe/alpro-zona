#include<iostream> 

int main() {
    char pilihan = 'y';
    
    while (pilihan == 'y' || pilihan == 'Y') {
        system("cls");
        std::cout << "[Verifikasi Teks]\n";

        for (int k = 1; k <= 3; k++) {
            char kalimat[1024];
            
            if (k == 1) {
                std::cin.clear();
            }
            std::cout << "Masukkan Kalimat ke-" << k << "\t: ";
            std::cin.getline(kalimat, 1024);
            
            char tanpa_spasi[1024];
            int n = 0;
            for (int i = 0; kalimat[i] != '\0'; i++) {
                if (kalimat[i] != ' ') {
                    tanpa_spasi[n++] = kalimat[i];
                }
            }
            tanpa_spasi[n] = '\0';
            std::cout << "\n-----------------------------------"<<std::endl;
            std::cout << "Hasil untuk Kalimat ke-\t" << k << ":\n";
            std::cout << "Jumlah Huruf\t:" << n << "\n";

            int total_huruf = 0;
            for (int i = 0; kalimat[i] != '\0'; i++) {
                if (kalimat[i] != ' ') {
                    total_huruf++;
                }
            }

            int count = 0;
            std::cout << "1. Aseli\t: ";
            for (int i = 0; kalimat[i] != '\0'; i++) {
                if (kalimat[i] != ' ') {
                    std::cout << kalimat[i];
                    count++;
                    if (count < total_huruf) {
                        std::cout << " , ";
                    }
                }
            }
            std::cout << std::endl;

            std::cout << "2. Inverse: ";
            for (int i = n - 1; i >= 0; i--) {
                std::cout << tanpa_spasi[i];
                if (i > 0) {
                    std::cout << ", ";
                }
            }
            std::cout << std::endl;

            char hasil_swap[1024];
            for (int i = 0; i <= n; i++) { 
                hasil_swap[i] = tanpa_spasi[i];
            }
            if (n > 1) {
                char temp = hasil_swap[0];
                hasil_swap[0] = hasil_swap[n - 1];
                hasil_swap[n - 1] = temp;
            }
            std::cout << "3. Swap: " << hasil_swap << std::endl;

            bool is_palindrome = true;
            for (int i = 0; i < n / 2; i++) {
                if (tanpa_spasi[i] != tanpa_spasi[n - 1 - i]) {
                    is_palindrome = false;
                    break;
                }
            }
            std::cout << "4. Palindrome\t: ";
            if (n > 0 && is_palindrome) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }

            char unik[1024];
            int n_unik = 0;
            for (int i = 0; i < n; i++) {
                bool sudah_ada = false;
                for (int j = 0; j < n_unik; j++) {
                    if (tanpa_spasi[i] == unik[j]) {
                        sudah_ada = true;
                        break;
                    }
                }
                if (!sudah_ada) {
                    unik[n_unik++] = tanpa_spasi[i];
                }
            }

            for (int i = 0; i < n_unik - 1; i++) {
                for (int j = 0; j < n_unik - i - 1; j++) {
                    if (unik[j] > unik[j + 1]) {
                        char temp = unik[j];
                        unik[j] = unik[j + 1];
                        unik[j + 1] = temp;
                    }
                }
            }

            std::cout << "5.Diurutkan (Unik): ";
            for (int i = 0; i < n_unik; i++) {
                std::cout << unik[i];
                if (i < n_unik - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "\n\n";
        }

        while (true) {
            std::cout << "Verifikasi Teks Lain? (y/n): ";
            std::cin >> pilihan;
            if (pilihan == 'y' || pilihan == 'Y' || pilihan == 'n' || pilihan == 'N') {
                break;
            }
            std::cout << "[!] Input tidak valid. Masukkan y atau n.\n";
        }
    }

    std::cout << ">> [TASK 2/3] COMPLETE - Text console back online.\n";
    return 0;
}