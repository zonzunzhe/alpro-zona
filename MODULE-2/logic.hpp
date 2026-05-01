#ifndef LOGIC_HPP
#define LOGIC_HPP

#include <iostream>
#define BELAH_KETUPAT(n)                                           \
    do {                                                           \
	for (int i = 1; i <= (n); i++) {                           \
	    for (int j = 1; j <= (n) - i; j++) std::cout << " ";   \
	    for (int k = 1; k <= 2 * i - 1; k++) std::cout << "*"; \
	    std::cout << std::endl;                                \
	}                                                          \
	for (int i = (n) - 1; i >= 1; i--) {                       \
	    for (int j = 1; j <= (n) - i; j++) std::cout << " ";   \
	    for (int k = 1; k <= 2 * i - 1; k++) std::cout << "*"; \
	    std::cout << std::endl;                                \
	}                                                          \
    } while (0)
#define SAPU_LAYAR() std::cout << "\033[2J\33[1;1H";
#define PAUSE()                                            \
    {                                                      \
	std::cout << "Press the ENTER key to continue..."; \
	do {                                               \
	    std::cin.get();                                \
	} while (0);                                       \
    }
#define TUGAS1(shield, pilihan_gerakan, cihuy)                         \
    {                                                                         \
	std::cout << "--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---" << std::endl; \
	std::cout << "Nyawa Anda Sisa " << shield << std::endl;               \
	do {                                                                  \
	    std::cout << "Pilih Strategi (a:sembunyi b:panggil sapu): "       \
		      << std::endl;                                           \
	    std::cin >> pilihan_gerakan;                                      \
	    std::cin.ignore(1000, '\n');                                      \
	    if (std::cin.fail()) {                                            \
		std::cin.clear();                                             \
		std::cout << "Input harus berupa karakter! Coba lagi.\n"      \
			  << std::endl;                                       \
		continue;                                                     \
	    }                                                                 \
	    if (pilihan_gerakan == 'a' || pilihan_gerakan == 'A') {           \
		shield--;                                                     \
		std::cout << "Naga Menyemburkan Api" << std::endl;            \
		std::cout << "Nyawa Anda Sisa " << shield << std::endl;       \
		if (shield <= 0) {                                            \
		    std::cout << "Kesempatan Habis Pawang Telah Menendang "   \
				 "Anda Keluar"                                \
			      << std::endl;                                   \
		    std::cout << "MULAI DARI TUGAS 1 LAGI" << std::endl;      \
		    shield = 3;                                               \
		    PAUSE();                                                  \
		    SAPU_LAYAR();                                             \
		}                                                             \
	    }                                                                 \
                                                                              \
	    else if (pilihan_gerakan == 'b' || pilihan_gerakan == 'B') {      \
		std::cout << "Anda Berhasil Menemukan Telur Emas"             \
			  << std::endl;                                       \
		cihuy = 0;                                                    \
	    } else {                                                          \
		std::cout << "Pilihan Tidak Valid" << std::endl;              \
	    }                                                                 \
	} while (cihuy);                                                      \
    }
#define TUGAS2(waktu_sekarang, waktu_selam, pilihan_lawan)                     \
    {                                                                          \
	std::cout << "--- DANAU IRENG ---" << std::endl;                       \
	while (waktu_sekarang < waktu_selam) {                                 \
	    std::cout << "menit " << waktu_sekarang << " "                     \
		      << "ada grindlow (l : lawan , h : hindari) :";           \
	    std::cin >> pilihan_lawan;                                         \
	    std::cin.ignore(1000, '\n');                                       \
	    if (std::cin.fail()) {                                             \
		std::cin.clear();                                              \
		std::cout << "Input harus berupa angka! Coba lagi.\n"          \
			  << std::endl;                                        \
		continue;                                                      \
	    }                                                                  \
	    if (pilihan_lawan == 'l' || pilihan_lawan == 'L') {                \
		std::cout << "Kamu sangat gegabah dan hampir "                 \
			     "meninggal,untungnya ada putri duyung baik yang " \
			     "mambantumu naik ke permukaan "                   \
			  << std::endl;                                        \
		waktu_sekarang = 0;                                            \
		SAPU_LAYAR();                                                  \
	    } else if (pilihan_lawan == 'h' || pilihan_lawan == 'H') {         \
		waktu_sekarang += 10;                                          \
	    } else {                                                           \
		std::cout << "pilihan tidak valid" << std::endl;               \
	    }                                                                  \
	}                                                                      \
	std::cout << "ANDA BERHASIL MENYELAMATKAN TAWANAN DALAM TEPAT "        \
		  << waktu_sekarang << " MENIT" << std::endl;                  \
    }
#define TUGAS3(langkah_sekarang, langkah_wajib, toleransi, arah)             \
    {                                                                        \
	std::cout << "--- TUGAS 3 : LABIRIN ---" << std::endl;               \
	while (langkah_sekarang < langkah_wajib) {                           \
	    std::cout << "Langkah Ditempuh: " << langkah_sekarang            \
		      << std::endl;                                          \
	    std::cout << "Toleransi Kesalahan: " << toleransi << std::endl;  \
	    std::cout << "Pilih Arrah (1.kiri , 2.kanan , 3.Lurus): ";       \
	    std::cin >> arah;                                                \
	    if (std::cin.fail()) {                                           \
		std::cin.clear();	     \
		std::cin.ignore(1000, '\n'); \
		std::cout << "Input harus angka! Coba lagi.\n"        \
			  << std::endl;                                      \
		continue;                                                    \
	    }                                                                \
                                                                             \
	    std::cin.ignore(1000, '\n');                                     \
	    if (arah == 1) {                                                 \
		std::cout                                                    \
		    << "Awww Kaki Saya Sakit (Kamu terkena akar berbisa)"    \
		    << std::endl;                                            \
		langkah_sekarang = 0;                                        \
		toleransi--;                                                 \
		if (toleransi <= 0) {                                        \
		    std::cout << ">>KESEMPATAN HABIS KAMU DITENDANG KELUAR " \
				 "DARI LABIRIN"                              \
			      << std::endl;                                  \
		    std::cout << ">>Mengulang Dari Awal" << std::endl;       \
		    langkah_sekarang = 0;                                    \
		    toleransi = 3;                                           \
		    PAUSE();                                                 \
		    SAPU_LAYAR();                                            \
		}                                                            \
	    } else if (arah == 2) {                                          \
		langkah_sekarang++;                                          \
	    } else if (arah == 3) {                                          \
		langkah_sekarang = 3;                                        \
	    } else {                                                         \
		std::cout << "pilihan tidak valid,pilih lagi: ";             \
	    }                                                                \
	}                                                                    \
	std::cout << "Aku melihat cahaya... ohh .. apatu woi" << std::endl;  \
    }
#define TUGAS4(lebar)                                                    \
    {                                                                    \
	std::cout << "--- JALAN KELUAR ---" << std::endl;                \
	std::cout << "Kamu melihat sesuatu yang bersinar ditengah arena" \
		  << std::endl;                                          \
	std::cout << "Terdapat sesuatu yang terkurung di dalam sebuah "  \
		     "mesin,coba masukan angka ke mesin itu"             \
		  << std::endl;                                          \
	std::cout << "Masukan Angka (Minimal 5): ";                      \
	std::cin >> lebar;                                               \
	BELAH_KETUPAT(lebar);                                            \
	std::cout << "HOREEEEE KAMU JUARAAAAA BANGGA GWH";               \
    }
#endif