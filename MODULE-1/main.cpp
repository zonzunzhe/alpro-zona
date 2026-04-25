#include <iostream>
int main() {
  std::cout << "===== HORIZON CALCULATOR =====" << std::endl;
  float angka_pertama, angka_kedua;
  int range;
  char a, b, c, d, e;
  std::cout << "masukan angka pertama: ";
  std::cin >> angka_pertama;
  std::cout << "masukan angka kedua: ";
  std::cin >> angka_kedua;
  float hasil_tambah = angka_pertama + angka_kedua;
  float hasil_kurang = angka_pertama - angka_kedua;
  float hasil_kali = angka_pertama * angka_kedua;
  float hasil_bagi = angka_pertama / angka_kedua;
  std::cout << "Pertambahan: " << hasil_tambah << std::endl;
  std::cout << "Pengurangan: " << hasil_kurang << std::endl;
  std::cout << "Perkalian: " << hasil_kali << std::endl;
  std::cout << "Pembagian: " << hasil_bagi << std::endl;
  std::cout << "===== HORIZON SIGNATURE NAME =====" << std::endl;
  std::cout << "masukan 5 karakter (lowercase): ";
  std::cin >> a;
  std::cin >> b;
  std::cin >> c;
  std::cin >> d;
  std::cin >> e;
  std::cout << "Input: " << a << b << c << d << e << std::endl;
  std::cout << "UPPERCASE: " << static_cast<char>(a - 32)
            << static_cast<char>(b - 32) << static_cast<char>(c - 32)
            << static_cast<char>(d - 32) << static_cast<char>(e - 32)
            << std::endl;
  std::cout << "ASCII: " << static_cast<int>(a) << " " << static_cast<int>(b)
            << " " << static_cast<int>(c) << " " << static_cast<int>(d) << " "
            << static_cast<int>(e) << " " << std::endl;
  std::cout << "Total ASCII: "
            << static_cast<int>(a) + static_cast<int>(b) + static_cast<int>(c) +
                   static_cast<int>(d) + static_cast<int>(e)
            << " " << std::endl;
  std::cout << "Rata-Rata: "
            << (static_cast<float>(a) + static_cast<float>(b) +
                static_cast<float>(c) + static_cast<float>(d) +
                static_cast<float>(e)) /
                   5
            << " " << std::endl;
  std::cout << "===== ENKRIPSI =====" << std::endl;
  std::cout << "Masukan Range: ";
  std::cin >> range;
  char e1 = ((a - 'a' + range) % 26) + 'a';
  char e2 = ((b - 'a' + range) % 26) + 'a';
  char e3 = ((c - 'a' + range) % 26) + 'a';
  char e4 = ((d - 'a' + range) % 26) + 'a';
  char e5 = ((e - 'a' + range) % 26) + 'a';
  std::cout << "Hasil Enkripsi: " << e1 << e2 << e3 << e4 << e5 << std::endl;
  std::cout << "===== REVERSE =====" << std::endl;
  char r1 = ((a - 'a' - range + 26) % 26) + 'a';
  char r2 = ((b - 'a' - range + 26) % 26) + 'a';
  char r3 = ((c - 'a' - range + 26) % 26) + 'a';
  char r4 = ((d - 'a' - range + 26) % 26) + 'a';
  char r5 = ((e - 'a' - range + 26) % 26) + 'a';
  std::cout << "Masukan Range: ";
  std::cin >> range;
  std::cout << "Hasil Enkripsi: " << r1 << r2 << r3 << r4 << r5 << std::endl;
  return 0;
}
