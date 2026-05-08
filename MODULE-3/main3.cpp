#include <iostream>

int main() {
    int besaran;
    std::cout << "[TASK 3/3] ALIGN NAVIGATION MATRIX Engine Core\n";
    std::cout << ">>Sistem Navigasi Mati Total Akibat Sabotase\n";
    std::cout << ">>Rekonstruksi matriks koordinat sekarang!\n";
    std::cout << " [MATRIX NAVIGATION] \n";

    while (true) {
        std::cout << "\nMasukan Ukuran Navigation Matrix (min3,max5):";
        if (!(std::cin >> besaran)) {
            std::cin.clear();
            while (std::cin.get() != '\n');
            continue;
        }
        if (besaran >= 3 && besaran <= 5) break;
        std::cout << "\nMasukan Besaran Yang Sesuai\n";
    }

    std::cout << "\n----------------------------------------\n";

    int matrix1[besaran][besaran];
    int angkaSekarang = 2;
    int r = 0, c = 0;
    while (r < besaran) {
        int count = 0;
        for (int j = 1; j <= angkaSekarang; j++) {
            if (angkaSekarang % j == 0) count++;
        }
        if (count == 2) {
            matrix1[r][c] = angkaSekarang;
            c++;
            if (c == besaran) {
                c = 0;
                r++;
            }
        }
        angkaSekarang++;
    }

    int matrix2[besaran][besaran];
    int angkaSekarang2 = 4;
    int r2 = 0, c2 = 0;
    while (r2 < besaran) {
        int count = 0;
        for (int j = 1; j <= angkaSekarang2; j++) {
            if (angkaSekarang2 % j == 0) count++;
        }
        if (count > 2) {
            matrix2[r2][c2] = angkaSekarang2;
            c2++;
            if (c2 == besaran) {
                c2 = 0;
                r2++;
            }
        }
        angkaSekarang2++;
    }

    std::cout << "Matriks Prima " << besaran << "x" << besaran << ":" << std::endl;
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (matrix1[i][j] < 10) std::cout << '0';
            std::cout << matrix1[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "\nMatriks Komposit " << besaran << "x" << besaran << ":" << std::endl;
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (matrix2[i][j] < 10) std::cout << '0';
            std::cout << matrix2[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "\nMatriks Koordinat Telah Dipulihkan\n";
    std::cout << "Lakukan Proses Proses Berikut Untuk Hasil Koordinat Yang Lebih Akurat\n";
    std::cout << "1. Coordinate Matriks Integration\n";
    std::cout << "2. Matriks Transpose\n";
    std::cout << "3. Snake Traverse\n";
    std::cout << "4. C-Wise Traverse\n";
    std::cout << "Tekan Enter Untuk Kanjut";
    std::cin.ignore(1000,'\n');
    std::cin.get();
    system("cls");
    std::cout << "COORDINATE MATRIX INTEGRATION\n";
    std::cout << "-----------------------------\n";
    int sum_matrix[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            sum_matrix[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (sum_matrix[i][j] < 10) std::cout << '0'<<'0';
            if (sum_matrix[i][j] >= 10 && sum_matrix[i][j]<100) std::cout << '0';
            std::cout << sum_matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    std::cout << "MATRIX TRANSPOSE\n";
    std::cout << "-----------------------------\n";
    int transpose[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            transpose[j][i]=sum_matrix[i][j];
        }
    }
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (transpose[i][j]<10)std::cout<<'0'<<'0';
            else if (transpose[i][j]<100)std::cout<<'0';
            std::cout << transpose[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "SNAKE TRAVERSE\n";
    std::cout << "-----------------------------\n";
    int mushadik[besaran][besaran];
    int temp_mushadik=1;
    for (int i = 0; i < besaran; i++) {
        if (i % 2 != 0) {
                for (int j = besaran-1; j >= 0; j--) {
                    mushadik[i][besaran-1-j]=transpose[i][j];
                }
            }
        else {
                for (int j = 0; j < besaran; j++) {
                    mushadik[i][j]=transpose[i][j];
                }
            }
        }
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (mushadik[i][j]<10)std::cout<<'0'<<'0';
            else if (mushadik[i][j]<100)std::cout<<'0';
            std::cout << mushadik[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    std::cout << "C-WISE TRAVERSE\n";
    std::cout << "-----------------------------\n";
    int mushadik_abil[besaran][besaran];
    int temp_mushadik_abil=0; 
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (j % 2 != 0) {
                 mushadik_abil[i][j]=mushadik[besaran-1-i][j];
                }
            else {
                mushadik_abil[i][j]=mushadik[i][j];
            } 
        }
        temp_mushadik_abil++; 
    }
    for (int i = 0; i < besaran; i++) {
        for (int j = 0; j < besaran; j++) {
            if (mushadik_abil[i][j]<10)std::cout<<'0'<<'0';
            else if (mushadik_abil[i][j]<100)std::cout<<'0';
            std::cout << mushadik_abil[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    return 0;
}