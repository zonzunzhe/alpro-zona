#include <iostream>

int main() {
    char text[1024];
	int text_len = 0;
	while (true) {
        std::cout << "[ENKRIPSI]\nMasukkan teks: ";
		std::cin.getline(text, 1024);
		text_len = 0;
		while (text[text_len] != '\0') {
            text_len++;
		}
		
		if (text_len > 0) break;
		std::cout << "[!] Input tidak boleh kosong.\n";
    }
    int cols = 0;
	while (true) {
        std::cout << "Masukkan jumlah kolom: ";
		std::cin >> cols;
		
		if (std::cin.fail() || cols <= 0 || cols > text_len) {
            std::cin.clear();
			char c;
			while (std::cin.get(c) && c != '\n');
			std::cout << "[!] Kolom harus > 0 dan <= panjang teks (" << text_len << ").\n";
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
			std::cout << "Input Harus Angka"<<std::endl;
		} else {
            char c;
			while (std::cin.get(c) && c != '\n');
			break;
		}
	}
    int rows=cols;
    int total_cels=rows*cols;
    char matrix[2000];
    for (int i=0 ; i<total_cels;i++){
        if (i<text_len){
            matrix[i]=text[i];
        }
        else {
            matrix[i]='_';
        }
    }
    std::cout << "\nMatriks enkripsi:\n";
	for (int r = 0; r < rows; r++) {
        std::cout<<"  ";
		for (int c = 0; c < cols; c++) {
            std::cout << matrix[r * cols + c];
		}
		std::cout << '\n';
	}
    char cipher_text[2000];
    int indx = 0;
	
	for (int c = 0; c < cols; c++) {
		for (int r = 0; r < rows; r++) {
            cipher_text[indx++] = matrix[r * cols + c];
		}
	}
	cipher_text[total_cels] = '\0';
	
	std::cout << "\nEnkripsi sebelum shift key: " << cipher_text << '\n';
    
	for (int i = 0; i < total_cels; i++) {
        cipher_text[i] = cipher_text[i] + keyshift;
	}
	
	std::cout << "Enkripsi setelah ditambah key: " << cipher_text << '\n';
}