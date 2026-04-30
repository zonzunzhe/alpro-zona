#include <iostream>
int main(){
    int umur;
    int shield=3;
    char pilihan_gerakan;
    char pilihan_lawan;
    int waktu_selam = 60;
    int waktu_sekarang = 0;
    int tugas = 1;
    bool cihuy = 1;
    std::cout<<"=== GOBLET OF FIRE: TURNAMENT TRIWIZARD ==="<<std::endl;
    std::cout<<"Masukan umur anda: "<<std::endl;
    std::cin >> umur;
    if (umur >= 17){
        std::cout<<"Piala Api Menyala! Anda Terpilih"<<std::endl;
        switch (tugas)
        {
            case 1:
            std::cin.ignore();        
            std::cin.get();
            system("cls");
            std::cout<<"--- TUGAS 1: NAGA HUNGARIAN HORNTAIL ---"<<std::endl;
            std::cout<<"Nyawa Anda Sisa "<< shield <<std::endl;
            do
            {
                std::cout<<"Pilih Strategi (a:sembunyi b:panggil sapu): "<<std::endl;
                std::cin>>pilihan_gerakan;
                if (pilihan_gerakan == 'a' || pilihan_gerakan == 'A' ) {
                    shield --;
                    std::cout<<"Naga Menyemburkan Api"<<std::endl;
                    std::cout<<"Nyawa Anda Sisa "<< shield <<std::endl;
                    if (shield <= 0){
                        std::cout<<"Kesempatan Habis Pawang Telah Menendang Anda Keluar"<<std::endl;
                        std::cout<<"MULAI DARI TUGAS 1 LAGI"<<std::endl;
                        tugas = 1;
                        shield = 3;
                        system("pause");
                        system("cls");
                    }
                }
                
                else if (pilihan_gerakan == 'b' || pilihan_gerakan == 'B' ) {
                    std::cout <<"Anda Berhasil Menemukan Telur Emas";
                    cihuy = 0; 
                    tugas = 2;
                }
                else {
                    std::cout<<"Pilihan Tidak Valid"<<std::endl;
                }
            } while (cihuy);
            case 2:
            system("pause");
            system("cls");
            std::cout<<"--- DANAU IRENG ---"<<std::endl;
            while (waktu_sekarang <= waktu_selam){
                std::cout<<"menit "<<waktu_sekarang<<" "<<"ada grindlow (l : lawan , h : hindari) :";
                std::cin>>pilihan_lawan;
                if (pilihan_lawan == 'l' || pilihan_lawan == 'L' ) {
                    waktu_sekarang = 0;
                    system("pause");
                    system("cls");
                }
                else if (pilihan_lawan == 'h' || pilihan_lawan == 'H') {
                    waktu_sekarang += 10;
                }
                else {
                    std::cout<<"pilihan tidak valid"<<std::endl;
                }
            }
            break;
        default:
            break;
        }
        
    }
    
    else{
        std::cout<<"-----------------------------------"<<std::endl;
        

    }

}