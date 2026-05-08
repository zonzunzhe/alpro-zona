#include <iostream>

int main() {
    // TASK 1
    char text_enkrip[1024];
    int text_len1 = 0;
    while (true) {
	std::cout << "[ENKRIPSI]\nMasukkan teks: ";
	std::cin.getline(text_enkrip, 1024);
	text_len1 = 0;
	while (text_enkrip[text_len1] != '\0') {
	    text_len1++;
	}

	if (text_len1 > 0)
	    break;
	std::cout << "[!] Input tidak boleh kosong.\n";
    }
    int cols = 0;
    while (true) {
	std::cout << "Masukkan jumlah kolom: ";
	std::cin >> cols;

	if (std::cin.fail() || cols <= 0 || cols > text_len1) {
	    std::cin.clear();
	    char c;
	    while (std::cin.get(c) && c != '\n');
	    std::cout << "[!] Kolom harus > 0 dan <= panjang teks ("
		      << text_len1 << ").\n";
	} else {
	    char c;
	    while (std::cin.get(c) && c != '\n');
	    break;
	}
    }
    int keyshift;
    while (true) {
	std::cout << "Masukkan Keyshift: ";
	std::cin >> keyshift;

	if (std::cin.fail()) {
	    std::cin.clear();
	    char c;
	    while (std::cin.get(c) && c != '\n');
	    std::cout << "Input Harus Angka" << std::endl;
	} else {
	    char c;
	    while (std::cin.get(c) && c != '\n');
	    break;
	}
    }
    int rows = (text_len1 + cols - 1) / cols;
    int total_cels = rows * cols;
    char matrix[2000];
    for (int i = 0; i < total_cels; i++) {
	if (i < text_len1) {
	    matrix[i] = text_enkrip[i];
	} else {
	    matrix[i] = '_';
	}
    }
    std::cout << "\nMatriks enkripsi:\n";
    for (int r = 0; r < rows; r++) {
	std::cout << "  ";
	for (int c = 0; c < cols; c++) {
	    std::cout << matrix[r * cols + c];
	}
	std::cout << '\n';
    }
    char cipher_text[2000];
    int indx1 = 0;

    for (int c = 0; c < cols; c++) {
	for (int r = 0; r < rows; r++) {
	    cipher_text[indx1++] = matrix[r * cols + c];
	}
    }
    cipher_text[total_cels] = '\0';

    std::cout << "\nEnkripsi sebelum shift key: " << cipher_text << '\n';

    for (int i = 0; i < total_cels; i++) {
	cipher_text[i] = cipher_text[i] + keyshift;
    }

    std::cout << "Enkripsi setelah ditambah key: " << cipher_text << '\n';
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    char text_dekrip[1024];
    int text_len2 = 0;
    do {
	std::cout << "\n[DEKSRIPSI]\nMasukkan teks: ";
	std::cin.getline(text_dekrip, 1024);
	text_len2 = 0;
	while (text_dekrip[text_len2] != '\0') {
	    text_len2++;
	}
	if (text_len2 > 0)
	    break;
	else {
	    std::cout << "[!] Input tidak boleh kosong.\n";
	}
    } while (true);

    char hasil_dekrip[2000];
    for (int i = 0; i < text_len2; i++) {
	hasil_dekrip[i] = text_dekrip[i] - keyshift;
    }
    hasil_dekrip[text_len2] = '\0';
    std::cout << "Dekripsi setelah dikurang key: " << hasil_dekrip << '\n';

    int current_idx = 0;
    for (int c = 0; c < cols; c++) {
	for (int r = 0; r < rows; r++) {
	    if (current_idx < text_len2) {
		matrix[r * cols + c] = hasil_dekrip[current_idx++];
	    } else {
		matrix[r * cols + c] = '_';
	    }
	}
    }

    int indx2 = 0;
    std::cout << "Matriks Dekripsi" << '\n';
    for (int r = 0; r < rows; r++) {
	std::cout << "  ";
	for (int c = 0; c < cols; c++) {
	    std::cout << matrix[r * cols + c];
	}
	std::cout << '\n';
    }

    for (int r = 0; r < rows; r++) {
	for (int c = 0; c < cols; c++) {
	    char current_char = matrix[r * cols + c];
	    if (current_char != '_') {
		cipher_text[indx2++] = current_char;
	    }
	}
    }
    cipher_text[indx2] = '\0';
    std::cout << "Hasil Dekripsi: " << cipher_text << '\n';
    std::cout << ">>[TASK 1/3] COMPLETE - Signal Channel Restored" << '\n';
    std::cout << ">>Tekan ENTER untuk melanjutkan ke [TASK2]";
    std::cin.clear();
    std::cin.ignore(1000, '\n');
    system("cls");

    // TASK 2
    char pilihan = 'y';

    while (pilihan == 'y' || pilihan == 'Y') {
	std::cin.ignore(1000, '\n');
	std::cin.clear();
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
	    std::cout << "\n-----------------------------------" << std::endl;
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
	    if (pilihan == 'y' || pilihan == 'Y' || pilihan == 'n' ||
		pilihan == 'N') {
		break;
	    }
	    std::cout << "[!] Input tidak valid. Masukkan y atau n.\n";
	}
    }
    std::cout << ">> [TASK 2/3] COMPLETE - Text console back online.\n";
    std::cin.ignore(1000, '\n');
    std::cin.clear();
    system("cls");
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
	if (besaran >= 3 && besaran <= 5)
	    break;
	std::cout << "\nMasukan Besaran Yang Sesuai\n";
    }

    std::cout << "\n----------------------------------------\n";

    int matrix1[besaran][besaran];
    int angkaSekarang = 2;
    int r = 0, c = 0;
    while (r < besaran) {
	int count = 0;
	for (int j = 1; j <= angkaSekarang; j++) {
	    if (angkaSekarang % j == 0)
		count++;
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
	    if (angkaSekarang2 % j == 0)
		count++;
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

    std::cout << "Matriks Prima " << besaran << "x" << besaran << ":"
	      << std::endl;
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (matrix1[i][j] < 10)
		std::cout << '0';
	    std::cout << matrix1[i][j] << "\t";
	}
	std::cout << std::endl;
    }

    std::cout << "\nMatriks Komposit " << besaran << "x" << besaran << ":"
	      << std::endl;
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (matrix2[i][j] < 10)
		std::cout << '0';
	    std::cout << matrix2[i][j] << "\t";
	}
	std::cout << std::endl;
    }
    std::cout << "\nMatriks Koordinat Telah Dipulihkan\n";
    std::cout << "Lakukan Proses Proses Berikut Untuk Hasil Koordinat Yang "
		 "Lebih Akurat\n";
    std::cout << "1. Coordinate Matriks Integration\n";
    std::cout << "2. Matriks Transpose\n";
    std::cout << "3. Snake Traverse\n";
    std::cout << "4. C-Wise Traverse\n";
    std::cout << "Tekan Enter Untuk Kanjut";
    std::cin.ignore(1000, '\n');
    std::cin.get();
    system("cls");
    std::cout << "COORDINATE MATRIX INTEGRATION\n";
    std::cout << "-----------------------------\n";
    int sum_matrix[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    sum_matrix[i][j] = matrix1[i][j] + matrix2[i][j];
	}
    }
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (sum_matrix[i][j] < 10)
		std::cout << '0' << '0';
	    if (sum_matrix[i][j] >= 10 && sum_matrix[i][j] < 100)
		std::cout << '0';
	    std::cout << sum_matrix[i][j] << "\t";
	}
	std::cout << std::endl;
    }

    std::cout << "MATRIX TRANSPOSE\n";
    std::cout << "-----------------------------\n";
    int transpose[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    transpose[j][i] = sum_matrix[i][j];
	}
    }
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (transpose[i][j] < 10)
		std::cout << '0' << '0';
	    else if (transpose[i][j] < 100)
		std::cout << '0';
	    std::cout << transpose[i][j] << "\t";
	}
	std::cout << std::endl;
    }
    std::cout << "SNAKE TRAVERSE\n";
    std::cout << "-----------------------------\n";
    int mushadik[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
	if (i % 2 != 0) {
	    for (int j = besaran - 1; j >= 0; j--) {
		mushadik[i][besaran - 1 - j] = transpose[i][j];
	    }
	} else {
	    for (int j = 0; j < besaran; j++) {
		mushadik[i][j] = transpose[i][j];
	    }
	}
    }
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (mushadik[i][j] < 10)
		std::cout << '0' << '0';
	    else if (mushadik[i][j] < 100)
		std::cout << '0';
	    std::cout << mushadik[i][j] << "\t";
	}
	std::cout << std::endl;
    }
    std::cout << "C-WISE TRAVERSE\n";
    std::cout << "-----------------------------\n";
    int mushadik_abil[besaran][besaran];
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (j % 2 != 0) {
		mushadik_abil[i][j] = mushadik[besaran - 1 - i][j];
	    } else {
		mushadik_abil[i][j] = mushadik[i][j];
	    }
	}
    }
    for (int i = 0; i < besaran; i++) {
	for (int j = 0; j < besaran; j++) {
	    if (mushadik_abil[i][j] < 10)
		std::cout << '0' << '0';
	    else if (mushadik_abil[i][j] < 100)
		std::cout << '0';
	    std::cout << mushadik_abil[i][j] << "\t";
	}
	std::cout << std::endl;
    }
    std::cout << ">> [TASK 3/3] COMPLETE -Navigation Matrix Alligned\n";
    std::cout << ">> ====================================================\n";
    std::cout << ">>\tSHIP SYSTEM RESTORED\n";
    return 0;
}
