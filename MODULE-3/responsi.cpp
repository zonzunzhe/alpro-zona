#include <iostream>
using namespace std;

int main() {
    char text_enkrip[1024];
    char matrix_cihuy[5][5];
    int shift_key = 9;
    int text_len = 0;

    cout << "Enter Clue: ";
    cin.getline(text_enkrip, 1024);
    char treasure_loc = toupper(text_enkrip[0]);

    while (text_enkrip[text_len] != '\0') {
        text_len++;
    }
    for (int i = 0; i < text_len; i++) {
        if (text_enkrip[i] >= 'a' && text_enkrip[i] <= 'z') {
            text_enkrip[i] = (text_enkrip[i] - 'a' - shift_key + 26) % 26 + 'a';
        }
        else if (text_enkrip[i] >= 'A' && text_enkrip[i] <= 'Z') {
            text_enkrip[i] = (text_enkrip[i] - 'A' - shift_key + 26) % 26 + 'A';
        }
    }
    cout << "Decrypt Result: " << text_enkrip << endl << endl;
    char abjad = 'A';
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            matrix_cihuy[i][j] = abjad++;
        }
    }
    int nyawa = 5;
    bool aseli = false;
    while (nyawa > 0 && !aseli) {
        cout << "Nyawa saat ini = " << nyawa << endl;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cout << "  " << matrix_cihuy[i][j] << "  ";
                if (j < 4) cout << "|";
            }
            cout << endl;
            if (i < 4) {
                for (int k = 0; k < 5; k++) {
                    cout << "-----";
                    if (k < 4) cout << "|";
                }
                cout << endl;
            }
        }
        char move;
        cout << endl << "Enter your move (A to Y): ";
        cin >> move;
        move = toupper(move);
        if (move == treasure_loc) {
            cout << endl;
            cout << "+-------------------------------------------------------+" << endl;
            cout << "|                                                       |" << endl;
            cout << "|    Prabowo Gilloww!                                   |" << endl;
            cout << "|                                                       |" << endl;
            cout << "|    You found the treasure at:                         |" << endl;
            cout << "|                                                       |" << endl;
            cout << "+-------------------------------------------------------+" << endl;
            cout << "You win the game!" << endl;
            aseli = true;
        } else {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (matrix_cihuy[i][j] == move) {
                        matrix_cihuy[i][j] = '_';
                    }
                }
            }
            nyawa--;
            cout << "Wrong move! The treasure was not there." << endl;
            if (nyawa == 0) {
                cout << "Game Over! Nyawa habis. Cupu banget njir." << endl;
                cout << "Harta sebenarnya ada di: " << treasure_loc << endl;
            }
        }
        cout << "---------------------------------------------------------" << endl;
    }
    return 0;
}