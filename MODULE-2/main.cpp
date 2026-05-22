#include <iostream>
#include "logic.hpp"
int main() {
    int umur,arah,lebar;
    char pilihan_gerakan,pilihan_lawan;
    int shield = 3,waktu_selam = 60,waktu_sekarang = 10,langkah_sekarang = 0,langkah_wajib = 3,toleransi = 2 ;
    bool cihuy = 1;
    std::cout << "=== GOBLET OF FIRE: TURNAMENT TRIWIZARD ===" << std::endl;
    std::cout << "Masukan umur anda: " << std::endl;
    std::cin >> umur;
    std::cin.clear(); 
    std::cin.ignore(1000, '\n');
    if (umur >= 17) {
	std::cout << "Piala Api Menyala! Anda Terpilih" << std::endl;
	PAUSE();
	SAPU_LAYAR();
	TUGAS1(shield, pilihan_gerakan, cihuy);
	PAUSE();
	SAPU_LAYAR();
	TUGAS2(waktu_sekarang, waktu_selam, pilihan_lawan);
	PAUSE();
	SAPU_LAYAR();
	TUGAS3(langkah_sekarang, langkah_wajib, toleransi, arah);
	PAUSE();
	SAPU_LAYAR();
	TUGAS4(lebar);
    } else if (umur > 0 && umur < 17) {
	std::cout << "BOCIL GAK BOLEH IKUT,BALEK SANA MAEN EP EP" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
    } else {
	std::cout << "INPUT TIDAK VALID" << std::endl;
	std::cout << "-----------------------------------" << std::endl;
    }
}