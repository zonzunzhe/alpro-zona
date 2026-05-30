#include <iostream>
#include <string>
#include <ctime>

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_WHITE   "\033[1;37m"
#define CLS std::cout<<"\033[2J\033[H"

struct Commit {
	std::string hash;
	std::string message;
	std::string author;
	std::string date;
	Commit* next = nullptr;
};

struct Branch {
	std::string name;
	Commit* head_commit = nullptr;
	int commit_count = 0;
};

struct Repo {
	std::string name;
	Branch* branches = nullptr;
	int branch_count = 0;
	int active_branch_idx = 0;
};
std::string to_lower_case(std::string str) {
	std::string result = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			result += (str[i] + 32);
		} else {
			result += str[i];
		}
	}
	return result;
}

int main(int argc, char* argv[]) {
	if (argc < 2) {
		CLS;
		std::cout << COLOR_RED << "[ERROR] Nama author tidak boleh kosong!" << COLOR_RESET << std::endl;
		std::cout << "Gunakan perintah: .\\gitsim <Nama_Anda>" << std::endl;
		return 1;
	}
	
	if (argc > 2) {
		CLS;
		std::cout << COLOR_RED << "[ERROR] Argumen terlalu banyak! Nama author cukup 1 kata tanpa spasi." << COLOR_RESET << std::endl;
		std::cout << "Gunakan perintah: .\\gitsim <Nama_Anda>" << std::endl;
		return 1;
	}

	std::string author_name = argv[1];
	if (author_name.length() < 3) {
		CLS;
		std::cout << COLOR_RED << "[ERROR] Nama author terlalu pendek! Minimal 3 huruf." << COLOR_RESET << std::endl;
		return 1;
	}

	std::string lower_name = to_lower_case(author_name);
	
	if (lower_name == "arizona" || lower_name == "zona") {
		CLS;
		std::cout << COLOR_GREEN << "Halo Pria Sigma (Siapa Lagi Klo Bukan Gwh), Apakah Anda Siap Menghijaukan Github" << COLOR_RESET << std::endl;
		std::cout << "\nTekan Enter untuk masuk ke Menu Utama...";
		std::cin.get();
	}

	while (true) {
		CLS;
		std::cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << std::endl;
		std::cout << "Author: " << author_name << std::endl;
		std::cout << "-------------------------------------------\n";
		std::cout << "[1] git commit\n";
		std::cout << "[2] git log\n";
		std::cout << "[3] git branch\n";
		std::cout << "[4] git checkout\n";
		std::cout << "[5] git init (new)\n";
		std::cout << "[6] switch repository\n";
		std::cout << "[7] exit\n";
		std::cout << "-------------------------------------------\n";
		std::cout << "> ";
		
		int pilihan;
		std::cin >> pilihan;
		
		if (pilihan == 7) {
			CLS;
			std::cout << "Keluar dari program. Sampai jumpa!" << std::endl;
			break;
		} else {
            CLS;
			std::cout << "\nCihuy\n";
			std::cout << "Tekan Enter untuk kembali...";
			std::cin.ignore(10000, '\n');
			std::cin.get();
		}
	}

	return 0;
}