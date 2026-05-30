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
	} else {
        cout << "\nCommit dibatalkan." << endl;
        return;
	}
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
    Repo* repo_aktif=new Repo;
    repo_aktif->branch_count = 1;
	repo_aktif->active_branch_idx = 0;
    repo_aktif->branches = new Branch[1];
	repo_aktif->branches[0].name = "main";
	repo_aktif->branches[0].head_commit = nullptr;
	repo_aktif->branches[0].commit_count = 0;
    string input_nama;
    cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
    cout << "Author: " << author_name << endl;
    garis();
    cout <<"git init"<< endl;
    garis();
    cout << COLOR_CYAN << "Repository name: " << COLOR_RESET;
    std::getline(std::cin, input_nama);
    if(input_nama.empty()){
        repo_aktif->name="My Repo";
    }
    else{
        repo_aktif->name=input_nama;
    }
    cout << COLOR_GREEN << "[OK]" << COLOR_RESET <<"Iniatialized empty repository: "<<repo_aktif->name<< endl;
    cout << "On branch: " << COLOR_GREEN <<repo_aktif->branches->name<< endl;
    cout << "\nTekan Enter untuk masuk ke Menu Utama...";
    cin.ignore(1000,'\n');
    cin.get();
	while (true) {
        CLS;
        cout << COLOR_CYAN << "GITSIM - Git Simulator" << COLOR_RESET << endl;
		cout << "Author : " << author_name << "  |  "
			 << "Repo: " << repo_aktif->name << "  |  "
			 << "HEAD: " << COLOR_GREEN << repo_aktif->branches[repo_aktif->active_branch_idx].name << COLOR_RESET << "  |  "
			 << "[1/1]" << endl;
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
                menu_commit(repo_aktif, author_name);
                break;
                        
            case 2:
                cout<<"cihuy";
                break;
                        
            case 3:
                cout<<"cihuy";
                break;
                        
            case 4:
                cout<<"cihuy";
                break;
                        
            case 5:
                cout<<"cihuy";
                break;
                        
            case 6:
                cout<<"cihuy";
                break;
                        
            case 7:
                CLS;
                cout << "Keluar dari program. Pembersihan memori selesai. Sampai jumpa!" << endl;
                        
                Commit* current = repo_aktif->branches[0].head_commit;
                while (current != nullptr) {
                    Commit* temp = current;
                    current = current->next;
                    delete temp;
            }
            break;
        }
        break;
    }
    delete[] repo_aktif->branches;
	delete repo_aktif;
	return 0;
}