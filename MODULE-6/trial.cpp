#include <iostream>
#include <string>
#include <ctime>
using namespace std;

#define COLOR_RESET   "\033[0m"
#define COLOR_GREEN   "\033[1;32m"
#define COLOR_YELLOW  "\033[1;33m"
#define COLOR_RED     "\033[1;31m"
#define COLOR_CYAN    "\033[1;36m"
#define COLOR_WHITE   "\033[1;37m"
#define CLS cout<<"\033[2J\033[H"

struct Commit {
	string hash;
	string message;
	string author;
	string date;
	Commit* next = nullptr;
};

struct Branch {
	string name;
	Commit* head_commit = nullptr;
	int commit_count = 0;
};

struct Repo {
	string name;
	Branch* branches = nullptr;
	int branch_count = 0;
	int active_branch_idx = 0;
};

void garis(){
    cout << "-------------------------------------------\n";
}
string to_lower_case(string str) {
	string result = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			result += (str[i] + 32);
		} else {
			result += str[i];
		}
	}
	return result;
}
string generate_short_hash(string msg) {
	const char hex_chars[] = "0123456789abcdef";
	string hash = "";
	int val = 0;
	
	// Loop manual untuk menghitung nilai karakter
	for (int i = 0; i < msg.length(); i++) {
		val += (int)msg[i];
	}
	
	srand(val + time(nullptr));
	for (int i = 0; i < 7; ++i) {
		hash += hex_chars[rand() % 16];
	}
	return hash;
}
string get_current_time() {
	time_t now = time(nullptr);
	tm* ltm = localtime(&now);
	char buffer[80];
	strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M", ltm);
	return string(buffer);
}
void menu_commit(Repo* repo, string author) {
	CLS;
	Branch& branch_aktif = repo->branches[repo->active_branch_idx];
    Commit* commit_baru = new Commit;
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "git commit [" << COLOR_GREEN << branch_aktif.name << COLOR_RESET << "]" << endl;
	garis();
	
	string pesan;
	cout << "Message: ";
	cin.ignore(10000, '\n');
	getline(cin, pesan);
	
	char konfirmasi;
	cout << "Push commit? (y/n): ";
	cin >> konfirmasi;
	if (konfirmasi == 'y' || konfirmasi == 'Y') {
		commit_baru->hash = generate_short_hash(pesan);
		commit_baru->message = pesan;
		commit_baru->author = author;
		commit_baru->date = get_current_time();
		commit_baru->next = branch_aktif.head_commit;
		branch_aktif.head_commit = commit_baru;
		branch_aktif.commit_count++;
        cout << "\n[" << COLOR_GREEN << branch_aktif.name << " " << commit_baru->hash << COLOR_RESET << "] " << pesan << endl;
        garis();
        cout << branch_aktif.name <<" -> origin/"<<branch_aktif.name<< endl;
        cout << "$ git push origin " << branch_aktif.name<< endl;
        garis();
        cout << "\nTekan Enter untuk kembali...";
        cin.ignore(1000,'\n');
        cin.get();
		return;
	} else {
        cout << "\nCommit dibatalkan." << endl;
        return;
	}
}

void menu_log(Repo* repo) {
	CLS;
	Branch& branch_aktif = repo->branches[repo->active_branch_idx];
	
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "git log [" << COLOR_GREEN << branch_aktif.name << COLOR_RESET << "]" << endl;
	garis();
	
	if (branch_aktif.head_commit == nullptr) {
		cout << COLOR_YELLOW << "(No commits on this branch)" << COLOR_RESET << endl;
	} 
	else {
		Commit* current = branch_aktif.head_commit;

		while (current != nullptr) {
			cout << COLOR_YELLOW << "commit " << current->hash << COLOR_RESET << endl;
			cout << "Author:\t" << current->author << endl;
			cout << "Date  :\t" << current->date << endl;
			cout << "\t" << current->message << "\n" << endl;
			current = current->next;
		}
	}
	
	cout << "Tekan Enter untuk kembali...";
	cin.ignore(1000, '\n');
	cin.get();
}

Commit* clone_commits(Commit* source_head) {
	if (source_head == nullptr) {
		return nullptr;
	}
	Commit* new_head = new Commit;
	new_head->hash = source_head->hash;
	new_head->message = source_head->message;
	new_head->author = source_head->author;
	new_head->date = source_head->date;
	new_head->next = nullptr;
	Commit* current_new = new_head;
	Commit* current_source = source_head->next;
	
	while (current_source != nullptr) {
		Commit* temp = new Commit;
		temp->hash = current_source->hash;
		temp->message = current_source->message;
		temp->author = current_source->author;
		temp->date = current_source->date;
		temp->next = nullptr;
		current_new->next = temp;
		current_new = temp;
		current_source = current_source->next;
	}
	
	return new_head;
}
void menu_branch(Repo* repo) {
	CLS;
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "git branch" << endl;
	garis();
	for (int i = 0; i < repo->branch_count; i++) {
		if (i == repo->active_branch_idx) {
			cout << "* " << COLOR_GREEN << repo->branches[i].name << COLOR_RESET 
				 << " (" << repo->branches[i].commit_count << " commits)" << endl;
		} else {
			cout << "  " << repo->branches[i].name 
				 << " (" << repo->branches[i].commit_count << " commits)" << endl;
		}
	}
	garis();
	string nama_branch_baru;
	cout << "New branch name: ";
	cin.ignore(1000, '\n');
	getline(cin, nama_branch_baru);
	if (nama_branch_baru.empty()) {
		cout << COLOR_RED << "[ERROR] Nama branch tidak boleh kosong!" << COLOR_RESET << endl;
	} 
	else {
		bool sudah_ada = false;
		for (int i = 0; i < repo->branch_count; i++) {
			if (repo->branches[i].name == nama_branch_baru) {
				sudah_ada = true;
				break;
			}
		}
		
		if (sudah_ada) {
			cout << COLOR_RED << "[ERROR] Branch '" << nama_branch_baru << "' sudah ada!" << COLOR_RESET << endl;
		} 
		else {
			int ukuran_baru = repo->branch_count + 1;
			Branch* array_baru = new Branch[ukuran_baru];
			
			// Salin isi data branch lama ke array yang baru
			for (int i = 0; i < repo->branch_count; i++) {
				array_baru[i] = repo->branches[i];
			}
			array_baru[repo->branch_count].name = nama_branch_baru;
			Branch& branch_sekarang = repo->branches[repo->active_branch_idx];
			array_baru[repo->branch_count].head_commit = clone_commits(branch_sekarang.head_commit);
			array_baru[repo->branch_count].commit_count = branch_sekarang.commit_count;
			delete[] repo->branches;
			repo->branches = array_baru;
			repo->branch_count = ukuran_baru;
			
			cout << "\n[" << COLOR_GREEN << "OK" << COLOR_RESET << "] Branch '" << nama_branch_baru 
				 << "' berhasil dibuat dari '" << branch_sekarang.name << "'" << endl;
			cout << branch_sekarang.commit_count << " commit(s) otomatis diwariskan." << endl;
		}
	}
	cout << "\nTekan Enter untuk kembali...";
	cin.get();
}
void menu_checkout(Repo* repo) {
	CLS;
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "git checkout" << endl;
	garis();
	
	cout << "Daftar branch yang tersedia:\n";
	for (int i = 0; i < repo->branch_count; i++) {
		if (i == repo->active_branch_idx) {
			cout << "* " << COLOR_GREEN << repo->branches[i].name << COLOR_RESET << endl;
		} else {
			cout << "  " << repo->branches[i].name << endl;
		}
	}
	garis();
	string branch_tujuan;
	cout << "Switch to branch: ";
	cin.ignore(1000, '\n');
	getline(cin, branch_tujuan);
	int indeks_ketemu = -1;
	for (int i = 0; i < repo->branch_count; i++) {
		if (repo->branches[i].name == branch_tujuan) {
			indeks_ketemu = i;
			break;
		}
	}
	if (indeks_ketemu == -1) {
		cout << COLOR_RED << "[ERROR] Branch '" << branch_tujuan << "' tidak ditemukan atau tidak tersedia!" << COLOR_RESET << endl;
	} 
	else {
		repo->active_branch_idx = indeks_ketemu;
		cout << "\n[" << COLOR_GREEN << "OK" << COLOR_RESET << "] Switched to branch '" << branch_tujuan << "'" << endl;
	}
	
	cout << "\nTekan Enter untuk kembali...";
	cin.get();
}
// Fungsi khusus untuk menangani pilihan [5] new repository
void menu_new_repository(Repo*& daftar_repo, int& total_repo, int& indeks_repo_aktif) {
	CLS;
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "git init (new repository)" << endl;
	garis();
	string nama_repo_baru;
	cout << "New repository name: ";
	cin.ignore(1000, '\n');
	getline(cin, nama_repo_baru);

	if (nama_repo_baru.empty()) {
		nama_repo_baru = "repo-" + to_string(total_repo + 1);
	}

	bool sudah_ada = false;
	for (int i = 0; i < total_repo; i++) {
		if (daftar_repo[i].name == nama_repo_baru) {
			sudah_ada = true;
			break;
		}
	}
	
	if (sudah_ada) {
		cout << COLOR_RED << "[ERROR] Repository '" << nama_repo_baru << "' sudah ada!" << COLOR_RESET << endl;
	} 
	else {
		int ukuran_baru = total_repo + 1;
		Repo* array_repo_baru = new Repo[ukuran_baru];
		
		for (int i = 0; i < total_repo; i++) {
			array_repo_baru[i] = daftar_repo[i];
		}

		array_repo_baru[total_repo].name = nama_repo_baru;
		array_repo_baru[total_repo].branch_count = 1;
		array_repo_baru[total_repo].active_branch_idx = 0;

		array_repo_baru[total_repo].branches = new Branch[1];
		array_repo_baru[total_repo].branches[0].name = "main";
		array_repo_baru[total_repo].branches[0].head_commit = nullptr;
		array_repo_baru[total_repo].branches[0].commit_count = 0;

		delete[] daftar_repo;

		daftar_repo = array_repo_baru;
		total_repo = ukuran_baru;
		indeks_repo_aktif = total_repo - 1;
		
		cout << "\n[" << COLOR_GREEN << "OK" << COLOR_RESET << "] Repository '" << nama_repo_baru << "' berhasil dibuat dan diaktifkan.\n";
		cout << "On branch: " << COLOR_GREEN << "main" << COLOR_RESET << endl;
	}
	
	cout << "\nTekan Enter untuk kembali...";
	cin.get();
}

void menu_switch_repository(Repo* daftar_repo, int total_repo, int& indeks_repo_aktif) {
	CLS;
	cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
	cout << "switch repository" << endl;
	garis();
	
	cout << "Daftar repository yang tersedia:\n";
	for (int i = 0; i < total_repo; i++) {
		int idx_b_aktif = daftar_repo[i].active_branch_idx;
		string nama_b_aktif = daftar_repo[i].branches[idx_b_aktif].name;
		int jml_commit = daftar_repo[i].branches[idx_b_aktif].commit_count;

		cout << "[" << i + 1 << "] " << daftar_repo[i].name 
			 << " (" << daftar_repo[i].branch_count << " branch, " 
			 << jml_commit << " commits at HEAD: " << nama_b_aktif << ")";
			 
		if (i == indeks_repo_aktif) {
			cout << COLOR_GREEN << " [ACTIVE]" << COLOR_RESET;
		}
		cout << endl;
	}
	garis();

	int pilihan_nomor;
	cout << "Select repository number: ";
	cin >> pilihan_nomor;
	if (cin.fail()){
		cout<<"[ERROR] Masukan Angka Positif 1-"<<total_repo<<endl;
		cin.clear();
		cin.ignore(1000, '\n');
		
		cout << "\nTekan Enter untuk kembali...";
		cin.get();
		return;
	}
	int indeks_tujuan = pilihan_nomor - 1;
	
	if (indeks_tujuan < 0 || indeks_tujuan >= total_repo) {
		cout << COLOR_RED << "[ERROR] Nomor repository tidak valid atau tidak ditemukan!" << COLOR_RESET << endl;
		return;
	} 
	else {
		indeks_repo_aktif = indeks_tujuan;
		string branch_baru = daftar_repo[indeks_repo_aktif].branches[daftar_repo[indeks_repo_aktif].active_branch_idx].name;
		
		cout << "\n[" << COLOR_GREEN << "OK" << COLOR_RESET << "] Berhasil beralih ke repository '" << daftar_repo[indeks_repo_aktif].name << "'\n";
		cout << "HEAD otomatis mengikuti branch aktif terakhir: " << COLOR_GREEN << branch_baru << COLOR_RESET << endl;
	}
	
	cout << "\nTekan Enter untuk kembali...";
	cin.ignore(1000, '\n');
	cin.get();
}
int main(int argc, char* argv[]) {
	if (argc < 2) {
		CLS;
		cout << COLOR_RED << "[ERROR] Nama author tidak boleh kosong!" << COLOR_RESET << endl;
		cout << "Gunakan perintah: .\\gitsim <Nama_Anda>" << endl;
		return 1;
	}
	
	if (argc > 2) {
		CLS;
		cout << COLOR_RED << "[ERROR] Argumen terlalu banyak! Nama author cukup 1 kata tanpa spasi." << COLOR_RESET << endl;
		cout << "Gunakan perintah: .\\gitsim <Nama_Anda>" << endl;
		return 1;
	}

	string author_name = argv[1];
	if (author_name.length() < 3) {
		CLS;
		cout << COLOR_RED << "[ERROR] Nama author terlalu pendek! Minimal 3 huruf." << COLOR_RESET << endl;
		return 1;
	}

	string input_name = to_lower_case(author_name);
	
	if (input_name == "arizona" || input_name == "zona") {
		CLS;
		cout << COLOR_GREEN << "Halo Pria Sigma (Siapa Lagi Klo Bukan Gwh), Apakah Anda Siap Menghijaukan Github" << COLOR_RESET << endl;
	}
	int total_repo = 1;
	int indeks_repo_aktif = 0;
	Repo* daftar_repo = new Repo[total_repo];
	daftar_repo[0].branch_count = 1;
	daftar_repo[0].active_branch_idx = 0;
	daftar_repo[0].branches = new Branch[1];
	daftar_repo[0].branches[0].name = "main";
	daftar_repo[0].branches[0].head_commit = nullptr;
	daftar_repo[0].branches[0].commit_count = 0;
    string input_nama;
    cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
    cout << "Author: " << author_name << endl;
    garis();
    cout <<"git init"<< endl;
    garis();
    cout << COLOR_CYAN << "Repository name: " << COLOR_RESET;
    std::getline(std::cin, input_nama);
    if(input_nama.empty()){
        daftar_repo[0].name="My Repo";
    }
    else{
        daftar_repo[0].name=input_nama;
    }
    cout << COLOR_GREEN << "[OK]" << COLOR_RESET <<"Iniatialized empty repository: "<<daftar_repo[0].name<< endl;
    cout << "On branch: " << COLOR_GREEN <<daftar_repo[0].branches->name<< endl;
    cout << "\nTekan Enter untuk masuk ke Menu Utama...";
    cin.ignore(1000,'\n');
    cin.get();
	while (true) {
		CLS;
		Repo& repo_sekarang = daftar_repo[indeks_repo_aktif];
		
		cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
		cout << "Author : " << author_name << "  |  "
			 << "Repo: " << repo_sekarang.name << "  |  "
			 << "HEAD: " << COLOR_GREEN << repo_sekarang.branches[repo_sekarang.active_branch_idx].name << COLOR_RESET << "  |  "
			 << "[" << (indeks_repo_aktif + 1) << "/" << total_repo << "]" << endl;
		garis();
		cout << "[1] git commit\n";
		cout << "[2] git log\n";
		cout << "[3] git branch\n";
		cout << "[4] git checkout\n";
		cout << "[5] git init (new)\n";
		cout << "[6] switch repository\n";
		cout << "[7] exit\n";
		garis();
        int pilihan;
		cout << "> ";
        cin>>pilihan;
        switch (pilihan) {
            case 1:
                menu_commit(&daftar_repo[indeks_repo_aktif], author_name);
                break;
            case 2:
				menu_log(&daftar_repo[indeks_repo_aktif]);
                break;
				
			case 3:
				menu_branch(&daftar_repo[indeks_repo_aktif]);
                break;
                        
            case 4:
                menu_checkout(&daftar_repo[indeks_repo_aktif]);
                break;  
            case 5:
				menu_new_repository(daftar_repo, total_repo, indeks_repo_aktif);
				break;
            case 6:
                menu_switch_repository(daftar_repo, total_repo, indeks_repo_aktif);
                break;    
			case 7:
				CLS;
				cout << "Keluar dari program. Pembersihan memori selesai. Sampai jumpa!" << endl;
				for (int i = 0; i < daftar_repo[indeks_repo_aktif].branch_count; i++) {
					Commit* current = daftar_repo[indeks_repo_aktif].branches[i].head_commit;
					while (current != nullptr) {
						Commit* temp = current;
						current = current->next;
						delete temp;
					}
				}
				delete[] daftar_repo->branches;
				delete daftar_repo;
				return 0;
        }
    }
}