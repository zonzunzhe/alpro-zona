#include <iostream>
#include <cstdlib>
#include <climits>

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

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cout <<"Usage: ./solution.exe <student_id>\nExample: ./solution.exe F1D02410053\n";
        return 1;
    }
    else if (argc > 2) {
        std::cout <<"Error: Too many arguments.\n";
        return 1;
    }
    if (nim_valid(argv[1])) {
        std::cout << "NIM VALID: " << argv[1] << "\n";
    } else {
        std::cout << "NIM INVALID: " << argv[1] << "\n";
    }
    std::cout << "Cihuy";
    return 0;
}
